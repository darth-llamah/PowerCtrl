PowerCtrl.ino:
Attiny85 arduino code for controlling step-down DC-DC converter(s).
Output is wired to Enable pin on the converter (high state enables).
Photoresistor is coupled with Odroid-U2 blue (heartbeat) led to check if OS is running,
if no blink is detected converters are powered down when timeout is reached.

By default timeout is set to 10 seconds which should be enough for hartbeat to start blinking.

ATtiny uses internal 1 MHz oscillator.

elapsedMillis library is required: https://github.com/pfeerick/elapsedMillis

Instructions how to enable Attiny85 support in Arduino IDE: http://highlowtech.org/?p=1695




1-Key-Keyboard:
Slightly modified Flip's 1-Key-Keyboard:http://blog.flipwork.nl/?x=entry:entry081009-142605
When pressed button sends "S" key, when released "Enter"- this launches Shutdown menu and executes Shutdown (default selected) in XBMC/Kodi.

Programming, fuse settings are available on Flip's blog.

Schematics- slightly modified to use 5V power (instead of 3.6)- this way it won't interfere with PowerCtrl. See PowerBtn pdf/fzz file.

Changes:
-updated v-usb stack (and one line in main.c) so code can compile with current AVG GCC
-project updated to use with Atmel Studio 6.2 (current version)
-changed sent scan codes