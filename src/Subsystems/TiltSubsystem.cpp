/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "TiltSubsystem.h"
#include "../RobotMap.h"

TiltSubsystem::TiltSubsystem() : Subsystem("TiltSubsystem"), tiltMotor{tiltMotorPort} {
	speed = 0.45;
}

void TiltSubsystem::up() {
	tiltMotor.SetSpeed(speed);
}

void TiltSubsystem::down() {
	tiltMotor.SetSpeed(-speed);
}

void TiltSubsystem::move(double power) {
	tiltMotor.SetSpeed(speed*power);
}

void TiltSubsystem::stop() {
	tiltMotor.SetSpeed(0);
}

void TiltSubsystem::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	// SetDefaultCommand(new MySpecialCommand());
}

// Put methods for controlling this subsystem
// here. Call these from Commands.
