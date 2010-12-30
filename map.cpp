/*
 * Map.cpp
 *
 *  Created on: Dec 21, 2010
 *      Author: crhan
 */

#include "map.h"

map::map() {
}

int map::print_DBus(int townIndex) {
	vector<bus> *tmp = aTown[townIndex].getBus();
	if (tmp->begin() == tmp->end()) {
		cout << "No buses available\n";
		return 1;
	}
	for (vector<bus>::iterator i = tmp->begin(); i != tmp->end(); ++i) {
		i->printBus();
	}

	return 0;
}

vector<town> *map::getTown() {
	vector<town> *ptr_town = &aTown;
	return ptr_town;
}

int map::print_NBus(string startT, int depTown, int desTown) {
	vector<bus> *tmp = aTown[depTown].getBus();

	//try to find the bus
	for (vector<bus>::iterator i = tmp->begin(); i != tmp->end(); ++i) {
		//check if this is the one I need
		if (i->getDesTown() == desTown && i->getDepTime() >= startT) {
			cout << i->getDesTime() << endl;
			return 0;
		}
	}
	//if reaching here, means there is no available buses
	cout << "No buses available\n";
	return 1;
}

int map::displayTrace(string trace, string startT) {
	cout << setw(12) << "   From         To      Dep.  Arr.\n";
	string tmp;
	for (string::size_type i = 0; i < trace.size() - 1; ++i) {
		int a = (int) trace[i] - 48, b = (int) trace[i + 1] - 48;
		cout << setw(12) << left << aTown[a].getName();
		cout << setw(12) << left << aTown[b].getName();
		cout << setw(6) << (aTown[a].getBus(b, startT)->getDepTime());
		cout << setw(6) << (aTown[a].getBus(b, startT)->getDesTime());
		cout << endl;
		//reset the startT
		startT = aTown[a].getBus(b, startT)->getDesTime();
	}
	return 0;
}

vector<bus>::iterator *map::traceBus(int a, int b, string stratT)
{
	//TODO 追踪从a出发的找到时间晚于startT的通往b处的bus，返回指针？ 需要指针吗？
}

int map::newTown(string townName) {
	town bTown(townName);
	aTown.push_back(bTown);

	return 0;
}

