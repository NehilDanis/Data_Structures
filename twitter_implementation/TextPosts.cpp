/*
 * TextPosts.cpp
 *
 *  Created on: 16 Kas 2015
 *      Author: User
 */

#include "TextPosts.h"

TextPosts::TextPosts(string postId,string postText){
	likerListHead=NULL;
	int id;
	id = atoi(postId.c_str());
	setPostId(id);
	setPostText(postText);
	setLike(0);
}