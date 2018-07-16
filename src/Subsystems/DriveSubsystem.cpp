/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include <cmath>
#include <iostream>
#include "DriveSubsystem.h"
#include "../RobotMap.h"

DriveSubsystem::DriveSubsystem() : Subsystem("DriveSubsystem"),
									leftFrontDrive{leftFrontPort},
									rightFrontDrive{rightFrontPort},
									leftBackDrive{leftBackPort},
									rightBackDrive{rightBackPort},
									leftEncoder{leftEncoderA, leftEncoderB, true},
									rightEncoder{rightEncoderA, rightEncoderB, true} {

	speed = 0.75;

	circumferenceOfWheels = 0.1016;
	pulsesPerRevolution = 2048;
	encoderMultiplier = 0.9650/3.8155;

	leftEncoder.SetMaxPeriod(0.1);
	leftEncoder.SetMinRate(10);
	leftEncoder.SetDistancePerPulse(M_PI * circumferenceOfWheels/pulsesPerRevolution);
	leftEncoder.SetSamplesToAverage(7);

	rightEncoder.SetMaxPeriod(0.1);
	rightEncoder.SetMinRate(10);
	rightEncoder.SetDistancePerPulse(M_PI * circumferenceOfWheels/pulsesPerRevolution);
	rightEncoder.SetSamplesToAverage(7);

}

void DriveSubsystem::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	// SetDefaultCommand(new MySpecialCommand());
}

void DriveSubsystem::arcade(double forwards, double turn) {
	power(forwards-turn,
		  forwards+turn);
}

void DriveSubsystem::tank(double left, double right) {
	power(left,
		  right);
}

void DriveSubsystem::power(double left, double right) {
//	std::cout << left << ", " << right << std::endl;
	leftFrontDrive.SetSpeed(-left*speed);
	rightFrontDrive.SetSpeed(right*speed);
	leftBackDrive.SetSpeed(-left*speed);
	rightBackDrive.SetSpeed(right*speed);
}

double DriveSubsystem::getLeftEncoder() {
	return leftEncoder.GetDistance();//*encoderMultiplier;
}

double DriveSubsystem::getRightEncoder() {
	return rightEncoder.GetDistance();//*encoderMultiplier;
}

void DriveSubsystem::highSpeed() {
	speed = 0.75;
}

void DriveSubsystem::lowSpeed() {
	speed = 0.5;
}

void DriveSubsystem::resetEncoders() {
	leftEncoder.Reset();
	rightEncoder.Reset();
}

// Put methods for controlling this subsystem
// here. Call these from Commands.
