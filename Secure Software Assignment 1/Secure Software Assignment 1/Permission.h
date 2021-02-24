#pragma once
#include<map>
#include<vector>
#include"Utilities.h"
#include "MenuView.h"

using namespace std;

class Permission
{
private:
	MenuView view;
	typedef vector<int16_t> ui16_options;
	map<string, ui16_options> mapOfAccess;

public:
	Permission();
	uint16_t ui16_permissionCheck(string privilegeLvl, uint16_t optionID);
};