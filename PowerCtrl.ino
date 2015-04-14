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
int buttonPin=4; //button input pin (attiny 3)
int ledPin=2; //led output pin (attiny 7)
boolean ledState=false;
elapsedMillis timer0;
boolean timedOut;
#define interval 10000 //timeout in millisecond- 10s
#define reference 512 //light threshold value, ~2.5V

void setup() {
pinMode(outPin, OUTPUT);
digitalWrite(outPin, LOW); //by default dc-dc converters are not enabled
pinMode(buttonPin,INPUT);
digitalWrite(buttonPin,HIGH); //enable internal pull-up resistor
digitalWrite(ledPin,LOW); //led is off
timedOut = true; //no need to check timer
}

void loop() {
  if (timedOut){
    if (digitalRead(buttonPin)==0){ //button is pressed- see PowerCtrl schematics
    digitalWrite(outPin,HIGH); //enable dc-dc converters
    timedOut=false; 
    timer0 =0; //reset timer0
    }
  }
    else {
      if ((timer0<=interval)&&(analogRead(lightPin)<reference)){
      timer0 =0; //when light is detected reset the timer
      ledState = !ledState; //switch led state
      digitalWrite(ledPin,ledState); //turn led on or off
  }
  else if (timer0>interval) {
    digitalWrite(outPin,LOW); //light was not detected and time is over- disable dc-dc converters
    timedOut=true;
     }
  }
  }
