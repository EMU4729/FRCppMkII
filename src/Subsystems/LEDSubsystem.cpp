/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include <Subsystems/LEDSubsystem.h>
#include "../RobotMap.h"

LEDSubsystem::LEDSubsystem() : Subsystem("LEDSubsystem") {
	//led = new CANLight(ledPort);

	alliance = DriverStation::GetInstance().GetAlliance();
}

void LEDSubsystem::stop() {
//	led->ShowRGB(0, 0, 0);
}

void LEDSubsystem::tank(double left, double right) {
//	if (DriverStation::GetInstance().GetMatchTime() <= 30) {
//		flash();
//	} else {
//		double speed = abs((left+right)/2);
//		if (alliance == DriverStation::Alliance::kBlue) {
//			led->ShowRGB(0, 0, speed*255);
//		} else { //for lukes sake: alliance == DriverStation::Alliance::kRed
//			led->ShowRGB(speed*255, 0, 0);
//		}
//	}
}

void LEDSubsystem::arcade(double forwards) {
//	if (DriverStation::GetInstance().GetMatchTime() <= 30) {
//		flash();
//	} else {
//		double speed = abs(forwards/2);
//		if (alliance == DriverStation::Alliance::kBlue) {
//			led->ShowRGB(0, 0, speed*255);
//		} else {
//			led->ShowRGB(speed*255, 0, 0);
//		}
//	}
//}
//
//void LEDSubsystem::flash() {
//	int time = DriverStation::GetInstance().GetMatchTime()*500;
//	double intensity = abs(255-time%510);
//	led->ShowRGB(intensity, intensity*((double)165/255), 0); // 255, 165, 0
//
}

void LEDSubsystem::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	// SetDefaultCommand(new MySpecialCommand());
}

// Put methods for controlling this subsystem
// here. Call these from Commands.
