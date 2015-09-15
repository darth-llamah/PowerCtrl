#include "TrinketHidCombo_m.h"

#define Button 1

static char    ButtonPressed = 0;

void setup()
{

  pinMode(Button, INPUT);
  digitalWrite(Button, HIGH);

  TrinketHidCombo.begin(); // start the USB device engine and enumerate
}

void loop()
{



  // remember that the switch is active-high
  if (digitalRead(Button)==0) 
  {
    if (ButtonPressed == 0) // only on initial press, so the keystroke is not repeated while the button is held down
    {
      TrinketHidCombo.pressSystemCtrlKey(SYSCTRLKEY_POWER);
      delay(5); // debounce delay
    }
    ButtonPressed = 1;
  }
  else
  {
    if (ButtonPressed != 0) {
      delay(5); // debounce delay
    }
    ButtonPressed = 0;
  }

  TrinketHidCombo.poll(); // check if USB needs anything done
}
