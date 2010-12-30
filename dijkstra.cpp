/*
 * Dijkstra.cpp
 *
 *  Created on: Dec 21, 2010
 *      Author: crhan
 */

#include "dijkstra.h"

string dijkstra::earlyAT(map & a_map, string startTi, int depTo, int desTo) {
	int numTo = a_map.getTown()->size();
	vector<bool> unknown(numTo, true);
	vector<int> towns; //used to track the town to visit
	vector<string> arrTi(numTo, "9999"); //used to store the earliest time can be arrived

	//Initializing
	arrTi[depTo] = startTi;
	towns.push_back(depTo);
	vector<int>::iterator current = towns.begin();

	//begin to search, and calc the time of arrival
	for (int index = 0; current != towns.end() && unknown[*current] == true;) {
		//redefine "current" to fit the dynamic changes to "towns"


		//make current town to known and traversal this town
		unknown[*current] = false;
		vector<bus> *tmpBus = a_map.getTown(*current)->getBus();
		for (vector<bus>::iterator i = tmpBus->begin(); i != tmpBus->end(); ++i) {
			int tmpTown = i->getDesTown();
			if (unknown[tmpTown] == false || arrTi[*current] > i->getDepTime() //如果当前出发时间晚于该汽车发车时间，则通过
					|| arrTi[tmpTown] < (i -> getDepTime())) { //如果目标镇最早到达时间早于该车到达时间，则通过
				continue;
			}
			towns.push_back(tmpTown);
			if (arrTi[tmpTown] > i -> getDesTime()) {
				arrTi[tmpTown] = i -> getDesTime();
			}
		}
		++index;
		current = towns.begin() + index;
	}

	//try to find the earliest time to the desTo
	if (arrTi[desTo] != "9999") {
		return arrTi[desTo];
	} else {
		return "Journey not possible";
	}
}

dijkstra::dijkstra() {
}

string dijkstra::QuickestR(map & a_map, string startTi, int depTo, int desTo) {
	int numTo = a_map.getTown()->size();
	vector<bool> unknown(numTo, true);
	vector<string> traceBack(numTo);
	vector<int> towns; //used to track the town to visit

	vector<string> arrTi(numTo, "9999"); //used to store the earliest time can be arrived

	//Initializing
	arrTi[depTo] = startTi;
	towns.push_back(depTo);
	vector<int>::iterator current = towns.begin();

	//	traceBack[*current] = (char)(depTo+48);

	//begin to search, and calc the time of arrival
	for (int index = 0; current != towns.end() && unknown[*current] == true;) {
		//redefine "current" to fit the dynamic changes to "towns"


		//make current town to known and traversal this town
		unknown[*current] = false;
		vector<bus> *tmpBus = a_map.getTown(*current)->getBus();
		for (vector<bus>::iterator i = tmpBus->begin(); i != tmpBus->end(); ++i) {
			int tmpTown = i->getDesTown();
			if (unknown[tmpTown] == false || arrTi[*current] > i->getDepTime() //如果当前出发时间晚于该汽车发车时间，则通过
					|| arrTi[tmpTown] < (i -> getDepTime())) { //如果目标镇最早到达时间早于该车到达时间，则通过
				continue;
			}
			towns.push_back(tmpTown);
			if (arrTi[tmpTown] > i -> getDesTime()) {
				arrTi[tmpTown] = i -> getDesTime();
				traceBack[tmpTown] = traceBack[*current]
						+ (char) (tmpTown + 48);
			}
		}
		++index;
		current = towns.begin() + index;
	}

	//try to find the earliest time to the desTo
	if (arrTi[desTo] != "9999") {
		return traceBack[desTo];
	} else {
		return "";
	}
}

vector<int> dijkstra::calc(map & a_map, string startTi, int depTo) {
	int numTo = a_map.getTown()->size();
	vector<bool> unknown(numTo, true);
	//used to track the town to visit
	vector<int> towns;
	//used to store the earliest time can be arrived
	vector<string> arrTi(numTo, "9999");
	//traceBack vector, set to 9999 means can not reach
	vector<int> toReturn(numTo, 9999);

	//Initializing
	arrTi[depTo] = startTi;
	//Set to -1 means it's the begin point
	toReturn[depTo] = -1;
	towns.push_back(depTo);
	vector<int>::iterator current = towns.begin();

	//begin to search, and calc the time of arrival
	for (int index = 0; current != towns.end() && unknown[*current] == true;) {
		//redefine "current" to fit the dynamic changes to "towns"


		//make current town to known and traversal this town
		unknown[*current] = false;
		vector<bus> *tmpBus = a_map.getTown(*current)->getBus();
		for (vector<bus>::iterator i = tmpBus->begin(); i != tmpBus->end(); ++i) {
			int tmpTown = i->getDesTown();
			if (unknown[tmpTown] == false || arrTi[*current] > i->getDepTime() //如果当前出发时间晚于该汽车发车时间，则通过
					|| arrTi[tmpTown] < (i -> getDepTime())) { //如果目标镇最早到达时间早于该车到达时间，则通过
				continue;
			}
			towns.push_back(tmpTown);
			if (arrTi[tmpTown] > i -> getDesTime()) {
				arrTi[tmpTown] = i -> getDesTime();
				toReturn[tmpTown] = *current;
			}
		}
		++index;
		current = towns.begin() + index;
	}

	return toReturn;


//	//try to find the earliest time to the desTo
//	if (arrTi[desTo] != "9999") {
//		return arrTi[desTo];
//	} else {
//		return "Journey not possible";
//	}

}

