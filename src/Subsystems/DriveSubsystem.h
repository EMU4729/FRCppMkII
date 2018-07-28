/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <Commands/Subsystem.h>
#include <ctre/Phoenix.h>
#include <Encoder.h>

using ctre::phoenix::motorcontrol::can::WPI_TalonSRX;
using frc::Encoder;

class DriveSubsystem : public frc::Subsystem {
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
	WPI_TalonSRX leftFrontDrive;
	WPI_TalonSRX rightFrontDrive;
	WPI_TalonSRX leftBackDrive;
	WPI_TalonSRX rightBackDrive;

	double speed;

	double circumferenceOfWheels;
	double pulsesPerRevolution;
	double encoderMultiplier; //alex and luke cannot decide name


	Encoder leftEncoder;
	Encoder rightEncoder;

public:
	DriveSubsystem();
	void InitDefaultCommand() override;
	void arcade(double forwards, double turn);
	void tank(double left, double right);
	void power(double left, double right);
	double getLeftEncoder();
	double getRightEncoder();
	void highSpeed();
	void lowSpeed();
	void resetEncoders();
};

