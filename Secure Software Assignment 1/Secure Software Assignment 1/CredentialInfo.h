#pragma once
#include<map>
#include<fstream>
#include "MenuView.h"

using namespace std;

class CredentialInfo
{
private:
	MenuView view;
	map <string, string> LoginPass;
public:
	CredentialInfo();
	bool userValidation(string, string);

};