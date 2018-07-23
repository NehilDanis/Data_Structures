/*
 * CommandList.h
 *
 *  Created on: 10 Kas 2015
 *      Author: Nehil
 */

#ifndef COMMANDLIST_H_
#define COMMANDLIST_H_

#include <iostream>
#include <string>
#include "List.h"
using namespace std;

//This class inherited from the List class.
class CommandList :public List{
public:
	CommandList();
	~CommandList();
	void addCommand(string,string,string,string,string,string,string);
	void doTheJob(string,string,string,char*);
	void addFirstTwoItems(char*);

	int stringToIntConverter(string);
	double stringToDoubleConverter(string);
	string doubleToStringConverter(double);
	string intToStringConverter(int);

	double operator +(const double);
	double operator +(const int);
	string operator +(const string);

private:
	typedef struct commandNode{//This will keep the commands.This is doubly linked list.So it will reach the both sides of nodes.
		string val1;
		string val2;
		string val3;
		string type1;
		string type2;
		string type3;
		string command;

		commandNode * next;//Next of the node.
		commandNode * prev;//Previous of the node

	}*commandNodePtr;

	commandNodePtr head;//Head of the linked list
	commandNodePtr tail;//Tail of the linked list
	commandNodePtr temp;//Temporary pointer for linked list


};

#endif /* COMMANDLIST_H_ */
