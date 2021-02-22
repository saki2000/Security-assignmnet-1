#include "Authenticator.h"

string Authenticator::tokenEncryption(string toEncrypt)
{
	string output = toEncrypt;
	char key = (char)rand();
	for (uint16_t i = 0; i < toEncrypt.size(); i++)
	{
		output[i] = toEncrypt[i] ^ key;
	}
	return output; 
}

ProofID Authenticator::authenticatedUser(User& user)
{
	CredentialInfo credentials;
	ProofID proofID;
	string ID = user.getId();
	string password;
	string token;

	cout << "Please eneter password: ";
	cin >> password;

	if (credentials.userValidation(ID, password))
	{
		token = tokenEncryption(ID + password);
		proofID = ProofID(token);					// set token
		user.setProofID(token);						// set token
		user.setPrivilegeLvl();						// set privlige level
		cout << "You are Loged in \n";
		system("pause");
	}
	else
	{
		cout << "Invalid user ID or password! \n";
	}
	return proofID;
}







