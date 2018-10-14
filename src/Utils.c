#pragma config(Motor,  port2,           DriveFR,       tmotorVex393_MC29, openLoop, driveRight)
#pragma config(Motor,  port3,           DriveFL,       tmotorVex393_MC29, openLoop, driveLeft)
#pragma config(Motor,  port4,           LiftR,         tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port5,           LiftL,         tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port6,           MiniLift,      tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port7,           BallLauncher,  tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port8,           DriveBR,       tmotorVex393_MC29, openLoop, driveRight)
#pragma config(Motor,  port9,           DriveBL,       tmotorVex393_MC29, openLoop, driveLeft)

void drive_foward(int time, int speed){
	setMultipleMotors(speed, DriveFR, DriveFL, DriveBR, DriveBL);
	wait(time);
	setMultipleMotors(0, DriveFR, DriveFL, DriveBR, DriveBL);
}

void drive_backward(int time, int speed){
	wait(time);
}

void lift_up(int time, int speed){
	wait(time);
}

void lift_down(int time, int speed){
	wait(time);
}

void minilift_up(int time, int speed){
	wait(time);
}

void minilift_down(int time, int speed){
	wait(time);
}

void ball_shoot(){
	setMotor(BallLauncher, -127);
	wait(1000);
	setMotor(BallLauncher, 0);
}
