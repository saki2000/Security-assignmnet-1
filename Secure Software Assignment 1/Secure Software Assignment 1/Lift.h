#pragma once
#include"Utilities.h"

class Lift
{
private:
	DeviceState state;
	DeviceState lights;
	uint16_t ui16_speed;
	
public:
	Lift();									// constructor setting peramiters when build
	void on();								//changing state of lift to on
	void off();								// changing lift sate to off
	void lightsOn();						//changing light status
	void lightsOff();			 			// changing lights status
	DeviceState getState()const;			// return status
	DeviceState getLights()const;			// status of lights
	void setSpeed(uint16_t ui16_speed);		// setting speed
	uint16_t ui16_getSpeed()const;			// getter speed
};