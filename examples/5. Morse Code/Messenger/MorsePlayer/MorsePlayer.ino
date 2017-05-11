#define UNIT 250 // Lets make time units 250 milliseconds long
#define LED 1    // Our LED is PB1

const char *message = "What hath god wrought";

int len = strlen(message);
int i;


void on(){        // Turn the LED on
  digitalWrite(LED, HIGH);
}

void off(){       // Turn the LED off
  digitalWrite(LED, LOW);
}

void sendSymbol(char *symbols){
  int l = strlen(symbols);
  for (i = 0; i < l; i++){
    send(symbols[i]);
  }
}

void sendCharacter(int c){
  switch(toupper(c)){
    case ' ': sendSymbol(" /"); break;
    case 'A': sendSymbol(".-"); break;
    case 'B': sendSymbol("-..."); break;
    case 'C': sendSymbol("-.-."); break;
    case 'D': sendSymbol("-.."); break;
    case 'E': sendSymbol("."); break;
    case 'F': sendSymbol("..-."); break;
    case 'G': sendSymbol("--."); break;
    case 'H': sendSymbol("...."); break;
    case 'I': sendSymbol(".."); break;
    case 'J': sendSymbol(".---"); break;
    case 'K': sendSymbol("-.-"); break;
    case 'L': sendSymbol(".-.."); break;
    case 'M': sendSymbol("--"); break;
    case 'N': sendSymbol("-."); break;
    case 'O': sendSymbol("---"); break;
    case 'P': sendSymbol(".--."); break;
    case 'Q': sendSymbol("--.-"); break;
    case 'R': sendSymbol(".-."); break;
    case 'S': sendSymbol("..."); break;
    case 'T': sendSymbol("-"); break;
    case 'U': sendSymbol("..-"); break;
    case 'V': sendSymbol("...-"); break;
    case 'W': sendSymbol(".--"); break;
    case 'X': sendSymbol("-..-"); break;
    case 'Y': sendSymbol("-.--"); break;
    case 'Z': sendSymbol("--.."); break;
    case '1': sendSymbol(".----"); break;
    case '2': sendSymbol("..---"); break;
    case '3': sendSymbol("...--"); break;
    case '4': sendSymbol("....-"); break;
    case '5': sendSymbol("....."); break;
    case '6': sendSymbol("-...."); break;
    case '7': sendSymbol("--..."); break;
    case '8': sendSymbol("---.."); break;
    case '9': sendSymbol("----."); break;
    case '0': sendSymbol("-----"); break;
    case '.': sendSymbol(".-.-"); break;
    default: break;
  }
  send(' ');
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
    sendCharacter(message[i]);
  }
  delay(UNIT*20);
}
