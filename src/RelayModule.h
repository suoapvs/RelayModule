/**
	RelayModule - class describes a set of methods
	for working with a digital relay module.

	Instantiation:
	RelayModule* relay = new RelayModule(2);

	If you need to invert a sensor signal:
	RelayModule* relay = new RelayModule(2, true);
	or call the method:
	relay.invert();

	Methods:
	relay.on();
	relay.off();
	relay.isOn();
	relay.isOff();

	v.1.1.1:
	- optimized calls of private methods;
	- updated invert() method.

	v.1.1.2:
	- removed deprecated init() method;
	- added setState() method.

	v.1.1.3:
	- optimized constructor;
	- updated documentation.

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

#define RELAY_DEFAULT_INVERT_SIGNAL false

class RelayModule final {

	private:
		/**
			Port number that is attached to the relay.
		*/
		int IN_pin;

		/**
			ON and OFF signal.
		*/
		int onSignal = LOW;
		int offSignal = HIGH;

	public:
		/**
			Constructor

			@param IN_pin - a digital port number
			that is attached to the relay
			@param invertSignal - invert relay signal (default, false):
			true - LOW is a ON signal;
			false - HIGH is a ON signal
		*/
		RelayModule(
			int IN_pin,
			boolean invertSignal = RELAY_DEFAULT_INVERT_SIGNAL
		);

		/**
			Destructor
			Turns off the relay before deleting the object.
		*/
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
			Changes current state of the relay.
			If the input parameter is true then turns on the relay,
			otherwise - turns off the relay.

			@param input - a new state (true / false)
		*/
		void setState(boolean input);

		/**
			Checks if the relay is on.

			@return true if the relay is on,
			false if the relay is off
		*/
		boolean isOn();

		/**
			Checks if the relay is off.

			@return true if the relay is off,
			false if the relay is on
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
			Turns on the relay.
		*/
		inline void turnOn();

		/**
			Turns off the relay.
		*/
		inline void turnOff();

		/**
			Writes a input signal to the relay.

			@param value - a new relay signal
		*/
		inline void write(int signal);

		/**
			Reads and returns the relay signal.

			@return relay signal
		*/
		inline int read();
};

#endif
