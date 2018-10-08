/*
 * ArmSwing.cpp
 *
 *  Created on: Feb 10, 2018
 *      Author: Sayfullah
 */

#include <Commands/ArmSwingDPAD.h>


ArmSwingDPAD::ArmSwingDPAD() {
	Requires(Robot::arm.get());
}

void ArmSwingDPAD::Initialize(){
	SmartDashboard::PutString("Arm", "Start");
	Robot::arm->SetArmSpeed(0);
}

void ArmSwingDPAD::Execute(){
	SmartDashboard::PutNumber("Arm Encoder", Robot::arm->GetArmPosition());
	if (Robot::oi->driveStick->GetPOV(0) == 90){//ArmSwing up
		Robot::arm->SetArmSpeed(0.6);
		SmartDashboard::PutString("Arm", "Moving");
	}
	else if(Robot::oi->driveStick->GetPOV(0) == -1){
		float currentArmPosition = Robot::arm->GetArmPosition();
		float speed = 0.0;
		Robot::arm->SetArmSpeed(speed);
		if (currentArmPosition == Robot::arm->GetArmPosition()){
			Robot::arm->SetArmSpeed(0);
		}
		else if (currentArmPosition > Robot::arm->GetArmPosition()){
			Robot::arm->SetArmSpeed(0.1);
		}
		SmartDashboard::PutString("Arm", "Stopped");
	}
	else if(Robot::oi->driveStick->GetPOV(0) == 270){//ArmSwing Down
		Robot::arm->SetArmSpeed(-0.1);
		SmartDashboard::PutString("Arm", "Moving");
	}
}

bool ArmSwingDPAD::IsFinished(){
	return false;
}

void ArmSwingDPAD::End(){
	Robot::arm->SetArmSpeed(0);
	SmartDashboard::PutString("Arm","Finished");
}

void ArmSwingDPAD::Interrupted(){
	End();
}
