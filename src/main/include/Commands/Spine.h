/*
 * Spine.h
 *
 *  Created on: Feb 20, 2018
 *      Author: raven8
 */

#ifndef SRC_COMMANDS_SPINE_H_
#define SRC_COMMANDS_SPINE_H_

#include "WPILib.h"
#include "Robot.h"
#include "RobotMap.h"

class Spine : public Command {
private:
	float Position;
public:
	Spine(float P);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif /* SRC_COMMANDS_SPINE_H_ */
