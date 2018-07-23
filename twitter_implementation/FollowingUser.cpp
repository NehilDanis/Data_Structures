/*
 * FollowingUser.cpp
 *
 *  Created on: 16 Kas 2015
 *      Author: User
 */

#include "FollowingUser.h"

void FollowingUser::setNext(FollowingUser* nextData){
	next=nextData;
}
void FollowingUser::setName(string nameData){
	name=nameData;
}

FollowingUser* FollowingUser::getNext(){
	return next;
}

string FollowingUser::getName(){
	return name;
}