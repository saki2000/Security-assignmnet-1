#include "Logger.h"
#include "MenuView.h"


void PasswordLogger::log(string str)				//#SS1
{
	try
	{
		ofstream myFile("encryptedPasswords", ofstream::app);
		myFile.exceptions(ios::badbit | ios::failbit);

		if (myFile.is_open())
		{
			if (!myFile.fail())
			{
				myFile << str << endl;
			}
		}
		else
			cerr << "Cant open file ";
		myFile.close();
	}
	catch (exception e)
	{
		cerr << "File error " << e.what();
	}
}

void PrivligeLogger::log(string str)				//#SS1
{
	try
	{
		ofstream myFile("encryptedPrivileges", ofstream::app);
		myFile.exceptions(ios::badbit | ios::failbit);

		if (myFile.is_open())
		{
			if (!myFile.fail())
			{
				myFile << str << endl;
			}
		}
		else
			cerr << "Cant open file  ";
		myFile.close();
	}
	catch (exception e)
	{
		cerr << "File error " << e.what();
	}

};

void DataLogger::log(string str)					//#SS1
{
	try
	{
		ofstream myFile("DataFile.txt", ofstream::app);
		myFile.exceptions(ios::badbit | ios::failbit);

		if (myFile.is_open())
		{
			if (!myFile.fail())
			{
				myFile << str;
			}
		}
		else
			cerr << "Cant open file";
		myFile.close();
	}
	catch (exception e)
	{
		cerr << "File error " << e.what();
	}
};