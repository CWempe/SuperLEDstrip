
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
  } else {
    // else set the whole stripe in one color
    baseColor1 = color;
    gCurrentPatternNumber = 0;
  }
}


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
  EVERY_N_MILLISECONDS(1000/NUM_LEDS)
  {
    startIndex = startIndex + 1;
  }
  FillLEDsFromPaletteColors( startIndex);
}


// This function sets up a palette of Bayern Munich.
void setupPaletteBayern()
{
  CRGB white = CRGB::Grey;
  CRGB blue  = CRGB::Blue;
  CRGB red   = CRGB::Red;
  
  gCurrentPatternNumber = 7;
  currentBlending = NOBLEND;
  currentPalette = CRGBPalette16(
                                 white, white,  red,  red,
                                 red,  blue,  blue, blue,
                                 white, white,  red,  red,
                                 red,  blue,  blue, blue ); 
}

// This function sets up a palette of white and brightblue stripes.
void setupPalette1860()
{
  CRGB blue   = CRGB::DodgerBlue;
  CRGB white  = CRGB::Grey;
  
  gCurrentPatternNumber = 7;
  currentBlending = NOBLEND;
  currentPalette = CRGBPalette16(
                                 blue,  blue,  white,  white,
                                 blue,  blue,  white,  white,
                                 blue,  blue,  white,  white,
                                 blue,  blue,  white,  white );
}

// This function sets up a palette of green stripes.
void setupPaletteBVB()
{
  CRGB yellow = CRGB::Gold;
  CRGB black  = CRGB::Black;
  
  gCurrentPatternNumber = 7;
  currentBlending = NOBLEND;
  currentPalette = CRGBPalette16(
                                 yellow,  yellow,  black,  black,
                                 yellow,  yellow,  black,  black,
                                 yellow,  yellow,  black,  black,
                                 yellow,  yellow,  black,  black );
}

// This function sets up a palette of green stripes.
void setupPaletteWerder()
{
  CRGB green  = CHSV( HUE_GREEN, 255, 255);
  CRGB white  = CRGB::Grey;
  
  currentBlending = NOBLEND;
  currentPalette = CRGBPalette16(
                                 green,  green,  white,  white,
                                 green,  green,  white,  white,
                                 green,  green,  white,  white,
                                 green,  green,  white,  white );
  gCurrentPatternNumber = 7;
}


// This function sets up a palette of the german flag.
// also works for Belgium
void setupPaletteGermany()
{
  CRGB black  = CRGB::Black;
  CRGB red    = CRGB::Red;
  CRGB yellow = CRGB::Yellow;
  
  gCurrentPatternNumber = 7;
  currentBlending = NOBLEND;
  currentPalette = CRGBPalette16(
                                 black,  black,  black,   red,
                                 red,    red,    yellow,  yellow,
                                 yellow, black,  black,   black,
                                 red,    red,    yellow,  yellow );
}

// This function sets up a palette of the italian flag.
void setupPaletteItaly()
{
  CRGB green  = CRGB::DarkGreen;
  CRGB white  = CRGB::Grey;
  CRGB red    = CRGB::DarkRed;
  
  gCurrentPatternNumber = 7;
  currentBlending = NOBLEND;
  currentPalette = CRGBPalette16(
                                 green,  green,  green,   white,
                                 white,    red,    red,  red,
                                 green, green,  green,   white,
                                 white,    red,    red,  red );
}


// This function sets up a palette of the brazilian flag.
void setupPaletteBrazil()
{
  CRGB blue   = CRGB::Blue;
  CRGB green  = CRGB::Green;
  CRGB yellow = CRGB::Yellow;
  
  gCurrentPatternNumber = 7;
  currentBlending = NOBLEND;
  currentPalette = CRGBPalette16(
                                 green, green, green,   blue,
                                 blue,  blue,  yellow,  yellow,
                                 green, green, green,   blue,
                                 blue,  blue,  yellow,  yellow );
}


// This function sets up a palette of the swedish flag.
void setupPaletteSweden()
{
  CRGB blue   = CRGB::Blue;
  CRGB yellow = CRGB::Yellow;

  gCurrentPatternNumber = 7;
  currentBlending = NOBLEND;
  currentPalette = CRGBPalette16(
                                 blue, blue, blue,   blue,
                                 yellow,  yellow,  yellow,  yellow,
                                 blue, blue, blue,   blue,
                                 yellow,  yellow,  yellow,  yellow );
}


