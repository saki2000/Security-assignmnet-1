#include "Permission.h"
#include "Utilities.h"

Permission::Permission()				// constructor creating holdin access levels
{	
	
			//option:		0.exit				1.Loc				2.speed				3.Lights				4.test				5.add user				 6.save				7.load				8.stop	
	mapOfAccess["staff"] = {AccessType::FA,		AccessType::FA,  	AccessType::FA,		AccessType::FA,         AccessType::NA,     AccessType::NA,			AccessType::FA,		AccessType::FA,		AccessType::FA};
	mapOfAccess["admin"] = {AccessType::FA,		AccessType::FA,	    AccessType::FA,		AccessType::FA,			AccessType::FA,		AccessType::FA,			AccessType::FA,		AccessType::FA,		AccessType::FA};
	
}

uint16_t Permission::ui16_permissionCheck(string privilegeLvl, uint16_t optionID) // returning permision level
{
	map<string, ui16_options>::iterator it;
	it = mapOfAccess.find(privilegeLvl);

	if (it != mapOfAccess.end())
	{
		if (optionID <= it->second.size())

			return static_cast <uint16_t>(it->second[optionID]);		// static cast to mitigate warrnings
		else
			view.message("Option " + to_string(optionID) + " not availalble");
	}
	else
		view.message("Level of Permission unknown");
	return static_cast <uint16_t>(AccessType::NA);
}
