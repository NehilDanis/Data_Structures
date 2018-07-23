/*
 * UsersPosts.h
 *
 *  Created on: 16 Kas 2015
 *      Author: User
 */

#ifndef USERSPOSTS_H_
#define USERSPOSTS_H_

#include <iostream>
#include <cstring>
#include <cstdlib>
#include "LikePost.h"
using namespace std;

class UsersPosts {
private:
	string userName;
	int postId;
	int size;
	int like;
	string postText;
	UsersPosts* next;

public:

	LikePost *likerListHead;
	LikePost *likerListTemp;
	LikePost *likerListCurr;

	void setLike(int);
	void setSize(int);
	void setSize(int,int);
	void setUserName(string);
	void setPostId(int);
	void setPostText(string);
	void setNext(UsersPosts*);

	int getLike();
	string getUserName();
	int getSize();
	int getPostId();
	string getPostText();
	UsersPosts* getNext();

};

#endif /* USERSPOSTS_H_ */
