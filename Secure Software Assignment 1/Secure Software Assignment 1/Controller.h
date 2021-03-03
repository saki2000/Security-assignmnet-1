#pragma once
#include "MenuView.h"
#include "Model.h"
#include "Authenticator.h"
#include "User.h"
#include "ProofID.h"
#include "Permission.h"
#include <thread>



enum class authenticationLevel   // enumerator for authentication
{
	Staff,
	Admin
};

class Controller
{
private:
	Model model;
	MenuView menuView;
	AccessType accessType = AccessType::NA;		//initialize acces to no access

public:
	Controller() = default;
	bool menuExit();											//exit menu bool
	string yesNo();												//validating yes NO
	void mainMenu();											//displaying main menu 
	void adminLogin();											//admin login option
	void adminMenu(const User& user, Permission& permission);	//admin menu
	void predictedWeather();									//24h prediction
	void changeLocationName();									//changing Location name
	void overrideSpeed();										//manual speed adjustment
	void lightChange();											//light change
	void emergencyStop();										//emegrency lift stop
	void runTest();												//testing sensors
	void tempetureTest();										//testing temp sensors
	void windTest();											//testing windsensors
	void snowTest();											//testing snowsensors
	void lightsTest();											//testing lights
	int16_t i16_converToKnots(int16_t kmh);						//converting to knots
	void addNewUser();											//adding new staff member
	void loadData();											//loading reading from file
		
	Controller(const Controller&) = delete;						//comapiler flag
	Controller& operator=(const Controller&) = delete;			// preventing compiler flag error
};

