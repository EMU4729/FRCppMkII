/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "CubeSubsystem.h"
#include "../RobotMap.h"

CubeSubsystem::CubeSubsystem() : Subsystem("CubeSubsystem"), cubeMotorLeft{cubeMotorLeftPort}, cubeMotorRight{cubeMotorRightPort} {
	speed = 0.4;
}

void CubeSubsystem::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	// SetDefaultCommand(new MySpecialCommand());
}

// Put methods for controlling this subsystem
// here. Call these from Commands.

void CubeSubsystem::intake() {
	cubeMotorLeft.SetSpeed(speed);
	cubeMotorRight.SetSpeed(speed);
}

void CubeSubsystem::outtake() {
	cubeMotorLeft.SetSpeed(-speed);
	cubeMotorRight.SetSpeed(-speed);
}

void CubeSubsystem::stop() {
	cubeMotorLeft.SetSpeed(0);
	cubeMotorRight.SetSpeed(0);
}
