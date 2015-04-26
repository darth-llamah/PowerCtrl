**PwrBtn.ino**

Attiny85 arduino code for emulating USB keyboard with SystemControl keyes- the only attached key is the Power Key.

Uses slightly modified Adafruit's TrinketHidCombo library:
- changed VID and PID to Obdev's shared ones
- change device name

**Howto**:
- add Digispark support to Arduino: https://github.com/digistump/DigistumpArduino (NOTE: micronucleus upload won't work unless files are in Arduino's installation directory, eg. C:\Program Files (x86)\Arduino\hardware)
- copy /TrinketHidCombo_m directory to /libraries
- burn using an ISP programmer micronucleus bootloader to the Attiny: https://github.com/micronucleus/micronucleus (NOTE: I've used micronucleus-1.11-entry_jumper_pb0.hex which enters bootloader mode when pin 5 is connected to GND when power is applied)
- open sketch, compile and load
- enjoy :)
