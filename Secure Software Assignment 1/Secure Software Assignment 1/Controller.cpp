#include "Controller.h"


static string yesNo()						// fun dispalying yes/no option
{
	string str;
	cin >> str;
	for (uint16_t i = 0; i < str.length(); i++)
	{
		str[i] = toupper(str[i]);
	}
	while (str != "Y" && str != "N")			//validating input
	{
		cout << " - Please choose only (Y)es or (N)o : ";
		cin >> str;
		for (uint16_t i = 0; i < str.length(); i++)
		{
			str[i] = toupper(str[i]);
		}
	}
	return str;
};

static bool menuExit()						// exit controler
{											// function making sure we want to quit
	bool menu = true;
	string answer;
	cout << "\n - Are You sure ?(Y/N): ";
	answer = yesNo();						//validating innput
	if (answer == "Y")
	{
		cout << endl << "Thank You, Good bye !";
		cin.get();
		menu = false;
	}
	return menu;
};

void Controller::mainMenu()
{
	MenuChoice choice = MenuChoice::CurrentWeather;
	bool menu = true;								//bool to keep menu running
	string answer;

	while (menu)
	{
		choice = menuView.mainMenu();
		switch (choice)
		{
		case MenuChoice::CurrentWeather:
			system("cls");
			model.lifControl();
			menuView.slopeInfo(model);
			system("pause");
			break;
		case MenuChoice::NextDayWeather:
			system("cls");
			Controller::predictedWeather();
			system("pause");
			break;
		case MenuChoice::AdminLogIn:
			adminLogin();                   
			break;
		case MenuChoice::Quit:
			menu = menuExit();
			break;
		}
	}
}

void Controller::predictedWeather()
{
	menuView.message("\n  --Predicted Weather for next 24h--  \n\n");
	menuView.header();
	tm tm = time();
	int16_t i16_topTemp = model.it16_getTemperatureAtTop();
	int16_t i16_bottomTemp = model.it16_getTemperatureAtBottom();
	int16_t i16_wind = model.ui16_getWindspeed();
	int16_t i16_snow = model.ui16_getSnowFall();
	
	for (int16_t i = 0; i < 24; i++)                // 24 hour loop simulation
	{
		tm.tm_hour++;
		if (tm.tm_hour > 23)						// date changing to display
		{
			tm.tm_hour = 0;
			tm.tm_wday++;
		}
		menuView.displayPredicted(tm,i16_topTemp, i16_bottomTemp, i16_wind, i16_snow );		// passing data
		
		i16_topTemp = checkAdd<int16_t>(i16_topTemp, (rand() % 3 - 1));						//randomazing
		i16_bottomTemp = checkAdd<int16_t>(i16_bottomTemp, (rand() % 3 - 1));				//
		i16_wind = checkAdd<int16_t>(i16_wind, (rand() % 31 - 15));							//data
		if (i16_wind < 0)																	//
			i16_wind = 0;																	//making sure
		i16_snow = checkAdd<int16_t>(i16_snow, (rand() % 6 - 3));							//no negative
		if (i16_snow < 0)																	//numbers generated
			i16_snow = 0;
	}
}

// admin login menu
void Controller::adminLogin()
{
	User user;
	ProofID proofID;
	Authenticator authenticator;
	bool login = true;
	string answer;
	Permission permission;

	while (login)
	{
		user.enterId();
		proofID = authenticator.authenticatedUser(user);

		if ((!proofID.getProofID().empty() && (proofID.getProofID() == user.getProofID())))
		{
			adminMenu(user,permission);
			login = false;					// changing proof of id to empty
			proofID.setProofID("");			// since key for proof id is generated randomly everytime	
		}									// user will have to login anytime when trying to access admin functions
		else                            
		{
			menuView.message("Would You like to try again? (Y/N)");
			answer = yesNo();
			if (answer == "N")
				login = false;
		}
	}
}

