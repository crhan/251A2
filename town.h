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
	vector<bus>::iterator getBus(vector<bus>::difference_type index);
	vector<bus> *getBus(){ vector<bus> *ptr_bus=&aBus; return ptr_bus;}
	int addBus(int a, string b, string c);

};

#endif /* TOWN_H_ */