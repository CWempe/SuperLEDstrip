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

void wled_set_fx_pal()
{
  // Set speed for specific effects
  if ( wled_fx == "8" ) {
    wled_sx = "4";
  } else {
    wled_sx = "128";
  }
  
  // set colors for custom palettes
  if ( wled_pal == "3" || wled_pal == "4" ) {
    wled_send_json("{\"on\":true,\"seg\":[{\"col\":[" + wled_pal_custom + "],\"fx\":" + wled_fx + ",\"sx\":" + wled_sx + ",\"ix\":" + wled_ix + ",\"pal\":" + wled_pal + "}]}}");
  } else {
    wled_send_json("{\"on\":true,\"seg\":[{\"fx\":" + wled_fx + ",\"sx\":" + wled_sx + ",\"ix\":" + wled_ix + ",\"pal\":" + wled_pal + "}]}}");
  }
}