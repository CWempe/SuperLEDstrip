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