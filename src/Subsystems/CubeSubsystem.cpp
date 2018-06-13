/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "CubeSubsystem.h"
#include "../RobotMap.h"

CubeSubsystem::CubeSubsystem() : Subsystem("ExampleSubsystem"), cubeMotor{cubeMotorPort} {
	speed = 0.4;
}

void CubeSubsystem::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	// SetDefaultCommand(new MySpecialCommand());
}

// Put methods for controlling this subsystem
// here. Call these from Commands.

void CubeSubsystem::intake() {
	cubeMotor.SetSpeed(speed);
}

void CubeSubsystem::outtake() {
	cubeMotor.SetSpeed(-speed);
}

void CubeSubsystem::stop() {
	cubeMotor.SetSpeed(0);
}
