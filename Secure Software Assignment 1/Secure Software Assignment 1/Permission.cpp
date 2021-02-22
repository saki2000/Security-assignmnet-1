#include "Permission.h"
#include "Utilities.h"

Permission::Permission()				// constructor creating holdin access levels
{	
			//option:		0.exit		1.speed	2.Lights	3.test  4.add user	5.stop	
	mapOfAccess["staff"] = {FA,			FA,		FA,         NA,     NA,			FA};
	mapOfAccess["admin"] = {FA,			FA,		FA,			FA,		FA,			FA};
}

uint16_t Permission::ui16_permissionCheck(string privilegeLvl, uint16_t optionID) // returning permision level
{
	map<string, ui16_options>::iterator it;
	it = mapOfAccess.find(privilegeLvl);

	if (it != mapOfAccess.end())
	{
		if (optionID <= it->second.size())
			return it->second[optionID];
		else
			cout << "Option " << optionID << " not availalble";
	}
	else
		cout << "Level of Permission " << privilegeLvl << " unknown";
	return AccessType::NA;
}
