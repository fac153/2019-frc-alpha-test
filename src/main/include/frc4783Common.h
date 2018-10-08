/*
 * frc4783Common.h
 *
 */

#ifndef SRC_FRC4783COMMON_H_
#define SRC_FRC4783COMMON_H_

namespace frc4783 {

enum class RobotType {
    Protocase,       ///< protocase test environment
    Steamworks,      ///< steamworks competition robot
    Powerup,         ///< power-up competition robot
    Powerup_Proto,   ///< power-up practice robot
    Practice         ///< practice robot
};

enum class ControllerTypes {
    Primary,    ///< primary controller
    Secondary,  ///< secondary controller
    Max,        ///< maximum number of controllers supported
};

enum class ControlType {
    ControlTypeMin = 0,
    LeftStick = ControlTypeMin,  ///< left joystick
    LeftStickButton,             ///< left joystick is pressed/released
    RightStick,                  ///< right joystick
    RightStickButton,            ///< right joystick is pressed/released
    LeftBumper1,                 ///< left bumper, top
    LeftBumper2,                 ///< left bumper, bottom
    RightBumper1,                ///< right bumper, top
    RightBumper2,                ///< right bumper, bottom
    ButtonLeft,                  ///< left button in cluster
    X_xbox = ButtonLeft,         ///< X (Xbox)
    Square = ButtonLeft,         ///< Square (PS4)
    ButtonTop,                   ///< top button in cluster
    Y = ButtonTop,               ///< Y (Xbox)
    Triangle = ButtonTop,        ///< Triangle (PS4)
    ButtonRight,                 ///< right button in cluster
    B = ButtonRight,             ///< B (Xbox)
    Circle = ButtonRight,        ///< Circle (PS4)
    ButtonBottom,                ///< bottom button in cluster
    A  = ButtonBottom,           ///< A (Xbox)
    X_ps4 = ButtonBottom,        ///< X (PS4)
    Home,                        ///< home button
    Other1,                      ///< other button on left side of controller
    Other2,                      ///< other button on right side of controller
    Touchpad,                    ///< touchpad
    ControlTypeMax
};

/**
 *  @enum  enumerates actions available for each JoystickButton
 *
 *  Identifies the action that are associated with a JoystickButton
 *  An frc::Command can be assigned to each one of these actions
 */

enum class ActionType {
    ActionTypeMin = 0,
    WhenPressed = ActionTypeMin,  ///< frc::Button::WhenPressed
    WhileHeld,                    ///< frc::Button::WhileHeld
    WhenReleased,                 ///< frc::Button::WhenReleased
    CancelWhenPressed,            ///< frc::Button:CancelWhenPressed
    ToggleWhenPressed,            ///< frc::Button::ToggleWhenPressed
    ActionTypeMax
};

} /* ns 4783 */

#endif /* SRC_FRC4783COMMON_H_ */
