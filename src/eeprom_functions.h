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
  if (Homie.isConnected()) lightNode.setProperty("scene").send(String(scene));
    
  if ( DEBUGLEVEL >= 1 ) Homie.getLogger() << "[DEBUG1] READ: Scene: " << scene << endl;
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
  if (Homie.isConnected()) lightNode.setProperty("palette").send(String(palette));
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
  
  if ( DEBUGLEVEL >= 1 ) Homie.getLogger() << "[DEBUG1] READ: Custom Color: " << red.toInt() << "," << green.toInt() << "," << blue.toInt() << endl;
}













//
// lightsaber color
//

void writeEeepromLightsaberColor(uint8_t preset = 0) {  
  String FileRed = "lightsaberColorRed";
  String FileGreen = "lightsaberColorGreen";
  String FileBlue = "lightsaberColorBlue";

  // Use other file names if function is called with preset > 0
  if ( preset > 0 ) {
    FileRed   = "lightsaberColorRed" + preset;
    FileGreen = "lightsaberColorGreen" + preset;
    FileBlue  = "lightsaberColorBlue" + preset;
  }

  if ( DEBUGLEVEL >= 1 ) {
    Homie.getLogger() << "[DEBUG1] WRITE: FileRed: " << FileRed << endl;
    Homie.getLogger() << "[DEBUG1] WRITE: FileGreen: " << FileGreen << endl;
    Homie.getLogger() << "[DEBUG1] WRITE: FileBlue: " << FileBlue << endl;
  }
  // Write current custom color to Eeeprom
  Embedis::set(FileRed, String(lightsaber_color_current.red));
  Embedis::set(FileGreen, String(lightsaber_color_current.green));
  Embedis::set(FileBlue, String(lightsaber_color_current.blue));

  if ( DEBUGLEVEL >= 1 ) {
    Homie.getLogger() << "[DEBUG1] WRITE: Lightsaber Color: " << lightsaber_color_current.red << "," << lightsaber_color_current.green << "," << lightsaber_color_current.blue << endl;
  }
}

