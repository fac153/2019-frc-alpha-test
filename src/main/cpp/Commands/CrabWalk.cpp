#include "Commands/CrabWalk.h"

CrabWalk::CrabWalk(bool isLeft):
	isLeftWalk(isLeft)
{
	Requires(Robot::drivetrain.get());
}

// Called just before this Command runs the first time
void CrabWalk::Initialize() {
	Robot::drivetrain->ResetEncoder();
	if (isLeftWalk){
			Robot::drivetrain->TankDrive(0,0.5);
			} else {
			Robot::drivetrain->TankDrive(0.5,0);
	}
}

// Called repeatedly when this Command is scheduled to run
void CrabWalk::Execute() {
	Robot::drivetrain->Debug();

}

// Make this return true when this Command no longer needs to run execute()
bool CrabWalk::IsFinished() {
	float target;
		if (isLeftWalk) {
			target = Robot::drivetrain->GetLeftCount();
		} else {
			target = Robot::drivetrain->GetRightCount();
		}
		float placeholder = 143;
		return (abs(target) >= abs(placeholder));
}

// Called once after isFinished returns true
void CrabWalk::End() {
	SetTimeout(0.5);
	while(!IsTimedOut()) {
			if (isLeftWalk) {
				Robot::drivetrain->ArcadeDrive(0, -0.4);
			} else {
				Robot::drivetrain->ArcadeDrive(-0.4, 0);
			}
		}
	Robot::drivetrain->Stop();
	Robot::drivetrain->TankDrive(0,0);
	Robot::drivetrain->ResetEncoder();

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void CrabWalk::Interrupted() {
	End();
}
