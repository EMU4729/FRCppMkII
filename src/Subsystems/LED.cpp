/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "LED.h"
#include "../RobotMap.h"

LED::LED() : Subsystem("ExampleSubsystem") {
	led = new CANLight(ledPort);
}

void LED::green() {
	led->ShowRGB(0, 255, 0);
}

void LED::stop() {
	led->ShowRGB(0, 0, 0);
}

void LED::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	// SetDefaultCommand(new MySpecialCommand());
}

// Put methods for controlling this subsystem
// here. Call these from Commands.
