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
	Joystick *joystick = new Joystick(0);
	joystick->SetThrottleChannel(1);
	joystick->SetTwistChannel(4);
	joystick->SetYChannel(5);

	defaultDrive = new TwoStickArcade(joystick);

	auto a = new JoystickButton(joystick, 1);
	auto b = new JoystickButton(joystick, 2);
	auto x = new JoystickButton(joystick, 3);
	auto y = new JoystickButton(joystick, 4);
	auto lb = new JoystickButton(joystick, 5);
	auto rb = new JoystickButton(joystick, 6);
	auto start = new JoystickButton(joystick, 7);
	auto select = new JoystickButton(joystick, 8);
	auto l3 = new JoystickButton(joystick, 9);
	auto r3 = new JoystickButton(joystick, 10);

	a->WhileHeld(new WinchDown(false));
	b->WhileHeld(new WinchDown(true));
	x->WhileHeld(new OpenFlaps());
	y->WhileHeld(new WinchUp());
	lb->WhileHeld(new CubeIntake());
	rb->WhileHeld(new CubeOuttake());
	l3->WhenPressed(new TwoStickArcade(joystick));
	r3->WhenPressed(new TwoStickTank(joystick));
	start->WhenPressed(new HighSpeed());
	select->WhenPressed(new LowSpeed());
}
