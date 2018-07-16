/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "MoveTurn.h"
#include "../../Robot.h"

static int signum(double value);

MoveTurn::MoveTurn(double deg, Direction dir) : degrees{deg}, direction{dir} {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	Requires(&Robot::gyroSubsystem);
	Requires(&Robot::driveSubsystem);

	double distanceTurned = abs(degrees-Robot::gyroSubsystem.getGyroAngle());
	speed = 0;

	if (direction == Direction::Left) {
		degrees *= -1;
	}
}

// Called just before this Command runs the first time
void MoveTurn::Initialize() {
	Robot::gyroSubsystem.reset();
}

// Called repeatedly when this Command is scheduled to run
void MoveTurn::Execute() {
	double distanceTurned = abs(degrees-Robot::gyroSubsystem.getGyroAngle());
	speed = fmax(0.3, distanceTurned/degrees);
	Robot::driveSubsystem.arcade(0, speed*signum(degrees));
}

// Make this return true when this Command no longer needs to run execute()
bool MoveTurn::IsFinished() {
	if (abs(Robot::gyroSubsystem.getGyroAngle() - degrees)%360 <= 10 || abs(Robot::gyroSubsystem.getGyroAngle() - degrees)%360 >= 350) {
		return true;
	} else {
		return false;
	}
}

// Called once after isFinished returns true
void MoveTurn::End() {
	Robot::driveSubsystem.arcade(0, 0);
	Robot::driveSubsystem.resetEncoders();
	Robot::gyroSubsystem.reset();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void MoveTurn::Interrupted() {
	End();
}

static int signum(double value) {
	if (value == 0) {
		return 0;
	} else {
		return value/abs(value);
	}
}
