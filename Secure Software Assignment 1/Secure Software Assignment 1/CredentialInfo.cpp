#include "CredentialInfo.h"

bool CredentialInfo::userValidation(string id, string pass)  // validating user
{
	map<string, string>::iterator it;				//map iterator

	it = LoginPass.find(id);
	if (it != LoginPass.end())						
	{
		if (!(it->second.compare(pass)))		//checking password
		{
			return true;						//returning validation if password match id
		}
	}
	return false;
}

static string decryptionFromFile(string str)   //  function decrypting from file
{
	unsigned char key = 0b11011011;						// random bits file was encode with
	string output = str;

	for (uint16_t i = 0; i < str.size(); i++)		
	{
		output[i] = str[i] ^ key;				// simple encryption
	}
	return output;
}

CredentialInfo::CredentialInfo()						// constructor reading from file and populating id, pass
{
	string id;												// storing id's
	string pass;											// storing passwords

	try
	{
		ifstream myFile("EncryptedPasswords", ifstream::in);	// loading from the file
		myFile.exceptions(ios::badbit | ios::failbit);

		if (myFile.is_open())
		{
			if (!myFile.fail())												// #SS1
			{
				while (myFile.peek() != char_traits<char>::eof() && getline(myFile, id))			//reading data
				{
					getline(myFile,pass);
					id = decryptionFromFile(id);
					pass = decryptionFromFile(pass);
					LoginPass.insert(pair<string, string>(id, pass));
				}
			}
		}
		else
			view.errorMessage("File error");
	}
	catch (exception e)
	{
		cerr << "File error " << e.what();
	}
}



