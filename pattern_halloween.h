
void setupHalloween()
{
  baseColor1 = CRGB::DarkOrange;    
  gCurrentPatternNumber = 14;
}

void halloween()
{

  //CRGBPalette16 halloween = halloween_gp;
  
  fill_solid(leds, NUM_LEDS, baseColor1);

  // DEFAULT_FPS/1000*halloweenBreath)
  EVERY_N_MILLIS_I(HalloweenTimer, 1000/DEFAULT_FPS*halloweenBreath) {
    FastLED.setBrightness(quadwave8(map(triwave8(gHue2), 0, 255, 24, 128)));
    gHue2++;
    HalloweenTimer.setPeriod(1000/DEFAULT_FPS*halloweenBreath);
  }

}