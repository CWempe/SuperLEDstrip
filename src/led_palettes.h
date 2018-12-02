DEFINE_GRADIENT_PALETTE( heatmap_gp ) {
    0,     0,  0,  0,   //black
  128,   255,  0,  0,   //red
  224,   255,255,  0,   //bright yellow
  255,   255,255,255 }; //full white
    
DEFINE_GRADIENT_PALETTE( purplefly_gp ) {
    0,   0,  0,  0,
   63, 239,  0,122,
  191, 252,255, 78,
  255,   0,  0,  0};
 
DEFINE_GRADIENT_PALETTE( thk_gp ) {
    0, 255,  0,  0,
  127, 255, 63,  0,
  255, 255, 0,255};

  CRGB green  = CRGB::DarkGreen;
  CRGB white  = CRGB::Grey;
  CRGB red    = CRGB::DarkRed;
  
CRGBPalette16 germany_p = CRGBPalette16(
                  green,  green,  green,   white,
                  white,    red,    red,  red,
                  green, green,  green,   white,
                  white,    red,    red,  red );
 
CRGBPalette16 lala_p = CRGBPalette16( 
                      CRGB::Yellow,
                      CRGB::Purple); 



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

    // flags
    case 150:
      currentPalette = germany_p;
      break;
  }
}