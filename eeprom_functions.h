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
  // read value from eeprom
  Embedis::get("sceneValue", sceneValue);

  if ( sceneValue == "" ) {
    // set to DEFAULT_SCENE if no value was stored
    setScene(DEFAULT_SCENE);
  } else {
  // set Scene to the Number that was read from the eeprom
    setScene(sceneValue.toInt());
  }
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
