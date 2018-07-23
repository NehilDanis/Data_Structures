/*
 * UsersPosts.cpp
 *
 *  Created on: 16 Kas 2015
 *      Author: User
 */

#include "UsersPosts.h"

void UsersPosts::setUserName(string userNameData){
	userName=userNameData;
}

void UsersPosts::setPostId(int idData){
	postId=idData;
}

void UsersPosts::setPostText(string text){
	postText=text;
}

void UsersPosts::setNext(UsersPosts* nextData){
	next=nextData;
}

void UsersPosts::setSize(int height,int width){
	size=height*width;
}

void UsersPosts::setLike(int likeData){
	like=likeData;
}

int UsersPosts::getLike(){
	return like;
}


string UsersPosts::getUserName(){
	return userName;
}

int UsersPosts::getPostId(){
	return postId;
}

string UsersPosts::getPostText(){
	return postText;
}

UsersPosts* UsersPosts::getNext(){
	return next;
}

int UsersPosts::getSize(){
	return size;
}

void UsersPosts::setSize(int sizeData){
	size=sizeData;
}

