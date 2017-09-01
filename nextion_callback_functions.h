// Nextion components functions
// global
// page 1
void titlePopCallback(void *ptr) { }
void tempPopCallback(void *ptr) { }
void humidPopCallback(void *ptr) { }
void p01PopCallback(void *ptr) { }
void p01titlePopCallback(void *ptr) { }
void p01tempPopCallback(void *ptr) { }
void p01humidPopCallback(void *ptr) { }
void p01settingsPopCallback(void *ptr) { setTextAllSensors(); }
void p01powerPopCallback(void *ptr) { toggleBrightness(); }
void p01t01PopCallback(void *ptr) { updateTab(); }
void p01t02PopCallback(void *ptr) { updateTab(); }
void p01t03PopCallback(void *ptr) { updateTab(); }
void p01t04PopCallback(void *ptr) { updateTab(); }
void p01t05PopCallback(void *ptr) { updateTab(); }
void p01t06PopCallback(void *ptr) { updateTab(); }
void p01t07PopCallback(void *ptr) { updateTab(); }
void p01c01PopCallback(void *ptr) { gCurrentPatternNumber = 3; }
void p01c02PopCallback(void *ptr) { gCurrentPatternNumber = 1; }
void p01c03PopCallback(void *ptr) { gCurrentPatternNumber = 2; }
void p01c04PopCallback(void *ptr) { gCurrentPatternNumber = 4; }
void p01c05PopCallback(void *ptr) { gCurrentPatternNumber = 8; }
void p01c06PopCallback(void *ptr) { gCurrentPatternNumber = 9; }
void p01c07PopCallback(void *ptr) { }
void p01c08PopCallback(void *ptr) { }
// page 2
void p02PopCallback(void *ptr) { }
void p02titlePopCallback(void *ptr) { }
void p02tempPopCallback(void *ptr) { }
void p02humidPopCallback(void *ptr) { }
void p02settingsPopCallback(void *ptr) { setTextAllSensors(); }
void p02powerPopCallback(void *ptr) { toggleBrightness(); }
void p02t01PopCallback(void *ptr) { updateTab(); }
void p02t02PopCallback(void *ptr) { updateTab(); }
void p02t03PopCallback(void *ptr) { updateTab(); }
void p02t04PopCallback(void *ptr) { updateTab(); }
void p02t05PopCallback(void *ptr) { updateTab(); }
void p02t06PopCallback(void *ptr) { updateTab(); }
void p02t07PopCallback(void *ptr) { updateTab(); }
void p02c01PopCallback(void *ptr) { setupFlashingLights(CRGB::Blue, CRGB::Blue); }
void p02c02PopCallback(void *ptr) { setupFlashingLights(CRGB::Blue, CRGB::Red); }
void p02c03PopCallback(void *ptr) { setupFlashingLights(CRGB::OrangeRed, CRGB::OrangeRed); }
void p02c04PopCallback(void *ptr) { gCurrentPatternNumber = 5; }
void p02c05PopCallback(void *ptr) { }
void p02c06PopCallback(void *ptr) { }
void p02c07PopCallback(void *ptr) { }
void p02c08PopCallback(void *ptr) { }
// page 3
void p03PopCallback(void *ptr) { }
void p03titlePopCallback(void *ptr) { }
void p03tempPopCallback(void *ptr) { }
void p03humidPopCallback(void *ptr) { }
void p03settingsPopCallback(void *ptr) { setTextAllSensors(); }
void p03powerPopCallback(void *ptr) { toggleBrightness(); }
void p03t01PopCallback(void *ptr) { updateTab(); }
void p03t02PopCallback(void *ptr) { updateTab(); }
void p03t03PopCallback(void *ptr) { updateTab(); }
void p03t04PopCallback(void *ptr) { updateTab(); }
void p03t05PopCallback(void *ptr) { updateTab(); }
void p03t06PopCallback(void *ptr) { updateTab(); }
void p03t07PopCallback(void *ptr) { updateTab(); }
void p03c01PopCallback(void *ptr) { setupPaletteGermany(); }
void p03c02PopCallback(void *ptr) { setupPaletteItaly(); }
void p03c03PopCallback(void *ptr) { setupPaletteBrazil(); }
void p03c04PopCallback(void *ptr) { }
void p03c05PopCallback(void *ptr) { }
void p03c06PopCallback(void *ptr) { }
void p03c07PopCallback(void *ptr) { }
void p03c08PopCallback(void *ptr) { }
// page 4
void p04PopCallback(void *ptr) { }
void p04titlePopCallback(void *ptr) { }
void p04tempPopCallback(void *ptr) { }
void p04humidPopCallback(void *ptr) { }
void p04settingsPopCallback(void *ptr) { setTextAllSensors(); }
void p04powerPopCallback(void *ptr) { toggleBrightness(); }
void p04t01PopCallback(void *ptr) { updateTab(); }
void p04t02PopCallback(void *ptr) { updateTab(); }
void p04t03PopCallback(void *ptr) { updateTab(); }
void p04t04PopCallback(void *ptr) { updateTab(); }
void p04t05PopCallback(void *ptr) { updateTab(); }
void p04t06PopCallback(void *ptr) { updateTab(); }
void p04t07PopCallback(void *ptr) { updateTab(); }
void p04c01PopCallback(void *ptr) { setupPaletteBVB(); }
void p04c02PopCallback(void *ptr) { setupPaletteBayern(); }
void p04c03PopCallback(void *ptr) { setupPaletteWerder(); }
void p04c04PopCallback(void *ptr) { setupPalette1860(); }
void p04c05PopCallback(void *ptr) { }
void p04c06PopCallback(void *ptr) { }
void p04c07PopCallback(void *ptr) { }
void p04c08PopCallback(void *ptr) { }
// page 5
void p05PopCallback(void *ptr) { }
void p05titlePopCallback(void *ptr) { }
void p05tempPopCallback(void *ptr) { }
void p05humidPopCallback(void *ptr) { }
void p05settingsPopCallback(void *ptr) { setTextAllSensors(); }
void p05powerPopCallback(void *ptr) { toggleBrightness(); }
void p05t01PopCallback(void *ptr) { updateTab(); }
void p05t02PopCallback(void *ptr) { updateTab(); }
void p05t03PopCallback(void *ptr) { updateTab(); }
void p05t04PopCallback(void *ptr) { updateTab(); }
void p05t05PopCallback(void *ptr) { updateTab(); }
void p05t06PopCallback(void *ptr) { updateTab(); }
void p05t07PopCallback(void *ptr) { updateTab(); }
void p05c01PopCallback(void *ptr) { setupOneColor(CRGB::White); }
void p05c02PopCallback(void *ptr) { setupOneColor(CRGB( 255, 147, 41)); }
void p05c03PopCallback(void *ptr) { setupOneColor(CRGB::Red); }
void p05c04PopCallback(void *ptr) { setupOneColor(CRGB::Green); }
void p05c05PopCallback(void *ptr) { setupOneColor(CRGB::Blue); }
void p05c06PopCallback(void *ptr) { setupOneColor(CRGB::Magenta); }
void p05c07PopCallback(void *ptr) { setupOneColor(CRGB::Cyan); }
void p05c08PopCallback(void *ptr) { setupOneColor(CRGB::Yellow); }
// page 6
void p06PopCallback(void *ptr) { }
void p06titlePopCallback(void *ptr) { }
void p06tempPopCallback(void *ptr) { }
void p06humidPopCallback(void *ptr) { }
void p06settingsPopCallback(void *ptr) { setTextAllSensors(); }
void p06powerPopCallback(void *ptr) { toggleBrightness(); }
void p06t01PopCallback(void *ptr) { updateTab(); }
void p06t02PopCallback(void *ptr) { updateTab(); }
void p06t03PopCallback(void *ptr) { updateTab(); }
void p06t04PopCallback(void *ptr) { updateTab(); }
void p06t05PopCallback(void *ptr) { updateTab(); }
void p06t06PopCallback(void *ptr) { updateTab(); }
void p06t07PopCallback(void *ptr) { updateTab(); }
void p06c01PopCallback(void *ptr) { gCurrentPatternNumber = 10; }
void p06c02PopCallback(void *ptr) { }
void p06c03PopCallback(void *ptr) { }
void p06c04PopCallback(void *ptr) { }
void p06c05PopCallback(void *ptr) { }
void p06c06PopCallback(void *ptr) { }
void p06c07PopCallback(void *ptr) { }
void p06c08PopCallback(void *ptr) { }
// page 7
void p07PopCallback(void *ptr) { }
void p07titlePopCallback(void *ptr) { }
void p07tempPopCallback(void *ptr) { }
void p07humidPopCallback(void *ptr) { }
void p07settingsPopCallback(void *ptr) { setTextAllSensors(); }
void p07powerPopCallback(void *ptr) { toggleBrightness(); }
void p07t01PopCallback(void *ptr) { updateTab(); }
void p07t02PopCallback(void *ptr) { updateTab(); }
void p07t03PopCallback(void *ptr) { updateTab(); }
void p07t04PopCallback(void *ptr) { updateTab(); }
void p07t05PopCallback(void *ptr) { updateTab(); }
void p07t06PopCallback(void *ptr) { updateTab(); }
void p07t07PopCallback(void *ptr) { updateTab(); }
void p07c01PopCallback(void *ptr) { }
void p07c02PopCallback(void *ptr) { }
void p07c03PopCallback(void *ptr) { }
void p07c04PopCallback(void *ptr) { }
void p07c05PopCallback(void *ptr) { }
void p07c06PopCallback(void *ptr) { }
void p07c07PopCallback(void *ptr) { }
void p07c08PopCallback(void *ptr) { }
// page 8
void p08PopCallback(void *ptr) { }
void p08titlePopCallback(void *ptr) { }
void p08tempPopCallback(void *ptr) { }
void p08humidPopCallback(void *ptr) { }
void p08settingsPopCallback(void *ptr) { setTextAllSensors(); }
void p08powerPopCallback(void *ptr) { toggleBrightness(); }
void p08t01PopCallback(void *ptr) { updateTab(); }
void p08t02PopCallback(void *ptr) { updateTab(); }
void p08t03PopCallback(void *ptr) { updateTab(); }
void p08t04PopCallback(void *ptr) { updateTab(); }
void p08t05PopCallback(void *ptr) { updateTab(); }
void p08t06PopCallback(void *ptr) { updateTab(); }
void p08t07PopCallback(void *ptr) { updateTab(); }
void p08c01PopCallback(void *ptr) { setBrightness(DEFAULT_BRIGHTNESS); }
void p08c02PopCallback(void *ptr) { setBrightness(255); }
void p08c03PopCallback(void *ptr) { setBrightness(170); }
void p08c04PopCallback(void *ptr) { setBrightness(85); }
void p08c05PopCallback(void *ptr) { setTextTemp(); }
void p08c06PopCallback(void *ptr) { setTextHumid(); }
void p08c07PopCallback(void *ptr) { }
void p08c08PopCallback(void *ptr) { }
void p08temp02PopCallback(void *ptr) { }
void p08humid02PopCallback(void *ptr) { }

