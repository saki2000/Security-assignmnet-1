#include "Tempeture.h"

int16_t TempetureAtTop::i16_read() const
{
	return i16_temp;
}

void TempetureAtTop::write(int16_t i16_temp_)
{
	this->i16_temp = i16_temp_;
}

int16_t TempetureAtBottom::i16_read() const
{
	return i16_temp;
}

void TempetureAtBottom::write(int16_t i16_temp_)
{
	this->i16_temp = i16_temp_;
}

TempetureAtTop::TempetureAtTop()		//#SS4
{
	int16_t i16_rand;																//intSubtstraction checking for overflows
	i16_rand = intSubstaction<int16_t>((((int16_t)rand()) % 30 ), (int16_t) 20);  // generating random number from -20 to 9
	this->i16_temp = i16_rand;														// set initial values
}

TempetureAtBottom::TempetureAtBottom()			//#SS4
{
	int16_t i16_rand;
	i16_rand = intSubstaction<int16_t>((((int16_t)rand()) % 30), (int16_t) 20);	 // generating random number from -20 to 9
	this->i16_temp = i16_rand;													 // set initial values
}
