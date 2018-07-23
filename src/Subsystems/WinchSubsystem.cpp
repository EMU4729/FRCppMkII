/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "WinchSubsystem.h"
#include "../RobotMap.h"

WinchSubsystem::WinchSubsystem() : Subsystem("WinchSubsystem"),
									winch1{winch1Port},
									winch2{winch2Port} {

	normalSpeed = 0.7;
	carrySpeed = 1;
	upSpeed = 0.5;
	highPower = false;
}

void WinchSubsystem::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	// SetDefaultCommand(new MySpecialCommand());
}

void WinchSubsystem::up() {
	winch1.SetSpeed(-upSpeed);
	winch2.SetSpeed(-upSpeed);
}

void WinchSubsystem::down() {
	if (highPower) {
		winch1.SetSpeed(carrySpeed);
		winch2.SetSpeed(carrySpeed);
	} else {
		winch1.SetSpeed(normalSpeed);
		winch2.SetSpeed(normalSpeed);
	}
}

void WinchSubsystem::stop() {
	winch1.SetSpeed(0);
	winch2.SetSpeed(0);
}

// Put methods for controlling this subsystem
// here. Call these from Commands.
