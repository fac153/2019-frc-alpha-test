/*
 * ClimbGroup.cpp
 *
 *  Created on: Feb 20, 2018
 *      Author: Sayfullah
 */

#include <Commands/ClimbGroup.h>
#include "Commands/Spine.h"
#include "Commands/ArmSwing.h"


ClimbGroup::ClimbGroup() {
	AddSequential(new ArmSwing(0));
	AddSequential(new Spine(2048));
	AddSequential(new ArmSwing(180));
	AddSequential(new Spine(6826));
}


