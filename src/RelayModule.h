/**
	RelayModule.h - The interface describes a set of methods 
	for working with a digital relay module.

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
			Port number to be attached to the sensor.
		*/
		int IN_pin = 0;
	
		/**
			Invert relay signal:
			true - LOW is a ON signal;
			false - HIGH is a ON signal.
		*/
		boolean invert = false;
	
	public:
		/**
			Constructor.
			@param IN_pin - a digital port number 
			to be attached to the relay.
		*/
		RelayModule(const int IN_pin);
		
		/**
			Constructor.
			@param IN_pin - a digital port number 
			that is attached to the relay.
			@param invert - invert relay signal:
			true - LOW is a ON signal;
			false - HIGH is a ON signal.
		*/
		RelayModule(const int IN_pin, const boolean invert);

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

	private:
		/**
			Initialization of module.
		*/
		void init();

		/**
			Turns on the relay.
		*/
		void turnOn();

		/**
			Turns off the relay.
		*/
		void turnOff();

		/**
			Wrintes a input signal to the relay.
			@param value - a new relay signal.
		*/
		void write(const int signal);

		/**
			Reads and returns the relay signal.
			@return relay signal
		*/
		int read();
	
		/**
			Return ON signal.
			@return relay on signal.
		*/
		int onSignal();

		/**
			Return OFF signal.
			@return relay off signal.
		*/
		int offSignal();
};

#endif
