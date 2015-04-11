Attiny85 arduino code for controlling step-down DC-DC converter(s).
Output is wired to Enable pin on the converter (high state enables).
Photoresistor is coupled with Odroid-U2 blue (heartbeat) led to check if OS is running,
if no blink is detected converters are powered down when timeout is reached.

By default timeout is set to 10 seconds which should be enough for hartbeat to start blinking.

ATtiny uses internal 1 MHz oscillator.

elapsedMillis library is required: https://github.com/pfeerick/elapsedMillis

Instructions how to enable Attiny85 support in Arduino IDE: http://highlowtech.org/?p=1695
