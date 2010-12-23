/*
 * Assignment.cpp
 *
 *  Created on: Dec 21, 2010
 *      Author: crhan
 */

#include"map.h"
#include<string>
#include<iostream>
#include<fstream>
using namespace std;

int print_menu();
int readInFile(string fileName, map &bMap);

int main(){
	// read in from file
	map aMap;
	readInFile("input1.txt", aMap);

	cout<<"haha";
	return 0;
}

int readInFile(string fileName, map &bMap){
	ifstream readin;
	readin.open(fileName.c_str());

	//Initialize towns name
	int cirTime(0);
	readin>>cirTime;

	for(int i=0; i<cirTime; ++i){
		string a;
		readin>>a;
		bMap.newTown(a);
	}

	//insert buses into town
	cirTime=0;
	readin>>cirTime;
	for(int i=0;i<cirTime; ++i){
		int a,b;
		string c,d;
		readin>>a>>b>>c>>d;

		//insert "0" if time string only have three digits
		if (c.length()==3){
			c="0"+c;
		}
		if (d.length()==3){
			d="0"+d;
		}

		bMap.getTown(a)->addBus(b,c,d);
	}

	return 0;
}
