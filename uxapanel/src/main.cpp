///
/// @file    uxapanel/main.cpp
/// @brief   QT Gui control UXA90 Light robot
/// @author  nvtienanh
///

#include <iostream>
#include <boost/filesystem.hpp>
#include <string>
#include <VirtualRobot/RuntimeEnvironment.h>
#include <VirtualRobot/XML/RobotIO.h>
#include "Window.h"

using namespace VirtualRobot;

/*!
 * \brief loadRobot model
 * \param robotFilename
 * \return Return the Robot Pointer (VirtualRobot::RobotPtr)
 */
VirtualRobot::RobotPtr loadRobot(std::string robotFilename) {
	VirtualRobot::RobotPtr robot;
	try {
		robot = VirtualRobot::RobotIO::loadRobot(robotFilename,
				VirtualRobot::RobotIO::eFull);
	} catch (VirtualRobot::VirtualRobotException& e) {
		std::cout << " ERROR while creating robot" << endl;
		std::cout << e.what();
	}

	return robot;
}

int main(int argc, char *argv[]) {
	SoDB::init();
	SoQt::init(argc, argv, "ReferenceIK Demo");

//    std::string filename(
//            "/home/tienanh/themarex/UXAProject/uxabiped/data/armar4/ArmarIV-StartLeftLeg.xml");

    std::string filename(
            "/home/tienanh/themarex/UXAProject/uxabiped/data/UXA/UXA-StartLeftLeg.xml");

	if (VirtualRobot::RuntimeEnvironment::hasValue("robot")) {
		std::string robFile = VirtualRobot::RuntimeEnvironment::getValue(
				"robot");
		if (VirtualRobot::RuntimeEnvironment::getDataFileAbsolute(robFile)) {
			filename = robFile;
		}
	}

	boost::filesystem::path path(filename);
	if (!boost::filesystem::exists(path)) {
		std::cout << "Error: Robot file not found: " << path.string()
				<< std::endl;
		return 1;
	}
	filename = boost::filesystem::canonical(path).string();

	std::cout << "Using robot at " << filename << std::endl;

	Window w(loadRobot(filename));
	w.main();

	return 0;

}
