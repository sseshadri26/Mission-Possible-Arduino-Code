// Example testing sketch for various DHT humidity/temperature sensors
// Written by ladyada, public domain

#include "DHT.h"

#define DHTPIN 2     // what digital pin we're connected to

// Uncomment whatever type you're using!
#define DHTTYPE DHT11   // DHT 11


#include <EEPROM.h>

#include <Wire.h>
#include <Servo.h> 
Servo myservo;
int count=0;


// Connect pin 1 (on the left) of the sensor to +5V
// NOTE: If using a board with 3.3V logic like an Arduino Due connect pin 1
// to 3.3V instead of 5V!
// Connect pin 2 of the sensor to whatever your DHTPIN is
// Connect pin 4 (on the right) of the sensor to GROUND
// Connect a 10K resistor from pin 2 (data) to pin 1 (power) of the sensor

// Initialize DHT sensor.
// Note that older versions of this library took an optional third parameter to
// tweak the timings for faster processors.  This parameter is no longer needed
// as the current DHT reading algorithm adjusts itself to work on faster procs.

float initial=20;

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);
  Serial.println("DHTxx test!");

  dht.begin();
  delay(2000);
  initial = dht.readTemperature();

  pinMode(12, OUTPUT);
  myservo.attach(5);
  
  
}

void loop() {
  // Wait a few seconds between measurements.

  delay(2000);

  // Reading temperature or humidity takes about 250 milliseconds!
  // Sensor readings may also be up to 2 seconds 'old' (its a very slow sensor)

  // Read temperature as Celsius (the default)
  float t = dht.readTemperature();
  
  if (count>32)
  {
    Serial.print("servo");

    servo();
  }
  
  count=count+1;
  Serial.print(count);


  // Check if any reads failed and exit early (to try again).
  if (isnan(t)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }




  Serial.print(t);
  Serial.print(" *C , vs ");
  Serial.println(initial);
  
  if (t<(initial) )
    {
    
       servo();
       initial=initial-1;
        
  

  }
}



void servo(){

  
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



  


