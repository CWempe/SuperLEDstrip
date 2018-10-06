
//InputCommand command;

//const uint8_t brightnessCount = 5;
//uint8_t brightnessMap[brightnessCount] = { 16, 32, 64, 128, 255 };
//uint8_t brightness = brightnessMap[brightnessCount - 1];

const uint8_t buttonCount = 8;

//const uint8_t buttonRedPin    =  7;
//const uint8_t buttonGreenPin  =  8;
//const uint8_t buttonBluePin   =  9;
//const uint8_t buttonYellowPin = 10;
//const uint8_t buttonWhitePin  = 11;
//
//const uint8_t ledRedPin    = 0;
//const uint8_t ledGreenPin  = 1;
//const uint8_t ledBluePin   = 4;
//const uint8_t ledYellowPin = 5;
//const uint8_t ledWhitePin  = 6;

//Bounce buttonRed = Bounce();
//Bounce buttonGreen = Bounce();
//Bounce buttonBlue = Bounce();
//Bounce buttonYellow = Bounce();
//Bounce buttonWhite = Bounce();

uint8_t currentPatternIndex = 0;


//uint8_t buttonPins[] = {
//  buttonRedPin,
//  buttonGreenPin,
//  buttonBluePin,
//  buttonYellowPin,
//  buttonWhitePin,
//};
//
//uint8_t ledPins[] = {
//  ledRedPin,
//  ledGreenPin,
//  ledBluePin,
//  ledYellowPin,
//  ledWhitePin,
//};
//
//Bounce buttons[] = {
//  buttonRed,
//  buttonGreen,
//  buttonBlue,
//  buttonYellow,
//  buttonWhite,
//};
//
//bool buttonChanged[buttonCount];
//
//ulong buttonPressTimes[buttonCount];
//
//String buttonNames[] = {
//  "Red",
//  "Green",
//  "Blue",
//  "Yellow",
//  "White",
//};
//
//CHSV buttonColors[] = {
//  CHSV(0, 255, 128),
//  CHSV(96, 255, 128),
//  CHSV(160, 255, 128),
//  CHSV(64, 255, 128),
//  CHSV(0, 0, 128),
//};



#include "arcade_ball.h"
//#include "arcade_juggle.h"
//#include "arcade_launcher.h"
//#include "arcade_colorInvaders.h"
//#include "arcade_simon.h"


void arc_pulse() {
  shiftDown();
  fadeToBlackBy(leds, 1, 10);
}

//void add() {
//  shiftDown();
//
//  fadeToBlackBy(leds, 1, 10);
//
//  for (uint8_t i = 0; i < buttonCount; i++) {
//    if (!buttons[i].read()) {
//      leds[0] += buttonColors[i];
//    }
//  }
//}

// List of modes.  Each is defined as a separate function below.
typedef void (*SimpleModeList[])();
SimpleModeList modes = {
  //launcher,
  arc_pulse,
  //add,
  //colorInvaders,
  //simon,
  //juggle,
};

uint8_t currentModeIndex = 0; // Index number of which mode is current

#define ARRAY_SIZE(A) (sizeof(A) / sizeof((A)[0]))

const int modeCount = ARRAY_SIZE(modes);

//void arcade_setup() {

//  for (uint8_t i = 0; i < buttonCount; i++) {
//    pinMode(ledPins[i], OUTPUT);
//  }

//  for (uint8_t i = 0; i < buttonCount; i++) {
//    pinMode(buttonPins[i], INPUT_PULLUP);
//  }
//
//  for (uint8_t i = 0; i < buttonCount; i++) {
//    buttons[i].attach(buttonPins[i]);
//  }

//}

//void arc_loop() {
  // update (get state) of all buttons
//  for (uint8_t i = 0; i < buttonCount; i++) {
//    buttonChanged[i] = buttons[i].update();
//
//  }
//
//  modes[currentModeIndex]();
//}


void shiftDown() {
  for (int i = NUM_LEDS - 1; i > 0; i--) {
    leds[i] = leds[i - 1];
  }
}