void Controller::adminMenu(const User& user, Permission& permission)
{
	AdminMenuChoice choice = AdminMenuChoice::OverrideSpeed;
	bool logged = true;								
	string answer;
	uint16_t ui16_optionID = 0;					//initialize option id to 0			
	
	while (logged)
	{
		system("cls");
		choice = menuView.adminMenu();
		switch (choice)
		{
		case AdminMenuChoice::OverrideSpeed:						// manual speed adj
			ui16_optionID = (uint16_t)AdminMenuChoice::OverrideSpeed;
			if (permission.ui16_permissionCheck(user.getPrivilegeLvl(), ui16_optionID))
			{
				overrideSpeed();
			}
			else
				menuView.message("Permission denied\nAdmin and Staff access only\n");
			system("pause");
			break;

		case AdminMenuChoice::ChangeLights:						// switching lights
			ui16_optionID = (uint16_t)AdminMenuChoice::OverrideSpeed;
			if (permission.ui16_permissionCheck(user.getPrivilegeLvl(), ui16_optionID))
			{
				lightChange();
			}
			else
				menuView.message("Permission denied\nAdmin and Staff access only\n");
			system("pause");
			break;

		case AdminMenuChoice::RunTest:							// testing lift sensors
			ui16_optionID = (uint16_t)AdminMenuChoice::RunTest;
			if (permission.ui16_permissionCheck(user.getPrivilegeLvl(), ui16_optionID))
			{
				runTest();
			}
			else
				menuView.message("Permission denied\nAdmin access only\n");;
			system("pause");
			break;

		case AdminMenuChoice::AddUser:									// add new member of staff
			ui16_optionID = (uint16_t)AdminMenuChoice::AddUser;
			if (permission.ui16_permissionCheck(user.getPrivilegeLvl(), ui16_optionID))
			{
				addNewUser();
			}
			else
				menuView.message("Permission denied\nAdmin access only\n");
			system("pause");
			break;

		case AdminMenuChoice::Emergency:								// emergency stop
			ui16_optionID = (uint16_t)AdminMenuChoice::Emergency;
			if (permission.ui16_permissionCheck(user.getPrivilegeLvl(), ui16_optionID))
			{
				emergencyStop();
			}
			else
				menuView.message("Permission denied\nAdmin and Staff access only\n");
			system("pause");
			break;

		case AdminMenuChoice::LogOut:								//exiting admin menu
			logged = false;
			break;
		}
	}
}

void Controller::overrideSpeed()
{
	string answer;
	uint16_t ui16_choice;
	int16_t i16_speed = 0;

	system("cls");
	menuView.message("Current lift speed: " + to_string(model.ui16_getLiftSpeed()) + "\n");
	menuView.message("Would You like o adjust speed manually? (Y/N)\n");
	answer = yesNo();

	if (answer == "Y")
	{
		menuView.message("Press:\n");
		menuView.message("[1] To increase speed\n");
		menuView.message("[2] To slow down\n");
		validation (ui16_choice);
		if (ui16_choice < 1 || ui16_choice > 2)			// making sure only correct input selected
		{
			menuView.message("Try again: \n");
			validation(ui16_choice);
		}
		if (ui16_choice == 1)														// using safe add
		{																			// templete
			model.setLiftSpeed(checkAdd(model.ui16_getLiftSpeed(), (uint16_t)2));	//to increse speer
		}																			//by 2
		if (ui16_choice == 2)
		{
			if (model.ui16_getLiftSpeed() < 4)
			{
				menuView.message("Lift already at minium speed\n");
			}
			else
			{
				model.setLiftSpeed(checkSubstract(model.ui16_getLiftSpeed(), (uint16_t)2));
			}
		}
		menuView.message("New lift speed: " + to_string(model.ui16_getLiftSpeed()) + "\n");
	}
	else
		return;


}

void Controller::lightChange()
{
	uint16_t i16_choice;
	
	menuView.message("LIGHTS OPTIONS\n");
	menuView.message("[1] Turn ON");
	menuView.message("[2] Turn OFF");

	validation(i16_choice);
	while (i16_choice < 1 || i16_choice > 2)			// validating input
	{
		menuView.message("Please try again:");
		validation(i16_choice);
	}

	if (i16_choice == 1)			//turning on
	{
		model.liftLightON();
		menuView.message("Lights are ON");
	}
	if (i16_choice == 2)			//turning off
	{
		model.liftLightsOFF();
		menuView.message("Lights are OFF");
	}
}

