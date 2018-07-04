/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "TwoStickTank.h"
#include "../Robot.h"
#include <iostream>

TwoStickTank::TwoStickTank(Joystick *joystick) : joystick{joystick} {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	Requires(&Robot::driveSubsystem);
}

// Called just before this Command runs the first time
void TwoStickTank::Initialize() {

}

// Called repeatedly when this Command is scheduled to run
void TwoStickTank::Execute() {
	Robot::driveSubsystem.tank(joystick->GetThrottle(), joystick->GetY());
}

// Make this return true when this Command no longer needs to run execute()
bool TwoStickTank::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void TwoStickTank::End() {

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void TwoStickTank::Interrupted() {

}
