#pragma config(Sensor, in7,    RightPotentiometer, sensorPotentiometer)
#pragma config(Sensor, in8,    LeftPotentiometer, sensorPotentiometer)
#pragma config(Sensor, dgtl1,  JumperClip,     sensorDigitalIn)
#pragma config(Sensor, dgtl2,  RightBumper,    sensorTouch)
#pragma config(Sensor, dgtl3,  LeftBumper,     sensorTouch)
#pragma config(Sensor, dgtl7,  RightLED,       sensorLEDtoVCC)
#pragma config(Sensor, dgtl8,  LeftLED,        sensorLEDtoVCC)
#pragma config(Sensor, dgtl9,  RightQuad1,     sensorQuadEncoder)
#pragma config(Sensor, dgtl11, LeftQuad1,      sensorQuadEncoder)
#pragma config(Motor,  port2,           DriveFL,       tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port3,           DriveFR,       tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port4,           LiftR,         tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port5,           LiftL,         tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port6,           BallLauncher,  tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port7,           MiniLift,      tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port8,           DriveBL,       tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port9,           DriveBR,       tmotorVex393_MC29, openLoop, reversed)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*        Description: Competition template for VEX EDR                      */
/*                                                                           */
/*---------------------------------------------------------------------------*/

// This code is for the VEX cortex platform
#pragma platform(VEX2)

// Select Download method as "competition"
#pragma competitionControl(Competition)

//Main competition background code...do not modify!
#include "Vex_Competition_Includes.c"

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                            Functions and Tasks                            */
/*                                                                           */
/*---------------------------------------------------------------------------*/

  //Blink Right LED Task
  task blinkRightLED(){
  	SensorValue[RightLED] = 0;
  	wait1Msec(100);
  	SensorValue[RightLED] = 1;
  	wait1Msec(100);
	}

	task blinkLeftLED(){
		SensorValue[LeftLED] = 0;
		wait1Msec(100);
		SensorValue[LeftLED] = 1;
		wait1Msec(100);
	}


  // Minilift Function
  void ballShooterLift(int up, int down)
  {
  	if(up == 1)
  	{
			setMotor(MiniLift, -50);
		}
		else if(vexRT(down) == 1)
		{
			setMotor(MiniLift, 50);
		}
		else
		{
			setMotor(MiniLift, 0);
		}
  }


  // Ball Shooter Function
  void ballShooter(int shoot){
  	if(shoot == 1)
		{
			setMotor(BallLauncher, -127);
		}
		else
		{
			setMotor(BallLauncher, 0);
		}
	}


  // Lift Function
  void lift(int up, int down)
  {
  	if(vexRT(Btn6U) == 1)
		{
			setMotor(LiftR, 127);
			setMotor(LiftL, -127);
		}
		else if(vexRT(Btn6D) == 1)
		{
			setMotor(LiftR, -127);
			setMotor(LiftL, 127);
		}
		else
		{
			setMotor(LiftR, 0);
			setMotor(LiftL, 0);
		}
  }


  // Lift Angle Correction Function
  void angleCorrection(int Right, int Left)
  {
  	if(Right != Left)
  	{
  		if(Right > Left)
  		{
  			setMotor(LiftL, 40);
  		}
  		else
  		{
  			setMotor(LiftR, 40);
  		}
  	}
  	else
  	{
  		setMotor(LiftR, 0);
			setMotor(LiftL, 0);
  	}
	}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                          Pre-Autonomous Functions                         */
/*                                                                           */
/*---------------------------------------------------------------------------*/

void pre_auton()
{
	int auto = SensorValue[JumperClip];

	if(auto == 0){
		startTask(blinkLeftLED);
	}
	else{
		startTask(blinkRightLED);
	}

  bStopTasksBetweenModes = true;
}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              Autonomous Task                              */
/*                                                                           */
/*---------------------------------------------------------------------------*/

task autonomous()
{
  AutonomousCodePlaceholderForTesting();
}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              User Control Task                            */
/*                                                                           */
/*---------------------------------------------------------------------------*/

task usercontrol()
{

  while (true)
  {
  	// Drivetrain
		motor[port2] = vexRT(Ch3);
  	motor[port3] = vexRT(Ch2);
  	motor[port8] = vexRT(Ch3);
  	motor[port9] = vexRT(Ch2);


  	// Minilift
  	int MiniliftUp = vexRT(Btn5U);
  	int MiniliftDown = vexRT(Btn5D);
  	ballShooterLift(MiniliftUp, MiniliftDown);


		// Ball Shooter
		int ShootButton = vexRT(Btn7D);
		ballShooter(ShootButton);


  	// Lift
		int LiftUp = vexRT(Btn6U);
		int LiftDown = vexRT(Btn6D);
		lift(LiftUp, LiftDown);


  	// Lift Angle Correction
  	int AngleLiftR = SensorValue[RightPotentiometer];
		int AngleLiftL = SensorValue[LeftPotentiometer];
		angleCorrection(AngleLiftR, AngleLiftL);
  }

}
