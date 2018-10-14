#pragma config(Motor,  port2,           DriveFR,       tmotorVex393_MC29, openLoop, driveRight)
#pragma config(Motor,  port3,           DriveFL,       tmotorVex393_MC29, openLoop, driveLeft)
#pragma config(Motor,  port4,           LiftR,         tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port5,           LiftL,         tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port6,           MiniLift,      tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port7,           BallLauncher,  tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port8,           DriveBR,       tmotorVex393_MC29, openLoop, driveRight)
#pragma config(Motor,  port9,           DriveBL,       tmotorVex393_MC29, openLoop, driveLeft)

task drive_foward(int time, int speed){
	setMultipleMotors(speed, DriveFR, DriveFL, DriveBR, DriveBL);
	wait(time);
	setMultipleMotors(0, DriveFR, DriveFL, DriveBR, DriveBL);
}

task drive_backward(int time, int speed){
	wait(time);
}

task lift_up(int time, int speed){
	wait(time);
}

task lift_down(int time, int speed){
	wait(time);
}

task minilift_up(int time, int speed){
	wait(time);
}

task minilift_down(int time, int speed){
	wait(time);
}

task ball_shoot()

}
