## Arduino ##
getestet mit Version 1.6.8

https://www.arduino.cc/en/Main/OldSoftwareReleases#previous

Version 1.6.9 scheint auch zu funktionieren.

## Board ##
ESP2866com (weiß nicht mehr)

Datei | Voreinstellungen | Zusätzliche Boardverwalter …

Stabel: http://arduino.esp8266.com/stable/package_esp8266com_index.json

Getestet: http://arduino.esp8266.com/stable/package_esp8266com_index.json


Werkzeuge | Board: [..] | Boardverwalter...

"esp8266 by ESP8266 Community"

Installieren…

## Libraries ##
Git (zum clonen der Bibliotheken aus den Repositories)

Installieren: https://git-scm.com/download/win

In das Verzeichnis %UserProfile%\Documents\Arduino\libraries\ wechseln.

Rechtsklick -> Git GUI here

### FastLED ###
(git master vom 30.4.2016)

`git clone https://github.com/FastLED/FastLED`

### Nextion ###
`git clone https://github.com/itead/ITEADLIB_Arduino_Nextion.git`

Debug deaktivieren und Serial2 nach Serial anpassen

https://github.com/itead/ITEADLIB_Arduino_Nextion#uno-like-mainboards

```
//#define DEBUG_SERIAL_ENAB#define dbSerial SerialLE
#define dbSerial Serial
//#define nexSerial Serial
/** 
* activate SoftSerial 
*/ 
#include <SoftwareSerial.h> 
extern SoftwareSerial HMISerial; 
#define nexSerial HMISerial
```

### SoftSerial ###
`git clone https://github.com/plerup/espsoftwareserial.git`

normal: https://www.reddit.com/r/arduino/comments/4b6jfi/nexconfigh_for_nextion_display_on_arduino_uno/

### elapsedMillis ###
über Bibliotheksverwaltung installieren.

Sketch | Bibliothek einbinden | Bibliotheken verwalten ..

### DHT sensor library by Ardafruit ###
über Bibliotheksverwaltung installieren. 
