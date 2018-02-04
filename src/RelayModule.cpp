/**
	The class implements a set of methods of the RelayModule.h 
	interface for working with a digital relay module.

	https://github.com/YuriiSalimov/RelayModule

	Created by Yurii Salimov, December, 2017.
	Released into the public domain.
*/
#include "RelayModule.h"

RelayModule::RelayModule(const int IN_pin) {
	this->IN_pin = IN_pin;
	init();
}

RelayModule::RelayModule(const int IN_pin, const boolean invert) 
: RelayModule::RelayModule(IN_pin) {
	this->invert = invert;
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
	return read() == onSignal();
}

boolean RelayModule::isOff() {
	return read() == offSignal();
}

void RelayModule::turnOn() {
	write(onSignal());
}

void RelayModule::turnOff() {
	write(offSignal());
}

void RelayModule::write(const int signal) {
	digitalWrite(this->IN_pin, signal);
}
	
int RelayModule::read() {
	return digitalRead(this->IN_pin);
}

/**
	Return ON signal.
	@return LOW if the invert value is true,
	HIGH - otherwise.
*/
int RelayModule::onSignal() {
	return (this->invert ? LOW : HIGH);
}

/**
	Return OFF signal.
	@return HIGH if the invert value is true,
	LOW - otherwise.
*/
int RelayModule::offSignal() {
	return (this->invert ? HIGH : LOW);
}
