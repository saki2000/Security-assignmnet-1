#pragma once
#include <cstdint>
#include <stdlib.h>

class Tempeture
{
public:
	virtual int16_t i16_read() const = 0;
	virtual void write(int16_t i16_temp) = 0;
};

class TempetureAtTop: Tempeture
{
private:
	int16_t i16_temp;
public:
	TempetureAtTop();						// constructor with random temp setting
	int16_t i16_read() const;				// returning data
	void write(int16_t i16_temp)override;	// reading from sensor
};

class TempetureAtBottom: Tempeture
{
private:
	int16_t i16_temp;
public:
	TempetureAtBottom();					// constructor with random temp setting
	int16_t i16_read() const;				// returning data
	void write(int16_t i16_temp)override;	// reading from sensor
};

