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


void setPalette (uint8_t palette) {
  // palettes are rotationable in general we assume
  paletteRotationable = true;

  switch (palette) {
    case 0:
      autoChangePalette = true;
      break;
    case 1:
      targetPalette = CloudColors_p;
      break;
    case 2:
      targetPalette = LavaColors_p;
      break;
    case 3:
      targetPalette = OceanColors_p;
      break;
    case 4:
      targetPalette = ForestColors_p;
      break;
    case 5:
      targetPalette = RainbowColors_p;
      paletteRotationable = false;
      break;
    case 6:
      targetPalette = RainbowStripeColors_p;
      paletteRotationable = false;
      break;
    case 7:
      targetPalette = PartyColors_p;
      paletteRotationable = false;
      break;
    case 8:
      targetPalette = HeatColors_p;
      break;
    case 9:
      targetPalette = Rainbow_gp;
      paletteRotationable = false;
      break;

    // custom palettes
    case 100:
      targetPalette = thk_gp;
      paletteRotationable = false;
      break;
    case 101:
      targetPalette = purplefly_gp;
      paletteRotationable = false;
      break;
    case 102:
      targetPalette = lala_p;
      paletteRotationable = false;
      break;

    // clubs
    case 150:
      targetPalette = bayern_p;
      break;
    case 151:
      targetPalette = m1860_p;
      break;
    case 152:
      targetPalette = dortmund_p;
      break;
    case 153:
      targetPalette = bremen_p;
      break;
    case 154:
      targetPalette = esv_p;
      break;
    case 155:
      targetPalette = hamburg_p;
      break;

    // flags
    case 180:
      targetPalette = germany_p;
      break;
    case 181:
      targetPalette = italy_p;
      break;
    case 182:
      targetPalette = brazil_p;
      break;
    case 183:
      targetPalette = sweden_p;
      break;
    case 184:
      targetPalette = england_p;
      break;
    case 185:
      targetPalette = france_p;
      break;
    case 186:
      targetPalette = spain_p;
      break;
  }

  if ( autoChangePalette == false ) {
    // publish new palette number via mqtt
    lightNode.setProperty("palette").send(String(palette));
  
    // store current palette number to eeprom
    Embedis::set("paletteValue", String(palette));
  }
}