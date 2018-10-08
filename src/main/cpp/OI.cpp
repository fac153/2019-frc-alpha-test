/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "OI.h"
#include <WPILib.h>
#include "Commands/Turn90Degrees.h"
#include "Commands/Turn180Degrees.h"
#include "Commands/CrabWalkGroup.h"
#include "Commands/CrabWalk.h"
#include "Commands/CrabWalk2.h"

#include "Commands/ClimbGroup.h"

#include "Commands/OpenClawGroup.h"
#include "Commands/CloseClawGroup.h"

#include "Commands/SwitchCamera.h"
OI::OI() {

	driveStick.reset(new Joystick(0));

	// Drive Stick Buttons
	aButtonD = new JoystickButton(driveStick.get(), 1);
	bButtonD = new JoystickButton(driveStick.get(), 2);
	xButtonD = new JoystickButton(driveStick.get(), 3);
	yButtonD = new JoystickButton(driveStick.get(), 4);
	leftBumperButtonD = new JoystickButton(driveStick.get(), 5);
	rightBumperButtonD = new JoystickButton(driveStick.get(), 6);
	selectButtonD = new JoystickButton(driveStick.get(), 7);
	startButtonD = new JoystickButton(driveStick.get(), 8);
	leftStickButtonD = new JoystickButton(driveStick.get(), 9);
	rightStickButtonD = new JoystickButton(driveStick.get(), 10);
	// Assigning Commands to Buttons

	//Drive Stick Controls
	bButtonD->ToggleWhenPressed(new Turn90Degrees(true));
	yButtonD->WhenPressed(new Turn180Degrees(true));
	xButtonD->ToggleWhenPressed(new Turn90Degrees(false));
	aButtonD->WhenPressed(new Turn180Degrees(false));
	leftStickButtonD->WhenPressed(new CrabWalkGroup(true));
	rightStickButtonD->WhenPressed(new CrabWalkGroup(false));

	//Camera Switch Controls
	selectButtonD->ToggleWhenPressed(new SwitchCamera());

	//Climb Controls
	startButtonD->WhenPressed(new ClimbGroup());

	//Claw Controls
	leftBumperButtonD->WhileHeld(new OpenClawGroup());
	leftBumperButtonD->WhenReleased(new CloseClawGroup());


}

std::shared_ptr<Joystick> OI::getDriveStick() {
	return driveStick;
}
