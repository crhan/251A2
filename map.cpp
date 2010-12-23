/*
 * Map.cpp
 *
 *  Created on: Dec 21, 2010
 *      Author: crhan
 */

#include "map.h"

map::map(){}

int map::print_DBus(int townIndex)
{
	for (vector<bus>::iterator i=aTown[townIndex].getBus()->begin();
			i != aTown[townIndex].getBus()->end(); ++i){
		i->printBus();
	}
	return 0;
}

vector<town> *map::getTown()
{
	vector<town> *ptr_town=&aTown;
	return ptr_town;
}

int map::newTown(string townName)
{
	town bTown(townName);
	aTown.push_back(bTown);

	return 0;
}