// This function sets up a palette of the english flag.
// also works for Denmark
void setupPaletteEngland()
{
  CRGB white  = CRGB::Grey;
  CRGB red    = CRGB::DarkRed;

  gCurrentPatternNumber = 7;
  currentBlending = NOBLEND;
  currentPalette = CRGBPalette16(
                                 white, white, white,   white,
                                 red,  red,  red,  red,
                                 white, white, white,   white,
                                 red,  red,  red,  red );
}

// This function sets up a palette of the french flag.
void setupPaletteFrance()
{
  CRGB blue   = CRGB::Blue;
  CRGB white  = CRGB::Grey;
  CRGB red    = CRGB::DarkRed;
  
  gCurrentPatternNumber = 7;
  currentBlending = NOBLEND;
  currentPalette = CRGBPalette16(
                                 blue,  blue,  blue,   white,
                                 white,    red,    red,  red,
                                 blue, blue,  blue,   white,
                                 white,    red,    red,  red );
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
  leds[pos] = CRGB::Red;
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
  
  int flashDuration = 80;             // ON time
  int flashFirstOff = 40;                // first OFF time
  int flash1secondOff = 400;          // second OFF time for flash light 1
  int flash2secondOff = 300;          // second OFF time for flash light 2
  static long flash1LastChange = 0;   // last Time the status of flash1 changed
  static long flash2LastChange = 0;   // last Time the status of flash2 changed
  static uint8_t flash1status = 3;    // 0=first ON; 1=first OFF; 2=second ON; 3=second OFF
  static uint8_t flash2status = 3;

  //Serial.print("flash1LastChange: ");
  //Serial.println(flash1LastChange);

  EVERY_N_SECONDS(10)
  {
    int flash1secondOff = 300 + random8(200);
    int flash2secondOff = 300 + random8(200);
  }


  /*
   *  left lights
   */

  // When status 3 is older than flash1secondOff
  if ( flash1status == 3 && ( timeElapsed1 > flash1secondOff ) )
  {
    leds(0, NUM_LEDS / 4 - 1) = baseColor1;
    flash1status = 0;
    timeElapsed1 = 0;
  }

  // When status 0 is older than flashPause
  if ( flash1status == 0 && ( timeElapsed1 > flashDuration ) )
  {
    leds(0, NUM_LEDS / 4 - 1) = CRGB::Black;
    flash1status = 1;
    timeElapsed1 = 0;
  }

  // When status 1 is older than flash1secondOff
  if ( flash1status == 1 && ( timeElapsed1 > flashFirstOff ) )
  {
    leds(0, NUM_LEDS / 4 - 1) = baseColor1;
    flash1status = 2;
    timeElapsed1 = 0;
  }

  // When status 2 is older than flashPause
  if ( flash1status == 2 && ( timeElapsed1 > flashDuration ) )
  {
    leds(0, NUM_LEDS / 4 - 1) = CRGB::Black;
    flash1status = 3;
    timeElapsed1 = 0;
  }
  

  /*
   *  rightlights
   */

  // When status 3 is older than flash2secondOff
  if ( flash2status == 3 && ( timeElapsed2 > flash2secondOff ) )
  {
    leds(NUM_LEDS / 4 * 3, NUM_LEDS - 1) = baseColor2;
    flash2status = 0;
    timeElapsed2 = 0;
  }

  // When status 0 is older than flashPause
  if ( flash2status == 0 && ( timeElapsed2 > flashDuration ) )
  {
    leds(NUM_LEDS / 4 * 3, NUM_LEDS - 1) = CRGB::Black;
    flash2status = 1;
    timeElapsed2 = 0;
  }

  // When status 1 is older than flash2secondOff
  if ( flash2status == 1 && ( timeElapsed2 > flashFirstOff ) )
  {
    leds(NUM_LEDS / 4 * 3, NUM_LEDS - 1) = baseColor2;
    flash2status = 2;
    timeElapsed2 = 0;
  }

  // When status 2 is older than flashPause
  if ( flash2status == 2 && ( timeElapsed2 > flashDuration ) )
  {
    leds(NUM_LEDS / 4 * 3, NUM_LEDS - 1) = CRGB::Black;
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
CRGB fadeTowardColor( CRGB& cur, const CRGB& target, uint8_t amount)
{
  nblendU8TowardU8( cur.red,   target.red,   amount);
  nblendU8TowardU8( cur.green, target.green, amount);
  nblendU8TowardU8( cur.blue,  target.blue,  amount);
  return cur;
}

// Fade an entire array of CRGBs toward a given background color by a given amount
// This function modifies the pixel array in place.
void fadeTowardColor( CRGB* L, uint16_t N, const CRGB& bgColor, uint8_t fadeAmount)
{
  for( uint16_t i = 0; i < N; i++) {
    fadeTowardColor( L[i], bgColor, fadeAmount);
  }
}


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

