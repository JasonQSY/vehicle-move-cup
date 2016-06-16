#include <Servo.h>

/* Motor pin */
const int leftMotor1 = 2;
const int leftMotor2 = 3;
const int rightMotor1 = 4;
const int rightMotor2 = 7;

const int leftPWM = 5;
const int rightPWM = 6;

/* sensor pin */
const int sensorPin = 10;

/* servo pin */
const int servoPin = 11;

/* singal from sensor pin */
int sgn;
int state;

int timeLoop;
const int timeFlag = 10;
const int initVelo = 100;
const int extraVelo = 155;
const int maxVelo = 255;

/* Servo */
Servo servo;

/**
 * state = 0 forward
 * state = 1 backward
 * value PWN
 */
void motor(int state, int value) {
    if (state == 0) {
        digitalWrite(leftMotor1, LOW);
        digitalWrite(leftMotor2, HIGH);
        digitalWrite(rightMotor1, LOW);
        digitalWrite(rightMotor2, HIGH);
    }
    if (state == 1) {
        digitalWrite(leftMotor1, HIGH);
        digitalWrite(leftMotor2, LOW);
        digitalWrite(rightMotor1, HIGH);
        digitalWrite(rightMotor2, LOW);
    }
    analogWrite(leftPWM, value);
    analogWrite(rightPWM, value);
}

void stopCar() {
    digitalWrite(leftMotor1, LOW);
    digitalWrite(leftMotor2, LOW);
    digitalWrite(rightMotor1, LOW);
    digitalWrite(rightMotor2, LOW);
}

void setup() {
    motor(0, initVelo);
    sgn = 0;
    state = 0;
    servo.attach(servoPin);
    timeLoop = 0;
    servo.writeMicroseconds(1500);
    //servo.writeMicroseconds(1530);
}

/**
 * state 0 : first acceleration and servo move
 * state 1 : stop servo. continue accelerating
 * state 2 : slow down the speed
 * state 3 : return and accelerating again
 * state 4 : slow down again
 * state 5 : stop
 */
void loop() {
	//int sgn = digitalRead(sensorPin);
        if (timeLoop == 2 && state == 0) {
            state = 1;
        }
	if (timeLoop == timeFlag && state == 1) {
            // slow down the velocity
            state = 2;
	}
        if (timeLoop == 2 * timeFlag && state == 2) {
            // accelerate again
            state = 3;
        }
        if (timeLoop == 3 * timeFlag && state == 3) {
            // slow down the velocity again
            state = 4;
        }
        if (timeLoop == 4 * timeFlag && state == 4) {
            // stop
            state = 5;
        }
        
        if (state == 0) {
            // first acceleration
            motor(0, initVelo + (extraVelo / timeFlag) * timeLoop);
            servo.writeMicroseconds(1700);
        }
        if (state == 1) {
            motor(0, initVelo + (extraVelo / timeFlag) * timeLoop);
            servo.writeMicroseconds(1500);
        }
        if (state == 2) {
            motor(0, maxVelo - (extraVelo / timeFlag) * (timeLoop - timeFlag));
        }
        if (state == 3) {
            motor(1, initVelo + (extraVelo / timeFlag) * (timeLoop - 2 * timeFlag));
            servo.writeMicroseconds(1500);
	}
        if (state == 4) {
            motor(1, maxVelo - (extraVelo / timeFlag) * (timeLoop - 3 * timeFlag));
        }
        if (state == 5) {
            stopCar();
        }
	timeLoop += 1;
	delay(80);
}
