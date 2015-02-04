#pragma config(Hubs,  S1, HTServo,  HTMotor,  HTMotor,  none)
#pragma config(Sensor, S1,     ,               sensorI2CMuxController)
#pragma config(Sensor, S2,     IRfront,        sensorHiTechnicIRSeeker1200)
#pragma config(Sensor, S3,     IRright,        sensorHiTechnicIRSeeker1200)
#pragma config(Motor,  mtr_S1_C2_1,     scissor_lift,  tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C2_2,     sweeper,       tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C3_1,     left_wheel,    tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C3_2,     right_wheel,   tmotorTetrix, openLoop)
#pragma config(Servo,  srvo_S1_C1_1,    left_tube_clamp,      tServoStandard)
#pragma config(Servo,  srvo_S1_C1_2,    right_tube_clamp,     tServoStandard)
#pragma config(Servo,  srvo_S1_C1_3,    servo3,               tServoNone)
#pragma config(Servo,  srvo_S1_C1_4,    servo4,               tServoNone)
#pragma config(Servo,  srvo_S1_C1_5,    servo5,               tServoNone)
#pragma config(Servo,  srvo_S1_C1_6,    servo6,               tServoNone)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

#include "turing_constants_try.c"

void initializeRobot()
{
	servo[left_tube_clamp] = 0;
	servo[right_tube_clamp] = 0;
  // Place code here to initialize servos to starting positions.
  // Sensors are automatically configured and setup by ROBOTC. They may need a brief time to stabilize.
}

///////////////////////////////////////////////////////////////////////////////////////////////////////

