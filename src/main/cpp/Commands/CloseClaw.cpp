#include "Commands/CloseClaw.h"
#include "Robot.h"
#include "RobotMap.h"
#include "Subsystems/Arm.h"

CloseClaw::CloseClaw() {
	// Use Requires() here to declare subsystem dependencies
	Requires(Robot::arm.get());
	maxcurrent = 15.0;
	// eg. Requires(Robot::chassis.get());
}

// Called just before this Command runs the first time
void CloseClaw::Initialize() {
	Robot::arm->CloseClawMotor();
	SetTimeout(3);
}

// Called repeatedly when this Command is scheduled to run
void CloseClaw::Execute() {
	SmartDashboard::PutString("Claw: ", "Closing");
	SmartDashboard::PutBoolean("Is Claw Closed", Robot::arm->IsClawClosed);
	SmartDashboard::PutNumber("CloseClaw-current", Robot::arm->CurrentDraw());
	SmartDashboard::PutNumber("CloseClaw-maxcurrent", maxcurrent);
}

// Make this return true when this Command no longer needs to run execute()
bool CloseClaw::IsFinished() {
	return  (abs(Robot::arm->CurrentDraw()) > abs(maxcurrent)) or IsTimedOut();
}

// Called once after isFinished returns true
void CloseClaw::End() {
	Robot::arm->IsClawClosed = true;
	Robot::arm->StopClaw();
	SmartDashboard::PutBoolean("Is Claw Closed", Robot::arm->IsClawClosed);
	SmartDashboard::PutNumber("CloseClaw-current", Robot::arm->CurrentDraw());
	SmartDashboard::PutNumber("CloseClaw-maxcurrent", maxcurrent);

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void CloseClaw::Interrupted() {
End();
}
