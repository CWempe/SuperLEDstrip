// define standard colors

CRGB white       = CRGB::Grey;
CRGB black       = CRGB::Black;
CRGB red         = CRGB::Red;
CRGB darkred     = CRGB::DarkRed;
CRGB yellow      = CRGB::Yellow;
CRGB gold        = CRGB::Gold;
CRGB blue        = CRGB::Blue;
CRGB dodgerblue  = CRGB::DodgerBlue;
CRGB blue2       = CRGB(  0, 118, 182);
CRGB green       = CHSV( HUE_GREEN, 255, 255);
CRGB green2      = CRGB(130, 175,  32);
CRGB darkgreen   = CRGB::DarkGreen;


// custom palettes

DEFINE_GRADIENT_PALETTE( purplefly_gp ) {
    0,   0,  0,  0,
   63, 239,  0,122,
  191, 252,255, 78,
  255,   0,  0,  0};
 
DEFINE_GRADIENT_PALETTE( thk_gp ) {
    0, 255,  0,  0,
  127, 255, 63,  0,
  255, 220, 0, 220};
 
// https://www.color-hex.com/color-palette/69287
DEFINE_GRADIENT_PALETTE( midnight_light_gp ) {
    0, 35,  8, 39,
   63, 73, 22, 71,
  127,124, 38, 94,
  191,255, 84, 84,
  255,255,129, 60};

// https://www.color-hex.com/color-palette/62352
DEFINE_GRADIENT_PALETTE( tragic_gp ) {
    0, 37,112, 81,
   63, 53, 96, 81,
  127, 69, 80, 81,
  191, 85, 64, 81,
  255,101, 48, 81};
  

// http://soliton.vm.bytemark.co.uk/pub/cpt-city/bhw/bhw1/tn/bhw1_05.png.index.html
DEFINE_GRADIENT_PALETTE( bhw1_05_gp ) {
    0,  5,239,137,
  255,158, 35,221};

// http://soliton.vm.bytemark.co.uk/pub/cpt-city/mpl/tn/plasma.png.index.html
DEFINE_GRADIENT_PALETTE( plasma_gp ) {
    0,13,   8,135,
   63,126,  3,168,
  127,204, 71,120,
  191,248,148, 65,
  255,240,249, 33};





CRGBPalette16 lala_p = CRGBPalette16( 
                      CRGB::Yellow,
                      CRGB::Purple);


// clubs

CRGBPalette16 bayern_p = CRGBPalette16(
                              white, white,  red,  red,
                              red,  blue,  blue, blue,
                              white, white,  red,  red,
                              red,  blue,  blue, blue );
 
CRGBPalette16 m1860_p = CRGBPalette16(
                              dodgerblue,  dodgerblue,  white,  white,
                              dodgerblue,  dodgerblue,  white,  white,
                              dodgerblue,  dodgerblue,  white,  white,
                              dodgerblue,  dodgerblue,  white,  white );

CRGBPalette16 dortmund_p = CRGBPalette16(
                              gold,  gold,  black,  black,
                              gold,  gold,  black,  black,
                              gold,  gold,  black,  black,
                              gold,  gold,  black,  black );

CRGBPalette16 bremen_p = CRGBPalette16(
                              green,  green,  white,  white,
                              green,  green,  white,  white,
                              green,  green,  white,  white,
                              green,  green,  white,  white );

CRGBPalette16 esv_p = CRGBPalette16(
                              white,  white,  white,  blue2,
                              blue2,  blue2,  blue2,  blue2,
                              white,  white,  white,  green2,
                              green2, green2, green2, green2 );

CRGBPalette16 hamburg_p = CRGBPalette16(
                              white,  white,  white,  blue,
                              blue,   blue,   blue,   blue,
                              white,  white,  white,  black,
                              black,  black,  black,  black );


// flags

CRGBPalette16 germany_p = CRGBPalette16(
                              black,  black,  black,   red,
                              red,    red,    yellow,  yellow,
                              yellow, black,  black,   black,
                              red,    red,    yellow,  yellow );

CRGBPalette16 italy_p = CRGBPalette16(
                              darkgreen, darkgreen, darkgreen, white,
                              white,     darkred,   darkred,   darkred,
                              darkgreen, darkgreen, darkgreen, white,
                              white,     darkred,   darkred,   darkred );

CRGBPalette16 brazil_p = CRGBPalette16(
                              green, green, green,   blue,
                              blue,  blue,  yellow,  yellow,
                              green, green, green,   blue,
                              blue,  blue,  yellow,  yellow );

CRGBPalette16 sweden_p = CRGBPalette16(
                                 blue,   blue,   blue,   blue,
                                 yellow, yellow, yellow, yellow,
                                 blue,   blue,   blue,   blue,
                                 yellow, yellow, yellow, yellow );

CRGBPalette16 england_p = CRGBPalette16(
                                 white, white, white, white,
                                 red,   red,   red,    red,
                                 white, white, white,  white,
                                 red,   red,   red,   red );

CRGBPalette16 france_p = CRGBPalette16(
                                 blue,  blue,    blue,    white,
                                 white, darkred, darkred, darkred,
                                 blue,  blue,    blue,    white,
                                 white, darkred, darkred, darkred );

CRGBPalette16 spain_p = CRGBPalette16(
                                 red,    red,    red,    red,
                                 yellow, yellow, yellow, yellow,
                                 red,    red,    red,    red,
                                 yellow, yellow, yellow, yellow );

