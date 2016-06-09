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

/* singal from sensor pin */
int sgn = 0;
int changed = 0;

/* direction */
int positive = 1;
int negative = 0;

/* Servo */
Servo servo;
int servoPos = 0;

void setup() {
	Serial.begin(9600);
        servo.attach(11);
        servo.write(servoPos);
}

void loop() {
	int sgn = digitalRead(sensorPin);
	if (sgn == 1 && changed == 0) {
                changed = 1;
	}

        /*
        analogWrite(leftMotor1, positive * 100);
	analogWrite(leftMotor2, negative * 100);
        analogWrite(rightMotor1, positive * 100);
	analogWrite(rightMotor2, negative * 100);*/
        if (changed == 0) {
            digitalWrite(leftMotor1, LOW);
            digitalWrite(leftMotor2, HIGH);
            digitalWrite(rightMotor1, LOW);
            digitalWrite(rightMotor2, HIGH);
            analogWrite(leftPWM, 100);
            analogWrite(rightPWM, 100);
        } else {
            digitalWrite(leftMotor1, HIGH);
            digitalWrite(leftMotor2, LOW);
            digitalWrite(rightMotor1, HIGH);
            digitalWrite(rightMotor2, LOW);
            analogWrite(leftPWM, 100);
            analogWrite(rightPWM, 100);
        }
        
        if (changed == 0) {
            servoPos += 5;
            servo.write(servoPos);
        }
	delay(100);
}
