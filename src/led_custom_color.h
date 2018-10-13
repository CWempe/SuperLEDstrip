bool lightCustomColorHandler(HomieRange range, String value) {
    if (value == "off") {
        customColor.red   = 0;
        customColor.green = 0;
        customColor.blue  = 0;
        // customColor.white = 0;
        lightNode.setProperty("customColor").send("0,0,0");
    } else if (value == "on") {
        customColor.red   = 255;
        customColor.green = 255;
        customColor.blue  = 255;
        // customColor.white = 255;
        lightNode.setProperty("customColor").send("255,255,255");
    } else {
        Serial.print (value);
        // split string at every "," and store in proper variable
        // convert final result to integer
        uint8_t firstIndex = value.indexOf(',');
        uint8_t secondIndex = value.indexOf(',', firstIndex+1);
        uint8_t thirdIndex = value.indexOf(',', secondIndex+1);

        customColor.red   = value.substring(0,firstIndex).toInt();
        customColor.green = value.substring(firstIndex+1,secondIndex+1).toInt();
        customColor.blue  = value.substring(secondIndex+1,thirdIndex+1).toInt();

        // check is there is a fourth value provided
        // if ( thirdIndex != 255 ) {
        //     customColor.white = value.substring(secondIndex+1).toInt();
        // }
        
        // set led strip with new color
        // customColor = CRGB(customColor.red, customColor.green, customColor.blue);
        setupOneColor(customColor);

        char customColorString[15] = "";
        sprintf(customColorString, "%i,%i,%i", customColor.red, customColor.green, customColor.blue);
        // sprintf(customColorString, "%i,%i,%i,%i", customColor.red, customColor.green, customColor.blue, customColor.white);
        
        lightNode.setProperty("customColor").send(customColorString);
    }
    return true;
}
