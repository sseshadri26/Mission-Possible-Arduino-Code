
int electromagnetPin=13;
int startPin=4;
int staplePin=2;

int countdown=5;

void setup() {

  Serial.begin(9600);

  pinMode(electromagnetPin, OUTPUT);
  pinMode(startPin, INPUT);
  
  pinMode(staplePin, INPUT);

  Serial.begin(9600);
  
  digitalWrite(electromagnetPin, LOW);
  
  
}

void loop() {
  
     Serial.println(digitalRead(startPin));

   
delay(500);
   

   




 }


