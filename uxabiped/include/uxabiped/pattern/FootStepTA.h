/*

Copyright (c) 2014, Patrick Niklaus, others
All rights reserved.

This file is licensed under the simplified 2-clause BSD license as provided
in by LICENSE file.

*/
#ifndef __REFERENCE_IK_H__
#define __REFERENCE_IK_H__

#include <Eigen/Dense>
#include <VirtualRobot/VirtualRobot.h>

#include "FootstepPlaner.h"
namespace Bipedal
{


/* Interface to compute IK from reference frames */
class FootStepTA
{
public:
    FootStepTA();
    virtual ~FootStepTA() {}
};

}

#endif

