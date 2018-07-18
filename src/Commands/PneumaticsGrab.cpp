/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "PneumaticsGrab.h"
#include "../Robot.h"

PneumaticsGrab::PneumaticsGrab() {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	Requires(&Robot::pneumaticSubsystem);
}

// Called just before this Command runs the first time
void PneumaticsGrab::Initialize() {

}

// Called repeatedly when this Command is scheduled to run
void PneumaticsGrab::Execute() {
	Robot::pneumaticSubsystem.Grab();

}

// Make this return true when this Command no longer needs to run execute()
bool PneumaticsGrab::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void PneumaticsGrab::End() {
	Robot::pneumaticSubsystem.Off();

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void PneumaticsGrab::Interrupted() {
	Robot::pneumaticSubsystem.Off();
}
