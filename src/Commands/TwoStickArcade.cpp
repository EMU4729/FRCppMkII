/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "TwoStickArcade.h"
#include "../Robot.h"
#include <iostream>

TwoStickArcade::TwoStickArcade(Joystick *joystick1, Joystick *joystick2) : joystick1{joystick1}, joystick2{joystick2} {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	Requires(&Robot::driveSubsystem);
}

// Called just before this Command runs the first time
void TwoStickArcade::Initialize() {

}

// Called repeatedly when this Command is scheduled to run
void TwoStickArcade::Execute() {
	Robot::driveSubsystem.arcade(joystick1->GetY(), joystick2->GetX());

	//Robot::ledSubsystem.arcade(fmin(abs(joystick->GetY()) + abs(joystick->GetTwist()), 1));
}

// Make this return true when this Command no longer needs to run execute()
bool TwoStickArcade::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void TwoStickArcade::End() {

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void TwoStickArcade::Interrupted() {
	printf("talon 4 interrupted\n");
}
