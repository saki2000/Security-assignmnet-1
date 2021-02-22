#pragma once
#include<string>
#include<map>
#include<fstream>
#include<iostream>

using namespace std;

class CredentialInfo
{
private:
	map <string, string> LoginPass;
public:
	CredentialInfo();
	bool userValidation(string, string);

};