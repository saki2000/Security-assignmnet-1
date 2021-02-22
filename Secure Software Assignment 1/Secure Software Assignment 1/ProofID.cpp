#include "ProofID.h"

ProofID::ProofID(string aproofID) :proofID(aproofID) {};

string ProofID::getProofID()
{
	return proofID;
}
void ProofID::setProofID(string proofID)
{
	this->proofID = proofID;
}