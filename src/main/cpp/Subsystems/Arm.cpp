#include <Commands/ArmSwingDPAD.h>
#include "Subsystems/Arm.h"
#include "RobotMap.h"

#include "Robot.h"

#include <algorithm>


#include "Subsystems/Drivetrain.h"
#include "ctre/phoenix/MotorControl/CAN/WPI_TalonSRX.h"
#include "SmartDashboard/Sendable.h"
#include "WPILib.h"
#include "Commands/CloseClaw.h"


Arm::Arm() : Subsystem("Arm") {
	armEncoder = RobotMap::armEncoder;
	spineEncoder1 = RobotMap::spineEncoder1;
	spineEncoder2 = RobotMap::spineEncoder2;
	bottomShoulderSwitch = RobotMap::bottomShoulderSwitch;
	topShoulderSwitch = RobotMap::topShoulderSwitch;

	armMotor1 = RobotMap::armMotor1;
	armMotor2 = RobotMap::armMotor2;
	clawMotor = RobotMap::clawMotor;
	spineMotor1 = RobotMap::spineMotor1;
	spineMotor2 = RobotMap::spineMotor2;


	IsClawClosed = false;

}

void Arm::InitDefaultCommand() {

	// Set the default command for a subsystem here.

	// SetDefaultCommand(new MySpecialCommand());
	SetDefaultCommand(new ArmSwingDPAD());
}

void Arm::SetArmSpeed(float speed){
	armMotor1->Set(speed);
	armMotor2->Set(speed);
}

void Arm::SetClawSpeed(float speed) {
	clawMotor->Set(speed);
}

float Arm::GetArmPosition(){
	return armEncoder->GetDistance();
}

void Arm::ResetArm(){
	if (bottomShoulderSwitch->Get()){
		armMotor1->Set(0);
		armMotor2->Set(0);
		ResetArmEncoder();
	}
}

bool Arm::CanMoveSpine(){
	if(Robot::arm->GetArmPosition() > -5 && Robot::arm->GetArmPosition() < 10){
		return true;
	}else if (Robot::arm->GetArmPosition() > 170 && Robot::arm->GetArmPosition() < 190){
		return true;
	}else return false;
}

void Arm::Reset(){
	ResetArmEncoder();
	armMotor1->Set(0);
	armMotor2->Set(0);
	clawMotor->Set(0);
	spineMotor1->Set(0);
	spineMotor2->Set(0);
	Log();
}

void Arm::ResetArmEncoder(){
	armEncoder->Reset();
}

void Arm::Log(){
	SmartDashboard::PutNumber("Arm Encoder:", GetArmPosition());
}

void Arm::OpenClawMotor(){
	clawMotor->Set(0.8);
}
void Arm::CloseClawMotor(){
	clawMotor->Set(-0.8);
}
void Arm::StopClaw(){
	clawMotor->Set(0);
}

double Arm::CurrentDraw(){
	double current = std::dynamic_pointer_cast<ctre::phoenix::motorcontrol::can::WPI_TalonSRX>(clawMotor)->GetOutputCurrent();
	SmartDashboard::PutNumber("Talon SRX - current: ", current);
	return (current);
}
