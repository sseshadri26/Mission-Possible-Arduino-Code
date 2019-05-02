

#include <EEPROM.h>

#include <Wire.h>
#include <Servo.h> 
Servo myservo;

 
void setup()
{
  Serial.begin(9600);
  myservo.attach(5);
}
 
void loop()
{

  Serial.print("a");
  int pos=0;
   for(pos = 30; pos>=60; pos-=10)   
   {                                
     myservo.write(pos);           
     delay(15);
   }
 

  for(pos = 30; pos <= 180; pos += 3) // goes from 0 degrees to 180 degrees 
  {                                  // in steps of 1 degree 
    myservo.write(pos);              // tell servo to go to position in variable 'pos' 
    delay(15);                       // waits 15ms for the servo to reach the position 
  } 
  
  for(pos = 180; pos>=30; pos-=1)     // goes from 180 degrees to 0 degrees 
  {                                
    myservo.write(pos);              // tell servo to go to position in variable 'pos' 
    delay(15);                       // waits 15ms for the servo to reach the position 
  } 
}
