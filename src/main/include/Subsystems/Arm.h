#ifndef Arm_H
#define Arm_H

#include <Commands/Subsystem.h>
#include "WPILib.h"

class Arm : public frc::Subsystem {
private:
	std::shared_ptr<Encoder> armEncoder;
	std::shared_ptr<Encoder> spineEncoder1;
	std::shared_ptr<Encoder> spineEncoder2;
	std::shared_ptr<DigitalInput> bottomShoulderSwitch;
	std::shared_ptr<DigitalInput> topShoulderSwitch;

	std::shared_ptr<SpeedController> armMotor1;
	std::shared_ptr<SpeedController> armMotor2;
	std::shared_ptr<SpeedController> clawMotor;
	std::shared_ptr<SpeedController> spineMotor1;
	std::shared_ptr<SpeedController> spineMotor2;



public:
	Arm();
	void InitDefaultCommand();
	void SetArmSpeed(float speed);
	void CheckEncoders();
	void SetClawSpeed(float speed);
	float GetArmPosition();
	float GetCurrentArmPosition();
	void ResetArm();
	void Reset();
	bool CanMoveSpine();
	void ResetArmEncoder();
	void Log();

	void OpenClawMotor();
	void CloseClawMotor();
	void StopClaw();
	bool LimitSwitchState();
	double CurrentDraw();

	bool IsClawClosed;

};

#endif  // Arm_H
