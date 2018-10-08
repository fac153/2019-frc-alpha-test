/*
 * ArmClimb.h
 *
 *  Created on: Feb 20, 2018
 *      Author: raven8
 */

#ifndef SRC_COMMANDS_ARMSWING_H_
#define SRC_COMMANDS_ARMSWING_H_

#include "WPILib.h"
#include "Robot.h"
#include "RobotMap.h"

class ArmSwing : public Command{
private:
	float Position;
public:
	ArmSwing(float position);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif /* SRC_COMMANDS_ARMSWING_H_ */
