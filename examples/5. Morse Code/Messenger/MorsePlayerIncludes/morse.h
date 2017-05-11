#ifndef PIN
  #define PIN PB1
#endif

#ifndef WPM
  #define WPM 5
#endif

#define UNIT 60 / (WPM * 50) * 1000 // unit length

void on(){        // Turn the LED on

  #ifdef BEEP
    tone(PIN,550); // If our pin is connected to a piezo we can use tone()
  #endif
  #ifndef BEEP
    digitalWrite(PIN, HIGH);
  #endif
}

void off(){       // Turn the LED off
  #ifdef BEEP
   noTone(PIN); // turn off piezo
  #endif
  #ifndef BEEP
    digitalWrite(PIN, LOW);
  #endif
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

void sendSymbol(char *symbols){
  int i;
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



void morse(const char *message){
  int i = 0;
  int len = strlen(message);
  //unit = 60 / (WPM * 50) * 1000; // unit length
  for (i = 0; i < len; i++){
    sendCharacter(message[i]);
  }
  delay(UNIT*20);
}

