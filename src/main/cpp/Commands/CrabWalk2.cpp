#include "Commands/CrabWalk2.h"

CrabWalk2::CrabWalk2(bool isLeft):
	isLeftWalk(isLeft)
{
	Requires(Robot::drivetrain.get());
}

// Called just before this Command runs the first time
void CrabWalk2::Initialize() {

	if (isLeftWalk){
		Robot::drivetrain->TankDrive(0.5,0);
		} else {
		Robot::drivetrain->TankDrive(0,0.5);
	}
}

// Called repeatedly when this Command is scheduled to run
void CrabWalk2::Execute() {
	Robot::drivetrain->Debug();
}

// Make this return true when this Command no longer needs to run execute()
bool CrabWalk2::IsFinished() {
	float target;
	if (isLeftWalk) {
		target = Robot::drivetrain->GetRightCount();
	} else {
		target = Robot::drivetrain->GetLeftCount();
	}
	float placeholder = 143;
	return (abs(target) <= abs(placeholder));
}

// Called once after isFinished returns true
void CrabWalk2::End() {
	SetTimeout(0.5);
	while(!IsTimedOut()) {
			if (isLeftWalk) {
				Robot::drivetrain->ArcadeDrive(-0.4, 0);
			} else {
				Robot::drivetrain->ArcadeDrive(0, -0.4);
			}
		}
	Robot::drivetrain->Stop();
	Robot::drivetrain->ResetEncoder();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void CrabWalk2::Interrupted() {
	End();
}
