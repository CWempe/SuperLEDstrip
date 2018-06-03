
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

