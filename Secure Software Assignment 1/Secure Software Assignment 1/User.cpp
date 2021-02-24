#include "User.h"

string User::getId() 
{
	return ID;
}
void User::enterId()
{
	view.message( "Please enter your ID: ");
	cin >> ID;
}
string User::getProofID()
{
	return proofId;
}
void User::setProofID(string proofId)
{
	this->proofId = proofId;
}
string User::getPrivilegeLvl()const
{
	return privilegeLvl;
}

void User::setPrivilegeLvl()
{
	PrivilegeLvl privlige;
	privilegeLvl = privlige.getPrivilegeLvl(ID);	// setting up privliges
}