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
	string name;
	vector<bus> aBus;

public:
	town(string a);
	vector<bus> getBus();
	int addBus(int a, string b, string c);

};

#endif /* TOWN_H_ */
