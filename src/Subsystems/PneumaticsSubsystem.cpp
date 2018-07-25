/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.
 *
 * "Do you know who I am?"
 *                     - INSERT_YOUR_NAME_HERE
/*----------------------------------------------------------------------------*/

#include <Subsystems/PneumaticsSubsystem.h>
#include "../RobotMap.h"


PneumaticsSubsystem::PneumaticsSubsystem() : Subsystem("pneumaticSubsystem"), leftGrabber{forwardLeftSolenoid, reverseLeftSolenoid}, rightGrabber{forwardRightSolenoid,reverseRightSolenoid} {

}

void PneumaticsSubsystem::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	// SetDefaultCommand(new MySpecialCommand());
}

// Put methods for controlling this subsystem
// here. Call these from Commands.
void PneumaticsSubsystem::Grab() { //button x
	// when the thing grabs the cube #excellantDescription
	leftGrabber.Set(frc::DoubleSolenoid::Value::kForward);
	rightGrabber.Set(frc::DoubleSolenoid::Value::kForward);

}

void PneumaticsSubsystem::Release() { //button b
	// when the thing release the cube
	leftGrabber.Set(frc::DoubleSolenoid::Value::kReverse);
	rightGrabber.Set(frc::DoubleSolenoid::Value::kReverse);
}

void PneumaticsSubsystem::Off() { //button y
	//solenoid off
	leftGrabber.Set(frc::DoubleSolenoid::Value::kOff);
	rightGrabber.Set(frc::DoubleSolenoid::Value::kOff);
}
