#include "Commands/DriveWithJoystick.h"

DriveWithJoystick::DriveWithJoystick() {
	Requires(Robot::drivetrain.get());// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
}

// Called just before this Command runs the first time
void DriveWithJoystick::Initialize() {

}

// Called repeatedly when this Command is scheduled to run
void DriveWithJoystick::Execute() {
	float direction = -1;

	if (Robot::drivetrain->IsSpine == true){
		direction = 1;
	}

	float speed = direction * (-Robot::oi->driveStick->GetRawAxis(OI::LEFT_Y_AXIS));
	float turn = (-0.75 * Robot::oi->driveStick->GetRawAxis(OI::RIGHT_X_AXIS));

	//Reduce the base speed while the left bumper is held
	if (Robot::oi->driveStick->GetRawButton(6)) {
		speed = 0.65 * speed;
	}

	if (Robot::oi->driveStick->GetRawButton(6)) {
		turn = 0.8 * turn;
	}

	Robot::drivetrain->ArcadeDrive(speed, turn);
	if (speed > 0.6){
		speed = 0.6;
	}
}


// Make this return true when this Command no longer needs to run execute()
bool DriveWithJoystick::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void DriveWithJoystick::End() {
     Robot::drivetrain->Stop();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void DriveWithJoystick::Interrupted() {
	End();
}
