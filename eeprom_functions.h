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
