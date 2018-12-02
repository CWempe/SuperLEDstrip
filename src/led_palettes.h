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
  255, 255, 0,255};


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
  switch (palette) {
    case 0:   // rotate all 
      currentPalette = RainbowColors_p; //placeholder until rotate function is implemented
      break;
    case 1:
      currentPalette = CloudColors_p;
      break;
    case 2:
      currentPalette = LavaColors_p;
      break;
    case 3:
      currentPalette = OceanColors_p;
      break;
    case 4:
      currentPalette = ForestColors_p;
      break;
    case 5:
      currentPalette = RainbowColors_p;
      break;
    case 6:
      currentPalette = RainbowStripeColors_p;
      break;
    case 7:
      currentPalette = PartyColors_p;
      break;
    case 8:
      currentPalette = HeatColors_p;
      break;
    case 9:
      currentPalette = Rainbow_gp;
      break;

    // custom palettes
    case 100:
      currentPalette = thk_gp;
      break;
    case 101:
      currentPalette = purplefly_gp;
      break;
    case 102:
      currentPalette = lala_p;
      break;

    // clubs
    case 150:
      currentPalette = bayern_p;
      break;
    case 151:
      currentPalette = m1860_p;
      break;
    case 152:
      currentPalette = dortmund_p;
      break;
    case 153:
      currentPalette = bremen_p;
      break;
    case 154:
      currentPalette = esv_p;
      break;
    case 155:
      currentPalette = hamburg_p;
      break;

    // flags
    case 180:
      currentPalette = germany_p;
      break;
    case 181:
      currentPalette = italy_p;
      break;
    case 182:
      currentPalette = brazil_p;
      break;
    case 183:
      currentPalette = sweden_p;
      break;
    case 184:
      currentPalette = england_p;
      break;
    case 185:
      currentPalette = france_p;
      break;
    case 186:
      currentPalette = spain_p;
      break;
  }
}