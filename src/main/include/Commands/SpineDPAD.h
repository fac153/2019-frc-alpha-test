#ifndef SpineUp_H
#define SpineUp_H

#include "WPILib.h"
#include "Robot.h"
#include "RobotMap.h"

class SpineDPAD : public Command {
public:
	SpineDPAD();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // SpineUp_H