task main() {
	initializeRobot();
	//waitForStart(); // Wait for the beginning of autonomous phase.

	// Drive forward to detect IR.
	nMotorEncoder[left_wheel] = ENCODER_RESET;
	nMotorEncoder[right_wheel] = ENCODER_RESET;
	nMotorEncoderTarget[left_wheel] = FIRST_DETECT_TICKS;
	nMotorEncoderTarget[right_wheel] = FIRST_DETECT_TICKS;
	motor[left_wheel] = DEAD_RECKONING;
	motor[right_wheel] = DEAD_RECKONING;

	while(nMotorRunState[left_wheel] != runStateIdle || nMotorRunState[right_wheel] != runStateIdle) {
		// Do nothing while both motors are running.
		// Loop will run until both motors are "idle", or have stopped.
	}

	if (SensorValue[S1] == CG_DEADON_READING || SensorValue[S1] == CG_ANGLED_READING || SensorValue[S1] == CG_AWAY_READING) {

		// IR IS 0 DEGREES FROM PARKING ZONE
		if (SensorValue[S1] == CG_DEADON_READING) {
			// Turn 180 deg counterclockwise
			nMotorEncoder[left_wheel] = ENCODER_RESET;
			nMotorEncoder[right_wheel] = NINETY_TURN_TICKS * 2;
			nMotorEncoderTarget[left_wheel] = NINETY_TURN_TICKS*2;
			nMotorEncoderTarget[right_wheel] = 0;
			motor[left_wheel] = DEAD_RECKONING;
			motor[right_wheel] = -DEAD_RECKONING;
			while (nMotorRunState[left_wheel] != runStateIdle || nMotorEncoderTarget[right_wheel] != runStateIdle) {}
		}

		// IR IS 45 DEGREES FROM PARKING ZONE
		if (SensorValue[S1] == CG_ANGLED_READING) {
			//IR is 45 deg, so turn 60 deg counterclockwise
			nMotorEncoder[left_wheel] = -CG_ANGLED_TURN_TICKS;
			nMotorEncoder[right_wheel] = 0;
			nMotorEncoderTarget[left_wheel] = 0;
			nMotorEncoderTarget[right_wheel] = CG_ANGLED_TURN_TICKS;
			motor[left_wheel] = DEAD_RECKONING;
			motor[right_wheel] = -DEAD_RECKONING;
			while (nMotorRunState[left_wheel] != runStateIdle || nMotorEncoderTarget[right_wheel] != runStateIdle) {}

			// Drive straight
			nMotorEncoder[left_wheel] = ENCODER_RESET;
			nMotorEncoder[right_wheel] = ENCODER_RESET;
			nMotorEncoderTarget[left_wheel] = CG_ANGLED_DRIVE_TICKS;
			nMotorEncoderTarget[right_wheel] = CG_ANGLED_DRIVE_TICKS;
			motor[left_wheel] = DEAD_RECKONING;
			motor[right_wheel] = -DEAD_RECKONING;
			while (nMotorRunState[left_wheel] != runStateIdle || nMotorEncoderTarget[right_wheel] != runStateIdle) {}
		}

		// IR IS 90 DEGREES FROM PARKING ZONE
		if (SensorValue[S1] == 0 && SensorValue[S2] == 0) {
		// Turn 90 deg counterclockwise
			nMotorEncoder[left_wheel] = -NINETY_TURN_TICKS;
			nMotorEncoder[right_wheel] = ENCODER_RESET;
			nMotorEncoderTarget[left_wheel] = 0;
			nMotorEncoderTarget[right_wheel] = NINETY_TURN_TICKS;
			motor[left_wheel] = DEAD_RECKONING;
			motor[right_wheel] = -DEAD_RECKONING;
			while (nMotorRunState[left_wheel] != runStateIdle || nMotorEncoderTarget[right_wheel] != runStateIdle) {}
		// Drive straight for 16 in

		// Turn 90 deg clockwise
			nMotorEncoder[left_wheel] = ENCODER_RESET;
			nMotorEncoder[right_wheel] = -NINETY_TURN_TICKS;
			nMotorEncoderTarget[left_wheel] = NINETY_TURN_TICKS;
			nMotorEncoderTarget[right_wheel] = 0;
			motor[left_wheel] = DEAD_RECKONING;
			motor[right_wheel] = -DEAD_RECKONING;
			while (nMotorRunState[left_wheel] != runStateIdle || nMotorEncoderTarget[right_wheel] != runStateIdle) {}
		// Detect IR - use distance instead of IR maybe???
			while (SensorValue[S2] != 5) {
				motor[left_wheel] = DEAD_RECKONING;
				motor[right_wheel] = DEAD_RECKONING;
			}
			motor[left_wheel] = 0;
			motor[right_wheel] = 0;
			nMotorEncoder[left_wheel] = ENCODER_RESET;
			nMotorEncoder[right_wheel] = ENCODER_RESET;
		}

		// Lift scissorlift and activate autoarm.
		wait1Msec(3000);

		// Back up a little
		nMotorEncoder[left_wheel] = KS_TINY_BACKUP;
		nMotorEncoder[right_wheel] = KS_TINY_BACKUP;
		nMotorEncoderTarget[left_wheel] = 0;
		nMotorEncoderTarget[right_wheel] = 0;
		motor[left_wheel] = -DEAD_RECKONING;
		motor[right_wheel] = -DEAD_RECKONING;
		while (nMotorRunState[left_wheel] != runStateIdle || nMotorEncoderTarget[right_wheel] != runStateIdle) {}
		//////////////////////////////////////////////////////////////////////////////////////////////////////////////
		//Turn 90 deg clockwise
		while (nMotorEncoder[left_wheel]<NINETY_TURN_TICKS && nMotorEncoder[right_wheel]<NINETY_TURN_TICKS) {
			motor[left_wheel] = TURNING_SPEED;
			motor[right_wheel] = TURNING_SPEED;
		}
		// Knock kickstand
		while (nMotorEncoder[left_wheel]<KS_DRIVE_TICKS && nMotorEncoder[right_wheel]<KS_DRIVE_TICKS) {
			motor[left_wheel] = DEAD_RECKONING;
			motor[right_wheel] = -DEAD_RECKONING;
		}
	}
}