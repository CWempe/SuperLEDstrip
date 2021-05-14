
void oneColor()
{
  // nothing changes over time in this this color pattern
  fill_solid(leds, NUM_LEDS, baseColor1);
}

void setupOneColor(CRGB color)
{
  // set firt LED to selected color when arcade pattern is active
  if ( gCurrentPatternNumber >= 10 && gCurrentPatternNumber <= 10 ) {
    leds[0] += color;
  } else if ( gCurrentPatternNumber == 16 ) {
    // set new color for lightsaber
    lightsaber_color_target = color;
    if ( lightsaber_color_current == lightsaber_color_target ) {
      lightsaber_toggle();
    }
  }
  else {
    // else set the whole stripe in one color
    baseColor1 = color;
    gCurrentPatternNumber = 0;
  }
  
  char baseColor1red [4];
  char baseColor1green [4];
  char baseColor1blue [4];
  String sBaseColor1red;
  String sBaseColor1green;
  String sBaseColor1blue;

  // Convert integer to char
  snprintf(baseColor1red, 4, "%u", color.red);
  snprintf(baseColor1green, 4, "%u", color.green);
  snprintf(baseColor1blue, 4, "%u", color.blue);
  
  // Convert char to String
  sBaseColor1red += baseColor1red;
  sBaseColor1green += baseColor1green;
  sBaseColor1blue += baseColor1blue;

  wled_send_json("{\"on\":true,\"seg\":[{\"col\":[[" + sBaseColor1red + "," + sBaseColor1green + "," + sBaseColor1blue + "],[0,0,0],[0,0,0]],\"fx\":83,\"pal\":0}]}}");

  if ( DEBUGLEVEL >= 1 ) {
    Homie.getLogger() << "[DEBUG1] baseColor1 red:   " << sBaseColor1red << endl;
    Homie.getLogger() << "[DEBUG1] baseColor1 green: " << sBaseColor1green << endl;
    Homie.getLogger() << "[DEBUG1] baseColor1 blue:  " << sBaseColor1blue << endl;
  }
}

void randomColor()
{
  // show random color three times a secondd and stay after 20 iterations
  EVERY_N_MILLIS_I(RandomColor, 1000/3)
  {
    // keep showing colors when countdown is still running or disabled
    if ( randomColorsCountdown > 1 || randomColorsCountdown == 0 ) {
      // generate random color until it is different to the last color
      do {
        baseColor2 = baseColor1;
        baseColor1 = randomColorArray[random(8)];
      } while ( baseColor1 == baseColor2 ) ;
      fill_solid(leds, NUM_LEDS, baseColor1);
      if ( randomColorsCountdown > 1 ) {
        // if countdown is running then descrease countdown
        randomColorsCountdown--;
      }
    }
  }
}

void setupRandomColor()
{
Homie.getLogger() << "setupRandomColor started... " << endl;
  if ( randomColorsCountdown == 0 ) {
    // if countdown is disabled, start countdown
    // 6 = schow five more colors
    randomColorsCountdown = 6;
  } else {
    // else disable countdown
    randomColorsCountdown = 0;
  }
  gCurrentPatternNumber = 12;
}

#ifdef FASTLED_RGBW
  void fill_part( struct CRGBW * leds, int numFromFill, int numToFill, CRGB color)
  {
    if ( numFromFill <= numToFill ) {
      for( int i = numFromFill; i < numToFill; i++) {
        leds[i] = color;
      }
    }
  }
#else
  void fill_part( struct CRGB * leds, int numFromFill, int numToFill, CRGB color)
  {
    if ( numFromFill <= numToFill ) {
      for( int i = numFromFill; i < numToFill; i++) {
        leds[i] = color;
      }
    }
  }
#endif

void FillLEDsFromPaletteColors( uint8_t colorIndex)
{
    uint8_t brightness = 255;
    
    for( int i = 0; i < NUM_LEDS; i++) {
        leds[i] = ColorFromPalette( currentPalette, colorIndex, brightness, currentBlending);
        colorIndex += 3;
    }
}

void runningPalette()
{
  static uint8_t startIndex = 0;
  
  // generade led array based on the current startIndex
  showPalette(startIndex);

  EVERY_N_MILLIS_I(runningPalette, rotationSpeedMs / 10) {
    // calculate next index of palette for the first pixel
    calculateNextIndex( &startIndex, &paletteMomentumStart );
    
    // Update Timer
    runningPalette.setPeriod(rotationSpeedMs / 10);
  }
}

