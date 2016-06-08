/* Motor pin */
const int leftMotor1 = 3;
const int leftMotor2 = 5;
const int rightMotor1 = 6;
const int rightMotor2 = 9;

/* sensor pin */
const int sensorPin = 10;

/* singal from sensor pin */
int sgn;

/* direction */
int positive = 1;
int negative = 0;

void setup() {
	Serial.begin(9600);
}

void loop() {
	int sgn = digitalRead(sensorPin);
	if (sgn == 0) {
		positive = 1;
		negative = 0;
	} else {
		positive = 0;
		negative = 1;
	}
	digitalWrite(leftMotor1, positive);
	digitalWrite(leftMotor2, negative);
	digitalWrite(rightMotor1, positive);
	digitalWrite(rightMotor2, negative);
	delay(100);
}
