#pragma once
#include <string>
using namespace std;

class ProofID
{
private:
	string proofID;
public:
	ProofID() {};
	ProofID(string);
	string getProofID();
	void setProofID(string);
};
