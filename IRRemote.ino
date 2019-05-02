

int PIN_DETECT =2;
int LED_PIN =3;
int PIN_START = 4;

int val;
int concescutive;
int start=0;

#include <Wire.h>
#include <Servo.h> 

#include <EEPROM.h>

Servo myservo;


void setup()
{
  
  Serial.begin(9600);
  
  pinMode(PIN_DETECT, INPUT);
  pinMode(LED_PIN, OUTPUT);
  pinMode(PIN_START, INPUT);
  pinMode(12, INPUT);
  
  myservo.attach(5);

}

void loop() {
      digitalWrite(LED_PIN, LOW);
      digitalWrite(12, LOW);
      
      
     if (digitalRead(PIN_START)==1)
     {

      digitalWrite(LED_PIN, HIGH);
            digitalWrite(12, HIGH);

      

     }



     val=digitalRead(PIN_DETECT);


     if(val==0){
      Serial.println("Activate");
      
      servo();
      
      


     }
     


     delay(100);
    
  
  
}



void servo() {

  
int pos=0;

          for(pos = 30; pos <= 180; pos += 5) // goes from 0 degrees to 180 degrees 
          {                                  // in steps of 1 degree 
            myservo.write(pos);              // tell servo to go to position in variable 'pos' 
            Serial.println(pos);
            delay(15);                       // waits 15ms for the servo to reach the position 
          } 

          for(pos = 180; pos >= 60; pos -= 5) // goes from 0 degrees to 180 degrees 
          {                                  // in steps of 1 degree 
            myservo.write(pos);              // tell servo to go to position in variable 'pos'
            Serial.println(pos);
            delay(15);                       // waits 15ms for the servo to reach the position 
          } 

         
        


          delay (3000);

          for(pos = 30; pos <= 180; pos += 5) // goes from 0 degrees to 180 degrees 
          {                                  // in steps of 1 degree 
            myservo.write(pos);              // tell servo to go to position in variable 'pos' 
            Serial.println(pos);
            delay(15);                       // waits 15ms for the servo to reach the position 
          } 

          for(pos = 180; pos >= 60; pos -= 5) // goes from 0 degrees to 180 degrees 
          {                                  // in steps of 1 degree 
            myservo.write(pos);              // tell servo to go to position in variable 'pos'
            Serial.println(pos);
            delay(15);                       // waits 15ms for the servo to reach the position 
          } 

         
        









}


