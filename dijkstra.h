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
	string QuickestR(map &a_map, string startTi, int depTo, int desTo);

private:
};

#endif /* DIJKSTRA_H_ */