CRGBPalette16 usa_p = CRGBPalette16(
                                 blue,    white, blue,   white,
                                 blue,    white, blue,   red,
                                 white,   red,   white,  red,
                                 white,   red,   white,  red );


void setPalette (uint8_t palette) {
  // palettes are rotationable in general we assume
  paletteRotationable = true;

  switch (palette) {
    case 0:
      autoChangePalette = true;
      break;
    case 1:
      targetPalette = CloudColors_p;
      currentBlending = LINEARBLEND;
      #ifdef WLED_ENABLE
        wled_pal = "7";
      #endif
      break;
    case 2:
      targetPalette = LavaColors_p;
      currentBlending = LINEARBLEND;
      #ifdef WLED_ENABLE
        wled_pal = "8";
      #endif
      break;
    case 3:
      targetPalette = OceanColors_p;
      currentBlending = LINEARBLEND;
      #ifdef WLED_ENABLE
        wled_pal = "9";
      #endif
      break;
    case 4:
      targetPalette = ForestColors_p;
      currentBlending = LINEARBLEND;
      #ifdef WLED_ENABLE
        wled_pal = "10";
      #endif
      break;
    case 5:
      targetPalette = RainbowColors_p;
      paletteRotationable = true;
      currentBlending = LINEARBLEND;
      #ifdef WLED_ENABLE
        wled_pal = "11";
      #endif
      break;
    case 6:
      targetPalette = RainbowStripeColors_p;
      paletteRotationable = false;
      currentBlending = NOBLEND;
      #ifdef WLED_ENABLE
        wled_pal = "12";
      #endif
      break;
    case 7:
      targetPalette = PartyColors_p;
      paletteRotationable = false;
      currentBlending = LINEARBLEND;
      #ifdef WLED_ENABLE
        wled_pal = "6";
      #endif
      break;
    case 8:
      targetPalette = HeatColors_p;
      currentBlending = LINEARBLEND;
      #ifdef WLED_ENABLE
        wled_pal = "54";
      #endif
      break;
    case 9:
      targetPalette = Rainbow_gp;
      paletteRotationable = true;
      currentBlending = LINEARBLEND;
      #ifdef WLED_ENABLE
        wled_pal = "11";
      #endif
      break;

    // custom palettes
    case 100:
      targetPalette = thk_gp;
      paletteRotationable = false;
      currentBlending = LINEARBLEND;
      #ifdef WLED_ENABLE
        wled_pal = "4";
        wled_pal_custom = "[200,30,15],[234,90,0],[180,48,146]";
      #endif
      break;
    case 101:
      targetPalette = purplefly_gp;
      paletteRotationable = false;
      currentBlending = LINEARBLEND;
      #ifdef WLED_ENABLE
        wled_pal = "3";
      #endif
      break;
    case 102:
      targetPalette = lala_p;
      paletteRotationable = false;
      currentBlending = LINEARBLEND;
      #ifdef WLED_ENABLE
        wled_pal = "3";
        wled_pal_custom = "[255,246,0],[195,0,255],[0,0,0]";
      #endif
      break;
    case 103:
      targetPalette = midnight_light_gp;
      paletteRotationable = false;
      currentBlending = LINEARBLEND;
      break;
    case 104:
      targetPalette = tragic_gp;
      paletteRotationable = false;
      currentBlending = LINEARBLEND;
      break;
    case 105:
      targetPalette = bhw1_05_gp;
      paletteRotationable = false;
      currentBlending = LINEARBLEND;
      break;
    case 106:
      targetPalette = plasma_gp;
      paletteRotationable = false;
      currentBlending = LINEARBLEND;
      break;

    // clubs
    case 150:
      targetPalette = bayern_p;
      currentBlending = NOBLEND;
      break;
    case 151:
      targetPalette = m1860_p;
      currentBlending = NOBLEND;
      break;
    case 152:
      targetPalette = dortmund_p;
      currentBlending = NOBLEND;
      break;
    case 153:
      targetPalette = bremen_p;
      currentBlending = NOBLEND;
      break;
    case 154:
      targetPalette = esv_p;
      currentBlending = NOBLEND;
      break;
    case 155:
      targetPalette = hamburg_p;
      currentBlending = NOBLEND;
      break;

    // flags
    case 180:
      targetPalette = germany_p;
      currentBlending = NOBLEND;
      break;
    case 181:
      targetPalette = italy_p;
      currentBlending = NOBLEND;
      break;
    case 182:
      targetPalette = brazil_p;
      currentBlending = NOBLEND;
      break;
    case 183:
      targetPalette = sweden_p;
      currentBlending = NOBLEND;
      break;
    case 184:
      targetPalette = england_p;
      currentBlending = NOBLEND;
      break;
    case 185:
      targetPalette = france_p;
      currentBlending = NOBLEND;
      break;
    case 186:
      targetPalette = spain_p;
      currentBlending = NOBLEND;
      break;
    case 187:
      targetPalette = usa_p;
      currentBlending = NOBLEND;
      break;
  }

  #ifdef WLED_ENABLE
    wled_set_fx_pal();
  #endif

  if ( autoChangePalette == false ) {
    // publish new palette number via mqtt
    if (Homie.isConnected()) lightNode.setProperty("palette").send(String(palette));
  
    // store current palette number to eeprom
    Embedis::set("paletteValue", String(palette));
  }
}