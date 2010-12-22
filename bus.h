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
using namespace std;

class bus {
private:
	int desTown;
	string depTime;
	string desTime;
public:
	bus(int a, string b, string c){
		desTown = a;
		depTime = b;
		desTime = c;
	}

	int detail();

    string getDepTime() const
    {
        return depTime;
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
    void setDesTime(string desTime)
    {
        this->desTime = desTime;
    }
    void setDesTown(int desTown)
    {
        this->desTown = desTown;
    }

};

#endif /* BUS_H_ */
