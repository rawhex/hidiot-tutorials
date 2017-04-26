// setup runs once on boot:

const int ledPin = 1;
const int numberDelay = 2000; // Wait two seconds betwen random numbers
int waitOn = 500; // 0.5 Seconds
int waitOff = 500; // 0.5 Seconds
int blinks = 11; // Our initial number of blinks. If we see 11 blinks, we know something is wrong with our code
int i = 0; // A throwaway variable for our while loop

void setup() {                
  // Tell the ATTiny that we want to use pin 1 as an output
  pinMode(ledPin, OUTPUT); // Our LED is pin 1 and we're supplying electricity to it.
}

// loop runs forever and ever:
void loop() {
  blinks = random(1,11);

  for (i = 0; i < blinks; i++){
    digitalWrite(ledPin, HIGH); // Make the LED turn on
    delay(waitOn);  // wait
    digitalWrite(ledPin, LOW); // Make the LED turn off
    delay(waitOff);
  }
  
  delay(numberDelay); // Wait between numbers
}
