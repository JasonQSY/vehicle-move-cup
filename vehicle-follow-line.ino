/* pin of sensor */
const int pinLeftSensor = 2;
const int pinRightSensor = 3;

/* pin of motor */
const int pinLeftMotor1 = 4;
const int pinLeftMotor2 = 5;
const int pinLeftMotorPWM = 6;
const int pinRightMotor1 = 7;
const int pinRightMotor2 = 8;
const int pinRightMotorPWM = 9;

/* Global variables */
int stateLeftSensor;
int stateRightSensor;

/* Functions */
void keepForward() {
    digitalWrite(pinLeftMotor1, 1);
    digitalWrite(pinLeftMotor2, 0);
    digitalWrite(pinRightMotor1, 1);
    digitalWrite(pinRightMotor2, 0);
}

void runForward() {
    keepForward();
    analogWrite(pinLeftMotorPWM, 255);
    analogWrite(pinRightMotorPWM, 255);
}

void stop() {
    digitalWrite(pinLeftMotor1, 0);
    digitalWrite(pinLeftMotor2, 0);
    digitalWrite(pinRightMotor1, 1);
    digitalWrite(pinRightMotor2, 1);
}

void turnLeft() {
    keepForward();
    analogWrite(pinLeftMotorPWM, 150);
    analogWrite(pinRightMotorPWM, 255);
}

void turnRight() {
    keepForward();
    analogWrite(pinLeftMotorPWM, 255);
    analogWrite(pinRightMotorPWM, 150);
}

void setup() {
    pinMode(pinLeftMotor1, OUTPUT);
    pinMode(pinLeftMotor2, OUTPUT);
    pinMode(pinRightMotor1, OUTPUT);
    pinMode(pinRightMotor2, OUTPUT);
}

void loop() { 
    /* Read from sensor */
    stateLeftSensor = digitalRead(pinLeftSensor);
    stateRightSensor = digitalRead(pinRightSensor);

    /* Correct the direction */
    if (stateLeftSensor == 0) {
        turnLeft();
        delayMicroseconds(2);
    }
    if (stateRightSensor == 0) {
        turnRight();
        delayMicroseconds(2);
    }

    /* Continue */
    runFoward(180);
    delay(2);
}