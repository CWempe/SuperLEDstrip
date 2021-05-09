
void wled_post_data()
{
    HTTPClient http; 
    
    // Ziel definieren
    http.begin("http://192.168.1.83/json");
    http.addHeader("Content-Type", "application/json");

    StaticJsonDocument<200> doc;

    // Werte setzen
    doc["on"] = "true";
    doc["bri"] = 32;

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