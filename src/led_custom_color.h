uint8_t red   = 10;
uint8_t green = 10;
uint8_t blue  = 10;
uint8_t white = 10;  // only needed when FastLED supports RGBW

bool lightCustomColorHandler(HomieRange range, String value) {
    if (value == "off") {
        red   = 0;
        green = 0;
        blue  = 0;
        // white = 0;
        lightNode.setProperty("customColor").send("0,0,0");
    } else if (value == "on") {
        red   = 255;
        green = 255;
        blue  = 255;
        white = 255;
        lightNode.setProperty("customColor").send("255,255,255");
    } else {
        Serial.print (value);
        // split string at every "," and store in proper variable
        // convert final result to integer
        // red   = value.substring(0,value.indexOf(',')).toInt();
        // green = value.substring(value.indexOf(',')+1,value.indexOf(',', value.indexOf(',')+1)).toInt();
        // blue  = value.substring(value.indexOf(',', value.indexOf(',')+1)+1,value.indexOf(',', value.indexOf(',', value.indexOf(',')+1)+1)).toInt();
        
        uint8_t firstIndex = value.indexOf(',');
        uint8_t secondIndex = value.indexOf(',', firstIndex+1);
        uint8_t thirdIndex = value.indexOf(',', secondIndex+1);

        Homie.getLogger() << "thirdIndex: " << thirdIndex << endl;

        red   = value.substring(0,firstIndex).toInt();
        green = value.substring(firstIndex+1,secondIndex+1).toInt();
        blue  = value.substring(secondIndex+1,thirdIndex+1).toInt();

        // check is there is a fourth value provided
        if ( thirdIndex != 255 ) {
            white = value.substring(secondIndex+1).toInt();
        }
        

        // set led strip with new color
        customColor = CRGB(red, green, blue)
        setupOneColor(customColor);

        lightNode.setProperty("customColor").send(value);
    }
    return true;
}
