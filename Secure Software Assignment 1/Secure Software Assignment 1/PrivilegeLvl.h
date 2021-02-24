#pragma once
#include<map>
#include "MenuView.h"
#include<fstream>

using namespace std;

class PrivilegeLvl
{
private:
	MenuView view;
	map<string, string> privilegeMap; 

public:
	PrivilegeLvl();
	string getPrivilegeLvl(string userID);
};