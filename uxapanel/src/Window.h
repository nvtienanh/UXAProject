/*!
  * \file uxapanel/Window.h
  * \author nvtienanh
  * \brief Header file of QT GUI
  *
  */

#ifndef __WINDOW_H_
#define __WINDOW_H_

#include <VirtualRobot/VirtualRobot.h>

#include <Eigen/Dense>

#include <string.h>

#include <QtCore/QtGlobal>
#include <QtGui/QtGui>
#include <QtCore/QtCore>

#include <Inventor/sensors/SoTimerSensor.h>
#include <Inventor/nodes/SoEventCallback.h>
#include <Inventor/Qt/viewers/SoQtExaminerViewer.h>
#include <Inventor/Qt/SoQt.h>
#include <Inventor/nodes/SoSeparator.h>

#include "uxabiped/bipedal.h"
#include "uxabiped/ik/DifferentialReferenceIK.h"
#include "uxabiped/pattern/PolynomialFootstepPlaner.h"

#include "ui_Window.h"

/*!
 * \brief The Window class
 * \todo Write more description for doxygen
 * \date
 */
class Window: public QMainWindow {
	Q_OBJECT
public:

    /*!
     * \brief Window constructor
     * \param flags
     */
	Window(VirtualRobot::RobotPtr, Qt::WFlags flags = 0);

     /*!
      * \brief Default Window class constructor
      * \author nvtienanh
      */
	~Window();

	/*!< Executes the SoQt mainLoop. You need to call this in order to execute the application. */
	int main();

public slots:
	/*! Closes the window and exits SoQt runloop. */
	void quit();

	/*!< Overriding the close event, so we know when the window was closed by the user. */
	void closeEvent(QCloseEvent *event);

	void frameChanged(double);
	void updateCurrentRef();

	SoQtExaminerViewer* getExaminerViewer() {
		return viewer;
	}

protected:

    /*!
     * \brief Initial UXA Control Panel Graphical User Interface
     */
	void setupUI();

    /*!
     * \brief Method update Inverse Kinematic problem
     */
	void updateIK();

    /*!
     * \brief UI
     */
	Ui::MainWindowShowRobot UI;

    /*!
     * \brief Viewer to display the 3D model of the robot and the environment.
     */
    SoQtExaminerViewer *viewer;

	SoSeparator *sceneSep;
	SoSeparator *robotSep;
	SoSeparator *robotInvSep;

	VirtualRobot::RobotPtr robot;
	VirtualRobot::RobotPtr robotInv;
	VirtualRobot::RobotNodeSetPtr nodes;

	Bipedal::ReferenceIKPtr referenceIK;
	std::vector<std::string> frameNames;
	std::vector<Eigen::Matrix4f, Eigen::aligned_allocator<Eigen::Matrix4f>> refFrames;

	bool computeIK;

};

#endif // __WINDOW_H_
