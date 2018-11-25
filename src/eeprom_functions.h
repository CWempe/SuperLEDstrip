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

void writeEeepromCustomColor() {
  // Write current custom color to Eeeprom
  Embedis::set("customColorRed", String(customColor.red));
  Embedis::set("customColorGreen", String(customColor.green));
  Embedis::set("customColorBlue", String(customColor.blue));

  if ( DEBUGLEVEL >= 1 ) {
    Homie.getLogger() << "[DEBUG1] WRITE: Custom Color: " << customColor.red << "," << customColor.green << "," << customColor.blue << endl;
  }
}

void readEeepromCustomColor() {
  String red;
  String green;
  String blue;
  
  // Read values from Eeeprom
  Embedis::get("customColorRed", red);
  Embedis::get("customColorGreen", green);
  Embedis::get("customColorBlue", blue);

  // set values
  updateCustomColorRed(red.toInt(), false);
  updateCustomColorGreen(green.toInt(), false);
  updateCustomColorBlue(blue.toInt(), true);
  
  if ( DEBUGLEVEL >= 1 ) {
    Homie.getLogger() << "[DEBUG1] READ: Custom Color: " << red.toInt() << "," << green.toInt() << "," << blue.toInt() << endl;
  }

}