#include "Window.h"
#include <VirtualRobot/RuntimeEnvironment.h>
#include <VirtualRobot/SceneObject.h>
#include <VirtualRobot/MathTools.h>
#include <VirtualRobot/Visualization/CoinVisualization/CoinVisualization.h>

#include <Eigen/Geometry>

#include <Inventor/actions/SoLineHighlightRenderAction.h>
#include <Inventor/nodes/SoShapeHints.h>
#include <Inventor/nodes/SoLightModel.h>
#include <Inventor/nodes/SoMaterial.h>

#include <boost/filesystem.hpp>
#include <boost/make_shared.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/assert.hpp>

float TIMER_MS = 30.0f;

Window::Window(VirtualRobot::RobotPtr robot, Qt::WFlags flags) :
		QMainWindow(NULL), robot(robot), computeIK(true) {
	frameNames =
	{
		"LeftLeg_TCP",
		"RightLeg_TCP",
		"TorsoCenter",
		"Waist",
	};

	nodes = robot->getRobotNodeSet("CoMCompensation");

	boost::shared_ptr<Bipedal::DifferentialReferenceIK> diffIK =
	boost::make_shared<Bipedal::DifferentialReferenceIK>(
			nodes,
			robot,
			robot->getRobotNodeSet("ColModelAll"),
			robot->getRobotNode(frameNames[0]),
			robot->getRobotNode(frameNames[1]),
			robot->getRobotNode(frameNames[2]),
			robot->getRobotNode(frameNames[3]));

	referenceIK = boost::dynamic_pointer_cast<Bipedal::ReferenceIK>(diffIK);
	robotInv = diffIK->getInvertedRobot();

	for (auto& s : frameNames)
	{
		refFrames.push_back(robot->getRobotNode(s)->getGlobalPose());
	}

	sceneSep = new SoSeparator();
	sceneSep->ref();
	robotSep = new SoSeparator();
	robotInvSep = new SoSeparator();
	sceneSep->addChild(robotSep);
	sceneSep->addChild(robotInvSep);
	boost::shared_ptr<VirtualRobot::CoinVisualization> visualization =
	robot->getVisualization<VirtualRobot::CoinVisualization>(VirtualRobot::SceneObject::Full);
	robotSep->addChild(visualization->getCoinVisualization());

	visualization =
	robotInv->getVisualization<VirtualRobot::CoinVisualization>(VirtualRobot::SceneObject::Full);
	SoMaterial* mat = new SoMaterial();
	mat->diffuseColor.setValue(0.2, 1.0, 0.2);
	mat->ambientColor.setValue(0.1, 0.8, 0.1);
	mat->setOverride(true);
	robotInvSep->addChild(mat);
	robotInvSep->addChild(visualization->getCoinVisualization());

//    boost::shared_ptr<Bipedal::PolynomialFootstepPlaner> PolyFootPlaner =
//    boost::shared_ptr<Bipedal::PolynomialFootstepPlaner>(new Bipedal::PolynomialFootstepPlaner(robot->getRobotNode(frameNames[0]),robot->getRobotNode(frameNames[1])));

//    PolynomialFootstepPlaner *PolyFootPlane = new PolynomialFootstepPlaner(robot->getRobotNode(frameNames[0]),
//            robot->getRobotNode(frameNames[1]));

    VirtualRobot::RobotNodePtr leftFootBody = robot->getRobotNode("LeftLeg_BodyAnkle2");
    VirtualRobot::RobotNodePtr rightFootBody = robot->getRobotNode("RightLeg_BodyAnkle2");

    boost::shared_ptr<Bipedal::PolynomialFootstepPlaner> PolyFootPlaner =
    boost::make_shared<Bipedal::PolynomialFootstepPlaner>(leftFootBody,rightFootBody);

    Eigen::Matrix4f leftFootPose = leftFootBody->getGlobalPose();
    Eigen::Matrix4f rightFootPose = rightFootBody->getGlobalPose();
    // Todo:
    // Should add Foot Poseture???
    // Set FootstepPlaner
    PolyFootPlaner->setParameters(3,10,double(0.3),double(0.7),double(0.1),double(0.1),double(0.0),double(1.0));
    PolyFootPlaner->generate(leftFootPose,rightFootPose);
    Eigen::Matrix6Xf LeftFootTrajectory, RightFootTrajectory;
    LeftFootTrajectory = PolyFootPlaner->getLeftFootTrajectory();
    RightFootTrajectory = PolyFootPlaner->getRightFootTrajectory();

    std::string sep = "\n----------------------------------------\n";
    Eigen::IOFormat CleanFmt(4, 0, ", ", "\n", "[", "]");
//    std::cout << LeftFootTrajectory.AlignedMapType<< sep;

    std::cout << "Number of cols" << std::endl;
    std::cout <<LeftFootTrajectory<< std::endl;
	setupUI();

	viewer->viewAll();
}

