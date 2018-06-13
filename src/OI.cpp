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

OI::OI() {
	// Process operator interface input here.
	leftStick = new Joystick(0);
	rightStick = new Joystick(1);

	auto a = new JoystickButton(leftStick, 1);
	auto b = new JoystickButton(leftStick, 2);
	auto x = new JoystickButton(leftStick, 3);
	auto y = new JoystickButton(leftStick, 4);
	auto lb = new JoystickButton(leftStick, 5);
	auto rb = new JoystickButton(leftStick, 6);
	auto start = new JoystickButton(leftStick, 7);
	auto select = new JoystickButton(leftStick, 8);
	auto l3 = new JoystickButton(leftStick, 9);
	auto r3 = new JoystickButton(leftStick, 10);

	a->WhileHeld(new WinchDown(false));
	b->WhileHeld(new WinchDown(true));
	x->WhileHeld(new OpenFlaps());
	y->WhileHeld(new WinchUp());
	lb->WhileHeld(new CubeIntake());
	rb->WhileHeld(new CubeOuttake());
	l3->WhenPressed(new TwoStickArcade(leftStick, rightStick));
	r3->WhenPressed(new TwoStickTank(leftStick, rightStick));
	start->WhenPressed(new HighSpeed());
	select->WhenPressed(new LowSpeed());
}
