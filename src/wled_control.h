void wled_send_json(String json)
{
    HTTPClient http; 
    
    // Ziel definieren
    http.begin("http://192.168.1.83/json");
    http.addHeader("Content-Type", "application/json");

    // Daten abschicken
    int httpResponseCode = http.POST(json);

    if ( DEBUGLEVEL >= 1 && httpResponseCode > 0 ) {
        Homie.getLogger() << "[DEBUG1] JSON: " << json << endl;
        Homie.getLogger() << "[DEBUG1] httpResponseCode: " << httpResponseCode << endl;
        // String response = http.getString();                       
        // Homie.getLogger() << "[DEBUG1] response: " << response << endl;
    } else {
        Homie.getLogger() << "[DEBUG1] httpResponseCode less than 0." << endl;
    }
}