Window::~Window() {
	sceneSep->unref();
}

void Window::setupUI() {
	UI.setupUi(this);
	viewer = new SoQtExaminerViewer(UI.frameViewer, "", TRUE,
			SoQtExaminerViewer::BUILD_POPUP);

	// setup
	viewer->setBackgroundColor(SbColor(1.0f, 1.0f, 1.0f));
	viewer->setAccumulationBuffer(true);
	viewer->setGLRenderAction(new SoLineHighlightRenderAction());
	viewer->setTransparencyType(SoGLRenderAction::BLEND);
	viewer->setFeedbackVisibility(true);
	viewer->setSceneGraph(sceneSep);
	viewer->viewAll();

	for (unsigned i = 0; i < frameNames.size(); i++) {
		UI.comboBoxFrames->insertItem(i, frameNames[i].c_str());
	}

connect(UI.spinBoxX, SIGNAL(valueChanged(double)), this, SLOT(frameChanged(double)));
connect(UI.spinBoxY, SIGNAL(valueChanged(double)), this, SLOT(frameChanged(double)));
connect(UI.spinBoxZ, SIGNAL(valueChanged(double)), this, SLOT(frameChanged(double)));
connect(UI.spinBoxRoll, SIGNAL(valueChanged(double)), this, SLOT(frameChanged(double)));
connect(UI.spinBoxPitch, SIGNAL(valueChanged(double)), this, SLOT(frameChanged(double)));
connect(UI.spinBoxYaw, SIGNAL(valueChanged(double)), this, SLOT(frameChanged(double)));
connect(UI.comboBoxFrames, SIGNAL(currentIndexChanged(int)), this, SLOT(updateCurrentRef()));
}

int Window::main() {
SoQt::show(this);
SoQt::mainLoop();
return 0;
}

void Window::quit() {
this->close();
SoQt::exitMainLoop();
}

void Window::closeEvent(QCloseEvent* event) {
quit();
QMainWindow::closeEvent(event);
}

void Window::frameChanged(double) {
unsigned i = UI.comboBoxFrames->currentIndex();
BOOST_ASSERT(i < refFrames.size());

VirtualRobot::MathTools::rpy2eigen4f(UI.spinBoxRoll->value(),
		UI.spinBoxPitch->value(), UI.spinBoxYaw->value(), refFrames[i]);
refFrames[i](0, 3) = UI.spinBoxX->value();
refFrames[i](1, 3) = UI.spinBoxY->value();
refFrames[i](2, 3) = UI.spinBoxZ->value();

//    VirtualRobot::RobotNodePtr rn = robot->getRobotNode("RightLeg_BodyToe");
//    std::cout << "and after being transposed:\n" << rn->getMass() << std::endl;
//    robot->print();

updateIK();
}

void Window::updateIK() {
if (!computeIK)
	return;

std::cout << "Using the following frames for IK:" << std::endl;
for (auto& f : refFrames) {
	std::cout << f << std::endl;
}

Eigen::VectorXf result;
Bipedal::SupportPhase phase;

if (UI.radioButtonLeftSupport->isChecked()) {
	phase = Bipedal::SUPPORT_LEFT;
} else if (UI.radioButtonRightSupport->isChecked()) {
	phase = Bipedal::SUPPORT_RIGHT;
} else if (UI.radioButtonDualSupport->isChecked()) {
	phase = Bipedal::SUPPORT_BOTH;
}
referenceIK->computeStep(refFrames[0], refFrames[1], refFrames[2], refFrames[3],
		Eigen::Vector3f::Zero(), phase, result);

//    zmpplaner->

for (unsigned i = 0; i < frameNames.size(); i++) {
	refFrames[i] = robot->getRobotNode(frameNames[i])->getGlobalPose();
//        std::cout << refFrames[i] << std::endl;
}
}

void Window::updateCurrentRef() {
unsigned i = UI.comboBoxFrames->currentIndex();

float xyzrpy[6];

VirtualRobot::MathTools::eigen4f2rpy(refFrames[i], xyzrpy);

computeIK = false;
UI.spinBoxX->setValue(xyzrpy[0]);
UI.spinBoxY->setValue(xyzrpy[1]);
UI.spinBoxZ->setValue(xyzrpy[2]);
UI.spinBoxRoll->setValue(xyzrpy[3]);
UI.spinBoxPitch->setValue(xyzrpy[4]);
UI.spinBoxYaw->setValue(xyzrpy[5]);
computeIK = true;
}

