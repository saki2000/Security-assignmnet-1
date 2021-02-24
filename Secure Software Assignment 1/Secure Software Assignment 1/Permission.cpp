#include "Permission.h"
#include "Utilities.h"

Permission::Permission()				// constructor creating holdin access levels
{	
			//option:		0.exit	1.Loc	2.speed	3.Lights	4.test  5.add user 6.save  7.load	8.stop	
	mapOfAccess["staff"] = {FA,		FA,  	FA,		FA,         NA,     NA,			FA,		FA,		FA};
	mapOfAccess["admin"] = {FA,		FA,	    FA,		FA,			FA,		FA,			FA,		FA,		FA};
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
			view.message("Option " + to_string(optionID) + " not availalble");
	}
	else
		view.message("Level of Permission unknown");
	return AccessType::NA;
}
