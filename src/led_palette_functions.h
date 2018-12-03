void setupStaticPalette() {
  gCurrentPatternNumber = 15;
  currentBlending = NOBLEND;
}

void staticPalette () {
  uint8_t colorIndex = 0;
  bool    invert = false;

  for( uint16_t i = 0; i < NUM_LEDS; i++) {
    leds[i] = ColorFromPalette( currentPalette, colorIndex, 255, currentBlending);

    // if palette cannot nicely attached to itselfe the palette will be printed in reverse
    // think:  "123456789987654321" instead of "123456789123456789"
    if ( paletteRotationable == false ) {
      if ( colorIndex >= ( 255 - incIndex) ) {
        invert = true;
      } else if ( colorIndex <= (0 + incIndex) ) {
        invert = false;
      }
  
      if ( invert == false ) {
        colorIndex += incIndex;
      } else {
        colorIndex -= incIndex;
      }
    } else {
      colorIndex += incIndex;
    }

  }
}