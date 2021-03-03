#include "Model.h"
#include "Decorator.h"
#include "MenuView.h"

Model::Model()
{
	this->name = "ZAKOPANE";
}

const string Model::getName() const
{
	return name;
}

void Model::setName(const string name_)
{
	this->name = name_;
}

int16_t Model::i16_getTemperatureAtBottom() const
{
	return tempetureAtBottom.i16_read();
}

void Model::setTemperatureAtBottom(const int16_t int16_tempeture)
{
	tempetureAtBottom.write(int16_tempeture);
}

int16_t Model::i16_getTemperatureAtTop() const
{
	return tempetureAtTop.i16_read();
}

void Model::setTemperatureAtTop(const int16_t int16_tempeture)
{
	tempetureAtTop.write(int16_tempeture);
}

int16_t Model::i16_getWindspeed() const
{
	return windspeed.i16_read();
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

int16_t Model::i16_getSnowFall() const
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
	if (i16_getWindspeed() > 30)
		return   "TO WINDY TO SKI";
	if (i16_getTemperatureAtTop() < -10)
		return   "GOOD CONDITIONS";
	if (i16_getTemperatureAtTop() > 5)
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
int16_t Model::i16_getLiftSpeed()const
{
	return lift.i16_getSpeed();
}

void Model::setLiftSpeed(int16_t i16_speed)
{
	lift.setSpeed(i16_speed);
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
	if (i16_getWindspeed() > 30)								// slowing down lift when strong lift
	{
		setLiftSpeed(intSubstaction<int16_t>(i16_getLiftSpeed() , (int16_t)2));
	}
		
	if (i16_getWindspeed() > 50 || i16_getSnowFall() > 25)	// automatic stop when very hard wind
	{															// or in case heavy snow
		lift.off();
	}

	if (i16_getWindspeed() < 10 && i16_getSnowFall() < 5)		// speedinf lift when perfect conditions
		setLiftSpeed(intAddition<int16_t>(i16_getLiftSpeed() ,(int16_t) 2));		//#SS4
}

void Model::logPassword(string name_, string pass_)				//#SS2
{
	logger = make_unique <PasswordLogger>();
	logger = make_unique <LoggerDecorator>(move(logger), FormatType::ENCRYPTEDPASS);
	logger->log(name_);
	logger->log(pass_);
}

void Model::logPrivlige(string name_, string priv_)				//#SS2
{
	logger = make_unique <PrivligeLogger>();
	logger = make_unique <LoggerDecorator>(move(logger), FormatType::ENCRYPTEDPRIV);
	logger->log(name_);
	logger->log(priv_);
}

void Model::logData()										//#SS2
{
	string data;
	logger = make_unique <DataLogger>();
	logger = make_unique <LoggerDecorator>(move(logger), FormatType::PLAIN);
	tm tm = MenuView::getTime();
	system("cls");

	data = to_string(tm.tm_mon + 1);						//saving month
	data += " " + to_string(tm.tm_mday);					//saving day
	data += " " + to_string(tm.tm_hour + 1);				//saving time
	data += "\n" + to_string(i16_getTemperatureAtTop());	//temp at top
	data += " " + to_string(i16_getTemperatureAtBottom());	//temp at bottom
	data += " " + to_string(i16_getWindspeed());			//wind
	data += " " + to_string(i16_getSnowFall()) + "\n";		//snowfall

	logger->log(data);

}