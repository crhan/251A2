/*
 * Dijkstra.h
 *
 *  Created on: Dec 21, 2010
 *      Author: crhan
 */

#ifndef DIJKSTRA_H_
#define DIJKSTRA_H_
#include<vector>
#include<string>
#include"map.h"

using namespace std;

class dijkstra {
public:
	dijkstra();
	string earlyAT(map &a_map, string startTi, int depTo, int desTo);
	//TODO 返回一个vector<int>，记录所有路径， 输入三个参数，不需要DesTo
	string QuickestR(map &a_map, string startTi, int depTo, int desTo);

	vector<int> calc(map &a_map, string startTi, int depTo);

private:
};

#endif /* DIJKSTRA_H_ */
