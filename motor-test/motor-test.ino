const int leftMotor1 = 2;
const int leftMotor2 = 3;
const int pwm = 6;
//const int rightMotor1 = 5;
//const int rightMotor2 = 6;

void setup() {
	pinMode(leftMotor1, OUTPUT);
	pinMode(leftMotor2, OUTPUT);
}

void loop() {
	digitalWrite(leftMotor1, 1);
	digitalWrite(leftMotor2, 0);
        analogWrite(pwm, 255);
	//analogWrite(rightMotor1, 100);
	//digitalWrite(rightMotor2, 0);
}
