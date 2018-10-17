
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

void setTextRotationSpeed()
{
    dtostrf(rotationSpeed, 3, 0, sRotationSpeed);
    p08speed01.setText(sRotationSpeed);
}

void setTextAll()
{
    setTextTitle();
    setTextAllSensors();
    setTextRotationSpeed();
}

void updateTab()
{
  setTextAll();
}

void updateRotationSpeed () {
  lightNode.setProperty("rotationSpeed").send(String(rotationSpeed));
  rotationSpeedMs = 3 * rotationSpeed * rotationSpeed - 120 * rotationSpeed + 1200;
  if ( rotationSpeedMs < 1 ) {
    rotationSpeedMs = 1;
  }
  ColorRotation.setPeriod(rotationSpeedMs);
  // Deactivated setTextRotationSpeed() here because it can produce "wdt reset"
  //setTextRotationSpeed();
  // store current scene number to eeprom
  Embedis::set("rotationSpeedValue", String(rotationSpeed));
}

void changeRotationSpeed (bool increaseSpeed)
{
  if ( increaseSpeed == true && rotationSpeed < 20 ) {
     rotationSpeed++;
  } else if ( increaseSpeed == false && rotationSpeed > 1 ) {
    rotationSpeed--;
  }
  // setTextRotationSpeed() can be deleted here if bug from updateRotationSpeed() is fixed
  setTextRotationSpeed();
  updateRotationSpeed();
}

void getRed ()
{
  uint32_t red = 999;
  p09sliderRed.getValue(&red);
  Homie.getLogger() << "Red: " << red << endl;
  // Sometimes getValue does not get the value so we try again
  if ( red != 999) {
    p09sliderRed.getValue(&red);
    Homie.getLogger() << "Red: " << red << endl;
  }
  if ( red != 999) {
    updateCustomColorRed(red);
  }  
}

void getGreen ()
{
  uint32_t green = 999;
  p09sliderGreen.getValue(&green);
  Homie.getLogger() << "Green: " << green << endl;
  // Sometimes getValue does not get the value so we try again
  if ( green != 999) {
    p09sliderGreen.getValue(&green);
    Homie.getLogger() << "Green: " << green << endl;
  }
  if ( green != 999) {
    updateCustomColorGreen(green);
  }
}


void getBlue ()
{
  uint32_t blue = 999;
  p09sliderBlue.getValue(&blue);
  Homie.getLogger() << "Blue: " << blue << endl;
  // Sometimes getValue does not get the value so we try again
  if ( blue != 999) {
    p09sliderBlue.getValue(&blue);
    Homie.getLogger() << "Blue: " << blue << endl;
  }
  if ( blue != 999) {
    updateCustomColorBlue(blue);
  }
}