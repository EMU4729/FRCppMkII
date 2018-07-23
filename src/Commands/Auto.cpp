/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include <iostream>
#include "Auto.h"
#include "../Robot.h"
#include "AutoPath/Left.h"
#include "AutoPath/Middle.h"
#include "AutoPath/Right.h"
#include "WinchUp.h"
#include "PneumaticsGrab.h"

Auto::Auto(string autoType) : autoType{autoType} {
	Robot::driveSubsystem.lowSpeed();
	Robot::driveSubsystem.resetEncoders();

	side = Direction::Left;

	gameData = DriverStation::GetInstance().GetGameSpecificMessage();
	if (gameData[0] == 'L') {
		side = Direction::Left;
	} else if (gameData[0] == 'R') {
		side = Direction::Right;
	}

	AddSequential(new PneumaticsGrab());
	AddSequential(new WinchUp(1)); // TODO: find better value
	if (autoType == "l") {
		AddSequential(new AutoPath::Left(side));
	} else if (autoType == "m") {
		AddSequential(new AutoPath::Middle());
	} else if (autoType == "r") {
		AddSequential(new AutoPath::Right(side));
	} else {
		AddSequential(new AutoPath::Middle());
	}


	// Add Commands here:
	// e.g. AddSequential(new Command1());
	//      AddSequential(new Command2());
	// these will run in order.

	// To run multiple commands at the same time,
	// use AddParallel()
	// e.g. AddParallel(new Command1());
	//      AddSequential(new Command2());
	// Command1 and Command2 will run in parallel.

	// A command group will require all of the subsystems that each member
	// would require.
	// e.g. if Command1 requires chassis, and Command2 requires arm,
	// a CommandGroup containing them would require both the chassis and the
	// arm.
}