void colorRotation()
{
  static uint8_t startIndex = 0;
  // static CRGB color;

  EVERY_N_MILLIS_I(runningPalette, rotationSpeedMs / 10) {
    calculateNextIndex( &startIndex, &paletteMomentumStart );
    // Update Timer
    runningPalette.setPeriod(rotationSpeedMs / 10);
  }
  fill_solid(leds, NUM_LEDS, ColorFromPalette( currentPalette, startIndex, 255));
}


// This function sets up a palette of Bayern Munich.
void setupPaletteBayern() {
  gCurrentPatternNumber = 7;
  currentBlending = NOBLEND;
  setPalette(150);
}

// This function sets up a palette of white and brightblue stripes.
void setupPalette1860() {
  gCurrentPatternNumber = 7;
  currentBlending = NOBLEND;
  setPalette(151);
}

// This function sets up a palette of green stripes.
void setupPaletteBVB() {
  gCurrentPatternNumber = 7;
  currentBlending = NOBLEND;
  setPalette(152);
}

// This function sets up a palette of green stripes.
void setupPaletteWerder() {
  gCurrentPatternNumber = 7;
  currentBlending = NOBLEND;
  setPalette(153);
}

// This function sets up a palette of green stripes.
void setupPaletteESV() {
  gCurrentPatternNumber = 7;
  currentBlending = NOBLEND;
  setPalette(154);
}

// This function sets up a palette of green stripes.
void setupPaletteHSV() {
  gCurrentPatternNumber = 7;
  currentBlending = NOBLEND;
  setPalette(155);
}

// This function sets up a palette of the german flag.
// also works for Belgium
void setupPaletteGermany() {
  gCurrentPatternNumber = 7;
  currentBlending = NOBLEND;
  setPalette(180);
}

// This function sets up a palette of the italian flag.
void setupPaletteItaly() {  
  gCurrentPatternNumber = 7;
  currentBlending = NOBLEND;
  setPalette(181);
}

// This function sets up a palette of the brazilian flag.
void setupPaletteBrazil() {
  gCurrentPatternNumber = 7;
  currentBlending = NOBLEND;
  setPalette(182);
}

// This function sets up a palette of the swedish flag.
void setupPaletteSweden() {
  gCurrentPatternNumber = 7;
  currentBlending = NOBLEND;
  setPalette(183);
}

// This function sets up a palette of the english flag.
// also works for Denmark
void setupPaletteEngland() {
  gCurrentPatternNumber = 7;
  currentBlending = NOBLEND;
  setPalette(184);
}

// This function sets up a palette of the french flag.
void setupPaletteFrance() {
  gCurrentPatternNumber = 7;
  currentBlending = NOBLEND;
  setPalette(185);

}

// This function sets up a palette of the spanish flag.
void setupPaletteSpain()
{
  gCurrentPatternNumber = 7;
  currentBlending = NOBLEND;
  setPalette(186);
}

// This function sets up a palette of the american flag.
void setupPaletteUSA()
{
  gCurrentPatternNumber = 7;
  currentBlending = NOBLEND;
  setPalette(187);
}

void stars()
{
  fadeToBlackBy( leds, NUM_LEDS, 1);
  if ( random8() < 8) {
    leds[ random16(NUM_LEDS) ] += CRGB::White;
  }
}

void confetti()
{
  // random colored speckles that blink in and fade smoothly
  fadeToBlackBy( leds, NUM_LEDS, 10);
  
  EVERY_N_MILLISECONDS(1000/NUM_LEDS/2)
  {
    int pos = random16(NUM_LEDS);
    leds[pos] += CHSV( random8(255), 200, 255);
  }
}

void rainbow()
{
  fill_rainbow( leds, NUM_LEDS, gHue, 7);
}


/*
  This function changes the momentum if necessary and in/decreses index

     index:
        240 |        / \                / \ 
            |      /     \            /     \
            |    /         \        /         \
            |  /             \    /             \
            |/_________________\/_________________\
          0                                          time
  momentum:  ⬆⬆⬆⬆⬆⬆⬆⬆⬆⬆⬇⬇⬇⬇⬇⬇⬇⬇⬇⬆⬆⬆⬆⬆⬆⬆⬆⬆⬆⬇⬇⬇⬇⬇⬇⬇⬇⬇
  (⬆ ≙ true; ⬇ ≙ false)
  
  use 240 instead of 255 because of https://github.com/FastLED/FastLED/issues/515
*/

