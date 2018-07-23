/*
 * ViewUser.h
 *
 *  Created on: 16 Kas 2015
 *      Author: User
 */

#ifndef VIEWUSER_H_
#define VIEWUSER_H_

#include "User.h"
#include <string>
#include <iostream>
using namespace std;

class ViewUser {
public:
	void viewUser(User*,string);
	User* existanceOfUser(User*,string);
};

#endif /* VIEWUSER_H_ */
