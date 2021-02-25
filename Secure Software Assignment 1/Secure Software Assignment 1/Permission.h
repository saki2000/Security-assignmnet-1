#pragma once
#include<map>
#include<vector>
#include "MenuView.h"

enum AccessType : int16_t               //enum for permissions
{
	NA = 0x00,
	FA = 0x10
};

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