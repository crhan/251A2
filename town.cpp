/*
 * Town.cpp
 *
 *  Created on: Dec 21, 2010
 *      Author: crhan
 */

#include "town.h"

town::town(string a):name(a),aBus(){}



vector<bus> town::getBus()
{
	return aBus;
}

int town::addBus(int a, string b, string c)
{
	bus tmp(a,b,c);
	aBus.push_back(tmp);

	return 0;
}



