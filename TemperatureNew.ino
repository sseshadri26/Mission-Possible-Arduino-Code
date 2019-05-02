#include <OneWire.h>
#include <DallasTemperature.h>
#include <Servo.h> 
 
// Which digital pin do you want the temp sensor in?? I've put 2. 
#define ONE_WIRE_BUS 2


// Setup a oneWire instance to communicate with any OneWire devices (not just temp sense, but it works)
OneWire oneWire(ONE_WIRE_BUS);
 
// Pass our oneWire reference to Dallas Temperature.
DallasTemperature sensors(&oneWire);

//new servo object
Servo myservo;
 
void setup()
{
  Serial.begin(9600);
  
  // Start up the library
  sensors.begin();

  //digital pin to put servo on?? ive put 5.
  myservo.attach(5);
}
 
 
void loop()
{
  // call this to issue a global temperature

  sensors.requestTemperatures(); 

  Serial.println(sensors.getTempCByIndex(0)); 
  //can handle more than 1 device, but we're using inly one so index 0

  //add conditions for if it dips below a certain value, call servo.
 
}
//you can change the values for the servo and all that

void servo(){

  
           int pos=0;
           
           for(pos = 30; pos>=60; pos-=10)   
           {                                
             myservo.write(pos);           
             delay(15);
           }
         
        
          for(pos = 30; pos <= 180; pos += 3) // goes from 30 degrees to 180 degrees 
          {                                  // in steps of 3 degree 
            myservo.write(pos);              // tell servo to go to position in variable 'pos' 
            delay(15);                       // waits 15ms for the servo to reach the position 
          } 
          
          for(pos = 180; pos>=30; pos-=1)     // goes from 180 degrees to 30 degrees 
          {                                
            myservo.write(pos);              // tell servo to go to position in variable 'pos' 
            delay(15);                       // waits 15ms for the servo to reach the position 
          }
          
          
}


