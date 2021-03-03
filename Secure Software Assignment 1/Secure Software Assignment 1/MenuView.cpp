#include "MenuView.h"

					
MenuChoice MenuView::mainMenu()															// Printing menu to the screen
{
	tm tm = getTime();
	uint16_t ui16_input = uint16_t(MenuChoice::SIZE);									// make sure this int is initialize to invalid value
	clearScreen();																		//clear screen
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
	clearScreen();
	cout << "  *** ADMIN MENU ***" << endl << endl;
	cout << "[" << (uint16_t)(AdminMenuChoice::Status) << "] Display Device Status \n";
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

void MenuView::displayStatus(const Model& model)
{
	system("cls");
	cout << "*****************************" << endl;
	cout << "*    -- DEVICE STATUS --    *" << endl;
	cout << "*****************************" << endl << endl << endl;
	cout << "Location: " << model.getName() << endl << endl;
	cout << "Tempeture at top         : " << setw(3) << model.i16_getTemperatureAtTop() << " [C]" << endl;
	cout << "Tempeture at bottom      : " << setw(3) << model.i16_getTemperatureAtBottom() << " [C]" << endl;
	cout << "Windspeed                : " << setw(3) << model.i16_getWindspeed() << " [km/h]" << endl;
	cout << "Rotator status (0/1)     : " << setw(3) << to_string((uint16_t)model.getWindState()) << endl;
	cout << "Snowfall                 : " << setw(3) << model.i16_getSnowFall() << " [mm/h]" << endl ;
	cout << "Lift speed               : " << setw(3) << model.i16_getLiftSpeed() << " [km/h]" << endl;
	cout << "Lift Status (0/1)        : " << setw(3) << to_string((uint16_t)model.getLiftState()) << endl;
	cout << "Lift Lights (0/1)        : " << setw(3) << to_string((uint16_t)model.getLights()) << endl;
	cout << "Predicted ski conditions : " << model.skingConditions() << endl << endl;
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

void MenuView::displayMoths()
{		 
	cout << "[1] Janduary " << endl;
	cout << "[2] February " << endl;
	cout << "[3] March " << endl;
	cout << "[4] April " << endl;
	cout << "[5] May " << endl;
	cout << "[6] June " << endl;
	cout << "[7] July " << endl;
	cout << "[8] August " << endl;
	cout << "[9] September " << endl;
	cout << "[10] October " << endl;
	cout << "[11] November " << endl;
	cout << "[12] December " << endl << endl;
	cout << " - Choice: ";
}

void MenuView::foundDataHeader()
{
	clearScreen();
	cout << "\n\n -- DATA FOUND -- \n\n";
}

void MenuView::displayHistoricalData(string month, string day, string hour, string top,
									 string bottom, string wind, string snow)
{
	cout << "DATE " << day << "/" << month << "      TIME:  " << hour <<":00" << endl << endl;
	cout << "Tempeture recorded ad top:    " << setw(4) << top << setw(8) << " [C]" << endl;
	cout << "Tempeture recorded ad bottom: " << setw(4) << bottom << setw(8) << " [C]" << endl;
	cout << "Windspeed recorded:           " << setw(4) << wind << setw(8) << " [km/h]" << endl;
	cout << "Snowfall recorded:            " << setw(4) << snow << setw(8) << " [mm/h]" << endl << endl << endl;
}

void MenuView::clearScreen()
{
	system("cls");
}

tm MenuView::getTime()						// tm for using time
{
	time_t current_time = time(0);
	tm now;
	localtime_s(&now, &current_time);
	return now;
}