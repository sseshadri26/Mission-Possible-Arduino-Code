
#include <EEPROM.h>

#include <Wire.h>



int photocellPin = A0;

int photocellVal = 0;

int previousBrightness=0;





void setup() {

  Serial.begin(9600);

  pinMode(photocellPin, INPUT);
  pinMode(12, OUTPUT);




  Serial.begin(9600);

  previousBrightness = analogRead(photocellPin);// read the analog from photocell
  
}

void loop() {
  digitalWrite(12, LOW);

  int photocellVal = analogRead(photocellPin);// read the analog from photocell


  Serial.print(photocellVal);
  Serial.print("      ");
  Serial.println(photocellVal-previousBrightness);
  

  if (previousBrightness==0) {
    Serial.println("404");
  }
  
  if (photocellVal-previousBrightness>100) {
    Serial.print(photocellVal-previousBrightness);
    Serial.println("                 Activate next");
    int counter=0;
    while (counter<2)
    {
    digitalWrite(12, HIGH);
    delay(2000);
    digitalWrite(12, LOW);
    delay(4000);
    counter++;
    }
    
  }


  previousBrightness = photocellVal;
  delay(500);
  



 }









