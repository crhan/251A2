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
	vector<bus> *tmp = aTown[townIndex].getBus();
	if (tmp->begin() == tmp->end()){
		cout<<"No buses available\n";
		return 1;
	}
	for (vector<bus>::iterator i=tmp->begin();
			i !=tmp->end(); ++i){
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







