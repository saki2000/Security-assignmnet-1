#pragma once
#include "Utilities.h"
#include "Model.h"
#include <iomanip>

enum class MenuChoice           // enum for main menu
{
	Quit,
	CurrentWeather,
	NextDayWeather,
	AdminLogIn,
	SIZE                // using this to in case of of adding or deleting options
};

enum class AdminMenuChoice          // enum for admin menu
{
	LogOut,
	Status,
	Location,
	OverrideSpeed,
	ChangeLights,
	RunTest,
	AddUser,
	SaveData,
	LoadData,
	Emergency,
	SIZE
};


class MenuView
{
public:

	MenuChoice mainMenu();																//dispalying main menu
	AdminMenuChoice adminMenu();														//dispalying staff menu
	void message(string str);															//dispalying messages
	void errorMessage(string str);														//displaying error messeges
	void slopeInfo(const Model& model);													//dispalying slop current info
	void displayStatus(const Model& model);												//displaying status of device
	void header();																		//displaying header for sensors
	void displayPredicted(tm tm, int16_t i16_tempAtTop, int16_t i16_tempAtBottom,
						  int16_t ui16_wind, int16_t ui16_snow);						//dispalying predicted values
	void tempTestHeader();																//header for test
	void displayTempTest(int16_t i16_tempTop, int16_t i16_tempBottom);					//temp results	
	void snowTestHeader();																//dispay header
	void displaySnowTest(int16_t i16_snow);												//displays snow rsult
	void windTestHeader();																//dispay header
	void displayWindTest(int16_t i16_wind,DeviceState state, string result );			//display results
	void dispalyLightTest(string result);												//dispalay reuslt of light test
	void displayMoths();																//displaying months to choose
	void foundDataHeader();																//display hedaer for loaded data
	void displayHistoricalData(string month, string day, string hour, string top,
							   string bottom, string wind, string snow);			    //displaying historical data
	void clearScreen();																	//clearing screen
	static tm getTime();
};


