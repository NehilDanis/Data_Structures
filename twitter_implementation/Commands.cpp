/*
 * Commands.cpp
 *
 *  Created on: 16 Kas 2015
 *      Author: User
 */

#include "Commands.h"

void Commands::getTheCommandDone(string command,string token1,string token2,string token3,string token4){
	if(command=="AddUser"){//if the command is equal to the AddUser the program will call the addNewUser function that stays into the AddUser class.
		newUser.addNewUser(token1,token2);
	}

	else if(command=="ViewUser"){//if the command is equal to the ViewUser the program will call the viewUser function that stays into the ViewUser class.
		view.viewUser(newUser.head,token1);

	}

	else if(command=="FollowUser"){//if the command is equal to the FollowUser the program will call the followSomeone function that stays into the User class.
		userObj.followSomeone(newUser.head,token1,token2);
	}
	else if(command=="AddPost"){//if the command is equal to the AddPost the program will call the addPost function that stays into the User class.
		if(token4==""){//text post
			userObj.addPost(newUser.head,token1,token2,token3,token4);
		}
		else{//image post
			userObj.addPost(newUser.head,token1,token2,token3,token4);
		}
	}

	else if(command=="Repost"){//if the command is equal to the Repost the program will call the repost function that stays into the User class.
		userObj.repost(newUser.head,token1,token2,token3);
	}

	else if(command=="BlockUser"){//if the command is equal to the BlockUser the program will call the blockSomeOne function that stays into the User class.
		userObj.blockSomeOne(newUser.head,token1,token2);
	}

	else if(command=="UnfollowUser"){//if the command is equal to the UnfollowUser the program will call the UnfollowSomeOne function that stays into the User class.
		userObj.UnfollowSomeOne(newUser.head,token1,token2);
	}
	else if(command=="LikePost"){//if the command is equal to the LikePost the program will call the likeSomeOnesPost function that stays into the User class.
		userObj.likeSomeOnesPost(newUser.head,token1,token2,token3);
	}


}
