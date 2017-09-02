#include "Nextion.h"
#include "FastLED.h"
#include <elapsedMillis.h>
#include <DHT.h>
#include <stdlib.h>
#include "nextion_declaration.h"
#include "custom_values.h"
#include <Homie.h>

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
 * DHT sensor
 */
bool DHT_POWER_STATE;           // power state of DHT
DHT dht(DHT_DATA_PIN, DHT_TYPE);
elapsedMillis timeElapsedDHT;
float fTemp         = 0;
char  sTemp[10]     = "";
float fHumid        = 0;
char  sHumid[10]    = "";

/*
 * define HomieNodes
 */
HomieNode temperatureNode("temperature", "temperature");
HomieNode humidityNode("humidity", "humidity");
HomieNode lightNode("light", "switch");
//HomieNode lightNode("brightness", "brightness");


/*
 * ############################
 * ### Enviroment Functions ###
 * ############################
 */
void setupDHT()
{
  pinMode(DHT_POWER_PIN, OUTPUT);
  digitalWrite(DHT_POWER_PIN, HIGH);
  DHT_POWER_STATE = true;
  timeElapsedDHT = 0;
}

void loopDHT()
{
  // When sensor is on and intervall time is reached, then power on
  if ( !DHT_POWER_STATE && (timeElapsedDHT/1000) > DHT_READ_INTERVAL )
  {
    digitalWrite(DHT_POWER_PIN, HIGH);
    DHT_POWER_STATE = true;
    timeElapsedDHT = 0;
  }

  // When seonsor is on and warmup time is reached, then read data and power off
  if ( DHT_POWER_STATE && (timeElapsedDHT/1000) > DHT_WARMUP )
  {
    fTemp = dht.readTemperature() + DHT_OFFSET_TEMP;
    dtostrf(fTemp, 4, 1, sTemp);
    sprintf(sTemp, "%s C", sTemp);
    temperatureNode.setProperty("degrees").send(String(fTemp));

    fHumid = dht.readHumidity() + DHT_OFFSET_HUMID;
    dtostrf(fHumid, 3, 0, sHumid);
    sprintf(sHumid, "%s %", sHumid);
    humidityNode.setProperty("percentage").send(String(fHumid));
    
    setTextAllSensors();
    
    digitalWrite(DHT_POWER_PIN, LOW);
    DHT_POWER_STATE = false;
    timeElapsedDHT = 0;

  }
}


/*
 * #########################
 * ### FastLED Functions ###
 * #########################
 */
#include "led_patterns.h"

typedef void (*SimplePatternList[])();
//     Pattern IDs              0          1      2         3        4    5     6               7              8     9         10
SimplePatternList gPatterns = { oneColor, stars, confetti, rainbow, bpm, kitt, flashingLights, runningPalette, xmas, Fire2012, arc_pulse };


// set brightness and save current value
void setBrightness(uint8_t newBrightness)
{
   currentBrightness = newBrightness;
   FastLED.setBrightness(currentBrightness);
   lightNode.setProperty("brightness").send(String(currentBrightness));
}

// toggle brightness between 0 and current
void toggleBrightness()
{
  if (lightON == false)
  {
    // When light is off switch back on to current brightness
    FastLED.setBrightness(currentBrightness);
    lightNode.setProperty("on").send("true");
    lightON = true;
  }
  else
  {
    // else set brightness to 0 and lightON to true
    FastLED.setBrightness(0);
    lightNode.setProperty("on").send("false");
    lightON = false;
  }  
}

void setupFastLED()
{
  gCurrentPatternNumber = 3; // Index number of which pattern is current; default is 3 (rainbow)
  setBrightness(DEFAULT_BRIGHTNESS);
  FastLED.addLeds<LED_TYPE, DATA_PIN, COLOR_ORDER>(leds, NUM_LEDS);
}

void loopFastLED()
{
  if ( gLastPatternNumber != gCurrentPatternNumber) {
    leds(0, NUM_LEDS - 1) = CRGB::Black;
    gLastPatternNumber = gCurrentPatternNumber;
  }
  gPatterns[gCurrentPatternNumber]();
  FastLED.show();
}



/*
   #########################
   ### Nextion Functions ###
   #########################
*/
#include "nextion_registration.h"
#include "nextion_callback_functions.h"
#include "nextion_initialization.h"


void setTextTitle()
{
    title.setText(DISPLAY_TITLE);
    p01title.setText(DISPLAY_TITLE);
}

void setTextTemp()
{
    temp.setText(sTemp);
    p08temp02.setText(sTemp);
}

void setTextHumid()
{
    humid.setText(sHumid);
    p08humid02.setText(sHumid);
}

void setTextAllSensors()
{
    setTextTemp();
    setTextHumid();
}

void setTextAll()
{
    //setTextTitle();
    //setTextTemp();
    //setTextHumid();
}

void updateTab()
{
  setTextAll();
}

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

