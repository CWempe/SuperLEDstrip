void setupEeprom() {
  EEPROM.begin(SPI_FLASH_SEC_SIZE);
  Embedis::dictionary( F("EEPROM"),
      SPI_FLASH_SEC_SIZE,
      [](size_t pos) -> char { return EEPROM.read(pos); },
      [](size_t pos, char value) { EEPROM.write(pos, value); },
      []() { EEPROM.commit(); }
  );
}

void readEepromScene() {
  String sceneValue;
  uint16_t scene;

  // read value from eeprom
  Embedis::get("sceneValue", sceneValue);

  if ( sceneValue == "" ) {
    // set to DEFAULT_SCENE if no value was stored
    scene = DEFAULT_SCENE;
  } else {
  // set Scene to the Number that was read from the eeprom
    scene = sceneValue.toInt();
  }
  setScene(scene);

  // publish loaded scene via mqtt
  lightNode.setProperty("scene").send(String(scene));
}

void readEepromPalette() {
  String paletteValue;
  uint8_t palette;

  // read value from eeprom
  Embedis::get("paletteValue", paletteValue);

  if ( paletteValue == "" ) {
    // set to DEFAULT_SCENE if no value was stored
    palette = DEFAULT_PALETTE;
  } else {
  // set Scene to the Number that was read from the eeprom
    palette = paletteValue.toInt();
  }
  setPalette(palette);

  // publish loaded scene via mqtt
  lightNode.setProperty("palette").send(String(palette));
}

void readEepromBrightness() {
  String brightnessValue;
  // read value from eeprom
  Embedis::get("brightnessValue", brightnessValue);

  if ( brightnessValue == "" ) {
    // set to DEFAULT_BRIGHTNESS if no value was stored
    setBrightness(DEFAULT_BRIGHTNESS);
  } else {
  // set Brightness to the Number that was read from the eeprom
    setBrightness(brightnessValue.toInt());
  }
}

void readEepromTempo() {
  String tempoValue;
  // read value from eeprom
  Embedis::get("tempoValue", tempoValue);

  if ( tempoValue == "" ) {
    // set to DEFAULT_TEMPO if no value was stored
    setTempo(DEFAULT_TEMPO);
  } else {
  // set Tempo to the Number that was read from the eeprom
    setTempo(tempoValue.toInt());
  }
}

void readEepromRotationSpeed() {
  String rotationSpeedValue;
  // read value from eeprom
  Embedis::get("rotationSpeedValue", rotationSpeedValue);

  if ( rotationSpeedValue == "" ) {
    // set to DEFAULT_ROTATION_SPEED if no value was stored
    setRotationSpeed(DEFAULT_ROTATION_SPEED);
  } else {
  // set RotationSpeed to the Number that was read from the eeprom
    setRotationSpeed(rotationSpeedValue.toInt());
  }
}

void readEepromPaletteSize() {
  String paletteSizeValue;
  // read value from eeprom
  Embedis::get("paletteSizeValue", paletteSizeValue);

  if ( paletteSizeValue == "" ) {
    // set to DEFAULT_ROTATION_SPEED if no value was stored
    setPaletteSize(DEFAULT_PALETTESIZE);
  } else {
  // set paletteSize to the Number that was read from the eeprom
    setPaletteSize(paletteSizeValue.toInt());
  }
}

//
// custom color
//

void writeEeepromCustomColor(uint8_t preset = 0) {  
  String FileRed = "customColorRed";
  String FileGreen = "customColorGreen";
  String FileBlue = "customColorBlue";

  // Use other file names if function is called with preset > 0
  if ( preset > 0 ) {
    FileRed   = "customColorRed" + preset;
    FileGreen = "customColorGreen" + preset;
    FileBlue  = "customColorBlue" + preset;
  }

  if ( DEBUGLEVEL >= 1 ) {
    Homie.getLogger() << "[DEBUG1] WRITE: FileRed: " << FileRed << endl;
    Homie.getLogger() << "[DEBUG1] WRITE: FileGreen: " << FileGreen << endl;
    Homie.getLogger() << "[DEBUG1] WRITE: FileBlue: " << FileBlue << endl;
  }
  // Write current custom color to Eeeprom
  Embedis::set(FileRed, String(customColor.red));
  Embedis::set(FileGreen, String(customColor.green));
  Embedis::set(FileBlue, String(customColor.blue));

  if ( DEBUGLEVEL >= 1 ) {
    Homie.getLogger() << "[DEBUG1] WRITE: Custom Color: " << customColor.red << "," << customColor.green << "," << customColor.blue << endl;
  }
}

