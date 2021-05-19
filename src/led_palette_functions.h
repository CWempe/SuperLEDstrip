void setupStaticPalette() {
  gCurrentPatternNumber = 15;
  currentBlending = NOBLEND;
  #ifdef WLED_ENABLE
    wled_fx = "83";
    wled_set_fx_pal();
  #endif
}


void staticPalette () {
  startPaletteInverted = false;
  showPalette (0);
}


void showPalette (uint8_t colorIndex = 0) {
  // get momentum from first pixel to calculate the further pixels
  paletteMomentumPixel = paletteMomentumStart;

  // define all leds of the strip indivudually
  for( uint16_t i = 0; i < NUM_LEDS; i++) {
    // set color for pixel i
    leds[i] = ColorFromPalette( currentPalette, colorIndex, 255, currentBlending);
    
    // calculate next idex of the palette
    calculateNextIndex( &colorIndex, &paletteMomentumPixel );
  }
}