/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "WinchUp.h"
#include "../Robot.h"
#include <Timer.h>

WinchUp::WinchUp() {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	Requires(&Robot::winchSubsystem);
	seconds = -1;
}

WinchUp::WinchUp(double s) {
	Requires(&Robot::winchSubsystem);
	seconds = s;
}

// Called just before this Command runs the first time
void WinchUp::Initialize() {
	if (seconds > 0) timer.Start();
}

// Called repeatedly when this Command is scheduled to run
void WinchUp::Execute() {
	Robot::winchSubsystem.up();
}

// Make this return true when this Command no longer needs to run execute()
bool WinchUp::IsFinished() {
	if (seconds <= 0) {
		return false;
	} else {
		return timer.HasPeriodPassed(seconds);
	}
}

// Called once after isFinished returns true
void WinchUp::End() {
	Robot::winchSubsystem.stop();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void WinchUp::Interrupted() {
	End();
}
