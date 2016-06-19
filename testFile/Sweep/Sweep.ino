#include <Servo.h>  
Servo servo1, servo2, servo3, servo4; 
Servo servo;
int pos = 0; 
void setup() 
{ 
  servo1.attach(2);
  servo2.attach(3);
  servo3.attach(4);
  servo4.attach(5);
  servo.attach(9);
}  
void loop() 
{ 
  for(pos = 0; pos <= 200; pos += 1)
  {
    servo1.write(pos);
    servo2.write(pos);
    servo3.write(pos);
    servo4.write(pos);
    servo.write(pos);
    //servo5.write(pos);
    delay(15);                       
  } 
  for(pos = 200; pos>=0; pos-=1)
  {       
    servo1.write(pos);
    servo2.write(pos);
    servo3.write(pos);
    servo4.write(pos);
    servo.write(pos);
    delay(15);                       
  }
} 


