#include <avr/pgmspace.h>

#define UNIT 250 // Lets make time units 250 milliseconds long
#define LED 1    // Our LED is PB1

/* This message was sent on 14th April at 02:15 from MGY 
 * This was the final full message sent from the Titanic.
 * One "CQ" was sent after this, but stopped abruptly.
 */

const char *message = "... --- ... / ... --- ... / -.-. --.- -.. / -.-. --.- -.. / -- --. -.-- .-.-.- / .-- . / .- .-. . / ... .. -. -.- .. -. --. / ..-. .- ... - .-.-.- / .--. .- ... ... . -. --. . .-. ... / .- .-. . / -... . .. -. --. / .--. ..- - / .. -. - --- / -... --- .- - ... .-.-.- / -- --. -.-- .-.-.-";

int len = strlen(message);
int i;


void on(){        // Turn the LED on
  digitalWrite(LED, HIGH);
}

void off(){       // Turn the LED off
  digitalWrite(LED, LOW);
}

void send(char c){
  switch (c){
    case '-':
      on();
      delay(UNIT*3);
      off();
      break;
    case '.':
      on();
      delay(UNIT);
      off();
      break;
    case ' ':
      delay(UNIT*3);
      break;
    case '/':
      delay(UNIT);
      break;
    default:
      // If nothing else matches, do this (nothing)
    break;
  }
}

void setup() {                
  // initialize the digital pin as an output.
  pinMode(LED, OUTPUT); // Tells the HIDIOT we want to use the pin to output a signal
}

void loop() {
  // put your main code here, to run repeatedly:
  for (i = 0; i < len; i++){
    send(message[i]);
  }
  delay(UNIT*21);
}
