/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "OI.h"

#include <WPILib.h>
#include "Commands/TwoStickArcade.h"
#include "Commands/TwoStickTank.h"
#include "Commands/WinchUp.h"
#include "Commands/WinchDown.h"
#include "Commands/CubeIntake.h"
#include "Commands/CubeOuttake.h"
#include "Commands/HighSpeed.h"
#include "Commands/LowSpeed.h"
#include "Commands/FlapUp.h"
#include "Commands/FlapDown.h"
#include "Commands/WinchPower.h"
#include "Commands/PneumaticsGrab.h"
#include "Commands/PneumaticsRelease.h"
#include "Commands/WinchControl.h"
#include "Commands/TiltControl.h"

// getThrottle = rightStick y
// getTwist = rightStick x

OI::OI() {
	// Process operator interface input here.
	Joystick *driveLeft = new Joystick(0);

	Joystick *driveRight = new Joystick(1);

	Joystick *player2 = new Joystick(2);
	player2->SetThrottleChannel(5);
	player2->SetTwistChannel(4);

	//auto leftTrigger = new JoystickButton(driveLeft, 1);
	auto leftB2 = new JoystickButton(driveLeft, 2);
	auto leftB3 = new JoystickButton(driveLeft, 3);
	/*auto leftB4 = new JoystickButton(driveLeft, 4);
	auto leftB5 = new JoystickButton(driveLeft, 5);
	auto leftB6 = new JoystickButton(driveLeft, 6);
	auto leftB7 = new JoystickButton(driveLeft, 7);
	auto leftB8 = new JoystickButton(driveLeft, 8);
	auto leftB9 = new JoystickButton(driveLeft, 9);
	auto leftB10 = new JoystickButton(driveLeft, 10);
	auto leftB11 = new JoystickButton(driveLeft, 11);*/



	//auto rightTrigger = new JoystickButton(driveRight, 1);
	auto rightB2 = new JoystickButton(driveRight, 2);
	auto rightB3 = new JoystickButton(driveRight, 3);
	/*auto rightB4 = new JoystickButton(driveRight, 4);
	auto rightB5 = new JoystickButton(driveRight, 5);
	auto rightB6 = new JoystickButton(driveRight, 6);
	auto rightB7 = new JoystickButton(driveRight, 7);
	auto rightB8 = new JoystickButton(driveRight, 8);
	auto rightB9 = new JoystickButton(driveRight, 9);
	auto rightB10 = new JoystickButton(driveRight, 10);
	auto rightB11 = new JoystickButton(driveRight, 11);*/

	auto a2 = new JoystickButton(player2, 1);
	auto b2 = new JoystickButton(player2, 2);
	auto x2 = new JoystickButton(player2, 3);
	auto y2 = new JoystickButton(player2, 4);
	auto lb2 = new JoystickButton(player2, 5);
	auto rb2 = new JoystickButton(player2, 6);
	/*auto start2 = new JoystickButton(player2, 7);
	auto select2 = new JoystickButton(player2, 8);
	auto l32 = new JoystickButton(player2, 9);
	auto r32 = new JoystickButton(player2, 10);*/

	defaultDrive = new TwoStickArcade(driveLeft, driveRight);
	leftB3->WhileHeld(new FlapUp());
	leftB2->WhileHeld(new FlapDown());
	//l31->WhenPressed(new TwoStickArcade(driveLeft));
	//r31->WhenPressed(new TwoStickTank(driveLeft));
	rightB3->WhenPressed(new HighSpeed());
	rightB2->WhenPressed(new LowSpeed());


	winchControl = new WinchControl(player2);
//	tiltControl = new TiltControl(player2);
	y2->WhileHeld(new CubeOuttake());
	b2->WhileHeld(new CubeIntake());
	x2->WhileHeld(new PneumaticsGrab());
	a2->WhileHeld(new PneumaticsRelease());
	//lb2->WhileHeld(new WinchDown());
	//rb2->WhileHeld(new WinchUp());
//	rb2->WhileHeld(new WinchPower());
}

//---------- Old code -----------
// a1->WhileHeld(new WinchDown(false));
// b1->WhileHeld(new WinchDown(true));
// x1->WhileHeld(new OpenFlaps());
// y1->WhileHeld(new WinchUp());
// lb1->WhileHeld(new CubeIntake());
// rb1->WhileHeld(new CubeOuttake());
// l31->WhenPressed(new TwoStickArcade(joystick1));
// r31->WhenPressed(new TwoStickTank(joystick1));
// start1->WhenPressed(new HighSpeed());
// select1->WhenPressed(new LowSpeed());
