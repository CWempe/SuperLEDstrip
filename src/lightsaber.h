void lightsaber_toggle(void) {
  // toggle growing 
  lightsaber_growing = !lightsaber_growing;
  // set to use loop function
  gCurrentPatternNumber = 16;
}

// loop function for lightsaber scene
void lightsaber(void)
{
  EVERY_N_MILLISECONDS(LIGHTSABER_SPEED / NUM_LEDS) {
    if ( ( lightsaber_growing && lightsaber_color_current == lightsaber_color_target ) ) {
      // increase lightsaber lenght
      if ( lightsaber_lenght_current < NUM_LEDS) { lightsaber_lenght_current++; }
      // make all leds black
      leds(0, NUM_LEDS - 1) = CRGB::Black;
      // now fill leds to lightsaber_lenght_current
      fill_solid(leds, lightsaber_lenght_current, lightsaber_color_current);
    } else {
      // decrease lightsaber lenght
      if ( lightsaber_lenght_current > 0) { lightsaber_lenght_current--; }
      // make all leds black
      leds(0, NUM_LEDS - 1) = CRGB::Black;
      // now fill leds to lightsaber_lenght_current
      fill_solid(leds, lightsaber_lenght_current, lightsaber_color_current);
      // set color_current to color_target when lightsaber is off
      if ( lightsaber_lenght_current == 0 && lightsaber_color_current != lightsaber_color_target) {
        lightsaber_color_current = lightsaber_color_target;
        writeEeepromLightsaberColor();
        // store current scene number to eeprom because a new color might have been saved as a new scene instead previously
        Embedis::set("sceneValue", "603");
        lightsaber_growing = true;
      }
    }
  }
}
