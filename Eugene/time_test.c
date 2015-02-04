#pragma config(Hubs,  S1, HTMotor,  HTMotor,  HTMotor,  HTServo)
#pragma config(Hubs,  S2, HTMotor,  none,     none,     none)
#pragma config(Sensor, S3,     IR,             sensorHiTechnicIRSeeker1200)
#pragma config(Motor,  mtr_S1_C1_1,     scissor_lift_up, tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C1_2,     right_wheel,   tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C2_1,     scissor_lift_down, tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C2_2,     motorE,        tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C3_1,     left_wheel,    tmotorTetrix, openLoop, encoder)
#pragma config(Motor,  mtr_S1_C3_2,     spinner,       tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S2_C1_1,     booster,       tmotorTetrix, openLoop, encoder)
#pragma config(Motor,  mtr_S2_C1_2,     motorK,        tmotorTetrix, openLoop, encoder)
#pragma config(Servo,  srvo_S1_C4_1,    left_grabber,         tServoStandard)
#pragma config(Servo,  srvo_S1_C4_2,    right_grabber,        tServoStandard)
#pragma config(Servo,  srvo_S1_C4_3,    hopper,               tServoStandard)
#pragma config(Servo,  srvo_S1_C4_4,    IR_arm,               tServoStandard)
#pragma config(Servo,  srvo_S1_C4_5,    servo11,              tServoStandard)
#pragma config(Servo,  srvo_S1_C4_6,    servo12,              tServoStandard)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

#include "JoystickDriver.c"

/////////////////////////////////////////////////////////////////////////////////////////////////////
//
//                           Autonomous Mode Code Template
//
// This file contains a template for simplified creation of an autonomous program for an TETRIX robot
// competition.
//
// You need to customize two functions with code unique to your specific robot.
//
/////////////////////////////////////////////////////////////////////////////////////////////////////



/////////////////////////////////////////////////////////////////////////////////////////////////////
//
//                                    initializeRobot
//
// Prior to the start of autonomous mode, you may want to perform some initialization on your robot.
// Things that might be performed during initialization include:
//   1. Move motors and servos to a preset position.
//   2. Some sensor types take a short while to reach stable values during which time it is best that
//      robot is not moving. For example, gyro sensor needs a few seconds to obtain the background
//      "bias" value.
//
// In many cases, you may not have to add any code to this function and it will remain "empty".
//
/////////////////////////////////////////////////////////////////////////////////////////////////////

void initializeRobot()
{
  // Place code here to sinitialize servos to starting positions.
  // Sensors are automatically configured and setup by ROBOTC. They may need a brief time to stabilize.
	servo[left_grabber] = 180;
	servo[right_grabber] = 180;
	servo[hopper] = 180;
	servo[IR_arm] = 180;

  return;
}


/////////////////////////////////////////////////////////////////////////////////////////////////////
//
//                                         Main Task
//
// The following is the main code for the autonomous robot operation. Customize as appropriate for
// your specific robot.
//
// The types of things you might do during the autonomous phase (for the 2008-9 FTC competition)
// are:
//
//   1. Have the robot follow a line on the game field until it reaches one of the puck storage
//      areas.
//   2. Load pucks into the robot from the storage bin.
//   3. Stop the robot and wait for autonomous phase to end.
//
// This simple template does nothing except play a periodic tone every few seconds.
//
// At the end of the autonomous period, the FMS will autonmatically abort (stop) execution of the program.
//
/////////////////////////////////////////////////////////////////////////////////////////////////////

task main()
{
  initializeRobot();

  //waitForStart(); // Wait for the beginning of autonomous phase.

  ///////////////////////////////////////////////////////////
  ///////////////////////////////////////////////////////////
  ////                                                   ////
  ////    Add your robot specific autonomous code here.  ////
  ////                                                   ////
  ///////////////////////////////////////////////////////////
  ///////////////////////////////////////////////////////////
}
