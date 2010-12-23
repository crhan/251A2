/*
 * Map.h
 *
 *  Created on: Dec 21, 2010
 *      Author: crhan
 */

#ifndef MAP_H_
#define MAP_H_

#include<string>
#include<vector>
#include<iostream>
#include"town.h"
using namespace std;

class map {

public:
	map();
	int print_townName(int index);
	int print_DBus(int townIndex);
	int print_NBus(string startT, int depTown, int desTown);

	vector<town>::iterator getTown(vector<town>::difference_type index){return aTown.begin()+index;}
	vector<town> *getTown();
	int newTown(string townName);
private:
	vector<town> aTown;
};

#endif /* MAP_H_ */