void readEeepromCustomColor(uint8_t preset = 0) {
  String red;
  String green;
  String blue;
  
  String FileRed = "customColorRed";
  String FileGreen = "customColorGreen";
  String FileBlue = "customColorBlue";

  // Use other file names if function is called with preset > 0
  if ( preset > 0 ) {
    FileRed   = "customColorRed" + preset;
    FileGreen = "customColorGreen" + preset;
    FileBlue  = "customColorBlue" + preset;
  }

  if ( DEBUGLEVEL >= 1 ) {
    Homie.getLogger() << "[DEBUG1] READ: FileRed: " << FileRed << endl;
    Homie.getLogger() << "[DEBUG1] READ: FileGreen: " << FileGreen << endl;
    Homie.getLogger() << "[DEBUG1] READ: FileBlue: " << FileBlue << endl;
  }

  // Read values from Eeeprom
  Embedis::get(FileRed, red);
  Embedis::get(FileGreen, green);
  Embedis::get(FileBlue, blue);

  // set values
  updateCustomColorRed(red.toInt(), false);
  updateCustomColorGreen(green.toInt(), false);
  updateCustomColorBlue(blue.toInt(), true);
  
  if ( DEBUGLEVEL >= 1 ) {
    Homie.getLogger() << "[DEBUG1] READ: Custom Color: " << red.toInt() << "," << green.toInt() << "," << blue.toInt() << endl;
  }
}


//
// Buttons
//
#ifdef BUTTON01_PIN
  // button01_switch
  void writeEeepromButton01switch() {
    if ( DEBUGLEVEL >= 1 ) {
      Homie.getLogger() << "[DEBUG1] WRITE: button01_switch: " << button01_switch << endl;
    }
    Embedis::set("button01_switch", String(button01_switch));
  }

  void readEepromButton01switch() {
    String StrButton01_switch;
    // read value from eeprom
    Embedis::get("button01_switch", StrButton01_switch);

    if ( StrButton01_switch == String(true) ) {
      button01_switch = true;
    } else {
      button01_switch = false;
    }
    if ( DEBUGLEVEL >= 1 ) {
      Homie.getLogger() << "[DEBUG1] READ: button01_switch: " << button01_switch << endl;
      Homie.getLogger() << "[DEBUG1] READ: StrButton01_switch: " << StrButton01_switch << endl;
    }
  }

  // button01_event_on_press
  void writeEeepromButton01eventOnPress() {
    if ( DEBUGLEVEL >= 1 ) {
      Homie.getLogger() << "[DEBUG1] WRITE: button01_event_on_press: " << button01_event_on_press << endl;
    }
    Embedis::set("button01_event_on_press", String(button01_event_on_press));
  }

  void readEepromButton01eventOnPress() {
    String StrButton01_event_on_press;
    // read value from eeprom
    Embedis::get("button01_event_on_press", StrButton01_event_on_press);

    if ( StrButton01_event_on_press == String(true) ) {
      button01_event_on_press = true;
    } else {
      button01_event_on_press = false;
    }
    if ( DEBUGLEVEL >= 1 ) {
      Homie.getLogger() << "[DEBUG1] READ: button01_event_on_press: " << button01_event_on_press << endl;
      Homie.getLogger() << "[DEBUG1] READ: StrButton01_event_on_press: " << StrButton01_event_on_press << endl;
    }
  }

  // button01_action
  void writeEeepromButton01action() {
    if ( DEBUGLEVEL >= 1 ) {
      Homie.getLogger() << "[DEBUG1] WRITE: button01_action: " << button01_action << endl;
    }
    Embedis::set("button01_action", String(button01_action));
  }

  void readEepromButton01action() {
    String StrButton01_action;
    // read value from eeprom
    Embedis::get("button01_action", StrButton01_action);

    if ( StrButton01_action == String(true) ) {
      button01_action = true;
    } else {
      button01_action = false;
    }
    if ( DEBUGLEVEL >= 1 ) {
      Homie.getLogger() << "[DEBUG1] READ: button01_action: " << button01_action << endl;
    }
  }
#endif

//
// Output01
//
#ifdef OUTPUT01_PIN
  // output01_on
  void writeEeepromOutput01on() {
    String StrButton01_on;
    Embedis::set("output01_on", String(output01_on));
    if ( DEBUGLEVEL >= 1 ) {
      Homie.getLogger() << "[DEBUG1] WRITE: output01_on: " << output01_on << endl;
    }
  }

  void readEepromOutput01on() {
    String StrOutput01_on;
    // read value from eeprom
    Embedis::get("output01_on", StrOutput01_on);
    updateOutput01on(StrOutput01_on, false);
    if ( DEBUGLEVEL >= 1 ) {
      Homie.getLogger() << "[DEBUG1] READ: output01_on: " << output01_on << endl;
    }
  }

  // output01_invert
  void writeEeepromOutput01invert() {
    if ( DEBUGLEVEL >= 1 ) {
      Homie.getLogger() << "[DEBUG1] WRITE: output01_invert: " << output01_invert << endl;
    }
    Embedis::set("output01_invert", String(output01_invert));
  }

  void readEepromOutput01invert() {
    String StrOutput01_invert;
    // read value from eeprom
    Embedis::get("output01_invert", StrOutput01_invert);
    updateOutput01invert(StrOutput01_invert, false);
    if ( DEBUGLEVEL >= 1 ) {
      Homie.getLogger() << "[DEBUG1] READ: output01_invert: " << output01_invert << endl;
    }
  }
#endif