//include global and custom values
#include "global_values.h"
#include "custom_values.h"

// include libraries
#include <Nextion.h>
#include <elapsedMillis.h>
#include <stdlib.h>
#include <Homie.h>
#include <EEPROM.h>
#include <Embedis.h>
#include <spi_flash.h>
#include <SoftwareSerial.h>
#include <FastLED.h>
#include <FastLED_RGBW.h>

#ifdef SENSOR_DHT
  #include <DHT.h>
#endif
#ifdef SENSOR_DS18B20
  #include <DallasTemperature.h>
  #include <OneWire.h>
#endif


/*
 * Function prototypes
 */
void setTextAllSensors(void);
void Fire2012(void);
void arc_pulse(void);
void setupHalloween(void);
void staticPalette();
void showPalette (uint8_t colorIndex);
void halloween(void);
void setScene(uint16_t scene);
void setPalette(uint8_t palette);
void setBrightness(uint8_t newBrightness);
void setTempo(uint8_t tempo);
#ifdef FASTLED_RGBW
  void fill_part( struct CRGBW * leds, int numFromFill, int numToFill, CRGB color);
#else
  void fill_part( struct CRGB * leds, int numFromFill, int numToFill, CRGB color);
#endif

void updateTab(void);
void setTextAll(void);
void setTextAllSensors(void);
void setTextHumid(void);
void setTextTemp(void);
void setTextTitle(void);
void setTextRotationSpeed(void);
void updateRotationSpeed(void);
void changeRotationSpeed(bool increaseSpeed);
void setRotationSpeed(uint8_t speed);
void setPaletteSize(uint8_t paletteSize);
void getRed(void);
void getGreen(void);
void getBlue(void);
void updateCustomColorRed(uint8_t red, bool updateRGB);
void updateCustomColorGreen(uint8_t green, bool updateRGB);
void updateCustomColorBlue(uint8_t blue, bool updateRGB);
void updateButton01switch(String value, bool write);
void updateButton01event_on_press(String value, bool write);
void updateButton01action(String value, bool write);
void updateOutput01on(String value, bool write);
void updateOutput01invert(String value, bool write);
void updateOutput02on(String value, bool write);
void updateOutput02invert(String value, bool write);
void updateOutput03on(String value, bool write);
void updateOutput03invert(String value, bool write);
void updateOutput04on(String value, bool write);
void updateOutput04invert(String value, bool write);
void readEepromScene(void);
void calculateNextIndex(uint8_t *index, bool *momentum);
#ifdef WLED_ENABLE
  void wled_power(void);
  void wled_send_json(String json);
#endif


Embedis embedis(Serial);


/*
 * #############################
 * ### WLED ontrol Functions ###
 * #############################
 */

#ifdef WLED_ENABLE
  String wled_pal = "0";
  String wled_fx = "0";
  String wled_ix = "128";
  String wled_sx = "128";
  String wled_bri = "128";
  String wled_pal_custom = "";

  #include "wled_control.h"
#endif

/*
 *  FastLED
 */
//  Definitions for FastLED RGBW Hack
#ifdef FASTLED_RGBW
  // FastLED with RGBW
  CRGBW leds[NUM_LEDS];
  // CRGBArray<NUM_LEDS> leds;
  CRGB *ledsRGB = (CRGB *) &leds[0];
#else
  // CRGB leds[NUM_LEDS];
  CRGBArray<NUM_LEDS> leds;
#endif
FASTLED_USING_NAMESPACE 
uint8_t gHue  = 0; // rotating "base color" used by many of the patterns
uint8_t gHue2 = 0; // rotating "color" incremented by some pattern with specific speed
uint8_t rotationSpeed = DEFAULT_ROTATION_SPEED; // default speed for color rotation
int rotationSpeedMs; // rotationSpeed converted to delay between color changing in ms
uint8_t paletteSize = DEFAULT_PALETTESIZE;
uint8_t incIndex = 255 / NUM_LEDS * paletteSize;
static CEveryNMilliseconds ColorRotation(100);
CRGB baseColor1 = CRGB::Blue;
CRGB baseColor2 = CRGB::Blue;
CRGB customColor = CRGB(255,255,255);
// Array of random default colors
CRGB randomColorArray[] = {CRGB::White, CRGB( 255, 147, 41), CRGB::Red, CRGB::Green, CRGB::Blue, CRGB::Magenta, CRGB::Cyan, CRGB::Yellow};
uint8_t randomColorsCountdown = 2;    // will be set to 0 (disable countdown) via first use of setupRandomColor
CRGBPalette16 currentPalette;
CRGBPalette16 targetPalette;
TBlendType    currentBlending;
uint8_t currentBrightness = DEFAULT_BRIGHTNESS;
uint8_t gCurrentPatternNumber; // Index number of which pattern is current
uint8_t gLastPatternNumber = 255;
elapsedMillis timeElapsed1;
elapsedMillis timeElapsed2;
uint8_t BeatsPerMinute = DEFAULT_TEMPO;
CRGB halloweenColorArray[] = {CRGB::White, CRGB::LimeGreen, CRGB::BlueViolet}; //
uint16_t halloweenFlickerTimer = 1000;  // initial flicker timer value
bool     halloweenFlickerState = false; // helper to save current state of flickering; true = light of
uint16_t halloweenFlashTimer = 1000;    // initial flash timer value
bool     halloweenFlashState = false;   // helper to save current state of flashing; true = flashing on
bool     paletteRotationable = true;    // helper to define if a palette can be attatched to itselfe nicely
bool     startPaletteInverted = false;
bool     paletteMomentumStart = true;   // Defines the momentum of the palette (forward or reverse) at the first pixel of the stripe.
                                        // The color index of the palette might descend from 255 to 0 if it cannot attached back to back.
