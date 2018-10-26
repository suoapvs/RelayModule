/**
	RelayModule.h - The interface describes a set of methods
	for working with a digital relay module.

	Instantiation:
		RelayModule relay(2);

	If you need to invert a sensor signal:
		RelayModule relay(2, true);
	or call the method:
		relay.invert();

	Methods:
		relay.on();
		relay.off();
		relay.isOn();
		relay.isOff();

	v.1.1.1:
	- optimized calls of private methods.

	https://github.com/YuriiSalimov/RelayModule

	Created by Yurii Salimov, February, 2018.
	Released into the public domain.
*/
#ifndef RELAY_MODULE_H
#define RELAY_MODULE_H

#if defined(ARDUINO) && (ARDUINO >= 100)
	#include <Arduino.h>
#else
	#include <WProgram.h>
#endif

class RelayModule final {

	private:
		/**
			Port number that is attached to the relay.
		*/
		int IN_pin = 0;

		/**
			ON and OFF signal.
		*/
		volatile int onSignal = LOW;
		volatile int offSignal = HIGH;

	public:
		/**
			Constructor.
			@param IN_pin - a digital port number
			that is attached to the relay.
		*/
		RelayModule(const int IN_pin);

		/**
			Constructor.
			@param IN_pin - a digital port number
			that is attached to the relay.
			@param invertSignal - invert relay signal:
				true - LOW is a ON signal;
				false - HIGH is a ON signal.
		*/
		RelayModule(const int IN_pin, const boolean invertSignal);

		~RelayModule();

		/**
			Turns on the relay if it is off.
		*/
		void on();

		/**
			Turns off the relay if it is on.
		*/
		void off();

		/**
			Checks if the relay is on.
			@return true if the relay is on,
			false if the relay is off.
		*/
		boolean isOn();

		/**
			Checks if the relay is off.
			@return true if the relay is off,
			false if the relay is on.
		*/
		boolean isOff();

		/**
			Inverts relay signal.
			If invert signal:
				onSignal = LOW
				offSignal = HIGH
			If not invert signal:
				onSignal = HIGH
				offSignal = LOW
		*/
		void invert();

	private:
		/**
			Initialization of module.
		*/
		inline void init();

		/**
			Turns on the relay.
		*/
		inline void turnOn();

		/**
			Turns off the relay.
		*/
		inline void turnOff();

		/**
			Wrintes a input signal to the relay.
			@param value - a new relay signal.
		*/
		void write(const int signal);

		/**
			Reads and returns the relay signal.
			@return relay signal.
		*/
		int read();
};

#endif
