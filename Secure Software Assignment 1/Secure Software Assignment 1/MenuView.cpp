#include "MenuView.h"

					
MenuChoice MenuView::mainMenu()															// Printing menu to the screen
{
	tm tm = time();
	uint16_t ui16_input = uint16_t(MenuChoice::SIZE);									// make sure this int is initialize to invalid value
	system("cls");																		//clear screen
	cout << "DATE: " << put_time(&tm, "%A %d %B %G    TIME: %R") << endl << endl;		// printing time

	cout << "    ---== WELCOME ==--- \n\n\n";
	cout << "Please select option : \n\n";
	cout << "[" << (uint16_t)(MenuChoice::CurrentWeather) << "] Wheather on the slope \n";
	cout << "[" << (uint16_t)(MenuChoice::NextDayWeather) << "] Prediction on next 24 hours \n";
	cout << "[" << (uint16_t)(MenuChoice::AdminLogIn) << "] Admin login \n\n";
	cout << "[" << (uint16_t)(MenuChoice::Quit) << "] EXIT \n \n";
	cout << "OPTION: ";
	validation(ui16_input);													// validate data with template
	while (ui16_input < 0 || ui16_input >= uint16_t(MenuChoice::SIZE))		// check if chocie is within range;
	{
		cout << "Please try again: ";
		validation(ui16_input);
	}
	return (MenuChoice)ui16_input;
};

AdminMenuChoice MenuView::adminMenu()
{
	uint16_t ui16_input = uint16_t(AdminMenuChoice::SIZE);
	system("cls");
	cout << "[" << (uint16_t)(AdminMenuChoice::Location) << "] Change Location Name \n";
	cout << "[" << (uint16_t)(AdminMenuChoice::OverrideSpeed) << "] Override speed \n";
	cout << "[" << (uint16_t)(AdminMenuChoice::ChangeLights) << "] Turn Lights ON/OFF \n";
	cout << "[" << (uint16_t)(AdminMenuChoice::RunTest) << "] Run Test \n";
	cout << "[" << (uint16_t)(AdminMenuChoice::AddUser) << "] Add User \n";
	cout << "[" << (uint16_t)(AdminMenuChoice::SaveData) << "] Save Data \n";
	cout << "[" << (uint16_t)(AdminMenuChoice::LoadData) << "] Load Data \n";
	cout << "[" << (uint16_t)(AdminMenuChoice::Emergency) << "] Emergency Stop \n\n";
	cout << "[" << (uint16_t)(AdminMenuChoice::LogOut) << "] LOG OUT \n\n";
	cout << "OPTION: ";
	validation(ui16_input);
	while (ui16_input < 0 || ui16_input >= uint16_t(AdminMenuChoice::SIZE)) // check if chocie is within range;
	{
		cout << "Please try again: ";
		validation(ui16_input);
	}
	return (AdminMenuChoice)ui16_input;
};

void MenuView::message(string str)
{
	cout << str << endl;
};

void MenuView::errorMessage(string str)
{
	cerr << str << endl;
}

void MenuView::header()
{
	cout << "HOUR" << setw(30) << "TEMPETURE AT TOP [C]" << setw(24) << "TEMPETURE AT TOP [C]" << setw(15) 
		 << "WIND [km/h]" << setw(20) << "SNOWFALL [mm/h]" << endl << endl;
};

void MenuView::displayPredicted(tm tm, int16_t i16_tempAtTop, int16_t i16_tempAtBottom, 
								int16_t ui16_wind, int16_t ui16_snow)
{
	ios init(NULL);
	init.copyfmt(cout);
	cout << put_time(&tm, "%a %H:%M");     // display formated time
	cout.copyfmt(init);
	cout << setw(25) << i16_tempAtTop << setw(24) << i16_tempAtBottom << setw(15) << ui16_wind << setw(20) << ui16_snow << endl;
}

void MenuView::slopeInfo(const Model& model)      // display current information
{
	cout << "*******************************" << endl;
	cout << "Welcome to: " << model.getName() << endl << endl;
	cout << "Current tempeture at the top:    " << model.i16_getTemperatureAtTop()
		 << " Celsius" << endl;
	cout << "Current tempeture at the bottom: " << model.i16_getTemperatureAtBottom()
		 << " Celsius" << endl;
	cout << "Windspeed:                       " << model.i16_getWindspeed()
		 << " km/h" << endl;
	cout << "Snow fall:                       " << model.i16_getSnowFall()
		 << " mm/h" << endl;
	cout << "Sking conditions:                " << model.skingConditions()  << endl;
	cout << "*******************************" << endl;
}

void MenuView::tempTestHeader()
{
	cout << "TOP TEMP[C]" << setw(20) << "BOTTOM TEMP[C]\n";
}

void MenuView::displayTempTest(int16_t i16_tempTop, int16_t i16_tempBottom)
{
	ios init(NULL);
	init.copyfmt(cout);
	cout.copyfmt(init);
	cout << setw(10) << i16_tempTop << setw(20) << i16_tempBottom << endl;
}

void MenuView::snowTestHeader()
{
	cout << "SNOW[mm/h]\n";
}

void MenuView::displaySnowTest(int16_t i16_snow)
{
	ios init(NULL);
	init.copyfmt(cout);
	cout.copyfmt(init);
	cout << setw(10) << i16_snow << endl;
}

void MenuView::windTestHeader()
{
	cout << "WINDSPEED[km/h]" << setw(25) << "ROTATOR STATUS [On/Off]"
		 << setw(20) << "LIFT TEST" << endl;
}

void MenuView::displayWindTest(int16_t i16_wind, DeviceState state, string result)
{
	ios init(NULL);
	init.copyfmt(cout);
	cout.copyfmt(init);
	cout << setw(15) << i16_wind << setw(25) << (int16_t)state << setw(20) << result <<endl;
}

void MenuView::dispalyLightTest(string result)
{
	cout << "TEST RESULT: " << result << endl;
}

