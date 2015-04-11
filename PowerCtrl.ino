/*Attiny85 arduino code for controlling step-down DC-DC converter(s)
Output is wired to Enable pin on the converter (high state enables)
Photoresistor is coupled with Odroid-U2 blue (heartbeat) led
to check if OS is running, if no blink is detected converters are powered down
when timeout is reached.

ATtiny uses internal 1 MHz oscillator

elapsedMillis library is required: https://github.com/pfeerick/elapsedMillis

Instructions how to enable Attiny85 support in Arduino IDE: http://highlowtech.org/?p=1695
*/
#include <elapsedMillis.h>
int lightPin=3; //photoresistor input pin (attiny 2)
int outPin=0; //output pin (attiny 5)
elapsedMillis timer0;
boolean timedOut;
#define interval 10000 //timeout in millisecond
#define reference 512 //light threshold value, ~2.5V

void setup() {
pinMode(outPin, OUTPUT);
digitalWrite(outPin, LOW);
timedOut = true;
}

void loop() {
  if (timedOut){
    if (analogRead(lightPin)<reference){
    digitalWrite(outPin,HIGH);
    timedOut=false;
    timer0 =0;
    }
  }
    else if (!timedOut){
      if ((timer0<=interval)&&(analogRead(lightPin)<reference)){
      timer0 =0;
  }
  else if (timer0>interval) {
    digitalWrite(outPin,LOW);
    timedOut=true;
     }
  }
  }