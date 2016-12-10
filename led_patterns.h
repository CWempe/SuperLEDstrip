
void oneColor()
{
  // nothing changes ofer time in this this color pattern
  fill_solid(leds, NUM_LEDS, baseColor1);
}

void setupOneColor(CRGB color)
{
  baseColor1 = color;
  gCurrentPatternNumber = 0;
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


// This function sets up a palette of Bayern Munich.
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

// This function sets up a palette of Bayern Munich.
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


// This function sets up a palette of Bayern Munich.
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
  uint8_t BeatsPerMinute = 80;
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
  int pos = beatsin16(FRAMES_PER_SECOND/4,0,NUM_LEDS);
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

