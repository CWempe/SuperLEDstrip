/*
 * Functions and commands to use buttons for input
 */

Bounce debouncer01 = Bounce();

HomieNode button01Node("button01", "button");

int lastButton01Value = -1;


 void loopButtons() {

  //
  // Button01
  //
  #ifdef BUTTON01_PIN
    debouncer01.update();
    int button01Value = debouncer01.read();

    if (button01Value != lastButton01Value) {
        // set next 100er scene
        // on press or on release
        if ( button01Value == button01_event_on_press && button01_action ) {

          String sceneValue;
          uint16_t currentScene;
      
          // read value from eeprom
          Embedis::get("sceneValue", sceneValue);
          currentScene = sceneValue.toInt();
      
          switch (currentScene) {
            case 501:   // switch to rainbow
              setScene(101);
              break;
            case 101:   // switch to running palette
              setScene(111);
              break;
            case 111:   // switch to red
              setScene(503);
              break;
            case 503:   // switch to OrangeRed
              setScene(510);
              break;
            case 510:   // switch to magenta
              setScene(506);
              break;
            case 506:   // switch to blue
              setScene(505);
              break;
            case 505:   // switch to green
              setScene(504);
              break;


            default:   // default to white
              setScene(501);
              break;
          }
        }
      Homie.getLogger() << "Button01 is now " << (button01Value ? "pressed" : "unpressed") << endl;
      if ( !HOMIE_STANDALONE ) { button01Node.setProperty("pressed").send(button01Value ? "true" : "false"); };
      lastButton01Value = button01Value;
    }
  #endif
}


void HomieSetupButtons() {
  #ifdef BUTTON01_PIN
    pinMode(BUTTON01_PIN, INPUT);
    digitalWrite(BUTTON01_PIN, LOW);
    debouncer01.attach(BUTTON01_PIN);
    debouncer01.interval(50);
    button01Node.advertise("pressed");
  #endif
}