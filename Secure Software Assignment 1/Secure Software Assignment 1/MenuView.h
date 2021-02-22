#pragma once
#include "Utilities.h"
#include "Model.h"
#include <iomanip>


class MenuView
{
public:

	MenuChoice mainMenu();																//dispalying main menu
	AdminMenuChoice adminMenu();														//dispalying staff menu
	void message(string str);															//dispalying messages
	void slopeInfo(const Model& model);													//dispalying slop current info
	void header();																		//displaying header for sensors
	void displayPredicted(tm tm, int16_t i16_tempAtTop, int16_t i16_tempAtBottom,
		int16_t ui16_wind, int16_t ui16_snow);						//dispalying predicted values
	void tempTestHeader();																//header for test
	void displayTempTest(int16_t i16_tempTop, int16_t i16_tempBottom);					//temp results	
	void snowTestHeader();																//dispay header
	void displaySnowTest(int16_t i16_snow);												//displays snow rsult
	void windTestHeader();																//dispay header
	void displayWindTest(int16_t i16_wind,DeviceState state, string result );			//display results
	void dispalyLightTest(string result);

};