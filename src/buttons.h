/*
 * Functions and commands to use buttons for input
 */

//
// Button01
//
#ifdef BUTTON01_PIN
  Bounce debouncer01 = Bounce();
  HomieNode button01Node("button01", "button");
  int lastButton01Value = -1;
  bool button01_do_scenes;
  int button01_do_length = -1;

  // Loop
  void loopButton01() {
    debouncer01.update();
    int button01Value = debouncer01.read();
    String sceneValue;
    uint16_t currentScene;


    if (button01Value != lastButton01Value) {
      // set next 100er scene
      // on press or on release
      if ( button01Value == button01_event_on_press && button01_action ) {

        if ( button01_do_scenes ) {
          // change scene
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
        } else {
          // change state of button(s)
          for (byte button_nr = 0; button_nr < button01_do_length; button_nr++) {
            if ( DEBUGLEVEL >= 1 ) Homie.getLogger() << "[DEBUG1] do something with output #: " << button01_do[button_nr] << endl;
            // toggle button
            switch (button01_do[button_nr]) {
              case 1:
                #ifdef OUTPUT01_PIN
                  updateOutput01on(String(!output01_on));
                #endif
                break;
              case 2:
                #ifdef OUTPUT02_PIN
                  updateOutput02on(String(!output02_on));
                #endif
                break;
              case 3:
                #ifdef OUTPUT03_PIN
                  updateOutput03on(String(!output03_on));
                #endif
                break;
              case 4:
                #ifdef OUTPUT04_PIN
                  updateOutput04on(String(!output04_on));
                #endif
                break;
            }
          }
        }
      }
      Homie.getLogger() << "Button01 is now " << (button01Value ? "pressed" : "unpressed") << endl;
      if ( !HOMIE_STANDALONE ) { button01Node.setProperty("pressed").send(button01Value ? "true" : "false"); };
      lastButton01Value = button01Value;
    }
  }

  // button01_switch
  void publishButton01switch() {
    if ( !HOMIE_STANDALONE ) button01Node.setProperty("switch").send(button01_switch ? "true" : "false");
  }

  void updateButton01switch(String value, bool write = true) {
    button01_switch = (value == "true" || value == String(true));
    if ( DEBUGLEVEL >= 1 ) Homie.getLogger() << "[DEBUG1] UPDATE: button01_switch: " << button01_switch << endl;
    publishButton01switch();
    if (write) writeEeepromButton01switch();
  }

  bool button01switchHandler(const HomieRange& range, const String& value) {
    if (value != "true" && value != "false") return false;
    updateButton01switch(value);
    return true;
  }

  // button01_event_on_press
  void publishButton01event_on_press() {
    if ( !HOMIE_STANDALONE ) button01Node.setProperty("event-on-press").send(button01_event_on_press ? "true" : "false");
  }

  void updateButton01event_on_press(String value, bool write = true) {
    button01_event_on_press = (value == "true" || value == String(true));
    if ( DEBUGLEVEL >= 1 ) Homie.getLogger() << "[DEBUG1] UPDATE: button01_event_on_press: " << button01_event_on_press << endl;
    publishButton01event_on_press();
    if (write) writeEeepromButton01eventOnPress();
  }

  bool button01event_on_pressHandler(const HomieRange& range, const String& value) {
    if (value != "true" && value != "false") return false;
    updateButton01event_on_press(value);
    return true;
  }

  // button01_action
  void publishButton01action() {
    if ( !HOMIE_STANDALONE ) button01Node.setProperty("action").send(button01_action ? "true" : "false");
  }

  void updateButton01action(String value, bool write = true) {
    button01_action = (value == "true" || value == String(true));
    if ( DEBUGLEVEL >= 1 ) Homie.getLogger() << "[DEBUG1] UPDATE: button01_action: " << button01_action << endl;
    publishButton01action();
    if (write) writeEeepromButton01action();
  }

  bool button01actionHandler(const HomieRange& range, const String& value) {
    if (value != "true" && value != "false") return false;
    updateButton01action(value);
    return true;
  }

  // Setup
  void HomieSetupButton01() {
    pinMode(BUTTON01_PIN, INPUT);
    digitalWrite(BUTTON01_PIN, LOW);
    debouncer01.attach(BUTTON01_PIN);
    debouncer01.interval(50);

    button01Node.advertise("pressed");
    button01Node.advertise("switch").settable(button01switchHandler);
    button01Node.advertise("event-on-press").settable(button01event_on_pressHandler);
    button01Node.advertise("action").settable(button01actionHandler);

    readEepromButton01switch();
    readEepromButton01eventOnPress();
    readEepromButton01action();

    // check is the defines array contains scenes or button numbers
    button01_do_scenes = (button01_do[0] >= 100);
    if ( DEBUGLEVEL >= 1 ) Homie.getLogger() << "[DEBUG1] button01_do_scenes: " << button01_do_scenes << endl;
    // get lenght or array
    button01_do_length = (sizeof(button01_do) / sizeof(button01_do[0]));
    if ( DEBUGLEVEL >= 1 ) Homie.getLogger() << "[DEBUG1] button01_do_length: " << button01_do_length << endl;
  }
#endif