void setupStaticPalette() {
  gCurrentPatternNumber = 15;
  currentBlending = NOBLEND;
}


void staticPalette () {
  startPaletteInverted = false;
  showPalette (0);
}


void showPalette (uint8_t colorIndex = 0) {
  if ( !(colorIndex > 9 && colorIndex < 246)) {
    Homie.getLogger() << "[DEBUG] showPalette " << colorIndex << " " << incIndex << " " << startPaletteInverted << " " << invert << endl;
  }

  // define all leds of the strip indivudually
  for( uint16_t i = 0; i < NUM_LEDS; i++) {
    if ( startPaletteInverted == false ) {
      leds[i] = ColorFromPalette( currentPalette, colorIndex, 255, currentBlending);
    } else {
      // invert colorIndex if the palette is started inverted
      leds[i] = ColorFromPalette( currentPalette, 255 - colorIndex, 255, currentBlending);
    }

    // if palette cannot nicely attached to itselfe the palette will be printed in reverse
    // think:  "123454321" instead of "1234512345"
    if ( paletteRotationable == false ) {
      if ( colorIndex >= ( 255 - incIndex) ) {
        invert = true;
      } else if ( colorIndex <= (0 + incIndex) ) {
        invert = false;
      }
  
      if ( invert == false ) {
        colorIndex += incIndex;
      } else {
        // decrease colorIndex if the palette is printed inverse
        colorIndex -= incIndex;
      }
    } else {
      colorIndex += incIndex;
    }
  }
}