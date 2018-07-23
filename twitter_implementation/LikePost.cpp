/*
 * LikePost.cpp
 *
 *  Created on: 17 Kas 2015
 *      Author: User
 */

#include "LikePost.h"

void LikePost::setName(string likerName){
	name=likerName;
}
void LikePost::setNext(LikePost* nextData){
	next=nextData;
}

LikePost* LikePost::getNext(){
	return next;
}
string LikePost::getName(){
	return name;
}
