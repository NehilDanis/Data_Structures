/*
 * ImagePosts.h
 *
 *  Created on: 16 Kas 2015
 *      Author: User
 */

#ifndef IMAGEPOSTS_H_
#define IMAGEPOSTS_H_

#include "UsersPosts.h"

class ImagePosts :public UsersPosts{
private:
	int height;
	int width;
public:
	ImagePosts(string,string,int);
	ImagePosts(string,string,string);
};

#endif /* IMAGEPOSTS_H_ */
