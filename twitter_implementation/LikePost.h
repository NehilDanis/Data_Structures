/*
 * LikePost.h
 *
 *  Created on: 17 Kas 2015
 *      Author: User
 */

#ifndef LIKEPOST_H_
#define LIKEPOST_H_

#include <iostream>
using namespace std;

class LikePost {
public:
	void setName(string);
	void setNext(LikePost*);

	LikePost* getNext();
	string getName();

private:
	string name;
	LikePost *next;
};

#endif /* LIKEPOST_H_ */
