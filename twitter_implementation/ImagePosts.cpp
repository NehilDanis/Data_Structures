/*
 * ImagePosts.cpp
 *
 *  Created on: 16 Kas 2015
 *      Author: User
 */

#include "ImagePosts.h"

ImagePosts::ImagePosts(string postId,string postText,string size){
	likerListHead=NULL;
	int id,widthData,heightData;
	id = atoi(postId.c_str());
	setPostId(id);
	setPostText(postText);
	 string delimiter = "x";//This is the token that the program used to divide the line.
	 size_t pos = 0;
	 string token;
	 while ((pos = size.find(delimiter)) != std::string::npos) {
		 token = size.substr(0, pos);
		 size.erase(0, pos + delimiter.length());
	 }
	 widthData = atoi(token.c_str());
	 heightData = atoi(size.c_str());

	height=heightData;
	width=widthData;
	setSize(heightData,widthData);
	setLike(0);
}

ImagePosts::ImagePosts(string postId,string postText,int size){
	likerListHead=NULL;
	int id;
	id = atoi(postId.c_str());
	setPostId(id);
	setPostText(postText);
	setSize(size);
	setLike(0);
}

