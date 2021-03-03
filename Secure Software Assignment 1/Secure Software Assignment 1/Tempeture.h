#pragma once
#include <cstdint>
#include <stdlib.h>
#include "Utilities.h"

class Tempeture
{
public:
	virtual int16_t i16_read() const = 0;
	virtual void write(int16_t i16_temp) = 0;
	virtual ~Tempeture() = default;
};

class TempetureAtTop: Tempeture
{
private:
	int16_t i16_temp;
public:
	TempetureAtTop();						// constructor with random temp setting
	 ~TempetureAtTop() = default;			// cimpailer error
	int16_t i16_read() const;				// returning data
	void write(int16_t i16_temp)override;	// reading from sensor
};

class TempetureAtBottom: Tempeture
{
private:
	int16_t i16_temp;
public:
	TempetureAtBottom();					// constructor with random temp setting
	~TempetureAtBottom() = default;			// compailer error
	int16_t i16_read() const;				// returning data
	void write(int16_t i16_temp)override;	// reading from sensor
};

