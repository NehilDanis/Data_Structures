/*
 * Block.cpp
 *
 *  Created on: 17 Kas 2015
 *      Author: User
 */

#include "Block.h"

void Block::setName(string nameData){
	name=nameData;
}

void Block::setNext(Block* nextData){
	next=nextData;
}

string Block::getName(){
	return name;
}

Block* Block::getNext(){
	return next;
}

Block::Block(){
	next=NULL;
}