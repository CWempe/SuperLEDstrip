/*
 * Functions and commands to use buttons for input
 */

Bounce debouncer01 = Bounce();
Bounce debouncer02 = Bounce();
Bounce debouncer03 = Bounce();
Bounce debouncer04 = Bounce();
Bounce debouncer05 = Bounce();

HomieNode button01Node("button01", "button");
HomieNode button02Node("button02", "button");
HomieNode button03Node("button03", "button");
HomieNode button04Node("button04", "button");
HomieNode button05Node("button05", "button");

int lastButton01Value = -1;
int lastButton02Value = -1;
int lastButton03Value = -1;
int lastButton04Value = -1;
int lastButton05Value = -1;


void loopButtons() {
  // Button01
  debouncer01.update();
  int button01Value = debouncer01.read();
  if (button01Value != lastButton01Value) {
    // set next 100er scene
    if ( button01Value ) { setScene(100); } ;
    Homie.getLogger() << "Button01 is now " << (button01Value ? "pressed" : "unpressed") << endl;
    if ( !HOMIE_STANDALONE ) { button01Node.setProperty("pressed").send(button01Value ? "true" : "false"); };
    lastButton01Value = button01Value;
  }

  // Button02
  debouncer02.update();
  int button02Value = debouncer02.read();
  if (button02Value != lastButton02Value) {
    // set next 200er scene
    if ( button02Value ) { setScene(200); } ;
    Homie.getLogger() << "Button02 is now " << (button02Value ? "pressed" : "unpressed") << endl;
    if ( !HOMIE_STANDALONE ) { button02Node.setProperty("pressed").send(button02Value ? "true" : "false"); };
    lastButton02Value = button02Value;
  }

  // Button03
  debouncer03.update();
  int button03Value = debouncer03.read();
  if (button03Value != lastButton03Value) {
    // set next 300er scene
    if ( button03Value ) { setScene(300); } ;
    Homie.getLogger() << "Button03 is now " << (button03Value ? "pressed" : "unpressed") << endl;
    if ( !HOMIE_STANDALONE ) { button03Node.setProperty("pressed").send(button03Value ? "true" : "false"); };
    lastButton03Value = button03Value;
  }
  
  // Button04
  debouncer04.update();
  int button04Value = debouncer04.read();
  if (button04Value != lastButton04Value) {
    // set next 500er scene
    if ( button04Value ) { 
      gCurrentPatternNumber = 3;
      setScene(500);
    }
    Homie.getLogger() << "Button04 is now " << (button04Value ? "pressed" : "unpressed") << endl;
    if ( !HOMIE_STANDALONE ) { button04Node.setProperty("pressed").send(button04Value ? "true" : "false"); };
    lastButton04Value = button04Value;
  }
  
  // Button05
  debouncer05.update();
  int button05Value = debouncer05.read();
  if (button05Value != lastButton05Value) {
    if ( button05Value ) {
      if ( currentScene != 601 ) {
        // set all leds to black
        leds(0, NUM_LEDS - 1) = CRGB::Black;
        setScene(601);
        arc_pulse();
      }
      // set Scene to arcade pulse and set first LED to random color
      leds[0] = CHSV( random8(255), 255, 255);
    } 
    Homie.getLogger() << "Button05 is now " << (button05Value ? "pressed" : "unpressed") << endl;
    if ( !HOMIE_STANDALONE ) { button04Node.setProperty("pressed").send(button05Value ? "true" : "false"); };
    lastButton05Value = button05Value;
  }
}


void HomieSetupButtons() {
  
  pinMode(BUTTON01_PIN, INPUT);
  pinMode(BUTTON02_PIN, INPUT);
  pinMode(BUTTON03_PIN, INPUT);
  pinMode(BUTTON04_PIN, INPUT);
  pinMode(BUTTON05_PIN, INPUT);
  digitalWrite(BUTTON01_PIN, LOW);
  digitalWrite(BUTTON02_PIN, LOW);
  digitalWrite(BUTTON03_PIN, LOW);
  digitalWrite(BUTTON04_PIN, LOW);
  digitalWrite(BUTTON05_PIN, LOW);
  debouncer01.attach(BUTTON01_PIN);
  debouncer02.attach(BUTTON02_PIN);
  debouncer03.attach(BUTTON03_PIN);
  debouncer04.attach(BUTTON04_PIN);
  debouncer05.attach(BUTTON05_PIN);
  debouncer01.interval(50);
  debouncer02.interval(50);
  debouncer03.interval(50);
  debouncer04.interval(50);
  debouncer05.interval(50);
  button01Node.advertise("pressed");
  button02Node.advertise("pressed");
  button03Node.advertise("pressed");
  button04Node.advertise("pressed");
  button05Node.advertise("pressed");
}

