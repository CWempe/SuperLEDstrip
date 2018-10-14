void updateCustomColor() {
       // set led strip with new color
       // customColor = CRGB(customColor.red, customColor.green, customColor.blue);
       setupOneColor(customColor);

       char customColorString[15] = "";
       sprintf(customColorString, "%i,%i,%i", customColor.red, customColor.green, customColor.blue);
       // sprintf(customColorString, "%i,%i,%i,%i", customColor.red, customColor.green, customColor.blue, customColor.white);
       
       lightNode.setProperty("customColor").send(customColorString);
}

void updateCustomColorRed(uint8_t red, bool updateRGB = true) {
    customColor.red = red;

    // Send updated RGB values to mqtt and display.
    // But only do so if you do not want to change other colors at the same time.
    // In that case only send update when you changed the last color.
    if ( updateRGB == true) {
        updateCustomColor();
    }
}

void updateCustomColorGreen(uint8_t green, bool updateRGB = true) {
    customColor.green = green;

    // Send updated RGB values to mqtt and display.
    // But only do so if you do not want to change other colors at the same time.
    // In that case only send update when you changed the last color.
    if ( updateRGB == true) {
        updateCustomColor();
    }
}

void updateCustomColorBlue(uint8_t blue, bool updateRGB = true) {
    customColor.blue = blue;

    // Send updated RGB values to mqtt and display.
    // But only do so if you do not want to change other colors at the same time.
    // In that case only send update when you changed the last color.
    if ( updateRGB == true) {
        updateCustomColor();
    }
}


bool lightCustomColorHandler (HomieRange range, String value) {
    uint8_t red   = 0;
    uint8_t green = 0;
    uint8_t blue  = 0;

    if (value == "on") {
        red   = 255;
        green = 255;
        blue  = 255;
    } else if (value == "off") {
        red   = 0;
        green = 0;
        blue  = 0;
    } else {
        // split string at every "," and store in proper variable
        // convert final result to integer
        uint8_t firstIndex  = value.indexOf(',');
        uint8_t secondIndex = value.indexOf(',', firstIndex+1);
        uint8_t thirdIndex  = value.indexOf(',', secondIndex+1);

        red   = value.substring(0,firstIndex).toInt();
        green = value.substring(firstIndex+1,secondIndex+1).toInt();
        blue  = value.substring(secondIndex+1,thirdIndex+1).toInt(); 
    }
    
    // update color values and send updated values with the last update.
    updateCustomColorRed(red, false);
    updateCustomColorGreen(green, false);
    updateCustomColorBlue(blue, true);
    return true;
}
