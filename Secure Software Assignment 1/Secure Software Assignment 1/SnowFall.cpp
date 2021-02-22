#include "SnowFall.h"

int16_t SnowFall::ui16_read()const
{
	return i16_snow;
}

void SnowFall::write(int16_t i16_snow)
{
	if (i16_snow < 0)
		i16_snow = 0;
	this->i16_snow = i16_snow;
}

SnowFall::SnowFall()
{
	int16_t i16_rand;
	i16_rand = (((int16_t)rand()) % 10);
	this->i16_snow = i16_rand;
}