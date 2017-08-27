# SuperLEDstripe

I started this project as a gift for my little cousin.
The goal was to create an LED strip that could be controlled by a kid via touchscreen.
The graphical layout is based on [Googles Material Design Guidelines](https://material.io/guidelines/material-design/introduction.html).

## Requirements

### Hardware

* [**Wemos D1 mini**](https://www.wemos.cc/)  
  An ESP8266 device is nice, because it is litte, cheap and we can add Wifi features later.  
  But any other Arduino compatible device should do.
* [**WS2812B LED strip**](https://de.aliexpress.com/item/1m-4m-5m-WS2812B-Smart-led-pixel-strip-Black-White-PCB-30-60-144-leds-m/2036819167.html?spm=a2g0s.9042311.0.0.Bdc3IG)  
  or any other LED strip that is [suported by FastLED](https://github.com/FastLED/FastLED#supported-led-chipsets)
   * It is recommended to use a **capacitor** to smooth out the power supply.  
      I used one with *1000 µF* and *16 V*.
* **level shifter** from 5V to 3.3V  
  like [Texas Instruments SN74HCT245N](http://www.ti.com/lit/ds/symlink/sn74hct245.pdf)
  * a 20 pin **IC socket** for this chip is a good idea, too
* [**DHT22**](https://www.aliexpress.com/wholesale?SearchText=dht22&opensearch=true)
  to get current temperture and humidity  
  This is not necessary, but it is very cheap. So why not?
* [**Nextion HMI touch screen**](https://nextion.itead.cc/)  
  I used the 3.2" basic model ([NX4024T032](https://www.itead.cc/wiki/NX4024T032))  
  * a few connectors to make it easier to (dis-)connect the display  
    [XHP-4](http://www.jst-mfg.com/product/pdf/eng/eXH.pdf)  
* **Power supply** like [this](https://de.aliexpress.com/item/5V-LED-Power-Supply-1A-2A-3A-6A-8A-10A-Switching-Adapter-AC110-240V-AC-to/32810906485.html)
  * a suitable male adapter like [these](https://de.aliexpress.com/item/10-pair-Led-Light-Strip-connector-DC-male-to-DC-female-Plug-Jack-cctv-connect-Adapter/1672619063.html) (not tested)
* **470Ω resistor**
* some more tools, cables and connectors
  * I used [Phoenix Contact MC 1,5/ 3-ST-3,5](http://www.produktinfo.conrad.com/datenblaetter/725000-749999/740631-da-01-en-LEITERPLATTENSTECKER_MC_1_5__3_ST_3_5.pdf) and [MCV 1,5/ 3-G-3,5 ](http://www.produktinfo.conrad.com/datenblaetter/725000-749999/740686-da-01-en-LEITERPLATTENSTECKER_MCV_1_5__3_G_3_5.pdf) to connect the LED cables, because they are small and are specified to work with the expected current..  
   But they are not good looking.
  * adding a **fuse** is a good idea for security, too
    
### Software

* [**Arduino IDE**](https://www.arduino.cc/en/Main/Software) (tested with v1.8.3)
  * You might need [**Git**](https://git-scm.com/download/win) to download some libraries  
    In Windows (10) start `Git Bash` and change to the libraries directory.  
    `cd ~/Documents/Arduino/libraries/`      
    Here you can `git clone`some libraries if necessary.
  * [**ESP8266 platform package**](https://github.com/esp8266/Arduino#installing-with-boards-manager) (tested with v2.3.0)  
     If you use an esp8266 device
  * libraries:
      * [**FastLED**](https://github.com/FastLED/FastLED) (tested with v3.1.6)
      * [**ITEADLIB\\_Arduino\\_Nextion**](https://github.com/itead/ITEADLIB_Arduino_Nextion#latestunstable) (tested with v0.9.0)
      * [**espsoftwareserial**](https://github.com/plerup/espsoftwareserial) (tested with v1.0)
      * [**elapsedMillis**](https://github.com/pfeerick/elapsedMillis) (tested with v1.0.4)
      * [**DHT sensor library**](https://github.com/adafruit/DHT-sensor-library) (tested with v1.3.0)
      * [**Adafruit Unified Sensor Driver**](https://github.com/adafruit/Adafruit_Sensor) (tested with v1.0.2)
* [**Nextion Editor**](https://nextion.itead.cc/resource/download/nextion-editor/)  
   This software is needed if you want to change the content of the display
* [**Inkscape**](https://inkscape.org/download)  
   to edit the graphics
* [**inkmake**](https://github.com/wader/inkmake)  
   to automatically create and export the necessary png files from the svg file
    * requires [Ruby](http://rubyinstaller.org/)
* [**msxml**](https://www.microsoft.com/en-us/download/details.aspx?id=21714)  
   to automatically replace colors in the svg file before exporting to png
* 

### Preparation

#### Nextion
Before you can start to compile the project you need to make some changes to the Nextion library.

Open the folling file with a text editor.  
`C:\Users\<username>\Documents\Arduino\libraries\ITEADLIB_Arduino_Nextion\NexConfig.h`

Disable debug by commenting it.

```
//#define DEBUG_SERIAL_ENABLE  
```

And replace

```
//#define nexSerial Serial
```

with

```
#include <SoftwareSerial.h>
extern SoftwareSerial HMISerial;
#define nexSerial HMISerial
```

see:

* https://github.com/itead/ITEADLIB_Arduino_Nextion#uno-like-mainboards
* https://www.reddit.com/r/arduino/comments/4b6jfi/nexconfigh_for_nextion_display_on_arduino_uno/
