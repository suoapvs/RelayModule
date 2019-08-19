/**
	The class implements a set of methods of the RelayModule.h
	interface for working with a digital relay module.

	https://github.com/YuriiSalimov/RelayModule

	Created by Yurii Salimov, December, 2017.
	Released into the public domain.
*/
#include "RelayModule.h"

RelayModule::RelayModule(const int IN_pin, const boolean invertSignal) {
  pinMode(this->IN_pin = IN_pin, OUTPUT);
  if (invertSignal) {
    invert();
  }
  off();
}

RelayModule::~RelayModule() {
  turnOff();
}

void RelayModule::on() {
  if (isOff()) {
    turnOn();
  }
}

void RelayModule::off() {
  if (isOn()) {
    turnOff();
  }
}

void RelayModule::setState(const boolean input) {
  if (input) {
    on();
  } else {
    off();
  }
}

boolean RelayModule::isOn() {
  return read() == this->onSignal;
}

boolean RelayModule::isOff() {
  return read() == this->offSignal;
}

inline void RelayModule::turnOn() {
  write(this->onSignal);
}

inline void RelayModule::turnOff() {
  write(this->offSignal);
}

inline void RelayModule::write(const int signal) {
  digitalWrite(this->IN_pin, signal);
}

inline int RelayModule::read() {
  return digitalRead(this->IN_pin);
}

void RelayModule::invert() {
  const int tempSignal = this->onSignal;
  this->onSignal = this->offSignal;
  this->offSignal = tempSignal;
}
