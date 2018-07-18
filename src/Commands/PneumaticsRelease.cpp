/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "PneumaticsRelease.h"
#include "../Robot.h"

PneumaticsRelease::PneumaticsRelease() {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	Requires(&Robot::pneumaticSubsystem);
}

// Called just before this Command runs the first time
void PneumaticsRelease::Initialize() {

}

// Called repeatedly when this Command is scheduled to run
void PneumaticsRelease::Execute() {
	Robot::pneumaticSubsystem.Release();

}

// Make this return true when this Command no longer needs to run execute()
bool PneumaticsRelease::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void PneumaticsRelease::End() {
	Robot::pneumaticSubsystem.Off();

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void PneumaticsRelease::Interrupted() {
	Robot::pneumaticSubsystem.Off();
}
