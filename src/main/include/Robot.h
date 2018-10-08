/*
 * Robot.h
 *
 *  Created on: Jan 13, 2018
 *      Author: Madeline
 */

#ifndef _ROBOT_H_
#define _ROBOT_H_

#include "WPILib.h"
#include "Commands/Command.h"
//#include "LiveWindow/LiveWindow.h"
#include "RobotMap.h"
// Vision includes
#include <thread>
#include <CameraServer.h>

// Autonomous mode includes
#include <Commands/AutoModes/CentreAutoMode.h>
#include <Commands/AutoModes/LeftAutoMode.h>
#include <Commands/AutoModes/RightAutoMode.h>

// Subsystem includes
#include "Subsystems/Arm.h"
#include "Subsystems/Drivetrain.h"
#include "OI.h"
#include "Subsystems/SpineSubSystem.h"

class Robot : public frc::TimedRobot {
	public:
	frc::Command* autonomousCommand = nullptr;
	static std::unique_ptr<OI> oi;
	//frc::LiveWindow *lw = frc::LiveWindow::GetInstance();
	frc::SendableChooser<frc::Command*> chooser;
	static std::shared_ptr<Arm> arm;
	static std::shared_ptr<Drivetrain> drivetrain;
	static std::shared_ptr<SpineSubSystem> spine;

	static void VisionThread();
	void RobotInit() override;
	void DisabledInit() override;
	void DisabledPeriodic() override;
	void AutonomousInit() override;
	void AutonomousPeriodic() override;
	void TeleopInit() override;
	void TeleopPeriodic() override;
};
#endif
