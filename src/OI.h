/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include "memory"
#include "Joystick.h"
#include <Commands/Command.h>

class OI {
private:
	Joystick *leftStick;
	Joystick *rightStick;
public:
	OI();
	frc::Command *defaultDrive = nullptr;
	frc::Command *winchControl = nullptr;
//	frc::Command *tiltControl = nullptr;
};
