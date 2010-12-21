/*
 * Town.h
 *
 *  Created on: Dec 21, 2010
 *      Author: crhan
 */

#ifndef TOWN_H_
#define TOWN_H_

#include<vector>
#include<string>
#include"bus.h"
using namespace std;

class town {
private:
	int static townNum;
	string name;
//	vector<bus> aBus;


public:
	town();
	int addBus();


};

#endif /* TOWN_H_ */
