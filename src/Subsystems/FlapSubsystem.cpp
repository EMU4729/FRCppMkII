/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include <Subsystems/FlapSubsystem.h>
#include "../RobotMap.h"

FlapSubsystem::FlapSubsystem() : Subsystem("FlapsSubsystem"), flapMotor{flapMotorPort} {
	speed = 0.45;
}

void FlapSubsystem::turn() {
	flapMotor.SetSpeed(speed);
}

void FlapSubsystem::stop() {
	flapMotor.SetSpeed(0);
}

void FlapSubsystem::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	// SetDefaultCommand(new MySpecialCommand());
}

// Put methods for controlling this subsystem
// here. Call these from Commands.
