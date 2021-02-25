#include "Logger.h"
#include "MenuView.h"


void PasswordLogger::log(string str)
{
	ofstream myFile("encryptedPasswords", ofstream::app);
	{
		if (myFile.fail())
		{	
			MenuView view;
			view.errorMessage("Couldny open file");
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
			MenuView view;
			view.errorMessage("Couldny open file");
		}
		else
			myFile << str << endl;

		myFile.close();
	}
};

void DataLogger::log(string str)
{
	ofstream myFile("DataFile.txt", ofstream::app);
	{
		if (myFile.fail())
		{
			MenuView view;
			view.errorMessage("Couldny open file");
		}
		else
		{
			myFile << str;
		}


		myFile.close();
	}
};