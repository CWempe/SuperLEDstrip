/*
 * Temperature sensor
 */

// float fTemp         = 0;
// char  sTemp[10]     = "";

// OneWire oneWire(TEMP_DATA_PIN);
// DallasTemperature sensors(&oneWire);

void setupTemp() {
  sensors.begin();
}

void loopTemp() {
  sensors.requestTemperatures();
  
  fTemp = sensors.getTempCByIndex(0) + OFFSET_TEMP;
  dtostrf(fTemp, 4, 1, sTemp);
  sprintf(sTemp, "%s C", sTemp);
  
  temperatureNode.setProperty("degrees").send(String(fTemp));
    Homie.getLogger() << "[DEBUG] DS18B20: " << sTemp << endl;
  setTextTemp();
}