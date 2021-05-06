# OTA Update for Homie via MQTT

Example:

```powershell
cd ./ota_updater
pip install -r requirements.txt

python ota_updater.py -l hostname -u user -d password -t "homie/" -i "devicename" ..\.pio\build\d1_mini_pro\firmware.bin

Source: https://github.com/homieiot/homie-esp8266/tree/develop/scripts/ota_updater

Documentation: https://homieiot.github.io/homie-esp8266/docs/3.0.1/others/ota-configuration-updates/
```
