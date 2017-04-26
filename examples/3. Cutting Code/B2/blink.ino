// setup runs once on boot:
void setup() {                
  // Tell the ATTiny that we want to use pin 1 as an output
  pinMode(1, OUTPUT); // Our LED is pin 1 and we're supplying electricity to it.
}

// loop runs forever and ever:
void loop() {
  digitalWrite(1, HIGH); // Make the LED turn on
  delay(1000);               // wait 1 second
  digitalWrite(1, LOW ); // Make the LED turn off
  delay(1000);               // wait 1 second
}
