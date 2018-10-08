#include "Commands/DriveDistance.h"
#include "Robot.h"
const float kP = 0.025;

DriveDistance::DriveDistance(double time)
{
	targetDistance = 0;
	timeDistance = time;
	Requires(Robot::drivetrain.get());// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
}

// Called just before this Command runs the first time
void DriveDistance::Initialize() {
	Robot::drivetrain->Reset();
	SetTimeout(timeDistance);
}

// Called repeatedly when this Command is scheduled to run
void DriveDistance::Execute() {
	SmartDashboard::PutNumber("Left Distance travelled", Robot::drivetrain->GetLeftDistance());
	SmartDashboard::PutNumber("Right Distance travelled", Robot::drivetrain->GetRightDistance());
	SmartDashboard::PutNumber("target distance", targetDistance);
	Robot::drivetrain->ArcadeDrive(-0.65, 0.05);
}

// Make this return true when this Command no longer needs to run execute()
bool DriveDistance::IsFinished() {
	return  IsTimedOut();
}

// Called once after isFinished returns true
void DriveDistance::End() {
	Robot::drivetrain->Stop();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void DriveDistance::Interrupted() {
	End();
}
