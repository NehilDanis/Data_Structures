/*
 * Block.h
 *
 *  Created on: 17 Kas 2015
 *      Author: User
 */

#ifndef BLOCK_H_
#define BLOCK_H_

#include <iostream>
using namespace std;

class Block {
private:
	string name;
	Block *next;
public:
	Block();
	void setName(string);
	void setNext(Block*);

	string getName();
	Block* getNext();

};

#endif /* BLOCK_H_ */
