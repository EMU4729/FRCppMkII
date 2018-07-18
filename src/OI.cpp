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
#include "Commands/OpenFlaps.h"
#include "Commands/CubeIntake.h"
#include "Commands/CubeOuttake.h"
#include "Commands/HighSpeed.h"
#include "Commands/LowSpeed.h"

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

	defaultDrive = new TwoStickArcade(joystick1);

	auto a = new JoystickButton(joystick1, 1);
	auto b = new JoystickButton(joystick1, 2);
	auto x = new JoystickButton(joystick1, 3);
	auto y = new JoystickButton(joystick1, 4);
	auto lb = new JoystickButton(joystick1, 5);
	auto rb = new JoystickButton(joystick1, 6);
	auto start = new JoystickButton(joystick1, 7);
	auto select = new JoystickButton(joystick1, 8);
	auto l3 = new JoystickButton(joystick1, 9);
	auto r3 = new JoystickButton(joystick1, 10);

	a->WhileHeld(new WinchDown(false));
	b->WhileHeld(new WinchDown(true));
	x->WhileHeld(new OpenFlaps());
	y->WhileHeld(new WinchUp());
	lb->WhileHeld(new CubeIntake());
	rb->WhileHeld(new CubeOuttake());
	l3->WhenPressed(new TwoStickArcade(joystick1));
	r3->WhenPressed(new TwoStickTank(joystick1));
	start->WhenPressed(new HighSpeed());
	select->WhenPressed(new LowSpeed());
}
