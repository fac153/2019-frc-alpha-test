#include "Commands/Turn90Degrees.h"

Turn90Degrees::Turn90Degrees(bool isLeft):
	isLeftTurn(isLeft)

{

Requires(Robot::drivetrain.get());
	Requires(Robot::drivetrain.get());
}

// Called just before this Command runs the first time
void Turn90Degrees::Initialize() {
	Robot::drivetrain->ResetEncoder();
	if(isLeftTurn) {
	Robot::drivetrain->TankDrive(-1,1);
	} else {
	Robot::drivetrain->TankDrive(1,-1);
	}
}

// Called repeatedly when this Command is scheduled to run
void Turn90Degrees::Execute() {
	Robot::drivetrain->Debug();
}

// Make this return true when this Command no longer needs to run execute()
bool Turn90Degrees::IsFinished() {
	float target;
	if (isLeftTurn) {
		target = Robot::drivetrain->GetLeftCount();
	} else {
		target = Robot::drivetrain->GetRightCount();
	}
	float placeholder = 305;
	return (abs(target) >= abs(placeholder));
}

// Called once after isFinished returns true
void Turn90Degrees::End() {
	Robot::drivetrain->Stop();
	Robot::drivetrain->ResetEncoder();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void Turn90Degrees::Interrupted() {
	End();
}
