/*
 * AddUser.h
 *
 *  Created on: 16 Kas 2015
 *      Author: User
 */

#ifndef ADDUSER_H_
#define ADDUSER_H_

#include "User.h"
#include <string>
#include <iostream>
#include <fstream>
using namespace std;


class AddUser {
public:
	AddUser();
	void addNewUser(string,string);
	bool controlTheNewUserExistance(string);
	User* head;
	User* end;
	User* temp;
};

#endif /* ADDUSER_H_ */
