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
#include<iomanip>
#include"town.h"
using namespace std;

class map {

public:
	map();
	int print_townName(int index);
	int print_DBus(int townIndex);
	int print_NBus(string startT, int depTown, int desTown);

	vector<town>::iterator getTown(vector<town>::difference_type index) {
		return aTown.begin() + index;
	}
	vector<town> *getTown();
	int displayTrace(string trace, string startT);//TODO 修改成为接受两个int，一个表示开始，一个表示结束，还有一个string表示开始时间

	vector<bus>::iterator *traceBus(int a, int b, string stratT);

	int newTown(string townName);
private:
	vector<town> aTown;
};

#endif /* MAP_H_ */