void calculateNextIndex(uint8_t *index, bool *momentum) {
    // change the momentum if we reach 0 or 240
    if ( paletteRotationable == false &&
           ( ( *index >= ( 240 - incIndex) && *momentum == true  ) ||
             ( *index <= (   0 + incIndex) && *momentum == false ) ) ) {
      *momentum = !*momentum;
    }

    // increment or decrement by incIndex depending on momentum    
    if ( *momentum == true ) {
      *index = *index + incIndex;
    } else {
      *index = *index - incIndex;
    }
}

void bpm()
{
  // colored stripes pulsing at a defined Beats-Per-Minute (BPM)
  CRGBPalette16 palette = PartyColors_p;
  uint8_t beat = beatsin8( BeatsPerMinute, 64, 255);
  for( int i = 0; i < NUM_LEDS; i++) { //9948
    leds[i] = ColorFromPalette(palette, gHue+(i*2), beat-gHue+(i*10));
  }
}

/* Knight Rider, Larson Scanner*/
void kitt()
{
  // a colored dot sweeping back and forth, with fading trails
  fadeToBlackBy( leds, NUM_LEDS, 20);
  int pos = beatsin16(DEFAULT_FPS/4,0,NUM_LEDS);
  if ( pos != NUM_LEDS ) leds[pos] = CRGB::Red;
}

void setupFlashingLights( CRGB colorLeft, CRGB colorRight)
{
  //FastLED.setBrightness(255);
  gCurrentPatternNumber = 6;
  baseColor1 = colorLeft;
  baseColor2 = colorRight;
  
}

void flashingLights()
{
  /*
   * The flashing code for the light is: (ON = +; OFF = -)
   * 
   * |<-- flash1Time --->|
   * |<------------ approx. 1 second -------->|
   * ++++--++++----------|++++--++++----------|...
   * first ON
   *     first OFF
   *       second ON
   *           second OFF
   *                      ... and again
   */ 
  
  uint8_t flashDuration = 80;             // ON time
  uint8_t flashFirstOff = 40;                // first OFF time
  uint16_t flash1secondOff = 400;          // second OFF time for flash light 1
  uint16_t flash2secondOff = 300;          // second OFF time for flash light 2
  static uint8_t flash1status = 3;    // 0=first ON; 1=first OFF; 2=second ON; 3=second OFF
  static uint8_t flash2status = 3;

  //Serial.print("flash1LastChange: ");
  //Serial.println(flash1LastChange);

  /*
   *  left lights
   */

  // When status 3 is older than flash1secondOff
  if ( flash1status == 3 && ( timeElapsed1 > flash1secondOff ) )
  {
    fill_part(leds, 0, NUM_LEDS / 4, baseColor1);
    flash1status = 0;
    timeElapsed1 = 0;
  }

  // When status 0 is older than flashPause
  if ( flash1status == 0 && ( timeElapsed1 > flashDuration ) )
  {
    
    fill_part(leds, 0, NUM_LEDS / 4, CRGB::Black);
    flash1status = 1;
    timeElapsed1 = 0;
  }

  // When status 1 is older than flash1secondOff
  if ( flash1status == 1 && ( timeElapsed1 > flashFirstOff ) )
  {
    fill_part(leds, 0, NUM_LEDS / 4, baseColor1);
    flash1status = 2;
    timeElapsed1 = 0;
  }

  // When status 2 is older than flashPause
  if ( flash1status == 2 && ( timeElapsed1 > flashDuration ) )
  {
    fill_part(leds, 0, NUM_LEDS / 4, CRGB::Black);
    flash1status = 3;
    timeElapsed1 = 0;
  }
  

  /*
   *  rightlights
   */

  // When status 3 is older than flash2secondOff
  if ( flash2status == 3 && ( timeElapsed2 > flash2secondOff ) )
  {
    fill_part(leds, NUM_LEDS / 4 * 3, NUM_LEDS, baseColor2);
    flash2status = 0;
    timeElapsed2 = 0;
  }

  // When status 0 is older than flashPause
  if ( flash2status == 0 && ( timeElapsed2 > flashDuration ) )
  {
    fill_part(leds, NUM_LEDS / 4 * 3, NUM_LEDS, CRGB::Black);
    flash2status = 1;
    timeElapsed2 = 0;
  }

  // When status 1 is older than flash2secondOff
  if ( flash2status == 1 && ( timeElapsed2 > flashFirstOff ) )
  {
    fill_part(leds, NUM_LEDS / 4 * 3, NUM_LEDS, baseColor2);
    flash2status = 2;
    timeElapsed2 = 0;
  }

  // When status 2 is older than flashPause
  if ( flash2status == 2 && ( timeElapsed2 > flashDuration ) )
  {
    fill_part(leds, NUM_LEDS / 4 * 3, NUM_LEDS, CRGB::Black);
    flash2status = 3;
    timeElapsed2 = 0;
  }

}



