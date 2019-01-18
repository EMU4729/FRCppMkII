/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include <cmath>
#include "MoveForwards.h"
#include "../../Robot.h"

MoveForwards::MoveForwards(double d) : distance{d} {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	Requires(&Robot::driveSubsystem);

	double distanceTravelled = abs(Robot::driveSubsystem.getLeftEncoder()+Robot::driveSubsystem.getRightEncoder())/2;
	speed = 0;
}

// Called just before this Command runs the first time
void MoveForwards::Initialize() {
	Robot::driveSubsystem.resetEncoders();
}

// Called repeatedly when this Command is scheduled to run
void MoveForwards::Execute() {
	double distanceTravelled = abs(Robot::driveSubsystem.getLeftEncoder()+Robot::driveSubsystem.getRightEncoder())/2;
	speed = fmax(0.4, (distance-distanceTravelled)/distance);
	Robot::driveSubsystem.arcade(speed, 0);
}


// Make this return true when this Command no longer needs to run execute()
bool MoveForwards::IsFinished() {
	if (abs(Robot::driveSubsystem.getLeftEncoder() + Robot::driveSubsystem.getRightEncoder())/2 >= distance) {
		return true;
	} else {
		return false;
	}
}

// Called once after isFinished returns true
void MoveForwards::End() {
	Robot::driveSubsystem.arcade(0, 0);
	Robot::driveSubsystem.resetEncoders();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void MoveForwards::Interrupted() {
	End();
}
