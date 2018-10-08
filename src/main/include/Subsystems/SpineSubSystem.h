/*
 * Spine.h
 *
 *  Created on: Feb 15, 2018
 *      Author: Sayfullah
 */

#ifndef SRC_SUBSYSTEMS_SPINESUBSYSTEM_H_
#define SRC_SUBSYSTEMS_SPINESUBSYSTEM_H_

#include <Commands/Subsystem.h>
#include "WPILib.h"

class SpineSubSystem : public frc::Subsystem  {
private:
	//Spine Encoders
	std::shared_ptr<Encoder> spineEncoder1;
	std::shared_ptr<Encoder> spineEncoder2;

	//Spine Switches
	std::shared_ptr<DigitalInput> bottomShoulderSwitch;
	std::shared_ptr<DigitalInput> topShoulderSwitch;

	//Spine Motors
	std::shared_ptr<SpeedController> spineMotor1;
	std::shared_ptr<SpeedController> spineMotor2;

public:
	SpineSubSystem();
	void InitDefaultCommand();
	double AdjustSpine(bool isGoingUp);
	void AdjustSimple(bool down);
	void SetMotorSpeed(double lspeed, double rspeed);
	void SetMotor(double spine1, double spine2);
	int GetSpinePos1();
	int GetSpinePos2();
	void ResetSpine1();
	void ResetSpine2();
	void Reset();
	bool CanMoveSpine();
	bool CheckMove1();
	bool CheckMove2();
	void ResetSpineEncoder1();
	void ResetSpineEncoder2();
	double Motor1Current();
	double Motor2Current();
	void CheckReset();
	void Log();

};

#endif /* SRC_SUBSYSTEMS_SPINESUBSYSTEM_H_ */
