/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.
 *
 * Do you know who I am?
 *                     - INSERT_YOUR_NAME_HERE
/*----------------------------------------------------------------------------*/

#include "Pneumatics.h"
#include "../RobotMap.h"


Pneumatics::Pneumatics() : Subsystem("PneumaticSubsystem") {
	leftGrabber = new DoubleSolenoid(forwardLeftSolenoid,reverseLeftSolenoid);
	rightGrabber = new DoubleSolenoid(forwardRightSolenoid,reverseRightSolenoid);

}

void Pneumatics::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	// SetDefaultCommand(new MySpecialCommand());
}

// Put methods for controlling this subsystem
// here. Call these from Commands.
void Pneumatics::Grab(DoubleSolenoid left, DoubleSolenoid right) { //button x
	// when the thing grabs the cube #excellantDescription
	left.Set(frc::DoubleSolenoid::Value::kForward);
	right.Set(frc::DoubleSolenoid::Value::kForward);

}

void Pneumatics::Release(DoubleSolenoid left, DoubleSolenoid right) { //button b
	// when the thing release the cube
	left.Set(frc::DoubleSolenoid::Value::kReverse);
	right.Set(frc::DoubleSolenoid::Value::kReverse);
}

void Pneumatics::Off(DoubleSolenoid left, DoubleSolenoid right) { //button y
	//solenoid off
	left.Set(frc::DoubleSolenoid::Value::kOff);
	right.Set(frc::DoubleSolenoid::Value::kOff);
}