void Controller::runTest()
{
	system("cls");
	menuView.message("SYSTEM TESTING IN PROGRESS\n\n");
	menuView.message("Testing Tempeture Sensors\n\n");
	tempetureTest();
	menuView.message("Testing Snow Sensors\n\n");
	snowTest();
	menuView.message("Testing Wind Sensors\n\n");
	windTest();
	menuView.message("Testing Lights\n\n");
	lightsTest();
	menuView.message("\n\n -- TEST COMPLETED -- \n\n");
}

void Controller::tempetureTest()
{
	int16_t i16_temp;
	int16_t i16_tempTwo;
	int16_t i16_reset;
	int16_t i16_resetTwo;

	i16_reset = model.it16_getTemperatureAtTop();
	i16_resetTwo = model.it16_getTemperatureAtBottom();
	i16_temp = model.it16_getTemperatureAtTop();
	i16_tempTwo = model.it16_getTemperatureAtBottom();

	menuView.tempTestHeader();
	for (uint16_t i = 0; i < 10; i++)			// loop testing temp sensors
	{
		model.setTemperatureAtTop(checkAdd<int16_t>(i16_temp, (rand() % 5 - 3)));
		model.setTemperatureAtBottom(checkAdd<int16_t>(i16_tempTwo, (rand() % 5 - 3)));
		i16_temp = model.it16_getTemperatureAtTop();
		i16_tempTwo = model.it16_getTemperatureAtBottom();
		menuView.displayTempTest(i16_temp, i16_tempTwo);
		this_thread::sleep_for(chrono::milliseconds(300));
	}
	//dispalay outcome of sensor test, positivie if in certain range
	if(i16_temp < -40 || i16_temp > 40 || i16_tempTwo < -40 || i16_tempTwo > 40)
		menuView.message("\nSENSOR TEST: NEGATIVE\n");
	else
		menuView.message("\nSENSOR TEST: POSITIVE \n");

	// resteting sensor values
	model.setTemperatureAtTop(i16_reset);
	model.setTemperatureAtBottom(i16_resetTwo);
}

void Controller::snowTest()
{
	int16_t i16_temp;
	int16_t i16_reset;

	i16_temp = model.ui16_getSnowFall();
	i16_reset = model.ui16_getSnowFall();

	menuView.snowTestHeader();
	for (uint16_t i = 0; i < 10; i++)			// loop testing temp sensors
	{
		model.setSnowFall(checkAdd<int16_t>(i16_temp, (rand() % 10 - 5)));
		i16_temp = model.ui16_getSnowFall();
		menuView.displaySnowTest(i16_temp);
		this_thread::sleep_for(chrono::milliseconds(300));
	}
	//dispalay outcome of sensor test, positivie if in certain range
	if (i16_temp >  60)
		menuView.message("\nSENSOR TEST: NEGATIVE\n");
	else
		menuView.message("\nSENSOR TEST: POSITIVE \n");

	//reseting values
	model.setSnowFall(i16_reset);              
}

void Controller::windTest()
{
	int16_t i16_temp;
	int16_t i16_reset;
	DeviceState tempState = DeviceState::off;
	string result;

	i16_temp = model.ui16_getWindspeed();
	i16_reset = model.ui16_getWindspeed();
	

	menuView.windTestHeader();
	for (uint16_t i = 0; i < 10; i++)										// loop testing temp sensors
	{
		i16_temp = checkAdd<int16_t>(i16_temp, (rand() % 30 - 15));			//randomazing data
		i16_temp = i16_converToKnots(i16_temp);								//converting to knots
		model.setWindspeed(i16_temp);	
		i16_temp = model.ui16_getWindspeed();								//reading data
		tempState = model.getWindState();
		if (i16_temp < 60 && tempState == DeviceState::on)					//checking if automatic lif control works
			result = "OK";
		else if (i16_temp > 60 && tempState == DeviceState::off)
			result = "OK";
		else
			result = "ERROR";

		menuView.displayWindTest(i16_temp,tempState,result);
		this_thread::sleep_for(chrono::milliseconds(300));
	}

	//dispalay outcome of sensor test, positivie if in certain range
	if (i16_temp > 150)
		menuView.message("\nSENSOR TEST: NEGATIVE\n");
	else
		menuView.message("\nSENSOR TEST: POSITIVE \n");
	model.setWindspeed(i16_reset);
}

