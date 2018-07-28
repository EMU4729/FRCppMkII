/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <Commands/Subsystem.h>
#include <ctre/Phoenix.h>

using ctre::phoenix::motorcontrol::can::WPI_TalonSRX;

class WinchSubsystem : public frc::Subsystem {
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
	WPI_TalonSRX winch1;
	WPI_TalonSRX winch2;

	double normalSpeed;
	double carrySpeed;
	double upSpeed;
public:
	WinchSubsystem();
	void InitDefaultCommand() override;
	void up();
	void down();
	void stop();
	void move(double power);
	bool highPower;
};