bool     paletteMomentumPixel = true;   // Same as paletteMomentumPixel but for each pixel of the strip.
bool     invert = false;
uint8_t  maxChanges = 10;               // How fast should palettes change (1-48)
bool     fadePalette = true;
bool     autoChangePalette = false;     // automatically change palette
uint16_t autoChangePaletteMS = 5000;       // automatically change palette every X seconds

//  lightsaber
bool    lightsaber_growing        = false;
uint8_t lightsaber_lenght_current = 0;
CRGB    lightsaber_color_current  = CRGB::Green;
CRGB    lightsaber_color_target   = CRGB::Green;
// millisenconds to turn on/off the lightsaber, smaller value = faster
#define LIGHTSABER_SPEED            300

bool updateDisplayRed   = false;
bool updateDisplayGreen = false;
bool updateDisplayBlue  = false;


/*
 * Nextion display
 */
SoftwareSerial HMISerial(NEXTION_TX, NEXTION_RX);

/*
 * DHT and DS18B20
 */
#if defined(SENSOR_DHT) || defined(SENSOR_DS18B20)
  float fTemp         = 0;
  char  sTemp[10]     = "";
  HomieNode temperatureNode("temperature", "temperature", "temperature");
#endif
#ifdef SENSOR_DHT
  float fHumid        = 0;
  char  sHumid[10]    = "";
  HomieNode humidityNode("humidity", "humidity");
  #include "dht_functions.h"
#endif
#ifdef SENSOR_DS18B20
  OneWire oneWire(TEMP_DATA_PIN);
  DallasTemperature sensors(&oneWire);
  #include "temp_functions.h"
#endif


HomieNode lightNode("light", "light switch", "switch");
#include "eeprom_functions.h"

#include "outputs.h"
#include "buttons.h"

/*
 * #########################
 * ### FastLED Functions ###
 * #########################
 */

#include "lightsaber.h"
#include "led_patterns.h"
#include "led_palette_functions.h"
#include "led_palettes.h"
#include "pattern_halloween.h"

typedef void (*SimplePatternList[])();
SimplePatternList gPatterns = { oneColor,          //  0
                                stars,             //  1
                                confetti,          //  2
                                rainbow,           //  3
                                bpm,               //  4
                                kitt,              //  5
                                flashingLights,    //  6
                                runningPalette,    //  7
                                xmas,              //  8
                                Fire2012,          //  9
                                arc_pulse,         // 10
                                ice,               // 11
                                randomColor,       // 12
                                colorRotation,     // 13
                                halloween,         // 14
                                staticPalette,     // 15
                                lightsaber         // 16
                               };


#include "led_functions.h"
#include "led_custom_color.h"


/*
   #########################
   ### Nextion Functions ###
   #########################
*/

#include "nextion_declaration.h"
#include "nextion_registration.h"
#include "nextion_callback_functions.h"
#include "nextion_initialization.h"
#include "nextion_functions.h"


/*
   #######################
   ### Homie Functions ###
   #######################
 */

void setupHandler() {
  #if defined(SENSOR_DHT) || defined(SENSOR_DS18B20)
    if (Homie.isConnected()) temperatureNode.setProperty("unit").send("°C");
  #endif
  #ifdef SENSOR_DHT
    if (Homie.isConnected()) humidityNode.setProperty("unit").send("%");
  #endif
  
}

bool lightBrightnessHandler(const HomieRange& range, const String& value) {
  Homie.getLogger() << "Brightness is " << value << endl;
  setBrightness(value.toInt());
  return true;
}

bool lightSceneHandler(const HomieRange& range, const String& value) {
  setScene(value.toInt());
  return true;
}

