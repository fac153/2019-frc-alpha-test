/*
 * SwitchCamera.h
 *
 *  Created on: Feb 7, 2018
 *      Author: Isaiah
 */

#ifndef SRC_COMMANDS_SWITCHCAMERA_H_
#define SRC_COMMANDS_SWITCHCAMERA_H_
#include "../Robot.h"
#include "../RobotMap.h"
#include "WPILib.h"

class SwitchCamera :public Command {
public:
	SwitchCamera();
	void Initialize();
	bool IsFinished();
	void End();
	void Interrupted();
};




#endif /* SRC_COMMANDS_SWITCHCAMERA_H_ */
