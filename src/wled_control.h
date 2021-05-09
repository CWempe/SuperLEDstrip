void wled_power(bool pwrState)
{
    HTTPClient http; 
    
    // Ziel definieren
    http.begin("http://192.168.1.83/json");
    http.addHeader("Content-Type", "application/json");

    StaticJsonDocument<200> doc;

    // Werte setzen
    doc["on"] = pwrState;

    // String erzeuigen    
    String requestBody;
    serializeJson(doc, requestBody);

    // Daten abschicken
    int httpResponseCode = http.POST(requestBody);

    if ( DEBUGLEVEL >= 1 ) {
        Homie.getLogger() << "[DEBUG1] JSON: " << requestBody << endl;

        Homie.getLogger() << "[DEBUG1] httpResponseCode: " << httpResponseCode << endl;
        // String response = http.getString();                       
        // Homie.getLogger() << "[DEBUG1] response: " << response << endl;
    }
}

void wled_scene(uint16_t effect, uint16_t pallette)
{
    HTTPClient http; 
    
    // Ziel definieren
    http.begin("http://192.168.1.83/json");
    http.addHeader("Content-Type", "application/json");

    StaticJsonDocument<200> doc;

    // Werte setzen
    doc["on"] = true;
    doc["seg"]["fx"] = effect;
    doc["seg"]["pal"] = pallette;

    // String erzeuigen    
    String requestBody;
    serializeJson(doc, requestBody);

    // Daten abschicken
    int httpResponseCode = http.POST(requestBody);

    if ( DEBUGLEVEL >= 1 && httpResponseCode > 0 ) {
        Homie.getLogger() << "[DEBUG1] JSON: " << requestBody << endl;

        Homie.getLogger() << "[DEBUG1] httpResponseCode: " << httpResponseCode << endl;
        // String response = http.getString();                       
        // Homie.getLogger() << "[DEBUG1] response: " << response << endl;
    } else {
        Homie.getLogger() << "[DEBUG1] httpResponseCode less than 0." << endl;
    }
}