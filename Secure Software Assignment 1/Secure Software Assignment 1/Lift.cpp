#include "Lift.h"
#include "MenuView.h"

void Lift::on()
{
	state = DeviceState::on;
	this->i16_speed = 8;
}

void Lift::off()
{
	state = DeviceState::off;
	this->i16_speed = 0;
}

DeviceState Lift::getState()const
{
	return state;
}

DeviceState Lift::getLights()const
{
	return lights;
}

void Lift::setSpeed(int16_t i16_speed_)
{
	this->i16_speed = i16_speed_;
}

int16_t Lift::i16_getSpeed()const
{
	return i16_speed;
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
	tm tm = MenuView::getTime();
	state = DeviceState::on;
	this->i16_speed = 8;

	if (tm.tm_hour > 15)					// checking if light should be on or off
		this->lights = DeviceState::on;
	else
		this->lights = DeviceState::off;
}