/*
 *  christmas tree
 *  based on https://gist.github.com/kriegsman/d0a5ed3c8f38c64adcb4837dafb6e690
 */

// Helper function that blends one uint8_t toward another by a given amount
void nblendU8TowardU8( uint8_t& cur, const uint8_t target, uint8_t amount)
{
  if( cur == target) return;
  
  if( cur < target ) {
    uint8_t delta = target - cur;
    delta = scale8_video( delta, amount);
    cur += delta;
  } else {
    uint8_t delta = cur - target;
    delta = scale8_video( delta, amount);
    cur -= delta;
  }
}

// Blend one CRGB color toward another CRGB color by a given amount.
// Blending is linear, and done in the RGB color space.
// This function modifies 'cur' in place.
#ifndef FASTLED_RGBW
CRGB fadeTowardColor( CRGB& cur, const CRGB& target, uint8_t amount)
{
  nblendU8TowardU8( cur.red,   target.red,   amount);
  nblendU8TowardU8( cur.green, target.green, amount);
  nblendU8TowardU8( cur.blue,  target.blue,  amount);
  return cur;
}
#else
  CRGBW fadeTowardColor( CRGBW& cur, const CRGB& target, uint8_t amount)
  {
    nblendU8TowardU8( cur.red,   target.red,   amount);
    nblendU8TowardU8( cur.green, target.green, amount);
    nblendU8TowardU8( cur.blue,  target.blue,  amount);
    // nblendU8TowardU8( cur.white, target.white, amount);
    return cur;
  }
#endif

// Fade an entire array of CRGBs toward a given background color by a given amount
// This function modifies the pixel array in place.
#ifndef FASTLED_RGBW
void fadeTowardColor( CRGB* L, uint16_t N, const CRGB& bgColor, uint8_t fadeAmount)
{
  for( uint16_t i = 0; i < N; i++) {
    fadeTowardColor( L[i], bgColor, fadeAmount);
  }
}
#else
  void fadeTowardColor( CRGBW* L, uint16_t N, const CRGB& bgColor, uint8_t fadeAmount)
  {
    for( uint16_t i = 0; i < N; i++) {
      fadeTowardColor( L[i], bgColor, fadeAmount);
    }
  }
#endif

void xmas()
{
  //dark green background color for christmas tree
  CRGB bgColor  = CHSV( HUE_GREEN, 255, 96);
  
  // fade all existing pixels toward bgColor by "1" (out of 255)
  // remeber this gets called 120 (FRAMES_PER_SECOND) times per second
  fadeTowardColor( leds, NUM_LEDS, bgColor, 1);

  // periodically set random pixel to a highlight color
  // one led per sesond (1000ms) for every meter
  EVERY_N_MILLISECONDS( 1000 * LEDS_PER_METER / NUM_LEDS ) {
    // set an array of possible highlight colors
    CRGB highlightColor[] = {CRGB::Grey, CRGB::Red, CRGB::Yellow, CRGB::Blue, CRGB::Magenta};

    // set highlight color for random led, except first and last led
    uint16_t pos = random16( NUM_LEDS - 2 );
    leds[ pos + 1 ] = highlightColor[random16(5)];
  }
}

void ice()
{
  //light blue background color for ice
  CRGB bgColor  = CRGB::LightSkyBlue;
  
  // fade all existing pixels toward bgColor by "1" (out of 255)
  // remeber this gets called 120 (FRAMES_PER_SECOND) times per second
  fadeTowardColor( leds, NUM_LEDS, bgColor, 1);

  // periodically set random pixel to a highlight color
  // one led per sesond (1000ms) for every meter
  EVERY_N_MILLISECONDS( 250 * LEDS_PER_METER / NUM_LEDS ) {
    // set an array of possible highlight colors
    CRGB highlightColor[] = {CRGB::Blue, CRGB::White, CRGB::DeepSkyBlue};

    // set highlight color for random led, except first and last led
    uint16_t pos = random16( NUM_LEDS - 2 );
    leds[ pos + 1 ] = highlightColor[random16(3)];
  }
}

