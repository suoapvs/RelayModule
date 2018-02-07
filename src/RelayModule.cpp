/**
	The class implements a set of methods of the RelayModule.h 
	interface for working with a digital relay module.

	https://github.com/YuriiSalimov/RelayModule

	Created by Yurii Salimov, December, 2017.
	Released into the public domain.
*/
#include "RelayModule.h"

RelayModule::RelayModule(const int IN_pin)
 : RelayModule::RelayModule(IN_pin, false) {
}

RelayModule::RelayModule(const int IN_pin, const boolean invert) {
	this->IN_pin = IN_pin;
	if (invert) {
		this->onSignal = HIGH;
		this->offSignal = LOW;
	} else {
		this->onSignal = LOW;
		this->offSignal = HIGH;
	}
	init();
}

/**
	Destructor.
	Turns off the relay before deleting the object.
*/
RelayModule::~RelayModule() {
	turnOff();
}

/**
	Initialization of module.
	Turns off the relay.
*/
void RelayModule::init() {
	pinMode(this->IN_pin, OUTPUT);
	off();
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

boolean RelayModule::isOn() {
	return read() == this->onSignal;
}

boolean RelayModule::isOff() {
	return read() == this->offSignal;
}

void RelayModule::turnOn() {
	write(this->onSignal);
}

void RelayModule::turnOff() {
	write(this->offSignal);
}

void RelayModule::write(const int signal) {
	digitalWrite(this->IN_pin, signal);
}
	
int RelayModule::read() {
	return digitalRead(this->IN_pin);
}
