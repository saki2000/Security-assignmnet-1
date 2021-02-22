#pragma once
#include "Utilities.h"
#include "PrivilegeLvl.h"

class User
{
private:
	string ID;
	string proofId;
	string privilegeLvl;
public:
	string getId();
	void enterId();
	string getProofID();
	void setProofID(string proofId);
	void setPrivilegeLvl();
	string getPrivilegeLvl()const;
};