void readEeepromLightsaberColor(uint8_t preset = 0) {
  String red;
  String green;
  String blue;
  
  String FileRed = "lightsaberColorRed";
  String FileGreen = "lightsaberColorGreen";
  String FileBlue = "lightsaberColorBlue";

  // Use other file names if function is called with preset > 0
  if ( preset > 0 ) {
    FileRed   = "lightsaberColorRed" + preset;
    FileGreen = "lightsaberColorGreen" + preset;
    FileBlue  = "lightsaberColorBlue" + preset;
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
  lightsaber_color_current = CRGB(red.toInt(), green.toInt(), blue.toInt());
  lightsaber_color_target = lightsaber_color_current;

  if ( DEBUGLEVEL >= 1 ) Homie.getLogger() << "[DEBUG1] READ: Lightsaber Color: " << red.toInt() << "," << green.toInt() << "," << blue.toInt() << endl;
}











//
// Buttons
//
#ifdef BUTTON01_PIN
  // button01_switch
  void writeEeepromButton01switch() {
    Embedis::set("button01_switch", String(button01_switch));
    if ( DEBUGLEVEL >= 1 ) Homie.getLogger() << "[DEBUG1] WRITE:  button01_switch: " << button01_switch << endl;
  }

  void readEepromButton01switch() {
    String StrButton01_switch;
    // read value from eeprom
    Embedis::get("button01_switch", StrButton01_switch);
    if ( DEBUGLEVEL >= 1 ) Homie.getLogger() << "[DEBUG1] READ:   StrButton01_switch: " << StrButton01_switch << endl;
    updateButton01switch(StrButton01_switch, false);
  }

  // button01_event_on_press
  void writeEeepromButton01eventOnPress() {
    Embedis::set("button01_event_on_press", String(button01_event_on_press));
    if ( DEBUGLEVEL >= 1 ) Homie.getLogger() << "[DEBUG1] WRITE:  button01_event_on_press: " << button01_event_on_press << endl;
  }

  void readEepromButton01eventOnPress() {
    String StrButton01_event_on_press;
    // read value from eeprom
    Embedis::get("button01_event_on_press", StrButton01_event_on_press);
    if ( DEBUGLEVEL >= 1 ) Homie.getLogger() << "[DEBUG1] READ:   StrButton01_event_on_press: " << StrButton01_event_on_press << endl;
    updateButton01event_on_press(StrButton01_event_on_press, false);
  }

  // button01_action
  void writeEeepromButton01action() {
    Embedis::set("button01_action", String(button01_action));
    if ( DEBUGLEVEL >= 1 ) Homie.getLogger() << "[DEBUG1] WRITE:  button01_action: " << button01_action << endl;
  }

  void readEepromButton01action() {
    String StrButton01_action;
    // read value from eeprom
    Embedis::get("button01_action", StrButton01_action);
    if ( DEBUGLEVEL >= 1 ) Homie.getLogger() << "[DEBUG1] READ:   StrButton01_action: " << StrButton01_action << endl;
    updateButton01action(StrButton01_action, false);
  }
#endif

//
// Output01
//
#ifdef OUTPUT01_PIN
  // output01_on
  void writeEeepromOutput01on() {
    Embedis::set("output01_on", String(output01_on));
    if ( DEBUGLEVEL >= 1 ) Homie.getLogger() << "[DEBUG1] WRITE:  output01_on: " << output01_on << endl;
  }

  void readEepromOutput01on() {
    String StrOutput01_on;
    // read value from eeprom
    Embedis::get("output01_on", StrOutput01_on);
    if ( DEBUGLEVEL >= 1 ) Homie.getLogger() << "[DEBUG1] READ:   StrOutput01_on: " << StrOutput01_on << endl;
    updateOutput01on(StrOutput01_on, false);
  }

  // output01_invert
  void writeEeepromOutput01invert() {
    if ( DEBUGLEVEL >= 1 ) Homie.getLogger() << "[DEBUG1] WRITE:  output01_invert: " << output01_invert << endl;
    Embedis::set("output01_invert", String(output01_invert));
  }

  void readEepromOutput01invert() {
    String StrOutput01_invert;
    // read value from eeprom
    Embedis::get("output01_invert", StrOutput01_invert);
    if ( DEBUGLEVEL >= 1 ) Homie.getLogger() << "[DEBUG1] READ:   StrOutput01_invert: " << StrOutput01_invert << endl;
    updateOutput01invert(StrOutput01_invert, false);
  }
#endif

//
// Output02
//
#ifdef OUTPUT02_PIN
  // output02_on
  void writeEeepromOutput02on() {
    Embedis::set("output02_on", String(output02_on));
    if ( DEBUGLEVEL >= 1 ) Homie.getLogger() << "[DEBUG1] WRITE:  output02_on: " << output02_on << endl;
  }

  void readEepromOutput02on() {
    String StrOutput02_on;
    // read value from eeprom
    Embedis::get("output02_on", StrOutput02_on);
    if ( DEBUGLEVEL >= 1 ) Homie.getLogger() << "[DEBUG1] READ:   StrOutput02_on: " << StrOutput02_on << endl;
    updateOutput02on(StrOutput02_on, false);
  }

  // output02_invert
  void writeEeepromOutput02invert() {
    if ( DEBUGLEVEL >= 1 ) Homie.getLogger() << "[DEBUG1] WRITE:  output02_invert: " << output02_invert << endl;
    Embedis::set("output02_invert", String(output02_invert));
  }

  void readEepromOutput02invert() {
    String StrOutput02_invert;
    // read value from eeprom
    Embedis::get("output02_invert", StrOutput02_invert);
    if ( DEBUGLEVEL >= 1 ) Homie.getLogger() << "[DEBUG1] READ:   StrOutput02_invert: " << StrOutput02_invert << endl;
    updateOutput02invert(StrOutput02_invert, false);
  }
#endif

//
// Output03
//
#ifdef OUTPUT03_PIN
  // output03_on
  void writeEeepromOutput03on() {
    Embedis::set("output03_on", String(output03_on));
    if ( DEBUGLEVEL >= 1 ) Homie.getLogger() << "[DEBUG1] WRITE:  output03_on: " << output03_on << endl;
  }

  void readEepromOutput03on() {
    String StrOutput03_on;
    // read value from eeprom
    Embedis::get("output03_on", StrOutput03_on);
    if ( DEBUGLEVEL >= 1 ) Homie.getLogger() << "[DEBUG1] READ:   StrOutput03_on: " << StrOutput03_on << endl;
    updateOutput03on(StrOutput03_on, false);
  }

  // output03_invert
  void writeEeepromOutput03invert() {
    if ( DEBUGLEVEL >= 1 ) Homie.getLogger() << "[DEBUG1] WRITE:  output03_invert: " << output03_invert << endl;
    Embedis::set("output03_invert", String(output03_invert));
  }

  void readEepromOutput03invert() {
    String StrOutput03_invert;
    // read value from eeprom
    Embedis::get("output03_invert", StrOutput03_invert);
    if ( DEBUGLEVEL >= 1 ) Homie.getLogger() << "[DEBUG1] READ:   StrOutput03_invert: " << StrOutput03_invert << endl;
    updateOutput03invert(StrOutput03_invert, false);
  }
#endif

//
// Output04
//
#ifdef OUTPUT04_PIN
  // output04_on
  void writeEeepromOutput04on() {
    Embedis::set("output04_on", String(output04_on));
    if ( DEBUGLEVEL >= 1 ) Homie.getLogger() << "[DEBUG1] WRITE:  output04_on: " << output04_on << endl;
  }

  void readEepromOutput04on() {
    String StrOutput04_on;
    // read value from eeprom
    Embedis::get("output04_on", StrOutput04_on);
    if ( DEBUGLEVEL >= 1 ) Homie.getLogger() << "[DEBUG1] READ:   StrOutput04_on: " << StrOutput04_on << endl;
    updateOutput04on(StrOutput04_on, false);
  }

  // output04_invert
  void writeEeepromOutput04invert() {
    if ( DEBUGLEVEL >= 1 ) Homie.getLogger() << "[DEBUG1] WRITE:  output04_invert: " << output04_invert << endl;
    Embedis::set("output04_invert", String(output04_invert));
  }

  void readEepromOutput04invert() {
    String StrOutput04_invert;
    // read value from eeprom
    Embedis::get("output04_invert", StrOutput04_invert);
    if ( DEBUGLEVEL >= 1 ) Homie.getLogger() << "[DEBUG1] READ:   StrOutput04_invert: " << StrOutput04_invert << endl;
    updateOutput04invert(StrOutput04_invert, false);
  }
#endif
