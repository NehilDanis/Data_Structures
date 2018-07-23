/*
 * User.h
 *
 *  Created on: 16 Kas 2015
 *      Author: User
 */

#ifndef USER_H_
#define USER_H_

#include <iostream>
#include "FollowingUser.h"
#include "UnfollowingUser.h"
#include "UsersPosts.h"
#include "TextPosts.h"
#include "ImagePosts.h"
#include "LikePost.h"
#include "Block.h"
#include <fstream>
#include <cstdlib>
#include <string>
using namespace std;


class User {
private:
	string userName;
	string personalComment;
	User* next;

	int followed;
	int blocked;
	int posted;
public:
	FollowingUser *followedListHead;
	FollowingUser *followedListTemp;
	FollowingUser *followedListEnd;
	UsersPosts *postedPostsHead;
	UsersPosts *postedPostsTemp;
	UsersPosts *postedPostsEnd;
	UnfollowingUser *unfollowedListHead;
	UnfollowingUser *unfollowedListTemp;
	UnfollowingUser *unfollowedListEnd;
	Block *blockedUsersListHead;
	Block *blockedUsersListTemp;
	Block *blockedUsersListEnd;



	bool controlTheExistance(User*,string,string);
	bool controlUser(User*,string);
	bool controlFollowedUser(User*,string,string);
	bool controlUnfollowedUser(User*,string,string);
	void SetNext(User*);
	User* getNext();
	string getUserName();
	string getPersonalComment();
	void setUserName(string);
	void setPersonalComment(string);
	void followSomeone(User*,string,string);
	void addPost(User*,string,string,string,string);
	void repost(User*,string,string,string);
	User* getTheAddress(User*,string);
	void addRepostedPost(User*,string,string,int);


	void blockSomeOne(User*,string,string);
	bool controlBlockedOrNot(User*,string,string);


	void cutTheFriendShip(User*,string,string);
	void UnfollowSomeOne(User*,string,string);
	void likeSomeOnesPost(User*,string,string,string);
	bool controlLikedOrNot(UsersPosts*,string);


	void deleteLike(User*,string,string);


	int getBlocked();
	int getFollowed();
	int getPosted();
	void setBlocked(int);
	void setFollowed(int);
	void setPosted(int);
};

#endif /* USER_H_ */
