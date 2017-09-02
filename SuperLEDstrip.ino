#include "Nextion.h"
#include "FastLED.h"
#include <elapsedMillis.h>
#include <DHT.h>
#include <stdlib.h>
#include "custom_values.h"
#include <Homie.h>

/*
 * Function prototypes
 */
void setTextAllSensors(void);
void Fire2012(void);
void arc_pulse(void);

void updateTab(void);
void setTextAll(void);
void setTextAllSensors(void);
void setTextHumid(void);
void setTextTemp(void);
void setTextTitle(void);


/*
 *  FastLED
 */
FASTLED_USING_NAMESPACE 
CRGBArray<NUM_LEDS> leds;
uint8_t gHue = 0; // rotating "base color" used by many of the patterns
CRGB baseColor1 = CRGB::Blue;
CRGB baseColor2 = CRGB::Blue;
CRGBPalette16 currentPalette;
TBlendType    currentBlending;
uint8_t currentBrightness = DEFAULT_BRIGHTNESS;
uint8_t gCurrentPatternNumber; // Index number of which pattern is current
uint8_t gLastPatternNumber = 255;
elapsedMillis timeElapsed1;
elapsedMillis timeElapsed2;

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
//HomieNode lightNode("brightness", "brightness");


#include "dht.h"



/*
 * #########################
 * ### FastLED Functions ###
 * #########################
 */
#include "led_patterns.h"

typedef void (*SimplePatternList[])();
//     Pattern IDs              0          1      2         3        4    5     6               7              8     9         10
SimplePatternList gPatterns = { oneColor, stars, confetti, rainbow, bpm, kitt, flashingLights, runningPalette, xmas, Fire2012, arc_pulse };

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
  
  Homie_setFirmware("SuperLEDstrip", "2.0.0"); // The underscore is not a typo! See Magic bytes
  Homie.disableResetTrigger();                 // disable ResetTrigger, because it creates some problemes for me
  //Homie.setStandalone();                     // uncomment if you do not want to use wifi
  Homie.setSetupFunction(setupHandler).setLoopFunction(loopHandler);
  temperatureNode.advertise("unit");
  temperatureNode.advertise("degrees");
  humidityNode.advertise("percentage");
  lightNode.advertise("on").settable(lightOnHandler);
  lightNode.advertise("brightness").settable(lightBrightnessHandler);
  Homie.setGlobalInputHandler(globalInputHandler);
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
  EVERY_N_MILLISECONDS(1000 / FRAMES_PER_SECOND)
  {
    loopFastLED();
  }

  loopDHT();

  Homie.loop();

}

