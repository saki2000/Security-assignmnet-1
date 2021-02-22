#pragma once
#include <cstdint>
#include <stdlib.h>

class SnowFall
{
private:
	int16_t i16_snow;						// snow and wind store as int not uint as 
public:										// i have to check for underflows and overflows
	SnowFall();								// and couldnt work out how to work with 2 diffrent types of var
	int16_t ui16_read()const;
	void write(int16_t i16_write);
};