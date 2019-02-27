/*
 * Functions and commands to use buttons for input
 */

Bounce debouncer01 = Bounce();

HomieNode button01Node("button01", "button");

int lastButton01Value = -1;


 void loopButtons() {
  // Button01
  debouncer01.update();
  int button01Value = debouncer01.read();
  if (button01Value != lastButton01Value) {
    // set next 100er scene
    if ( button01Value ) {

      String sceneValue;
      uint16_t currentScene;
  
      // read value from eeprom
      Embedis::get("sceneValue", sceneValue);
      currentScene = sceneValue.toInt();
  
      switch (currentScene) {
        case 501:   // white to rainbow
          setScene(101);
          break;
        case 101:   // white to rainbow
          setScene(501);
          break;
      }
    }

    Homie.getLogger() << "Button01 is now " << (button01Value ? "pressed" : "unpressed") << endl;
    if ( !HOMIE_STANDALONE ) { button01Node.setProperty("pressed").send(button01Value ? "true" : "false"); };
    lastButton01Value = button01Value;
  }
}


 void HomieSetupButtons() {

  pinMode(BUTTON01_PIN, INPUT);
  digitalWrite(BUTTON01_PIN, LOW);
  debouncer01.attach(BUTTON01_PIN);
  debouncer01.interval(50);
  button01Node.advertise("pressed");
}