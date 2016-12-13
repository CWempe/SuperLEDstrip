#include "Nextion.h"
#include "FastLED.h"
#include <elapsedMillis.h>
#include <DHT.h>
#include <stdlib.h>
#include "nextion_declaration.h";
FASTLED_USING_NAMESPACE

// Master RX, TX, connect to Nextion TX, RX
SoftwareSerial HMISerial(D1, D2);

char displayTitle[40] = "Klaas LED-Leiste";

/*
 * DHT sensor
 */
#define DHT_DATA_PIN  D4
#define DHT_POWER_PIN D0
#define DHT_READ_INTERVAL 120   // Interval the sensor data is read
#define DHT_WARMUP          5   // Time between power on and reading data
#define DHT_TYPE DHT22          // Change this if you have a DHT11
bool DHT_POWER_STATE;           // power state of DHT
DHT dht(DHT_DATA_PIN, DHT_TYPE);
elapsedMillis timeElapsedDHT;
float OffsetTemp    = -0;
float OffsetHumid   = 5;
float fTemp         = 0;
char  sTemp[10]     = "";
float fHumid        = 0;
char  sHumid[10]    = "";

/*
 * FastLED
 */
#define DATA_PIN            D3
#define NUM_LEDS           134
#define LEDS_PER_METER      60
#define LED_TYPE        WS2811
#define COLOR_ORDER        GRB
#define DEFAULT_BRIGHTNESS 128
#define FRAMES_PER_SECOND  120

CRGBArray<NUM_LEDS> leds;
uint8_t gHue = 0; // rotating "base color" used by many of the patterns
CRGB baseColor1 = CRGB::Blue;
CRGB baseColor2 = CRGB::Blue;
CRGBPalette16 currentPalette;
TBlendType    currentBlending;
uint8_t currentBrightness = DEFAULT_BRIGHTNESS;
bool lightOFF = false;

uint8_t gCurrentPatternNumber; // Index number of which pattern is current
uint8_t gLastPatternNumber = 255;

elapsedMillis timeElapsed1;
elapsedMillis timeElapsed2;


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
    fTemp = dht.readTemperature() + OffsetTemp;
    dtostrf(fTemp, 4, 1, sTemp);
    sprintf(sTemp, "%s C", sTemp);

    fHumid = dht.readHumidity() + OffsetHumid;
    dtostrf(fHumid, 3, 0, sHumid);
    sprintf(sHumid, "%s %", sHumid);
    
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
#include "led_patterns.h";

typedef void (*SimplePatternList[])();
//     Pattern IDs              0          1      2         3        4    5     6               7              8
SimplePatternList gPatterns = { oneColor, stars, confetti, rainbow, bpm, kitt, flashingLights, runningPalette, xmas };


// set brightness and save current value
void setBrightness(uint8_t newBrightness)
{
   currentBrightness = newBrightness;
   FastLED.setBrightness(currentBrightness);
}

// toggle brightness between 0 and current
void toggleBrightness()
{
  if (lightOFF == true)
  {
    // When light is off switch back on to current brightness
    FastLED.setBrightness(currentBrightness);
    lightOFF = false;
  }
  else
  {
    // else set brightness to 0 and lightOFF to true
    FastLED.setBrightness(0);
    lightOFF = true;
  }  
}

void setupFastLED()
{
  gCurrentPatternNumber = 8; // Index number of which pattern is current; default is 3
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
#include "nextion_registration.h";
#include "nextion_callback_functions.h";
#include "nextion_initialization.h";


void setTextTitle()
{
    title.setText(displayTitle);
    p01title.setText(displayTitle);
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
   ######################
   ### Main Functions ###
   ######################
*/
void setup(void)
{
  Serial.begin(115200);
  
  setupDHT();
  
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

}

