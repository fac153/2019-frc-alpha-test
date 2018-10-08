#include <Commands/SwitchCamera.h>

SwitchCamera::SwitchCamera() {
}

void SwitchCamera::Initialize(){
	Robot::drivetrain->IsSpine = false;
	SmartDashboard::PutString("Front of robot: ", "Ramp");
}
bool SwitchCamera::IsFinished(){
	return false;
}

void SwitchCamera::End(){
	Robot::drivetrain->IsSpine = true;
	SmartDashboard::PutString("Front of the Robot: ", "Cube");
}

void SwitchCamera::Interrupted(){
	End();
}