void Controller::lightsTest()
{
	string result;
	DeviceState temp = model.getLights();

	// testing lights OFF
	menuView.message("Switching Ligts OFF");
	model.liftLightsOFF();
	this_thread::sleep_for(chrono::milliseconds(300));
	if (model.getLights() == DeviceState::off)				// checking status of lights
		result = "OK";
	else
		result = "LIGHTS ERROR";
	menuView.dispalyLightTest(result);

	//testing lightON
	menuView.message("Switching Ligts ON");
	model.liftLightON();
	this_thread::sleep_for(chrono::milliseconds(300));
	if (model.getLights() == DeviceState::on)				// checking status of lights
		result = "OK";
	else
		result = "LIGHTS ERROR";
	menuView.dispalyLightTest(result);

	// reseting light status
	if (temp == DeviceState::on)
	{
		model.liftLightON();
	}
	else
		model.liftLightsOFF();
}

void Controller::addNewUser()
{
	string name;
	string passwordOne;
	string passwordTwo;
	string privligeLvl;
	string answer;
	bool correct = true;
	uint16_t ui16_choice;

	system("cls");
	menuView.message("Would You like to add new user? (Y/N):");
	answer = yesNo();
	if (answer == "Y")
	{
		while (correct)
		{
			menuView.message("\nPlease enter new ID: ");
			cin >> name;
			menuView.message("\nSelect privlige level: \n");
			menuView.message("[1] STAFF");
			menuView.message("[2] ADMIN\n");
			validation(ui16_choice);
			while (ui16_choice < 1 || ui16_choice >2)		// makeing sure only correct option selected
			{
				menuView.message("Please Try again");
				validation(ui16_choice);
			}
			if (ui16_choice == 1)
				privligeLvl = "staff";
			if (ui16_choice == 2)
				privligeLvl = "admin";

			menuView.message("\nEnter password:");
			cin >> passwordOne;
			menuView.message("\nRepeat password:");
			cin >> passwordTwo;
			if (passwordOne != passwordTwo)					// if passwords dont match
			{
				menuView.message("\nPasswords dont match, try again\n");
			}
			else
			{
				model.logPassword(name, passwordOne);
				model.logPrivlige(name, privligeLvl);
				correct = false;
			}
		}
	}
}














void Controller::emergencyStop()
{
	string answer;
	string message;

	menuView.message( "Shut down lift? (Y/N)\n");
	answer = yesNo();
	
	if (answer == "Y")
	{
		model.setLiftSpeed(0);				// set speed to 0
		model.setLiftStateOFF();			// change state to off
		model.liftLightsOFF();				// turn off lights
		system("cls");
		menuView.message("EMERGENCY STOP EXECUTED\n\n");

		message = "Lift speed: " + to_string(model.ui16_getLiftSpeed());
		message = message + "\nLift status: " + to_string((uint16_t)model.getLiftState());
		message = message + "\nLights staus: " + to_string((uint16_t)model.getLiftState());
		message = message + "\n\n";

		menuView.message(message);
	}
	else
		return;
}

int16_t Controller::i16_converToKnots(int16_t kmh)  // converting to knots
{
	double d_knots;
	int16_t i16_temp;
	d_knots = kmh * 0.539957;
	i16_temp = (int16_t)d_knots;			// casting to whole number
	if ((d_knots - i16_temp) > 0.4)			// rounding error
		d_knots = d_knots + 1;

	return (int16_t)d_knots;				// returning whole number
}