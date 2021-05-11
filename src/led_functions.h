

// set brightness and save current value
// newBrightness is percentage (0-100) and will be mapped to 0-255 for FastLED
void setBrightness(uint8_t newBrightness)
{
  currentBrightness = newBrightness;
  FastLED.setBrightness(map(currentBrightness, 0, 100, 0, 255));
  if (Homie.isConnected()) lightNode.setProperty("brightness").send(String(currentBrightness));
  #ifdef WLEDSHIELD
    // Turn ofs Relais if brightnes is set to 0; else torn on
    updateOutput01on((newBrightness == 0 ? "false" : "true"));
  #endif
  // store current scene number to eeprom
  Embedis::set("brightnessValue", String(currentBrightness));
}

void setTempo(uint8_t tempo) {
  BeatsPerMinute = tempo;
  if (Homie.isConnected()) lightNode.setProperty("tempo").send(String(BeatsPerMinute));
  // store current scene number to eeprom
  Embedis::set("tempoValue", String(tempo));
}

void setRotationSpeed(uint8_t speed) {
  // prevent speed from exceeding 20
  if ( speed > 20 ) {
    speed = 20;
  }
  rotationSpeed = speed;
  //lightNode.setProperty("rotationSpeed").send(String(speed));
  updateRotationSpeed();
}

void setPaletteSize(uint8_t paletteSize) {
  if (paletteSize == 0 ) {
    paletteSize = 1;   // streching the palette to infinity makes no sense
  }
  
  incIndex = round(255 / (float)( LEDS_PER_METER * 5 ) * paletteSize);  // update incIndex

  if (incIndex == 0 ) {
    incIndex = 1;   // streching the palette to infinity makes no sense
  }
  if (Homie.isConnected()) lightNode.setProperty("paletteSize").send(String(paletteSize));
  // store current palette size to eeprom
  Embedis::set("paletteSizeValue", String(paletteSize));
}


// toggle brightness between 0 and current
void toggleBrightness()
{
  if (lightON == false)
  {
    // When light is off switch back on to current brightness
    FastLED.setBrightness(map(currentBrightness, 0, 100, 0, 255));
    if (Homie.isConnected()) lightNode.setProperty("on").send("true");
    lightON = true;
  }
  else
  {
    // else set brightness to 0 and lightON to true
    FastLED.setBrightness(0);
    if (Homie.isConnected()) lightNode.setProperty("on").send("false");
    lightON = false;
  }

  // Turn wled off everytime the button is pressed
  wled_send_json("{\"on\":false}");
}


void setupFastLED()
{
  // restore last values from eeprom
  readEeepromCustomColor();
  readEeepromLightsaberColor();
  readEepromBrightness();
  readEepromTempo();
  readEepromRotationSpeed();
  readEepromScene();
  readEepromPalette();
  readEepromPaletteSize();
  #ifdef FASTLED_RGBW
    FastLED.addLeds<LED_TYPE, DATA_PIN, COLOR_ORDER>(ledsRGB, getRGBWsize(NUM_LEDS));
  #else
    FastLED.addLeds<LED_TYPE, DATA_PIN, COLOR_ORDER>(leds, NUM_LEDS);
  #endif
  FastLED.setCorrection( COLOR_CORRECTION );
  FastLED.setTemperature( COLOR_TEMPERATURE) ;
}

void loopFastLED() {
  if ( gLastPatternNumber != gCurrentPatternNumber) {
    fill_part(leds, 0, NUM_LEDS, CRGB::Black);
    gLastPatternNumber = gCurrentPatternNumber;
  }

  if ( autoChangePalette == true ) {
    EVERY_N_MILLIS_I(changePalette, autoChangePaletteMS) {
      // automatically change palette if palette number is 0
      uint8_t nextPalette = random8( 1, 9+3);
      if ( nextPalette <= 9 ) {
        setPalette(nextPalette);
      } else {
        setPalette(nextPalette - 9  + 99);
      }
      // Update Timer
      changePalette.setPeriod(autoChangePaletteMS);
    }
  }

  if ( fadePalette == true ) {
    nblendPaletteTowardPalette( currentPalette, targetPalette, maxChanges);
  } else {
    currentPalette = targetPalette;
  }
  
  gPatterns[gCurrentPatternNumber]();
  FastLED.show();
}


/*
 * Here the different light scenes are defined by numbers
 * 
 * Each scene-number starts with the number of the page on the display
 * and ist counted forward
 * 1st page = 101..199
 * 2nd page = 201..299
 * 
 * Scene that are not represented on the display wil start with 1001.
 * 
 */
