
void setupHalloween()
{
  baseColor1 = CRGB::DarkOrange;    
  gCurrentPatternNumber = 14;
  FastLED.setBrightness(128);
}

void halloween()
{

  //CRGBPalette16 halloween = halloween_gp;
  
  fill_solid(leds, NUM_LEDS, baseColor1);

  EVERY_N_MILLIS_I(HalloweenTimer, halloweenTimer) {
    if (halloweenFlickerState == false) {
      // stay black for a short time
      baseColor1 = CRGB::Black;
      halloweenFlickerState = true;
      halloweenTimer = random16(50, 100);
    } else {
      // return to normal for a longer time
      baseColor1 = CRGB::DarkOrange;
      FastLED.setBrightness(128);
      halloweenFlickerState = false;
      halloweenTimer = random16(100, 5000);
    }
    HalloweenTimer.setPeriod(halloweenTimer);
  }




}