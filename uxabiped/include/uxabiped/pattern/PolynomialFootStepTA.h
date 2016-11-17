/*

Copyright (c) 2014, Patrick Niklaus, others
All rights reserved.

This file is licensed under the simplified 2-clause BSD license as provided
in by LICENSE file.

*/
#ifndef __DIFFERENTIAL_REFERENCE_IK_H__
#define __DIFFERENTIAL_REFERENCE_IK_H__

#include "FootStepTA.h"

#include <VirtualRobot/VirtualRobot.h>
#include <VirtualRobot/Robot.h>
#include <VirtualRobot/RobotFactory.h>
#include <VirtualRobot/RobotNodeSet.h>
#include <VirtualRobot/IK/HierarchicalIK.h>
#include <VirtualRobot/IK/DifferentialIK.h>
#include <Eigen/Dense>

#include "../utils/Kinematics.h"

namespace Bipedal
{

/**
 * This class computes a differtial IK from the current support foot
 * to the pelvis, from the pevlis to the chest and swing foot.
 *
 * TODO: Much of this code should be in Simox.
 * Most of the node names can be obtained from a RobotConfig.
 * They should not be initialized by hard coded names.
 */
class PolynomialFootStepTA : public FootStepTA
{


}

#endif

