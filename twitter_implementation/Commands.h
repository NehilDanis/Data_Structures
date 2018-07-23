/*
 * Commands.h
 *
 *  Created on: 16 Kas 2015
 *      Author: User
 */

#ifndef COMMANDS_H_
#define COMMANDS_H_

#include <iostream>
#include <string>
#include <fstream>
#include "User.h"
#include "ViewUser.h"
#include "AddUser.h"
using namespace std;

class Commands {
public:
	User userObj;//This object created for calling the functions that stays into the User class.
	AddUser newUser;//This object created for calling the functions that stays into the AddUser class.
	ViewUser view;//This object created for calling the functions that stays into the ViewUser class.
	void getTheCommandDone(string,string,string,string,string);
};

#endif /* COMMANDS_H_ */
