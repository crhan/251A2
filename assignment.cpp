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
int select();

int main(){
	// read in from file
	map aMap;
	readInFile("input1.txt", aMap);

	//print the menu
	while (true){
		print_menu();
		switch (select()){
		case 1:
		case 2:
		case 3:
		case 4:
		case 5:
		case 0:
		default:;
		}
	}

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

int print_menu(){
	cout<<"Welcome to Bus Journey Planner\n\
			1) Show main menu\n\
			2) Print direct buses\n\
			3) Print next direct bus\n\
			4) Print earliest arrival time\n\
			5) Print quickest route\n\
			0) Exit\n\n\
			Please choose an option:";

	return 0;
}

int select(){
	while (true) {
		int a;
		cin.sync();
		cin >> a;

		if (cin.fail()) {
			cin.clear(); //清除std::cin的错误状态
			cin.sync(); //清空输入缓冲区
			continue;
		}
		else {
			return a;
		}
	}
}
