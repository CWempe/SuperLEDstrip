#include "Nextion.h"
#include "FastLED.h"
#include <elapsedMillis.h>
#include <DHT.h>
#include <stdlib.h>
#include "custom_values.h"
#include <Homie.h>
#include <EEPROM.h>
#include <Embedis.h>
#include "spi_flash.h"

/*
 * Function prototypes
 */
void setTextAllSensors(void);
void Fire2012(void);
void arc_pulse(void);
void setupHalloween(void);
void halloween(void);
void setScene(uint16_t scene);
void setBrightness(uint8_t newBrightness);
void setTempo(uint8_t tempo);

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
void readEepromScene(void);


Embedis embedis(Serial);

/*
 *  FastLED
 */
FASTLED_USING_NAMESPACE 
CRGBArray<NUM_LEDS> leds;
uint8_t gHue  = 0; // rotating "base color" used by many of the patterns
uint8_t gHue2 = 0; // rotating "color" incremented by some pattern with specific speed
uint8_t rotationSpeed = DEFAULT_ROTATION_SPEED; // default speed for color rotation
int rotationSpeedMs; // rotationSpeed converted to delay between color changing in ms
static CEveryNMilliseconds ColorRotation(100);
CRGB baseColor1 = CRGB::Blue;
CRGB baseColor2 = CRGB::Blue;
// Array of random default colors
CRGB randomColorArray[] = {CRGB::White, CRGB( 255, 147, 41), CRGB::Red, CRGB::Green, CRGB::Blue, CRGB::Magenta, CRGB::Cyan, CRGB::Yellow};
uint8_t randomColorsCountdown = 2;    // will be set to 0 (disable countdown) via first use of setupRandomColor
CRGBPalette16 currentPalette;
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


/*
 * Nextion display
 */
SoftwareSerial HMISerial(NEXTION_TX, NEXTION_RX);


/*
 * define HomieNodes
 */
HomieNode temperatureNode("temperature", "temperature");
HomieNode humidityNode("humidity", "humidity");
HomieNode lightNode("light", "switch");


#include "dht.h"
#include "eeprom_functions.h";


/*
 * #########################
 * ### FastLED Functions ###
 * #########################
 */

#include "led_patterns.h"
#include "pattern_halloween.h"

typedef void (*SimplePatternList[])();
//     Pattern IDs              0          1      2         3        4    5     6               7              8     9         10         11   12           13             14
SimplePatternList gPatterns = { oneColor, stars, confetti, rainbow, bpm, kitt, flashingLights, runningPalette, xmas, Fire2012, arc_pulse, ice, randomColor, colorRotation, halloween };


#include "led_functions.h"


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
  temperatureNode.setProperty("unit").send("°C");
  humidityNode.setProperty("unit").send("%");
  
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

bool lightTempoHandler(const HomieRange& range, const String& value) {
  setTempo(value.toInt());
  return true;
}

bool lightRotationSpeedHandler(const HomieRange& range, const String& value) {
  Homie.getLogger() << "rotationSpeed is " << value << endl;
  setRotationSpeed(value.toInt());
  return true;
}



bool lightOnHandler(const HomieRange& range, const String& value) {
  if (value != "true" && value != "false") return false;

  bool on = (value == "true");
  FastLED.setBrightness(on ? currentBrightness : 0);
  lightNode.setProperty("on").send(value);
  lightON = (value == "true");
  Homie.getLogger() << "Light is " << (on ? "on" : "off") << endl;

  return true;
}

bool globalInputHandler(const HomieNode& node, const String& property, const HomieRange& range, const String& value) {
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
  
  setupDHT();

  Homie_setFirmware(HOMIE_FW_NAME, HOMIE_FW_VERSION); // The underscore is not a typo! See Magic bytes
  Homie.disableResetTrigger();                 // disable ResetTrigger, because it creates some problemes for me
  //Homie.setStandalone();                     // uncomment if you do not want to use wifi
  Homie.setSetupFunction(setupHandler).setLoopFunction(loopHandler);
  temperatureNode.advertise("unit");
  temperatureNode.advertise("degrees");
  humidityNode.advertise("percentage");
  lightNode.advertise("on").settable(lightOnHandler);
  lightNode.advertise("brightness").settable(lightBrightnessHandler);
  lightNode.advertise("scene").settable(lightSceneHandler);
  lightNode.advertise("tempo").settable(lightTempoHandler);
  lightNode.advertise("rotationSpeed").settable(lightRotationSpeedHandler);
  Homie.setGlobalInputHandler(globalInputHandler);
  if ( HOMIE_STANDALONE == true ) {
    Homie.setHomieBootMode(HomieBootMode::STANDALONE);
  }
  Homie.setup();

  NextionSetup();
  setTextTitle();
  setupEeprom();
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

  loopDHT();

  Homie.loop();

}
