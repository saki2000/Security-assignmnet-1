#pragma once
#include "User.h"
#include "ProofID.h"
#include "CredentialInfo.h"

class Authenticator
{
private:
	string tokenEncryption(string toEncrypt);
public:
	ProofID authenticatedUser(User& user);

};