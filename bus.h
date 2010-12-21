/*
 * Bus.h
 *
 *  Created on: Dec 21, 2010
 *      Author: crhan
 */

#ifndef BUS_H_
#define BUS_H_

#include<string>
#include<iostream>
#include"town.h"
using namespace std;

class bus {
public:
	bus(int a, int b, string c, string d){
		depTown = a;
		desTown = b;
		depTime = c;
		desTime = d;
	}
	int print(int printNum);


    string getDepTime() const
    {
        return depTime;
    }
    int getDepTown() const
    {
        return depTown;
    }
    string getDesTime() const
    {
        return desTime;
    }
    int getDesTown() const
    {
        return desTown;
    }
    void setDepTime(string depTime)
    {
        this->depTime = depTime;
    }
    void setDepTown(int depTown)
    {
        this->depTown = depTown;
    }
    void setDesTime(string desTime)
    {
        this->desTime = desTime;
    }
    void setDesTown(int desTown)
    {
        this->desTown = desTown;
    }

private:
	int depTown;
	int desTown;
	string depTime;
	string desTime;
};

#endif /* BUS_H_ */
