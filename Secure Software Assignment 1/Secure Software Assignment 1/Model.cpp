#include "Model.h"
#include "Decorator.h"

const string Model::getName() const
{
	return name;
}

void Model::setName(const string name)
{
	this->name = name;
}

int16_t Model::it16_getTemperatureAtBottom() const
{
	return tempetureAtBottom.i16_read();
}

void Model::setTemperatureAtBottom(const int16_t int16_tempeture)
{
	tempetureAtBottom.write(int16_tempeture);
}

int16_t Model::it16_getTemperatureAtTop() const
{
	return tempetureAtTop.i16_read();
}

void Model::setTemperatureAtTop(const int16_t int16_tempeture)
{
	tempetureAtTop.write(int16_tempeture);
}

int16_t Model::ui16_getWindspeed() const
{
	return windspeed.ui16_read();
}

void Model::setWindspeed(const int16_t ui16_windspeed)
{
	windspeed.write(ui16_windspeed);
	lifControl();
}

void Model::protractingWindSensor()
{
	windspeed.protracted();
}

void Model::retractingWindSensor()
{
	windspeed.retracted();
}

DeviceState Model::getWindState()const
{
	return windspeed.state();
}

int16_t Model::ui16_getSnowFall() const
{
	return snowFall.ui16_read();
}

void Model::setSnowFall(int16_t ui16_snowFall)
{
	snowFall.write(ui16_snowFall);
	lifControl();
}

string Model::skingConditions()const
{
	if (ui16_getWindspeed() > 30)
		return   "TO WINDY TO SKI";
	if (it16_getTemperatureAtTop() < -10)
		return   "GOOD CONDITIONS";
	if (it16_getTemperatureAtTop() > 5)
		return   "SNOW IS MELTING BE CAREFUL";
	else
		return  "PERFECT";
}

DeviceState Model::getLights()const
{
	return lift.getLights();
}

DeviceState Model::getLiftState()const
{
	return lift.getState();
}
uint16_t Model::ui16_getLiftSpeed()const
{
	return lift.ui16_getSpeed();
}

void Model::setLiftSpeed(uint16_t ui16_speed)
{
	lift.setSpeed(ui16_speed);
}

void Model::setLiftStateON()
{
	lift.on();
}

void Model::setLiftStateOFF()
{
	lift.off();
}

void Model::liftLightON()
{
	lift.lightsOn();
}

void Model::liftLightsOFF()
{
	lift.lightsOff();
}

void Model::lifControl()
{
	if (ui16_getWindspeed() > 30)								// slowing down lift when strong lift
		setLiftSpeed(ui16_getLiftSpeed() - 4);

	if (ui16_getWindspeed() > 50 || ui16_getSnowFall() > 25)	// automatic stop when very hard wind
	{															// or in case heavy snow
		lift.off();
	}

	if (ui16_getWindspeed() < 10 && ui16_getSnowFall() < 5)		// speedinf lift when perfect conditions
		setLiftSpeed(ui16_getLiftSpeed() + 2);
}

void Model::logPassword(string name, string pass)
{
	logger = make_unique <PasswordLogger>();
	logger = make_unique <LoggerDecorator>(move(logger), FormatType::ENCRYPTEDPASS);
	logger->log(name);
	logger->log(pass);
}

void Model::logPrivlige(string name, string priv)
{
	logger = make_unique <PrivligeLogger>();
	logger = make_unique <LoggerDecorator>(move(logger), FormatType::ENCRYPTEDPRIV);
	logger->log(name);
	logger->log(priv);
}

void Model::logData()
{
	logger = make_unique <DataLogger>();
	logger = make_unique <LoggerDecorator>(move(logger), FormatType::ENCRYPTEDPASS);
	logger->log("xxx");
}