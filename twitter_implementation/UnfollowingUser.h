/*
 * UnfollowingUser.h
 *
 *  Created on: 17 Kas 2015
 *      Author: User
 */

#ifndef UNFOLLOWINGUSER_H_
#define UNFOLLOWINGUSER_H_

#include <iostream>
using namespace std;

class UnfollowingUser {
private:
	string name;
	UnfollowingUser* next;

public:
	void setNext(UnfollowingUser*);
	void setName(string);
	UnfollowingUser* getNext();
	string getName();

};

#endif /* UNFOLLOWINGUSER_H_ */
