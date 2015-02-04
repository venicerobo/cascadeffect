#pragma config(Hubs,  S1, HTMotor,  HTServo,  HTMotor,  HTMotor)
#pragma config(Sensor, S2,     IR,             sensorHiTechnicIRSeeker1200)
#pragma config(Motor,  mtr_S1_C1_1,     scissor_lift_up, tmotorTetrix, openLoop, encoder)
#pragma config(Motor,  mtr_S1_C1_2,     right_wheel,   tmotorTetrix, openLoop, encoder)
#pragma config(Motor,  mtr_S1_C3_1,     scissor_lift_down, tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C3_2,     motorI,        tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C4_1,     left_wheel,    tmotorTetrix, openLoop, encoder)
#pragma config(Motor,  mtr_S1_C4_2,     spinner,       tmotorTetrix, openLoop)
#pragma config(Servo,  srvo_S1_C2_1,    grabber_left,         tServoStandard)
#pragma config(Servo,  srvo_S1_C2_2,    grabber_right,        tServoStandard)
#pragma config(Servo,  srvo_S1_C2_3,    hopper,               tServoStandard)
#pragma config(Servo,  srvo_S1_C2_4,    IR_arm,               tServoStandard)
#pragma config(Servo,  srvo_S1_C2_5,    servo5,               tServoNone)
#pragma config(Servo,  srvo_S1_C2_6,    servo6,               tServoNone)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

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

#include "JoystickDriver.c"  //Include file to "handle" the Bluetooth messages.

// DICTIONARY
const int LEFT_DR = 100;
const int RIGHT_DR = -100;

const int CG_DRIVE_TIME = 1250;
const int NINETY_DEG_TURN_TIME = 1000;
const int NINETY_DEG_PIVOT_TIME = 1000;
const int KICKSTAND_DRIVE_TIME = 5000;


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

while(true) {
  initializeRobot();

  waitForStart(); // Wait for the beginning of autonomous phase.

  ///////////////////////////////////////////////////////////
  ///////////////////////////////////////////////////////////
  ////                                                   ////
  ////    Add your robot specific autonomous code here.  ////
  ////                                                   ////
  ///////////////////////////////////////////////////////////
  ///////////////////////////////////////////////////////////

  //FIRST DETECT
  // drive straight for 1.05 seconds
	motor[left_wheel] = 100;
	motor[right_wheel] = -100;
	wait1Msec(1050);
	motor[left_wheel] = 0;
	motor[right_wheel] = 0;
	wait1Msec(1000);
	// turn 15 deg clockwise
	motor[left_wheel] = -50;
  motor[right_wheel] = -50;
  wait1Msec(700);
  motor[left_wheel] = 0;
	motor[right_wheel] = 0;
	wait1Msec(1000);
	// CUSTOM
	if (SensorValue[IR] >= 1 && SensorValue[IR] <= 4) {
	// must be: DEAD ON
		// small 1 sec pivot
		motor[left_wheel] = 100;
  	motor[right_wheel] = -15;
  	wait1Msec(1000);
  	// run forward to knock kickstand
  	motor[right_wheel] = -100;
  	wait1Msec(3500);

  	motor[left_wheel] = 0;
  	motor[right_wheel] = 0;
  }

  else {
  // must be ANGLED or AWAY
  	// SECOND DETECT
  	// turn 30 deg counterclockwise
		motor[left_wheel] = 50;
  	motor[right_wheel] = 50;
  	wait1Msec(1400);
  	motor[left_wheel] = 0;
		motor[right_wheel] = 0;

		nxtDisplayString(0, "IRSensor value");
		nxtDisplayString(1, "%03d", SensorValue[IR]);

		if (SensorValue[IR] == 4 || SensorValue[IR] == 5) {
		// must be: ANGLED
			// clockwise pseudo-pivot for 2 sec
			motor[right_wheel] = -100;
			motor[left_wheel] = -20;
			wait1Msec(2000);
			// run forward to knock kickstand
			motor[left_wheel] = -100;
			wait1Msec(3000);
			motor[left_wheel] = 0;
			motor[right_wheel] = 0;
		}
		else {
		// must be: AWAY
			// clockwise pivot for 2 sec
			motor[left_wheel] = 1;
			motor[right_wheel] = -100;
			wait1Msec(2000);
			// proportion turn for 3 sec
			motor[left_wheel] = 50;
			motor[right_wheel] = 100;
			wait1Msec(3000);
			motor[left_wheel] = 0;
			motor[right_wheel] = 0;
		}
	}
}