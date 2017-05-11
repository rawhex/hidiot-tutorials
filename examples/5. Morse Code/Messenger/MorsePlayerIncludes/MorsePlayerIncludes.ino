ls#include "morse.h"

const char *message = "What hath god wrought";

void setup() {                
  // initialize the digital pin as an output.
  pinMode(PIN, OUTPUT); // Tells the HIDIOT we want to use the pin to output a signal
}

void loop() {
  // put your main code here, to run repeatedly:
  morse(message);
}
