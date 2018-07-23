/*
 * List.h
 *
 *  Created on: 10 Kas 2015
 *      Author: Nehil
 */

#ifndef LIST_H_
#define LIST_H_

#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <cstdlib>
#include <fstream>
using namespace std;

class List {

public:
	List();
	~List();
	void deleteFromItemList(int);
	void putToTheItemList(string,string,int);
	void printTheItemList(char*);

	double stringToDoubleConverter(string);

	int getItemNumber();
	string getFirstItem();
	string getSecondItem();
	string getFirstItemType();
	string getSecondItemType();


private:
	int itemNumber;
	typedef struct itemNode{
		string value;
		string type;
		itemNode * next;

	}*itemNodePtr;
	itemNodePtr headOfList;
	itemNodePtr tailOfLits;
	itemNodePtr tempOfList;

};

#endif /* LIST_H_ */
