/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "CubeOuttake.h"
#include "../Robot.h"

CubeOuttake::CubeOuttake() {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	Requires(&Robot::cubeSubsystem);
}

// Called just before this Command runs the first time
void CubeOuttake::Initialize() {

}

// Called repeatedly when this Command is scheduled to run
void CubeOuttake::Execute() {
	Robot::cubeSubsystem.outtake();
}

// Make this return true when this Command no longer needs to run execute()
bool CubeOuttake::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void CubeOuttake::End() {
	Robot::cubeSubsystem.stop();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void CubeOuttake::Interrupted() {
	End();
}
