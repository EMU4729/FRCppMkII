/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include <cmath>
#include "MoveRam.h"
#include "../../Robot.h"

MoveRam::MoveRam(double d) : distance{d/2} { // TODO: Why is distance d/2
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	Requires(&Robot::driveSubsystem);
}

// Called just before this Command runs the first time
void MoveRam::Initialize() {
	Robot::driveSubsystem.resetEncoders();
}

// Called repeatedly when this Command is scheduled to run
void MoveRam::Execute() {
	Robot::driveSubsystem.arcade(1, 0);
}

// Make this return true when this Command no longer needs to run execute()
bool MoveRam::IsFinished() {
	if (abs(Robot::driveSubsystem.getLeftEncoder() + Robot::driveSubsystem.getRightEncoder())/2 >= distance) {
		return true;
	} else {
		return false;
	}
}

// Called once after isFinished returns true
void MoveRam::End() {
	Robot::driveSubsystem.resetEncoders();
	Robot::driveSubsystem.arcade(0, 0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void MoveRam::Interrupted() {
	End();
}
