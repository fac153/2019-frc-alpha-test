#ifndef OpenClaw_H
#define OpenClaw_H


#include "../RobotMap.h"
#include "../Robot.h"
#include "WPILib.h"

class OpenClaw : public Command {
private:
	double maxcurrent;
public:
	OpenClaw();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // OpenClaw_H
