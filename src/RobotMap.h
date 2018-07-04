/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

constexpr int leftFrontPort = 0;
constexpr int rightFrontPort = 1;
constexpr int leftBackPort = 2;
constexpr int rightBackPort = 3;

constexpr int leftEncoderA = 0;
constexpr int leftEncoderB = 1;
constexpr int rightEncoderA = 2;
constexpr int rightEncoderB = 3;

constexpr int motorFlap = 6;

constexpr int ledPort = 30;

constexpr int winch1Port = 11;
constexpr int winch2Port = 12;

constexpr int cubeMotorPort = 5;

/**
 * The RobotMap is a mapping from the ports sensors and actuators are wired into
 * to a variable name. This provides flexibility changing wiring, makes checking
 * the wiring easier and significantly reduces the number of magic numbers
 * floating around.
 */

// For example to map the left and right motors, you could define the
// following variables to use with your drivetrain subsystem.
// constexpr int kLeftMotor = 1;
// constexpr int kRightMotor = 2;

// If you are using multiple modules, make sure to define both the port
// number and the module. For example you with a rangefinder:
// constexpr int kRangeFinderPort = 1;
// constexpr int kRangeFinderModule = 1;
