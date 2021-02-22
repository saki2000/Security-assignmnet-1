#include "Lift.h"

void Lift::on()
{
	state = DeviceState::on;
	this->ui16_speed = 8;
}

void Lift::off()
{
	state = DeviceState::off;
	this->ui16_speed = 0;
}

DeviceState Lift::getState()const
{
	return state;
}

DeviceState Lift::getLights()const
{
	return lights;
}

void Lift::setSpeed(uint16_t ui16_speed)
{
	this->ui16_speed = ui16_speed;
}

uint16_t Lift::ui16_getSpeed()const
{
	return ui16_speed;
}

void Lift::lightsOn()
{
	this->lights = DeviceState::on;
}
void Lift::lightsOff()
{
	this->lights = DeviceState::off;
}

Lift::Lift()
{
	tm tm = time();
	state = DeviceState::on;
	this->ui16_speed = 8;

	if (tm.tm_hour > 15)					// checking if light should be on or off
		this->lights = DeviceState::on;
	else
		this->lights = DeviceState::off;
}