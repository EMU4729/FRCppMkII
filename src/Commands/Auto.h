/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <string>

#include <Commands/CommandGroup.h>
#include <DriverStation.h>
#include "../Enums/Direction.h"
using std::string;


class Auto : public frc::CommandGroup {
private:
	string autoType;
	Direction side;
	string gameData;
public:
	Auto(string autoType);
};

