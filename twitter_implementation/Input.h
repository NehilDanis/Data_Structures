/*
 * Input.h
 *
 *  Created on: 15 Kas 2015
 *      Author: User
 */

#ifndef INPUT_H_
#define INPUT_H_

#include <iostream>
#include <string>
#include "Commands.h"
#include <fstream>
using namespace std;

class Input {
public:
	Commands obj;//This is for calling the getTheCommandDone fuction that stays into the command class.
	void readInput();
	void split(string line);
};

#endif /* INPUT_H_ */
