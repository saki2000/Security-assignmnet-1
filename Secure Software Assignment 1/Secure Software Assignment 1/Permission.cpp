#include "Permission.h"
#include "Utilities.h"

Permission::Permission()				// constructor creating holdin access levels
{	
	
			//option:		0.exit				1.Status			2.Loc				3.speed				4.Lights				5.test				6.add user				7.save				8.load				9.stop	
	mapOfAccess["staff"] = {AccessType::FA,		AccessType::FA,		AccessType::FA,  	AccessType::FA,		AccessType::FA,         AccessType::NA,     AccessType::NA,			AccessType::FA,		AccessType::FA,		AccessType::FA};
	mapOfAccess["admin"] = {AccessType::FA,		AccessType::FA,		AccessType::FA,	    AccessType::FA,		AccessType::FA,			AccessType::FA,		AccessType::FA,			AccessType::FA,		AccessType::FA,		AccessType::FA};
	
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
