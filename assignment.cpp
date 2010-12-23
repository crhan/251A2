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
int pDirectBus(map &a_map);
int pNextDB(map &a_map);

int main(){
	// read in from file
	map aMap;
	readInFile("input1.txt", aMap);

	//print the menu
	print_menu();
	while (true){
		switch (select()){
		case 1: print_menu();
		case 2: pDirectBus(aMap); break;
		case 3: pNextDB(aMap); break;
		case 4:
		case 5:
		case 0:
		default:;
		}
		cout<<"\nPlease choose an option (Enter 1 for menu):\n";
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
	cout<<"\nWelcome to Bus Journey Planner\n"
			"1) Show main menu\n"
			"2) Print direct buses\n"
			"3) Print next direct bus\n"
			"4) Print earliest arrival time\n"
			"5) Print quickest route\n"
			"0) Exit\n\n"
			"Please choose an option:\n";

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

int pDirectBus(map &a_map){
	cout<<"Please enter a town number (0.."<<(a_map.getTown()->size()-1)<<"):\n";
	int townIndex=select();
	a_map.print_DBus(townIndex);

	return 0;
}


int pNextDB(map &a_map){
	string depT;
	vector<bus>::difference_type townSize;
	int a, b;
	townSize = a_map.getTown()->size()-1;

	//Collecting informations
	cout<<"Please enter the start time:\n";
	cin>>depT;
	cout<<"Please enter the departure town number (0.."
			<<townSize<<"):\n";
	a=select();
	cout<<"Please enter the destination town number (0.."
			<<townSize<<"):\n";
	b = select();
	a_map.print_NBus(depT,a,b);

	return 0;
}
