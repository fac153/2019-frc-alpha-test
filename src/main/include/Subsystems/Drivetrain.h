#ifndef SRC_SUBSYSTEMS_DRIVETRAIN_H_
#define SRC_SUBSYSTEMS_DRIVETRAIN_H_



#include "Commands/Subsystem.h"
#include "WPILib.h"

class Drivetrain : public frc::Subsystem {
private:
	std::shared_ptr<AnalogGyro> gyro;
	std::shared_ptr<Encoder> leftDriveEncoder;
	std::shared_ptr<Encoder> rightDriveEncoder;
	std::shared_ptr<DifferentialDrive> differentialDrive;

public:

	bool IsSpine;

	std::shared_ptr<SpeedControllerGroup> leftDrive;
	std::shared_ptr<SpeedControllerGroup> rightDrive;
	std::shared_ptr<SpeedController> frontLeftDrive;
	std::shared_ptr<SpeedController> backLeftDrive;
	std::shared_ptr<SpeedController> frontRightDrive;
	std::shared_ptr<SpeedController> backRightDrive;

	Drivetrain();
	void InitDefaultCommand();
	void ArcadeDrive(double, double);
	float GetLeftDistance();
	float GetRightDistance();
	float GetLeftCount();
	float GetRightCount();
	void Debug();
	void TankDrive(double leftSpeed, double rightSpeed);
	void Reset();
	void ResetEncoder();
	void Stop();
};

#endif // Drivetrain_H
