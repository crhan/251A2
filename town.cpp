/*
 * Town.cpp
 *
 *  Created on: Dec 21, 2010
 *      Author: crhan
 */

#include "town.h"

town::town(string a) :
	name(a), aBus() {
}

//vector<bus>::iterator town::getBus(vector<bus>::difference_type index)
//{
//	return aBus.begin()+index;
//}

vector<bus>::iterator town::getBus(int desTown, string time) {
	for (vector<bus>::iterator i = aBus.begin(); i != aBus.end(); ++i) {
		if (i->getDesTown() == desTown && i->getDepTime() > time)
			return i;
	}
	return aBus.end();
}

int town::addBus(int a, string b, string c) {
	bus tmp(a, b, c);
	aBus.push_back(tmp);

	return 0;
}

