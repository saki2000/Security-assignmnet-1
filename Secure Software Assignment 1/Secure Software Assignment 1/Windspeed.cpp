#include "Windspeed.h"


int16_t Windspeed::ui16_read()const
{
	return i16_speed;
}

void Windspeed::write(int16_t i16_speedInKnots)
{
	if (i16_speedInKnots < 0)								// preventing wind be a negative
		i16_speedInKnots = 0;
	i16_speedInKnots = i16_knotsToKmh(i16_speedInKnots);	// getting speed in km
	this->i16_speed = i16_speedInKnots;						// setting speed
	if (i16_speed > 60)										// setting device status 
		this->windSensorState = DeviceState::off;			// depending on windspeed
	else
		this->windSensorState = DeviceState::on;
}

DeviceState Windspeed::state()const
{
	return windSensorState;
}

void Windspeed::retracted()
{
	windSensorState = DeviceState::off;
}

void Windspeed::protracted()
{
	windSensorState = DeviceState::on;
}

int16_t Windspeed::i16_knotsToKmh(int16_t i16_knots)
{
	double d_kmh;
	int16_t i16_temp;
	d_kmh = i16_knots * 1.852;				// converting to km/h
	i16_temp = (int16_t)d_kmh;					// casting to whole number
	if ((d_kmh - i16_temp) > 0.4 )
		d_kmh = d_kmh + 1;					// taking care of rounding error when casting to int 
	return (int16_t)d_kmh;					
}

Windspeed::Windspeed()
{
	int16_t i16_rand;
	i16_rand = (((int16_t)rand()) % 22);				// genereating number in knots
	write(i16_rand);									// setting speed and status
}