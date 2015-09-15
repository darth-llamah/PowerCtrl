/*
Attiny85 arduino code for controlling step-down DC-DC converter(s)
Output is wired to Enable pin on the converter (high state enables)
Photoresistor is coupled with Odroid-U2 blue (heartbeat) led
to check if OS is running, if no blink is detected converters are powered down
when timeout is reached.

ATtiny uses internal 1 MHz oscillator

elapsedMillis library is required: https://github.com/pfeerick/elapsedMillis

Instructions how to enable Attiny85 support in Arduino IDE: http://highlowtech.org/?p=1695

    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program; if not, write to the Free Software
    Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
    
    
*/
#include <elapsedMillis.h>
int lightPin=3; //photoresistor input pin (attiny 2)
int outPin=0; //output pin (attiny 5)
int buttonPin=4; //button input pin (attiny 3)
int ledPin=2; //led output pin (attiny 7)
boolean prevLightState=false; //remember if lightState was changed
boolean lightState;
elapsedMillis timer0;
boolean timedOut;
#define interval 10000 //timeout in millisecond- 10s
#define reference 512 //light threshold value, ~2.5V

void setup() {
pinMode(outPin, OUTPUT);
digitalWrite(outPin, LOW); //by default dc-dc converters are not enabled
pinMode(buttonPin,INPUT);
digitalWrite(buttonPin,HIGH); //enable internal pull-up resistor- button connects pin to GND
digitalWrite(ledPin,LOW); //led is off
timedOut = true; //no need to check timer
}

void loop() {
  if (analogRead(lightPin)<reference) lightState=true;
  else lightState=false;
  if (timedOut){
    if (digitalRead(buttonPin)==0){ //button is pressed- see PowerCtrl schematics
    digitalWrite(outPin,HIGH); //enable dc-dc converters
    timedOut=false; 
    timer0 =0; //reset timer0
    }
  }
    else {
      if (timer0<=interval){
        if ((lightState==true)&&(lightState!=prevLightState)){
      timer0 =0; //when light is detected reset the timer
      digitalWrite(ledPin,lightState); //turn led on
      prevLightState=lightState;
      }
      else if ((lightState==false)&&(lightState!=prevLightState)){
        digitalWrite(ledPin,lightState); // turn led off
        prevLightState=lightState;
      }
        
  }
  else if (timer0>interval) {
    digitalWrite(outPin,LOW); //light was not detected and time is over- disable dc-dc converters
    timedOut=true;
     }
  }
  }
