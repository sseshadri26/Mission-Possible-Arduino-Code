
// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin 16 as an output.
  pinMode(16, OUTPUT);
}

// the loop function runs over and over again forever
void loop() {
  char onOff = Serial.read();
  if (onOff=='1')
    digitalWrite(16, HIGH);   // turn the LED on (HIGH is the voltage level)
    Serial.write("on");
  if (onOff='0')
    digitalWrite(16, LOW);    // turn the LED off by making the voltage LOW
    Serial.write("off");
}
