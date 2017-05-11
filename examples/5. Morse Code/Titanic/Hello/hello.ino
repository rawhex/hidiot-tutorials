#define UNIT 250 // Lets make time units 250 milliseconds long
#define LED 1    // Our LED is PB1

void on(){        // Turn the LED on
  digitalWrite(LED, HIGH);
}

void off(){       // Turn the LED off
  digitalWrite(LED, LOW);
}

void dit(){       // A dit (1 pulse of 1 time unit)
  on();
  delay(UNIT);
}

void dah(){      // A dah (1 pulse of 3 time units in length)
  on();
  delay(UNIT*3);
}

void nextSymbol(){ // The space between symbols
  off();
  delay(UNIT);
}

void nextLetter(){ // The space between letters
  off();
  delay(UNIT*3);
}

void nextWord(){ // The space between words
  off();
  delay(UNIT*7);
}

// setup starts once when you power on your HIDIOT:
void setup() {                
  // initialize the digital pin as an output.
  pinMode(LED, OUTPUT); // Tells the HIDIOT we want to use the pin to output a signal
}

// loop runs forever and ever:
void loop() {
  // Lets send the word "HELLO", or ".... . .-.. .-.. ---"
  // H
  dit();
  nextSymbol();
  dit();
  nextSymbol();
  dit();
  nextSymbol();
  dit();

  nextLetter();

  // E
  dit();

  nextLetter();

  // L
  dit();
  nextSymbol();
  dah();
  nextSymbol();
  dit();
  nextSymbol();
  dit();

  nextLetter();

  // L
  dit();
  nextSymbol();
  dah();
  nextSymbol();
  dit();
  nextSymbol();
  dit();

  nextLetter();

  // O
  dah();
  nextSymbol();
  dah();
  nextSymbol();
  dah();

  nextWord();
}
