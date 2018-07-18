/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <Commands/Command.h>
#include <SmartDashboard/SendableChooser.h>
#include <Subsystems/FlapSubsystem.h>
#include <Subsystems/LEDSubsystem.h>
#include <TimedRobot.h>
#include <memory>

#include "OI.h"
#include "Subsystems/DriveSubsystem.h"
#include "Subsystems/WinchSubsystem.h"
#include "Subsystems/CubeSubsystem.h"
#include "Subsystems/GyroSubsystem.h"
#include "Subsystems/Pneumatics.h"
#include "Joystick.h"

using std::string;

class Robot : public frc::TimedRobot {
public:
	static DriveSubsystem driveSubsystem;
	static OI m_oi;
	static FlapSubsystem flaps;
	static LEDSubsystem led;
	static WinchSubsystem winchSubsystem;
	static CubeSubsystem cubeSubsystem;
	static GyroSubsystem gyroSubsystem;
	static Pneumatics pneumaticSubsystem;

	void RobotInit() override;
	void DisabledInit() override;
	void DisabledPeriodic() override;
	void AutonomousInit() override;
	void AutonomousPeriodic() override;
	void TeleopInit() override;
	void TeleopPeriodic() override;
	void TestPeriodic() override;

private:
	// Have it null by default so that if testing teleop it
	// doesn't have undefined behavior and potentially crash.
	frc::CommandGroup *m_autonomousCommand = nullptr;
	frc::SendableChooser<string> m_chooser;
};
