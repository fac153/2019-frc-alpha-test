#include "Robot.h"

std::shared_ptr<Arm> Robot::arm;
std::shared_ptr<Drivetrain> Robot::drivetrain;
std::unique_ptr<OI> Robot::oi;
std::shared_ptr<SpineSubSystem> Robot::spine;

cs::UsbCamera invertableCubeCamera;
cs::UsbCamera backCamera;
cs::VideoSink server;
cs::CvSink invertableCubeCvSink;
cs::CvSink backCvSink;

void Robot::VisionThread(){
	invertableCubeCamera = CameraServer::GetInstance()->StartAutomaticCapture(0);
	invertableCubeCamera.SetResolution(160, 120);

	backCamera = CameraServer::GetInstance()->StartAutomaticCapture(1);
	backCamera.SetResolution(160, 120);

	server = CameraServer::GetInstance()->GetServer();

	//Making sure Cameras don't disconnect
	invertableCubeCvSink.SetSource(invertableCubeCamera);
	invertableCubeCvSink.SetEnabled(true);

	backCvSink.SetSource(backCamera);
	backCvSink.SetEnabled(true);
}
void Robot::RobotInit() {
	//running Vision Thread separately
	std::thread visionThread(VisionThread);
	visionThread.detach();

	RobotMap::init();

	arm.reset(new Arm());
	drivetrain.reset(new Drivetrain());
	spine.reset(new SpineSubSystem());

	oi.reset(new OI());

	// Select autonomous mode
	chooser.AddObject("Centre Auto Mode", new CentreAutoMode()); // Default autonomous mode
	chooser.AddDefault("Cross Line", new LeftAutoMode());
	frc::SmartDashboard::PutData("Auto Modes", &chooser);
}

void Robot::DisabledInit() {
	RobotMap::reset();
}

void Robot::DisabledPeriodic() {
	frc::Scheduler::GetInstance()->Run();
}

void Robot::AutonomousInit() {
	autonomousCommand = chooser.GetSelected();
	if (autonomousCommand != nullptr)
		autonomousCommand->Start();
}

void Robot::AutonomousPeriodic() {
	frc::Scheduler::GetInstance()->Run();

}

void Robot::TeleopInit() {
	if (autonomousCommand != nullptr)
		autonomousCommand->Cancel();
}

void Robot::TeleopPeriodic() {
	frc::Scheduler::GetInstance()->Run();
	if(Robot::drivetrain->IsSpine){
		server.SetSource(invertableCubeCamera);
	} else {
		server.SetSource(backCamera);
	}

}

START_ROBOT_CLASS(Robot);
