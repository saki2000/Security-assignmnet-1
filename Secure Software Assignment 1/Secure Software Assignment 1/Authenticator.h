#pragma once
#include "User.h"
#include "ProofID.h"
#include "CredentialInfo.h"
#include "MenuView.h"

class Authenticator
{
private:
	MenuView view;
	string tokenEncryption(string toEncrypt);
public:
	ProofID authenticatedUser(User& user);

};