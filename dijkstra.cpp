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
	arrTi[depTo] = startTi;
	towns.push_back(depTo);
	vector<int>::iterator current = towns.begin();

	//begin to search, and calc the time of arrival
	for (int index = 0; current != towns.end() && unknown[*current] == true; ++index) {
		//redefine "current" to fit the dynamic changes to "towns"
		current = towns.begin() + index;

		//make current town to known and traversal this town
		unknown[*current] = false;
		vector<bus> *tmpBus = a_map.getTown(*current)->getBus();
		for (vector<bus>::iterator i = tmpBus->begin(); i != tmpBus->end(); ++i) {
			int tmpTown = i->getDesTown();
			if (unknown[tmpTown] == false) {
				continue;
			}
			towns.push_back(tmpTown);
			if (arrTi[tmpTown] > i -> getDesTime()) {
				arrTi[tmpTown] = i -> getDesTime();
			}
		}
	}

	//try to find the earliest time to the desTo
	if (arrTi[desTo] != "9999"){
		return arrTi[desTo];
	}
	else{
		return " Journey not possible";
	}
}



dijkstra::dijkstra()
{
}



