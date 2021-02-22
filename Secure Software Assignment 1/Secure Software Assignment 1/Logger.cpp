#include "Logger.h"

void PasswordLogger::log(string str)
{
	ofstream myFile("encryptedPasswords", ofstream::app);
	{
		if (myFile.fail())
		{
			cerr << "Couldny open file";
		}
		else
			myFile << str << endl;

		myFile.close();
	}
}

void PrivligeLogger::log(string str)
{
	ofstream myFile("encryptedPrivileges", ofstream::app);
	{
		if (myFile.fail())
		{
			cerr << "Couldny open file";
		}
		else
			myFile << str << endl;

		myFile.close();
	}
};

void DataLogger::log(string str)
{
	//cout << str << "data";
};