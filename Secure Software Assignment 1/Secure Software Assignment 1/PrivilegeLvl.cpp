#include "PrivilegeLvl.h"

static string decryptionFromFilePrivileges(string str)   //  function decrypting from file
{
	char key = 0b00100100;						// random bits file was encode with
	string output = str;
													//#SS8
	for ( uint16_t i = 0; i < str.size(); i++)
	{
		output[i] = str[i] ^ key;				// simple encryption
	}
	return output;
};

PrivilegeLvl::PrivilegeLvl()								// constructor reading from encoded file 
{															// and populating map
	string ID;
	string privilegeLvl;

	try
	{
		ifstream myFile2("encryptedPrivileges", ifstream::in);	// loading from the file
		myFile2.exceptions(ios::badbit | ios::failbit);

		if (myFile2.is_open())
		{															//#SS1
			if (!myFile2.fail())
			{
				while (myFile2.peek() != char_traits<char>::eof() && getline(myFile2, ID))								//reading data
				{
					getline(myFile2, privilegeLvl);
					ID = decryptionFromFilePrivileges(ID);
					privilegeLvl = decryptionFromFilePrivileges(privilegeLvl);
					privilegeMap.insert(pair<string, string>(ID, privilegeLvl)); // populating map of privliges
				}
			}
		}
		else
			view.errorMessage("Cant open file");
		myFile2.close();
	}
	catch (exception e)
	{
		cerr << "File error " << e.what();
	}
	

};

string PrivilegeLvl::getPrivilegeLvl(string userID)
{
	map<string, string>::iterator it;				//iterator for map
	it = privilegeMap.find(userID);					//compare inside map
	if (it != privilegeMap.end())					// check till end of map
	{
		return it->second;
	}
	else
		return "UNKNOWN";							// this should never be the case
};													// as all loged in users should have 
													// one of two lvl of privleges
