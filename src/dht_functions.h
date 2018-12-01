/*
 * DHT sensor
 */
bool DHT_POWER_STATE;           // power state of DHT
DHT dht(DHT_DATA_PIN, DHT_TYPE);
elapsedMillis timeElapsedDHT;

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
  if ( !DHT_POWER_STATE && (timeElapsedDHT/1000) > SENSOR_READ_INTERVAL )
  {
    digitalWrite(DHT_POWER_PIN, HIGH);
    DHT_POWER_STATE = true;
    timeElapsedDHT = 0;
  }

  // When seonsor is on and warmup time is reached, then read data and power off
  if ( DHT_POWER_STATE && (timeElapsedDHT/1000) > DHT_WARMUP )
  {
    fTemp = dht.readTemperature() + OFFSET_TEMP;
    dtostrf(fTemp, 4, 1, sTemp);
    sprintf(sTemp, "%s C", sTemp);
    if ( fTemp > 0 ) {
      temperatureNode.setProperty("degrees").send(String(fTemp));
    }

    fHumid = dht.readHumidity() + OFFSET_HUMID;
    dtostrf(fHumid, 3, 0, sHumid);
    sprintf(sHumid, "%s %", sHumid);
    if ( fHumid >= 0 ) {
      humidityNode.setProperty("percentage").send(String(fHumid));
    }
    
    setTextAllSensors();
    
    digitalWrite(DHT_POWER_PIN, LOW);
    DHT_POWER_STATE = false;
    timeElapsedDHT = 0;

  }
}