void setScene (uint16_t scene) {
  switch (scene) {
    // page 1
    case 101:   // rainbow
      gCurrentPatternNumber = 3;
      wled_send_json("{\"on\":true,\"seg\":{\"fx\":9,\"sx\":128,\"pal\":0}}");
      break;
    case 102:   // stars
      gCurrentPatternNumber = 1;
      wled_send_json("{\"on\":true,\"seg\":[{\"col\":[[255,255,255],[0,0,0],[0,0,0]],\"fx\":20,\"sx\":1,\"pal\":0}]}}");
      break;
    case 103:   // confetti
      gCurrentPatternNumber = 2;
      wled_send_json("{\"on\":true,\"seg\":{\"fx\":74,\"sx\":128,\"pal\":0}}");
      break;
    case 104:   // bpm
      gCurrentPatternNumber = 4;
      wled_send_json("{\"on\":true,\"seg\":{\"fx\":68,\"sx\":128,\"pal\":0}}");
      break;
    case 105:   // xmas
      gCurrentPatternNumber = 8;
      wled_send_json("{\"on\":true,\"seg\":[{\"col\":[[255,0,0],[0,255,0],[0,0,0]],\"fx\":20,\"sx\":10,\"pal\":0}]}}");
      break;
    case 106:   // fire
      gCurrentPatternNumber = 9;
      wled_send_json("{\"on\":true,\"seg\":{\"fx\":66,\"sx\":128,\"pal\":0}}");
      break;
    case 107:   // ice
      gCurrentPatternNumber = 11;
      wled_send_json("{\"on\":true,\"seg\":[{\"fx\":115,\"sx\":128,\"pal\":9}]}}");
      break;
    case 108:   // color rotation
      gCurrentPatternNumber = 13;
      wled_send_json("{\"on\":true,\"seg\":[{\"fx\":8,\"sx\":16,\"pal\":0}]}}");
      break;
    case 109:   // Halloween
      setupHalloween();
      wled_send_json("{\"on\":true,\"seg\":{\"fx\":53,\"sx\":128,\"pal\":0}}");
      break;
    case 110:   // static pattern
      setupStaticPalette();
      break;
    case 111:   // running palette
      gCurrentPatternNumber = 7;
      break;

      
    // page 2
    case 201:   // german police
      setupFlashingLights(CRGB::Blue, CRGB::Blue);
      wled_send_json("{\"on\":true,\"seg\":[{\"col\":[[0,0,255],[0,0,255],[0,0,0]],\"fx\":50,\"sx\":128,\"pal\":0}]}}");
      break;
    case 202:   // american police
      setupFlashingLights(CRGB::Blue, CRGB::Red);
      wled_send_json("{\"on\":true,\"seg\":[{\"col\":[[0,0,0],[0,0,0],[0,0,0]],\"fx\":48,\"sx\":128,\"pal\":0}]}}");
      break;
    case 203:   // orange flashing lights
      setupFlashingLights(CRGB::OrangeRed, CRGB::OrangeRed);
      wled_send_json("{\"on\":true,\"seg\":[{\"col\":[[255,165,0],[255,165,0],[0,0,0]],\"fx\":50,\"sx\":128,\"pal\":0}]}}");
      break;
    case 204:   // kitt
      gCurrentPatternNumber = 5;
      wled_send_json("{\"on\":true,\"seg\":[{\"col\":[[255,0,0],[0,0,0],[0,0,0]],\"fx\":40,\"sx\":128,\"pal\":0}]}}");
      break;
      
    // page 3
    case 301:   // german/beglium flag
      setupPaletteGermany();
      break;
    case 302:   // italian flag
      setupPaletteItaly();
      break;
    case 303:   // brazilian flag
      setupPaletteBrazil();
      break;
    case 304:   // swedish flag
      setupPaletteSweden();
      break;
    case 305:   // english/danish flag
      setupPaletteEngland();
      break;
    case 306:   // french flag
      setupPaletteFrance();
      break;
    case 307:   // spanish flag
      setupPaletteSpain();
      break;
    case 308:   // american flag
      setupPaletteUSA();
      break;
      
    // page 4
    case 401:   // BVB
      setupPaletteBVB();
      break;
    case 402:   // FC Bayern Munich
      setupPaletteBayern();
      break;
    case 403:   // Werder Bremen
      setupPaletteWerder();
      break;
    case 404:   // 1860 Munich
      setupPalette1860();
      break;
    case 405:   // ESV München
      setupPaletteESV();
      break;
    case 406:   // HSV München
      setupPaletteHSV();
      break;
      
    // page 5
    case 501:   // white
      setupOneColor(CRGB::White);
      break;
    case 502:   // warm white
      setupOneColor(CRGB( 255, 147, 41));
      break;
    case 503:   // red
      setupOneColor(CRGB::Red);
      break;
    case 504:   // green
      setupOneColor(CRGB::Green);
      break;
    case 505:   // blue
      setupOneColor(CRGB::Blue);
      break;
    case 506:   // magenta
      setupOneColor(CRGB::Magenta);
      break;
    case 507:   // cyan
      setupOneColor(CRGB::Cyan);
      break;
    case 508:   // yellow
      setupOneColor(CRGB::Yellow);
      break;
    case 509:   // customColor
      setupOneColor(customColor);
      break;
    case 510:   // OrangeRed
      setupOneColor(CRGB::OrangeRed);
      break;
      
    // page 6
    case 601:   // arcade pulse
      gCurrentPatternNumber = 10;
      break;
    case 602:   // random color
      setupRandomColor();
      break;
    case 603:   // lightsaber
      lightsaber_toggle();
      break;
  }

  // reset randomColorsCountdown if another scene is selected
  if ( scene != 602 ) {
    randomColorsCountdown = 2;
  }
  // reset lightsaber if another scene is selected
  if ( gCurrentPatternNumber != 16 ) {
    lightsaber_growing = false;
    lightsaber_lenght_current = 0;
  }
  // publish new scene number via mqtt
  if (Homie.isConnected()) lightNode.setProperty("scene").send(String(scene));

  // store current scene number to eeprom
  Embedis::set("sceneValue", String(scene));
}

