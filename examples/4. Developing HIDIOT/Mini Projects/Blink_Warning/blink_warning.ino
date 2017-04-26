// setup runs once on boot:

const int ledPin = 1;
int waitOn = 1000; // 1 Second
int waitOff = 500; // 0.5 Seconds

void setup() {                
  // Tell the ATTiny that we want to use pin 1 as an output
  pinMode(ledPin, OUTPUT); // Our LED is pin 1 and we're supplying electricity to it.
}

// loop runs forever and ever:
void loop() {
  digitalWrite(ledPin, HIGH); // Make the LED turn on
  delay(waitOn);               // wait
  if (waitOn > 0){
    waitOn = waitOn - 10;
	waitOff = waitOff - 5;
  }

  if (waitOn > 0){
    digitalWrite(ledPin, LOW ); // Make the LED turn off
    delay(waitOff);               // wait
  }
}
