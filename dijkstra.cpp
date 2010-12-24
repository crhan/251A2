/*
 * Dijkstra.cpp
 *
 *  Created on: Dec 21, 2010
 *      Author: crhan
 */

#include "dijkstra.h"

string dijkstra::earlyAT(map & a_map, string startTi, int depTo, int desTo)
{
	int numTo = a_map.getTown()->size();
	vector<bool> unknown(numTo, true);
	vector<int> towns; 						//used to track the town to visit
	vector<string> arrTi(numTo, "9999");	//used to store the earliest time can be arrived

	//Initializing
	unknown[depTo] = false;
	arrTi[depTo] = startTi;
	towns.push_back(depTo);
	vector<int>::iterator current = towns.begin();

	//begin to search
}



dijkstra::dijkstra()
{
}



