/*
 * Map.cpp
 *
 *  Created on: Dec 21, 2010
 *      Author: crhan
 */

#include "map.h"

map::map(){}

int map::newTown(string townName)
{
	town bTown(townName);
	aTown.push_back(bTown);

	return 0;
}





