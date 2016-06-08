const int leftMotor1 = 2;
const int leftMotor2 = 3;
const int rightMotor1 = 4;
const int rightMotor2 = 5;

void setup() {
	/*
	pinMode(leftMotor1, OUTPUT);
	pinMode(leftMotor2, OUTPUT);
	pinMode(rightMotor1, OUTPUT);
	pinMode(rightMotor2, OUTPUT);
	pinMode(10, OUTPUT);*/
	
}

void loop() {
	digitalWrite(leftMotor1, 1);
	digitalWrite(leftMotor2, 0);

	//digitalWrite(rightMotor1, 1);
	digitalWrite(rightMotor2, 0);
	
	for (int t = 0; t < 255; t++) {
		analogWrite(rightMotor1, t);
		delay(0.1);
	}
}