/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <DoubleSolenoid.h>
#include <Commands/Subsystem.h>

class Pneumatics : public frc::Subsystem {
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
	DoubleSolenoid *leftGrabber;
	DoubleSolenoid *rightGrabber;

public:
	Pneumatics();
	void InitDefaultCommand() override;
	void Grab(DoubleSolenoid left, DoubleSolenoid right);
	void Release(DoubleSolenoid left, DoubleSolenoid right);
	void Off(DoubleSolenoid left, DoubleSolenoid right);
};

