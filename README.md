**PowerCtrl.ino:**

Attiny85 arduino code for controlling step-down DC-DC converter(s).
Output is wired to Enable pin on the converter (high state enables).
Photoresistor is coupled with Odroid-U2 blue (heartbeat) led to check if OS is running,
if no blink is detected converters are powered down when timeout is reached.

By default timeout is set to 10 seconds which should be enough for hartbeat to start blinking.

ATtiny uses internal 1 MHz oscillator.

elapsedMillis library is required: https://github.com/pfeerick/elapsedMillis

Instructions how to enable Attiny85 support in Arduino IDE: http://highlowtech.org/?p=1695




**1-Key-Keyboard:**

Slightly modified Flip's 1-Key-Keyboard:http://blog.flipwork.nl/?x=entry:entry081009-142605

When button is pressed sends "S" key, when released "Enter"- this launches Shutdown menu and executes Shutdown (by default selected action) in OpenElec XBMC/Kodi.

Programming and fuse settings info on Flip's blog (link above)

Circuit- slightly modified to use 5V power (instead of 3.6)- this should prevent any possible issues with analog input in PowerCtrl. See PowerBtn pdf/fzz file.

Changes:
- updated v-usb stack (and one line in main.c) so the code can be compiled with current AVR GCC
- project updated to use with Atmel Studio 6.2 (current version)
- changed sent scan codes
