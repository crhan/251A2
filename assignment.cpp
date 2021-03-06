/*
 * Assignment.cpp
 *
 *  Created on: Dec 21, 2010
 *      Author: crhan
 */

#include"map.h"
#include"dijkstra.h"
#include<string>
#include<iostream>
#include<fstream>
using namespace std;

int print_menu();
int readInFile(string fileName, map &bMap);
int select();
int pDirectBus(map &a_map);
int pNextDB(map &a_map);
int PEAT(map &a_map, dijkstra & a_D);
int PQR(map &a_map, dijkstra &a_D);
string cinTime();

int main() {
	// read in from file
	map aMap;
	dijkstra aD;
	readInFile("input1.txt", aMap);

	//print the menu
	print_menu();
	while (true) {
		switch (select()) {
		case 1:
			print_menu();
			break;
		case 2:
			pDirectBus(aMap);
			break;
		case 3:
			pNextDB(aMap);
			break;
		case 4:
			PEAT(aMap, aD);
			break;
		case 5:
			PQR(aMap, aD);
			break;
		case 0:
			return 0;
		default:
			cout << "Not implemention\n";
		}
		cout << "\nPlease choose an option (Enter 1 for menu):\n";
	}
	return 0;
}

int readInFile(string fileName, map &bMap) {
	ifstream readin;
	readin.open(fileName.c_str());

	//Initialize towns name
	int cirTime(0);
	readin >> cirTime;

	for (int i = 0; i < cirTime; ++i) {
		string a;
		readin >> a;
		bMap.newTown(a);
	}

	//insert buses into town
	cirTime = 0;
	readin >> cirTime;
	for (int i = 0; i < cirTime; ++i) {
		int a, b;
		string c, d;
		readin >> a >> b >> c >> d;

		//insert "0" if time string only have three digits
		if (c.length() == 3) {
			c = "0" + c;
		}
		if (d.length() == 3) {
			d = "0" + d;
		}

		bMap.getTown(a)->addBus(b, c, d);
	}
	readin.close();

	return 0;
}

int print_menu() {
	cout << "\nWelcome to Bus Journey Planner\n"
		"1) Show main menu\n"
		"2) Print direct buses\n"
		"3) Print next direct bus\n"
		"4) Print earliest arrival time\n"
		"5) Print quickest route\n"
		"0) Exit\n\n"
		"Please choose an option:\n";

	return 0;
}

int select() {
	while (true) {
		int a;
		cin.sync();
		cin >> a;

		if (cin.fail()) {
			cin.clear(); //清除std::cin的错误状态
			cin.sync(); //清空输入缓冲区
			continue;
		} else {
			return a;
		}
	}
}

int pDirectBus(map &a_map) {
	cout << "Please enter a town number (0.." << (a_map.getTown()->size() - 1)
			<< "):\n";
	int townIndex = select();
	a_map.print_DBus(townIndex);

	return 0;
}

int pNextDB(map &a_map) {
	string depT;
	vector<bus>::difference_type townSize;
	int a, b;
	townSize = a_map.getTown()->size() - 1;

	//Collecting informations
	cout << "Please enter the start time:\n";
	depT = cinTime();
	cout << "Please enter the departure town number (0.." << townSize << "):\n";
	a = select();
	cout << "Please enter the destination town number (0.." << townSize
			<< "):\n";
	b = select();
	a_map.print_NBus(depT, a, b);

	return 0;
}

string cinTime() {
	string a;
	cin >> a;
	if (a.size() == 3) {
		a = "0" + a;
	}
	return a;
}

int PEAT(map &a_map, dijkstra &a_D) {
	string a;
	int b, c;
	vector<bus>::difference_type townSize;
	townSize = a_map.getTown()->size() - 1;

	cout << "Please enter the start time:\n";
	a = cinTime();
	cout << "Please enter the departure town number (0.." << townSize << "):\n";
	b = select();
	cout << "Please enter the destination town number (0.." << townSize
			<< "):\n";
	c = select();

	cout << a_D.earlyAT(a_map, a, b, c) << endl;

	return 0;
}

int PQR(map &a_map, dijkstra &a_D) {
	string a;
	int b, c;
	vector<bus>::difference_type townSize;
	townSize = a_map.getTown()->size() - 1;

	cout << "Please enter the start time:\n";
	a = cinTime();
	cout << "Please enter the departure town number (0.." << townSize << "):\n";
	b = select();
	cout << "Please enter the destination town number (0.." << townSize
			<< "):\n";
	c = select();

	string tmpTrace = a_D.QuickestR(a_map, a, b, c);
	string trace = (char) (b + 48) + tmpTrace;
	if (tmpTrace.empty()) {
		cout << "Journey not possible\n";
		return 1;
	}

	cout << trace << endl;
	a_map.displayTrace(trace, a);
	return 0;
}
