#pragma once
#include "DeviceState.h"
#include <cstdint>

class Lift
{
private:
	DeviceState state;
	DeviceState lights;
	int16_t i16_speed;
	
public:
	Lift();									// constructor setting peramiters when build
	void on();								//changing state of lift to on
	void off();								// changing lift sate to off
	void lightsOn();						//changing light status
	void lightsOff();			 			// changing lights status
	DeviceState getState()const;			// return status
	DeviceState getLights()const;			// status of lights
	void setSpeed(int16_t i16_speed);		// setting speed
	int16_t i16_getSpeed()const;			// getter speed
};