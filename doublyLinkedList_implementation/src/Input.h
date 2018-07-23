/*
 * Input.h
 *
 *  Created on: 10 Kas 2015
 *      Author: Nehil
 */

#ifndef INPUT_H_
#define INPUT_H_

#include <iostream>
#include <string>
#include <fstream>
#include "CommandList.h"
using namespace std;


//This is the Input class.And in this class I have a function to read the input file.
//After reading the file I have another function to decide to type of putting values.
//I have a function to send all seperated lines to the CommandList class.
class Input {

public :
	void readInputFile(char*,char*);
	void split(string,char*);
	string decideToType(string);
	void addToTheCommandList(string,string,string,char*);

};

#endif /* INPUT_H_ */