bool lightPaletteHandler(const HomieRange& range, const String& value) {
  if ( value.toInt() == 0 ) {
    autoChangePalette = true;
  } else {
    autoChangePalette = false;
    setPalette(value.toInt());
  }
  return true;
}

bool lightTempoHandler(const HomieRange& range, const String& value) {
  setTempo(value.toInt());
  return true;
}

bool lightRotationSpeedHandler(const HomieRange& range, const String& value) {
  setRotationSpeed(value.toInt());
  return true;
}

bool lightPaletteSizeHandler(const HomieRange& range, const String& value) {
  setPaletteSize(value.toInt());
  return true;
}



bool lightOnHandler(const HomieRange& range, const String& value) {
  if (value != "true" && value != "false") return false;

  bool on = (value == "true");
  FastLED.setBrightness(on ? currentBrightness : 0);
  #ifdef WLEDSHIELD
    // Turn off Relais if brightness is set to 0; else torn on
    updateOutput01on((on ? "true" : "false"));
  #endif
  if (Homie.isConnected()) lightNode.setProperty("on").send(value);
  lightON = (value == "true");
  Homie.getLogger() << "Light is " << (on ? "on" : "off") << endl;

  return true;
}

bool globalInputHandler(const HomieNode& node, const HomieRange& range, const String& property, const String& value) {
  Homie.getLogger() << "Received on node " << node.getId() << ": " << property << " = " << value << endl;
  
  return false;
}

void loopHandler() {
  
}


/*
   ######################
   ### Main Functions ###
   ######################
*/
void setup(void)
{
  Serial.begin(115200);
  setupEeprom();
  
  if ( DEBUGLEVEL >= 1 ) {
    Homie.getLogger() << "" << endl;
    Homie.getLogger() << "[DEBUG1] starting..." << endl;
  }

  #ifdef SENSOR_DHT
    setupDHT();
  #endif
  #ifdef SENSOR_DS18B20
    setupTemp();
  #endif

  Homie_setFirmware(HOMIE_FW_NAME, HOMIE_FW_VERSION); // The underscore is not a typo! See Magic bytes
  Homie.disableResetTrigger();                 // disable ResetTrigger, because it creates some problemes for me
  //Homie.setStandalone();                     // uncomment if you do not want to use wifi
  Homie.setSetupFunction(setupHandler).setLoopFunction(loopHandler);
  #if defined(SENSOR_DHT) || defined(SENSOR_DS18B20)
    temperatureNode.advertise("unit");
    temperatureNode.advertise("degrees");
  #endif
  #ifdef SENSOR_DHT
    humidityNode.advertise("percentage");
  #endif
  lightNode.advertise("on").settable(lightOnHandler);
  lightNode.advertise("customColor").settable(lightCustomColorHandler);
  lightNode.advertise("brightness").settable(lightBrightnessHandler);
  lightNode.advertise("scene").settable(lightSceneHandler);
  lightNode.advertise("palette").settable(lightPaletteHandler);
  lightNode.advertise("tempo").settable(lightTempoHandler);
  lightNode.advertise("rotationSpeed").settable(lightRotationSpeedHandler);
  lightNode.advertise("paletteSize").settable(lightPaletteSizeHandler);
  Homie.setGlobalInputHandler(globalInputHandler);
  if ( HOMIE_STANDALONE == true ) {
    Homie.setHomieBootMode(HomieBootMode::STANDALONE);
  }
  #ifdef BUTTON01_PIN
    HomieSetupButton01();
  #endif
  #ifdef OUTPUT01_PIN
    HomieSetupOutput01();
  #endif
  #ifdef OUTPUT02_PIN
    HomieSetupOutput02();
  #endif
  #ifdef OUTPUT03_PIN
    HomieSetupOutput03();
  #endif
  #ifdef OUTPUT04_PIN
    HomieSetupOutput04();
  #endif

  Homie.setup();  
  NextionSetup();
  setTextTitle();
  delay(1000);
  setupFastLED();
}

void loop(void)
{
  nexLoop(nex_listen_list);

  EVERY_N_MILLISECONDS( 20 ) {
    gHue++;  // slowly cycle the "base color" through the rainbow
  }
  // Call FastLED commands every 1/120th ms
  EVERY_N_MILLISECONDS(1000 / DEFAULT_FPS)
  {
    loopFastLED();
  }

  // Test WLED_command
  // EVERY_N_MILLISECONDS(1000 * 10)
  // {
  //   wled_power(true);
  // }

  #ifdef SENSOR_DHT
    loopDHT();
  #endif
  #ifdef SENSOR_DS18B20
    EVERY_N_SECONDS(SENSOR_READ_INTERVAL) {
      loopTemp();
    }
  #endif

  #ifdef BUTTON01_PIN
    loopButton01();
  #endif

  Homie.loop();

  updateDisplayColors();
  
}
