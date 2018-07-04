/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <Commands/Command.h>
#include <SmartDashboard/SendableChooser.h>
#include <TimedRobot.h>
#include <memory>

#include "Commands/ExampleCommand.h"
#include "OI.h"
#include "Subsystems/ExampleSubsystem.h"
#include "Subsystems/DriveSubsystem.h"
#include "Subsystems/Flaps.h"
#include "Subsystems/LED.h"
#include "Subsystems/WinchSubsystem.h"
#include "Subsystems/CubeSubsystem.h"
#include "Subsystems/GyroSubsystem.h"
#include "Joystick.h"

using std::string;

class Robot : public frc::TimedRobot {
public:
	static ExampleSubsystem m_subsystem;
	static DriveSubsystem driveSubsystem;
	static OI m_oi;
	static Flaps flaps;
	static LED led;
	static WinchSubsystem winchSubsystem;
	static CubeSubsystem cubeSubsystem;
	static GyroSubsystem gyroSubsystem;

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
	ExampleCommand m_defaultAuto;
	frc::SendableChooser<string> m_chooser;
};
