#pragma once
#include <stdlib.h>
#include <cstdint>
#include "Utilities.h"

class Windspeed
{
private:
	int16_t i16_speed;								// expleined in wind.h why not using usigned int
	DeviceState windSensorState;					// status of wind sensor
public:
	Windspeed();									// constructor
	int16_t i16_knotsToKmh(int16_t i16_knots);		// proccessing data from knots to km/h
	DeviceState state()const;						// return state of sensor
	int16_t i16_read()const;						//	return speed reading
	void write(int16_t i16_speed);					// setting speed reading
	void retracted();								// changing state of lift to on
	void protracted();								// changing lift sate to off

};