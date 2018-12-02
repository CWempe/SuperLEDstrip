void setupStaticPalette() {
  gCurrentPatternNumber = 15;
  currentBlending = NOBLEND;
  setPalette(4);
}

void staticPalette() {
  fill_palette( leds,
                NUM_LEDS, 
                0,
                5, /* higher = narrower stripes */ 
                currentPalette,
                255,             // brightnes
                currentBlending);
}

// void gradientFill()
// {
//   gCurrentPatternNumber = 7;
//   currentBlending = NOBLEND;
//   currentPalette = testPalette_p; 
// }