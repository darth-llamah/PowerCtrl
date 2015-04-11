/*Attiny85 arduino code or controlling step-down converter(s)
Output is wired to Enable pin on the converter (high state enables)
Photoresistor is coupled with Odroid-U2 blue (heartbeat) led
to check if OS is running, if no blink is detected converters are powered down
when timeout is reached

Sensitivity is set using R3 potentiometer
Timeout is set using R4 potentiometer from ~0.5 to ~60 seconds
ATtiny uses internal 1 MHz oscillator

elapsedMillis library is required: https://github.com/pfeerick/elapsedMillis

Instructions how to enable Attiny85 support in Arduino IDE: http://highlowtech.org/?p=1695
*/
#include <elapsedMillis.h>
int lightIn=3; //photoresistor input pin (attiny 2)
int outPin=0; //output pin (attiny 5)
int lightRef=4; // light reference input (attiny 3)
int timeRef=2; //timeout setting pin (attiny 7)
elapsedMillis timer0;
boolean timedOut;
int interval;

void setup() {
  
pinMode(outPin, OUTPUT);
digitalWrite(outPin, LOW);
timedOut = true;
}

void loop() {
  interval=(analogRead(timeRef)*60);
  if (timedOut==true){
    if (analogRead(lightIn)<analogRead(lightRef)){
    digitalWrite(outPin,HIGH);
    timedOut=false;
    timer0 =0;
    }
  }
    else {
      if ((timer0<=interval)&&(analogRead(lightIn)<analogRead(lightRef))){
      timer0 =0;
  }
  else {
    digitalWrite(outPin,LOW);
    timedOut=true;
     }
  }
  }
