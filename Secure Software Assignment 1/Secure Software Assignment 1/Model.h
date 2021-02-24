#pragma once
#include "Windspeed.h"
#include "Tempeture.h"
#include "SnowFall.h"
#include "Lift.h"
#include <string>
#include "Logger.h"
#include "Utilities.h"

using namespace std;

class Model
{
private:
	TempetureAtTop tempetureAtTop;
	TempetureAtBottom tempetureAtBottom;
	Windspeed windspeed;
	Lift lift;
	SnowFall snowFall;
	string name;
	unique_ptr<Logger>logger;

public:
	
	Model();														//constructor
	const string getName() const;									//get name
	void setName(const string name);								//set name
	int16_t i16_getTemperatureAtBottom() const;						//get temp at bottom
	void setTemperatureAtBottom(const int16_t i16_tempeture);		//set temp at bottom
	int16_t i16_getTemperatureAtTop() const;						//get temp at top
	void setTemperatureAtTop(const int16_t i16_tempeture);			//set temp at top
	int16_t i16_getWindspeed() const;								//get wind
	void setWindspeed(const int16_t i16_windspeed);					//set wind
	void retractingWindSensor();									//retracting wind sensor
	void protractingWindSensor();							 		//protracting wind sensor
	DeviceState getWindState()const;								//return state of windsensor
	int16_t i16_getSnowFall()const;									//get snow
	void setSnowFall(int16_t i16_snowFall);							//set snow	
	string skingConditions()const;									//return description of conditions on slope
	DeviceState getLights()const;									//return light state
	DeviceState getLiftState()const;								//return lift state
	uint16_t ui16_getLiftSpeed()const;								//return liftspeed
	void setLiftSpeed(uint16_t ui16_speed);							//set lif speed
	void setLiftStateON();											//turn on lift
	void setLiftStateOFF();											//switch off lift
	void liftLightON();												//changing light status
	void liftLightsOFF();			 								// changing lights status
	void lifControl();												//autoimatic lift control
	void logPassword(string name, string pass);						//saving password to file
	void logPrivlige(string name, string priv);						//saving privliges to file
	void logData();													//saving data to file

};

