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

	view.message( "Please eneter password: ");
	cin >> password;

	if (credentials.userValidation(ID, password))
	{
		token = tokenEncryption(ID + password);
		proofID = ProofID(token);					// set token
		user.setProofID(token);						// set token
		user.setPrivilegeLvl();						// set privlige level
		view.message( "You are Loged in ");
		system("pause");
	}
	else
	{
		view.message("Invalid user ID or password! ");
	}
	return proofID;
}







