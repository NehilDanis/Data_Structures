/*
 * FollowingUser.h
 *
 *  Created on: 16 Kas 2015
 *      Author: User
 */

#ifndef FOLLOWINGUSER_H_
#define FOLLOWINGUSER_H_

#include <iostream>
using namespace std;

class FollowingUser {
public:
	void setNext(FollowingUser*);
	void setName(string);
	FollowingUser* getNext();
	string getName();

private:
	string name;
	FollowingUser *next;


};

#endif /* FOLLOWINGUSER_H_ */
