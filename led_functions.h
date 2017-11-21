

// set brightness and save current value
// newBrightness is percentage (0-100) and will be mapped to 0-255 for FastLED
void setBrightness(uint8_t newBrightness)
{
   currentBrightness = newBrightness;
   FastLED.setBrightness(map(currentBrightness, 0, 100, 0, 255));
   lightNode.setProperty("brightness").send(String(currentBrightness));
}

void setTempo(uint8_t tempo) {
  BeatsPerMinute = tempo;
  lightNode.setProperty("tempo").send(String(BeatsPerMinute));
}

// toggle brightness between 0 and current
void toggleBrightness()
{
  if (lightON == false)
  {
    // When light is off switch back on to current brightness
    FastLED.setBrightness(map(currentBrightness, 0, 100, 0, 255));
    lightNode.setProperty("on").send("true");
    lightON = true;
  }
  else
  {
    // else set brightness to 0 and lightON to true
    FastLED.setBrightness(0);
    lightNode.setProperty("on").send("false");
    lightON = false;
  }  
}


void setupFastLED()
{
  //gCurrentPatternNumber = DEFAULT_PATTERN; // Index number of which pattern is current; default is 3 (rainbow)
  setScene(DEFAULT_SCENE);
  setBrightness(DEFAULT_BRIGHTNESS);
  FastLED.addLeds<LED_TYPE, DATA_PIN, COLOR_ORDER>(leds, NUM_LEDS);
}

void loopFastLED()
{
  if ( gLastPatternNumber != gCurrentPatternNumber) {
    leds(0, NUM_LEDS - 1) = CRGB::Black;
    gLastPatternNumber = gCurrentPatternNumber;
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
      break;
    case 102:   // stars
      gCurrentPatternNumber = 1;
      break;
    case 103:   // confetti
      gCurrentPatternNumber = 2;
      break;
    case 104:   // bpm
      gCurrentPatternNumber = 4;
      break;
    case 105:   // xmas
      gCurrentPatternNumber = 8;
      break;
    case 106:   // fire
      gCurrentPatternNumber = 9;
      break;
      
    // page 2
    case 201:   // german police
      setupFlashingLights(CRGB::Blue, CRGB::Blue);
      break;
    case 202:   // american police
      setupFlashingLights(CRGB::Blue, CRGB::Red);
      break;
    case 203:   // orange flashing lights
      setupFlashingLights(CRGB::OrangeRed, CRGB::OrangeRed);
      break;
    case 204:   // kitt
      gCurrentPatternNumber = 5;
      break;
      
    // page 3
    case 301:   // german flag
      setupPaletteGermany();
      break;
    case 302:   // italian flag
      setupPaletteItaly();
      break;
    case 303:   // brazilian flag
      setupPaletteBrazil();
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
  }
      
  lightNode.setProperty("scene").send(String(scene));
}

