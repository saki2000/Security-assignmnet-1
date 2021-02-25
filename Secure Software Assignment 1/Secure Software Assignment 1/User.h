#pragma once
#include "Utilities.h"
#include "PrivilegeLvl.h"
#include "MenuView.h"

class User
{
private:
	MenuView view;
	string ID;
	string proofId;
	string privilegeLvl;
public:
	~User();					// destructor - set all members to empty string
	string getId();
	void enterId();
	string getProofID();
	void setProofID(string proofId);
	void setPrivilegeLvl();
	string getPrivilegeLvl()const;
};