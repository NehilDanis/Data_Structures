/*
 * UnfollowingUser.cpp
 *
 *  Created on: 17 Kas 2015
 *      Author: User
 */

#include "UnfollowingUser.h"

void UnfollowingUser::setNext(UnfollowingUser* nextData){
	next=nextData;
}
void UnfollowingUser::setName(string nameData){
	name=nameData;
}

UnfollowingUser* UnfollowingUser::getNext(){
	return next;
}

string UnfollowingUser::getName(){
	return name;
}
