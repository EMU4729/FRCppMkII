/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <Commands/Subsystem.h>
#include <Talon.h>

using frc::Talon;

class WinchSubsystem : public frc::Subsystem {
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
	Talon winch1;
	Talon winch2;

	double normalSpeed;
	double carrySpeed;
	double upSpeed;
public:
	WinchSubsystem();
	void InitDefaultCommand() override;
	void up();
	void down(bool carry);
	void stop();
};

