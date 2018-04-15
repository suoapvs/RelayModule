/*
  Relay Blink (Inverted)

  Turns an Relay on for one second,
  then off for one second, repeatedly.

  https://github.com/YuriiSalimov/RelayModule

  Created by Yurii Salimov, April, 2018.
  Released into the public domain.
*/

#include <RelayModule.h>

#define RELAY_PIN   1
#define DELAY_TIME  1000
#define INVERT_RELAY true

RelayModule* relay;

// the setup function runs once when you press reset or power the board
void setup() {
  relay = new RelayModule(RELAY_PIN, INVERT_RELAY);
  /** or
     relay = new RelayModule(RELAY_PIN);
     relay->invert();
  */
}

// the loop function runs over and over again forever
void loop() {
  if (relay->isOn()) {
    relay->off(); // turn the relay off.
  } else if (relay->isOff()) {
    relay->on(); // turn the relay on.
  }
  delay(DELAY_TIME); // wait for a delay time.
}

