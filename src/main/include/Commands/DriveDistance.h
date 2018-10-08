#ifndef DriveDistance_H
#define DriveDistance_H

#include "WPILib.h"
#include "../Robot.h"
#include "../RobotMap.h"

class DriveDistance : public Command {
private:
	float targetDistance;
	double timeDistance;
public:
	DriveDistance(double time);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // DriveDistance_H
