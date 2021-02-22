#pragma once
#include<map>
#include<string>
#include<fstream>
#include<iostream>

using namespace std;

class PrivilegeLvl
{
private:
	map<string, string> privilegeMap; 

public:
	PrivilegeLvl();
	string getPrivilegeLvl(string userID);
};