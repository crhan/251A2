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
#include"town.h"
using namespace std;

class map {

public:
	map();
	int print_townName(int index);
	int print_DBus(int index);
	int print_NBus(string depTime, string desTime, int desIndex);

	vector<town> getTown(){return aTown;}
private:
	vector<town> aTown;
};

#endif /* MAP_H_ */
