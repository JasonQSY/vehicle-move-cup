#include <Servo.h>  

Servo servo;

void setup() 
{ 
  servo.attach(11);
}  
void loop() 
{ 
  servo.writeMicroseconds(2000);
} 


