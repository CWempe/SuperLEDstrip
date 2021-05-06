# Changelog

## 3.0.0

* Switching to Homie 3.0.1 with support of Homie convention v3.0.1
* Control WLED Relay via brightness
* Add `RELAIS_ALWAYS_ON` for WLED pcb

## 2.7.0

* limited support for RGBW (SK6812 LEDs)
* using official FastLED library again

## 2.6.1

* Add pattern "lightsaber"

## 2.6.0

* Make BUTTON01 configurable via `custom_values.h`
* Add OUTPUT pins and make them configurable via `custom_values.h`

## 2.5.4

* Add version number to display

## 2.5.3

* Add USA flag

## 2.5.2

* Make pre defined palletes and pallete scenes selectable via Display

## 2.5.1

* Add support for Button01
  Changes between pre defined scenes

## 2.5.0

* Add color palletes
  * Add pre defines color palletes
  * Add pallete scenes (animation styles) `static pallete`, `running pallete` and `color rotation`
  * Make palletes and pallete scenes selectable via mqtt
  * Make pallete size changeable (via mqtt)
  * Save pallete to eeeprom and restore after reboot

## 2.4.1

* Add option to use DS18B20 instead of DHT22 sensor or neither

## 2.4.0

* Add pattern "custom color"
  * Add support to save and load tweo different custom colrs

## 2.3.0

* Migrate to PlatformIO
* Add option to correct color and color temperature via FastLED
* Move random color pattern to arcade tab
* Add support for RGBW and DMA via custom library ([coryking/FastLED](https://github.com/coryking/FastLED))
* Add support for external graphics in display svg
* Add patterns
  * spanish flag
  * halloween
