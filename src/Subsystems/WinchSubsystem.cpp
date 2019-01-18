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
	upSpeed = 0.9;
	highPower = false;
}

void WinchSubsystem::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	// SetDefaultCommand(new MySpecialCommand());
}

void WinchSubsystem::up() {
	winch1.Set(-upSpeed);
	winch2.Set(-upSpeed);
}

void WinchSubsystem::down() {
	if (highPower) {
		winch1.Set(carrySpeed);
		winch2.Set(carrySpeed);
	} else {
		winch1.Set(normalSpeed);
		winch2.Set(normalSpeed);
	}
}

void WinchSubsystem::stop() {
	winch1.Set(0);
	winch2.Set(0);
}

void WinchSubsystem::move(double power) {
	winch1.Set(power);
	winch2.Set(power);
}

// Put methods for controlling this subsystem
// here. Call these from Commands.
