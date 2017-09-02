

// set brightness and save current value
// newBrightness is percentage (0-100) and will be mapped to 0-255 for FastLED
void setBrightness(uint8_t newBrightness)
{
   currentBrightness = newBrightness;
   FastLED.setBrightness(map(currentBrightness, 0, 100, 0, 255));
   lightNode.setProperty("brightness").send(String(currentBrightness));
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
  gCurrentPatternNumber = 3; // Index number of which pattern is current; default is 3 (rainbow)
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

