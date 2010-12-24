/*
 * Map.cpp
 *
 *  Created on: Dec 21, 2010
 *      Author: crhan
 */

#include "map.h"

map::map(){}

int map::print_DBus(int townIndex)
{
	vector<bus> *tmp = aTown[townIndex].getBus();
	if (tmp->begin() == tmp->end()){
		cout<<"No buses available\n";
		return 1;
	}
	for (vector<bus>::iterator i=tmp->begin();
			i !=tmp->end(); ++i){
		i->printBus();
	}

	return 0;
}

vector<town> *map::getTown()
{
	vector<town> *ptr_town=&aTown;
	return ptr_town;
}

int map::print_NBus(string startT, int depTown, int desTown)
{
	vector<bus> *tmp = aTown[depTown].getBus();

	//try to find the bus
	for ( vector<bus>::iterator i = tmp->begin();
			i != tmp->end(); ++i){
		//check if this is the one I need
		if ( i->getDesTown() == desTown
				&& i->getDepTime() >= startT){
			cout<<i->getDesTime()<<endl;
			return 0;
		}
	}
	//if reaching here, means there is no available buses
	cout<<"No buses available\n";
	return 1;
}

string map::displayTrace(string aString)
{
	cout<<"   From         To      Dep.  Arr.\n";
	string tmp;
	for (int i=0; i<aString.size()-1; ++i){
		int a = (int)aString[i]-48,
				b = (int)aString[i+1]-48;
		//TODO 打印bus的出发和到达时间即可


		cout<<setw(12)<<aTown[a].getName()<<aTown[b].getName()<<
				setw(6)<<endl;
	}
}

int map::newTown(string townName)
{
	town bTown(townName);
	aTown.push_back(bTown);

	return 0;
}







