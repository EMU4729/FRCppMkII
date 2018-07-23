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
	Joystick *joystick1 = new Joystick(0);
	joystick1->SetThrottleChannel(5);
	joystick1->SetTwistChannel(4);

	Joystick *joystick2 = new Joystick(1);
	joystick2->SetThrottleChannel(5);
	joystick2->SetTwistChannel(4);

	auto a1 = new JoystickButton(joystick1, 1);
	auto b1 = new JoystickButton(joystick1, 2);
	auto x1 = new JoystickButton(joystick1, 3);
	auto y1 = new JoystickButton(joystick1, 4);
	auto lb1 = new JoystickButton(joystick1, 5);
	auto rb1 = new JoystickButton(joystick1, 6);
	auto start1 = new JoystickButton(joystick1, 7);
	auto select1 = new JoystickButton(joystick1, 8);
	auto l31 = new JoystickButton(joystick1, 9);
	auto r31 = new JoystickButton(joystick1, 10);

	auto a2 = new JoystickButton(joystick2, 1);
	auto b2 = new JoystickButton(joystick2, 2);
	auto x2 = new JoystickButton(joystick2, 3);
	auto y2 = new JoystickButton(joystick2, 4);
	auto lb2 = new JoystickButton(joystick2, 5);
	auto rb2 = new JoystickButton(joystick2, 6);
	auto start2 = new JoystickButton(joystick2, 7);
	auto select2 = new JoystickButton(joystick2, 8);
	auto l32 = new JoystickButton(joystick2, 9);
	auto r32 = new JoystickButton(joystick2, 10);

	defaultDrive = new TwoStickArcade(joystick1);
	y1->WhileHeld(new FlapUp());
	b1->WhileHeld(new FlapDown());
	l31->WhenPressed(new TwoStickArcade(joystick1));
	r31->WhenPressed(new TwoStickTank(joystick1));
	start1->WhenPressed(new HighSpeed());
	select1->WhenPressed(new LowSpeed());

	new WinchControl(joystick2);
	new TiltControl(joystick2);
	y2->WhileHeld(new CubeOuttake());
	b2->WhileHeld(new CubeIntake());
	x2->WhileHeld(new PneumaticsGrab());
	a2->WhileHeld(new PneumaticsRelease());
//	rb2->WhileHeld(new WinchPower());
}

// // Old code
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
