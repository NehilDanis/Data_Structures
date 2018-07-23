/*
 * User.cpp
 *
 *  Created on: 16 Kas 2015
 *      Author: User
 */

#include "User.h"


void User::SetNext(User* nextData){//This is for setting the next address of the current user.
	next=nextData;
}

void User::setUserName(string userNameData){//This is for setting the user name of the current user.
	userName=userNameData;
}

void User::setPersonalComment(string personalCommentData){//This is for setting the personal comment of the current user.
	personalComment=personalCommentData;
}

User* User::getNext(){//This is a getter for next address of the current user.
	return next;
}

string User::getUserName(){//This is a getter for name of the current user.
	return userName;
}

string User::getPersonalComment(){//This is a getter for personal comment of the current user.
	return personalComment;
}

int User::getBlocked(){//This is a getter for number of blocked users for each user.
	return blocked;
}
int User::getFollowed(){//This is a getter for number of unfollowed user users for each user.
	return followed;
}
int User::getPosted(){//This is a getter for number of  posted posts for each user.
	return posted;
}
void User::setBlocked(int blockedData){//This is for setting the number of blocked users for each user.
	blocked=blockedData;
}
void User::setFollowed(int followedData){//This is for setting the number of unfollowed users for each user.
	followed=followedData;
}
void User::setPosted(int postedData){//This is for setting the number of posted posts for each user.
	posted=postedData;
}

void User::followSomeone(User* headData,string username1,string username2){
	ofstream outfile ("output.txt",ios::app);
	int followed;//This is for number of followed users.
	if(controlTheExistance(headData,username1,username2)==1){//Here the program control the existance of these two person into the user list.
		if(username1==username2){
			cout<<"Err: "<<username1<<" connot follow itself!"<<endl;
			outfile<<"Err: "<<username1<<" connot follow itself!"<<endl;
		}
		else{

			if(controlBlockedOrNot(headData,username2,username1)==1){//If username2 doesn't block username1 ,the program will execute this if block.
				while(headData!=NULL){
					if(headData->getUserName()==username1){//the program will find the follower.
						if(controlFollowedUser(headData,username1,username2)==1){//If username2 hadn't been followed by username1 the program will execute this if block.
							FollowingUser* newFollowedOne = new FollowingUser();//A following user will be create.
							newFollowedOne->setNext(NULL);
							newFollowedOne->setName(username2);
						
							if(headData->followedListHead!=NULL){
								headData->followedListEnd=headData->followedListHead;
								while(headData->followedListEnd->getNext()!=NULL){
									headData->followedListEnd=headData->followedListEnd->getNext();
								}
								headData->followedListEnd->setNext(newFollowedOne);
							}

							else{
								headData->followedListHead=newFollowedOne;
							}

							followed=headData->getFollowed();//This is for setting the username1's number of followed users.
							followed++;
							headData->setFollowed(followed);
							cout<<username1<<" followed "<<username2<<endl;
							outfile<<username1<<" followed "<<username2<<endl;
						}
						else{//If username2 had already been followed by username1,the program will give this error message.
							cout<<"Err: "<<username1<<" has already followed "<<username2<<"!"<<endl;
							outfile<<"Err: "<<username1<<" has already followed "<<username2<<"!"<<endl;
						}

					}
					headData=headData->getNext();//This is for reaching each user into the user list.
				}
			}
			else{//If username2 blocked username1,the program will give an error message.
				cout<<"Err: "<<username2<<" blocked "<<username1<<" because of that follow ignored!"<<endl;
				outfile<<"Err: "<<username2<<" blocked "<<username1<<" because of that follow ignored!"<<endl;
			}
		}
	}

}

bool User::controlTheExistance(User* headData,string userName1,string userName2){//here the program will control the username1 and uernam2's existance.
	ofstream outfile ("output.txt",ios::app);
	int counter1=0,counter2=0;
	while(headData!=NULL){
		if(userName1==userName2){//If the username1 and username2 are equal to each other,the program will give an error message.
			if(headData->getUserName()==userName1){
				return true;
			}
		}
		if(headData->getUserName()==userName1){
			counter1++;
		}
		else if(headData->getUserName()==userName2){
			counter2++;
		}
		headData=headData->getNext();
	}
	if(counter1==1 && counter2==1){//If two of these user was found , the function would return true.
		return true;
	}
	else if(counter1==0 && counter2==1){
		cout<<"Err: The user '"<<userName1<<"' could not be found!"<<endl;
		outfile<<"Err: The user '"<<userName1<<"' could not be found!"<<endl;
	}
	else if(counter1==1 && counter2==0){
		cout<<"Err: The user '"<<userName2<<"' could not be found!"<<endl;
		outfile<<"Err: The user '"<<userName2<<"' could not be found!"<<endl;
	}
	else if(counter1==0 && counter2==0){
		if(userName1==userName2){
			cout<<"Err: The user '"<<userName1<<"' could not be found!"<<endl;
			outfile<<"Err: The user '"<<userName1<<"' could not be found!"<<endl;
		}
		else{
			cout<<"Err: The user '"<<userName1<<"' could not be found!"<<endl;
			cout<<"Err: The user '"<<userName2<<"' could not be found!"<<endl;
			outfile<<"Err: The user '"<<userName1<<"' could not be found!"<<endl;
			outfile<<"Err: The user '"<<userName2<<"' could not be found!"<<endl;
		}
	}
	return false;

}

bool User::controlFollowedUser(User* headData,string userName1,string userName2){//headata=address of username1	 
	headData->followedListTemp=headData->followedListHead;
	while(headData->followedListTemp!=NULL){
		if(userName2==headData->followedListTemp->getName()){
			return false;//If username2 had already been followed by username1,the function would have returned false.
		}
		headData->followedListTemp=headData->followedListTemp->getNext();
	}
	return true;//Else the program would have returned true.

}

void User::addPost(User* headData,string token0,string token1,string token2,string token3){
	int post;//This is for number of posts user.
	if(controlUser(headData,token0)==1){//token0==username,If user was found the program will continue to add post.
		while(headData!=NULL){
			if(headData->getUserName()==token0){//If the user was found.
				if(token3==""){//text post
					UsersPosts* newPost= new TextPosts(token1,token2);//A new text post object was created.
					newPost->setNext(NULL);

					if(headData->postedPostsHead!=NULL){
						headData->postedPostsEnd=headData->postedPostsHead;
						while(headData->postedPostsEnd->getNext()!=NULL){
							headData->postedPostsEnd=headData->postedPostsEnd->getNext();
						}
						headData->postedPostsEnd->setNext(newPost);
					}
					else{
						headData->postedPostsHead=newPost;
					}

				}
				else{//image post
					UsersPosts* newPost= new ImagePosts(token1,token2,token3);//A new image post object was created.
					newPost->setNext(NULL);
					
					if(headData->postedPostsHead!=NULL){
						headData->postedPostsEnd=headData->postedPostsHead;
						while(headData->postedPostsEnd->getNext()!=NULL){
							headData->postedPostsEnd=headData->postedPostsEnd->getNext();
						}
						headData->postedPostsEnd->setNext(newPost);
					}
					else{
						headData->postedPostsHead=newPost;
					}

				}
				post=headData->getPosted();//These are for setting the number of posts of user.
				post++;
				headData->setPosted(post);
			}
			headData=headData->getNext();//This is for finding the user into the user list.
		}
	}
}

bool User::controlUser(User* headData,string userName){//This controls the existance of any user.
	ofstream outfile ("output.txt",ios::app);
	while(headData!=NULL){
		if(headData->getUserName()==userName){
			return true;//If the user is in the user list the program will return true.
		}
		headData=headData->getNext();
	}
	//Else the program will give an error messages and then will return false.
	cout<<"Err: The user '"<<userName<<"' could not be found!"<<endl;
	outfile<<"Err: The user '"<<userName<<"' could not be found!"<<endl;
	return false;
}

void User::likeSomeOnesPost(User* headData,string username1,string username2,string postId){
	ofstream outfile ("output.txt",ios::app);
	int counter=0;
	int id;
	User* liked=getTheAddress(headData,username2);//Address of the liked user.
	id = atoi(postId.c_str());
	if(controlTheExistance(headData,username1,username2)==1){//If both users are in the user list.
		if(controlBlockedOrNot(headData,username2,username1)==1){//If username2 hadn't blocked username1. 
		liked->postedPostsTemp=liked->postedPostsHead;
			while(liked->postedPostsTemp!=NULL){
				if(liked->postedPostsTemp->getPostId()==id){//Here the program is looking for the post.
					counter++;
					break;
				}
				liked->postedPostsTemp=liked->postedPostsTemp->getNext();
			}
			if(counter==0){//If the post isn't in the user's post list
				cout<<"Err: "<<username2<<"'s post could not be found!"<<endl;
				outfile<<"Err: "<<username2<<"'s post could not be found!"<<endl;
			}
			else{//If the post is found.
				if(controlLikedOrNot(liked->postedPostsTemp,username1)==1){//Here we send the address of post to the control function.
					LikePost* likeItem=new LikePost();
					likeItem->setName(username1);
					likeItem->setNext(NULL);

					if(liked->postedPostsTemp->likerListHead!=NULL){
						liked->postedPostsTemp->likerListCurr=liked->postedPostsTemp->likerListHead;
						while(liked->postedPostsTemp->likerListCurr->getNext()!=NULL){
							liked->postedPostsTemp->likerListCurr=liked->postedPostsTemp->likerListCurr->getNext();
						}
						liked->postedPostsTemp->likerListCurr->setNext(likeItem);

					}
					else{
						liked->postedPostsTemp->likerListHead=likeItem;
					}


					int numberOfLike=liked->postedPostsTemp->getLike();
				    numberOfLike++;
				    liked->postedPostsTemp->setLike(numberOfLike);
					cout<<username1<<" has liked "<<username2<<"'s post"<<endl;
					outfile<<username1<<" has liked "<<username2<<"'s post"<<endl;
				}
				else {
					cout<<"Err: "<<username2<<"'s post has already been liked!"<<endl;
					outfile<<"Err: "<<username2<<"'s post has already been liked!"<<endl;
				}
			}
		}
		else{
			cout<<"Err: The user '"<<username2<<"' had blocked '"<<username1<<"'.You cannot like a post of '"<<username2<<"'!"<<endl;
			outfile<<"Err: The user '"<<username2<<"' had blocked '"<<username1<<"'.You cannot like a post of '"<<username2<<"'!"<<endl;
		}
		
	}
}




bool User::controlLikedOrNot(UsersPosts* headData,string username){
	headData->likerListTemp=headData->likerListHead;
	while(headData->likerListTemp!=NULL){
		if(headData->likerListTemp->getName()==username){
			return false;//If user had already been liked the post of the other user,the program will return  false.
		}
		headData->likerListTemp=headData->likerListTemp->getNext();
	}
	return true;//Else the program will return true.
}

User* User::getTheAddress(User* headData,string name){//Here the program will find the address of user.
	while(headData!=NULL){
			if(headData->getUserName()==name){
				return headData;//If the user is found,the program will return the address of this user.
			}
			headData=headData->getNext();
		}
		return NULL;//Else the program will return NULL.

}

void User::repost(User* headData,string userNameReposter,string UserNameReposted,string postIdRepostedItem){
	ofstream outfile ("output.txt",ios::app);
	int id;
	string postText;
	int size;
	int counter=0;
	User* reposter;//This is for keeping the address of reposter.
	id = atoi(postIdRepostedItem.c_str());//The post's id is in string type after reading from input file.So the program convert it from string to integer.
	if(controlTheExistance(headData,userNameReposter,UserNameReposted)==1){//If the both user are in the user list.
		if(UserNameReposted==userNameReposter){
			cout<<"Err: The user A already posted this post! You cannot repost it!"<<endl;
			outfile<<"Err: The user A already posted this post! You cannot repost it!"<<endl;
		}
		else{
			if(controlBlockedOrNot(headData,UserNameReposted,userNameReposter)==1){//If the reposter hadn't been blocked by reposted user.
				reposter=getTheAddress(headData,userNameReposter);//Here the program will found the address of reposter.
				while(headData!=NULL){
					if(headData->getUserName()==UserNameReposted){//At fisrt the program will find the reposted user
						headData->postedPostsTemp=headData->postedPostsHead;
						while(headData->postedPostsTemp!=NULL){//Then the program will look for post that the reposter wants to repost.
							if(headData->postedPostsTemp->getPostId()==id){//If the post was found.
								counter++;
								postText=headData->postedPostsTemp->getPostText();
								if(headData->postedPostsTemp->getSize()>10){//This is for image post.
									size=headData->postedPostsTemp->getSize();//We will take the size of reposted image.
									addRepostedPost(reposter,postIdRepostedItem,postText,size);//Here the program will send all informations about post to the addRepostedPost function.

								}
								else{//This is for text post.
									addRepostedPost(reposter,postIdRepostedItem,postText,0);//Here the program will send all informations about post to the addRepostedPost function.

								}

							}
							headData->postedPostsTemp=headData->postedPostsTemp->getNext();
						}
						if(counter==0){//If the user wasn't found.
							cout<<"Err: "<<UserNameReposted<<"'s post could not be found!"<<endl;
							outfile<<"Err: "<<UserNameReposted<<"'s post could not be found!"<<endl;
						}

					}

					headData=headData->getNext();
				}
				if(counter!=0){
					cout<<userNameReposter<<" has reposted "<<UserNameReposted<<"'s post."<<endl;
					outfile<<userNameReposter<<" has reposted "<<UserNameReposted<<"'s post."<<endl;
				}
	
			}
			else{//If reposter had been blocked by reposted user.
				cout<<"Err:The user '"<<UserNameReposted<<"' has blocked '"<<userNameReposter<<"'.You cannot repost the post of '"<<UserNameReposted<<"'!"<<endl;
				outfile<<"Err:The user '"<<UserNameReposted<<"' has blocked '"<<userNameReposter<<"'.You cannot repost the post of '"<<UserNameReposted<<"'!"<<endl;
			}
		}

	}


}



void User::addRepostedPost(User* reposter,string postId,string postText,int postSize){
	int post;//This is for a number of post of reposter.
	if(postSize==0){//If post's size is equal to the zero,this will be for text post.

		UsersPosts* newPost= new TextPosts(postId,postText);//A new text post object was created.
		newPost->setNext(NULL);
		if(reposter->postedPostsHead!=NULL){
			reposter->postedPostsEnd=reposter->postedPostsHead;
			while(reposter->postedPostsEnd->getNext()!=NULL){
				reposter->postedPostsEnd=reposter->postedPostsEnd->getNext();
			}
			reposter->postedPostsEnd->setNext(newPost);
		}
		else{
			reposter->postedPostsHead=newPost;
		}

	}


	else{//If post's size is not equal to the zero,this will be for image post.
		UsersPosts* newPost= new ImagePosts(postId,postText,postSize);//A new image post object was created.
		newPost->setNext(NULL);
		if(reposter->postedPostsHead!=NULL){
			reposter->postedPostsEnd=reposter->postedPostsHead;
			while(reposter->postedPostsEnd->getNext()!=NULL){
				reposter->postedPostsEnd=reposter->postedPostsEnd->getNext();
			}
			reposter->postedPostsEnd->setNext(newPost);
		}
		else{
			reposter->postedPostsHead=newPost;
		}


	}
	post=reposter->getPosted();//These are for the setting of number of posts of reposter.
	post++;
	reposter->setPosted(post);
}



void User::cutTheFriendShip(User* headData,string username1,string username2){//In this function the relationship between username1 and username2 will be cut.
	int followed;
	FollowingUser* delObj=NULL;
	while(headData!=NULL){
		if(headData->getUserName()==username1){
			if(controlFollowedUser(headData,username1,username2)==0){//If username1 follows username2,the program will continue to execute this function.

			headData->followedListEnd=headData->followedListHead;
			headData->followedListTemp=headData->followedListHead;
			while(headData->followedListEnd!=NULL && headData->followedListEnd->getName()!=username2){
				headData->followedListTemp=headData->followedListEnd;
				headData->followedListEnd=headData->followedListEnd->getNext();
			}
			if(headData->followedListEnd==NULL){
				followed=headData->getFollowed();
				followed--;
				headData->setFollowed(followed);
				delete delObj;
			}
			else{
				delObj=headData->followedListEnd;
				headData->followedListEnd=headData->followedListEnd->getNext();
				headData->followedListTemp->setNext(headData->followedListEnd);
				if(delObj==headData->followedListHead){
					headData->followedListHead=headData->followedListHead->getNext();
					headData->followedListTemp=NULL;
				}
				followed=headData->getFollowed();
				followed--;
				headData->setFollowed(followed);
				delete delObj;

			}

			}
		}
		headData=headData->getNext();
	}

}

void User::UnfollowSomeOne(User* headData,string username1,string username2){
	ofstream outfile ("output.txt",ios::app);
	User* head=headData;
	if(controlTheExistance(headData,username1,username2)==1){//If bothe users are in the user list.
		if(username1==username2){
			cout<<"Err: "<<username1<<" cannot unfollow itself!"<<endl;
			outfile<<"Err: "<<username1<<" cannot unfollow itself!"<<endl;
		}
		else{
			if(controlBlockedOrNot(headData,username2,username1)==1){//username1 hadn't blocked the username2. 
				while(headData!=NULL){
					if(headData->getUserName()==username1){//The program will find the username1.
							if(controlUnfollowedUser(headData,username1,username2)==1){//If the username2 hadn't been unfollowed by usernmae1 yet.
							    UnfollowingUser* newUnfollowedOne = new UnfollowingUser();
							    newUnfollowedOne->setNext(NULL);
								newUnfollowedOne->setName(username2);

								if(headData->unfollowedListHead!=NULL){
									headData->unfollowedListEnd=headData->unfollowedListHead;
									while(headData->unfollowedListEnd->getNext()!=NULL){
										headData->unfollowedListEnd=headData->unfollowedListEnd->getNext();
									}
									headData->unfollowedListEnd->setNext(newUnfollowedOne);
								}
								else{
								headData->unfollowedListHead=newUnfollowedOne;
								}
								cout<<username2<<" has been unfollowed by "<<username1<<endl;
								outfile<<username2<<" has been unfollowed by "<<username1<<endl;
								cutTheFriendShip(head,username1,username2);

							}
							else{
								cout<<"Err: "<<username2<<" has already been unfollowed by you!You cannot unfollow again."<<endl;
								outfile<<"Err: "<<username2<<" has already been unfollowed by you!You cannot unfollow again."<<endl;
							}

					}
					headData=headData->getNext();
				}
			}

			else{
				cout<<"Err: "<<username2<<" has already been unfollowed by you!You cannot unfollow again."<<endl;
				outfile<<"Err: "<<username2<<" has already been unfollowed by you!You cannot unfollow again."<<endl;
			}
		}

	}

}

bool User::controlUnfollowedUser(User*headData,string username1,string username2){
	headData->unfollowedListTemp=headData->unfollowedListHead;
	while(headData->unfollowedListTemp!=NULL){
		if(username2==headData->unfollowedListTemp->getName()){
			return false;//If the username2 had already been unfollowed by username1,the program will return false.
		}
		headData->unfollowedListTemp=headData->unfollowedListTemp->getNext();
	}
	return true;//else the program will return true.

}


void User::blockSomeOne(User* headData,string username1,string username2){
	ofstream outfile ("output.txt",ios::app);
	int blocked;//This is for the number of blocked users of username1.
	User *head=headData;//We don't want to lose the value of head data because of that we create the user * head.
	if(controlTheExistance(headData,username1,username2)==1){//If both of user is in the user list.
		if(username1==username2){
			cout<<"Err: "<<username1<<" cannot block itself!"<<endl;
			outfile<<"Err: "<<username1<<" cannot block itself!"<<endl;
		}
		else{
			if(controlBlockedOrNot(headData,username1,username2)==1){//If username2 hadn't been blocked by username1 yet.
				while(headData!=NULL){
					if(headData->getUserName()==username1){//The blocked will be found.
						Block* blockedOne= new Block();
						blockedOne->setNext(NULL);
						blockedOne->setName(username2);

						if(headData->blockedUsersListHead!=NULL){
							headData->blockedUsersListEnd=headData->blockedUsersListHead;
							while(headData->blockedUsersListEnd->getNext()!=NULL){
								headData->blockedUsersListEnd=headData->blockedUsersListEnd->getNext();
							}
							headData->blockedUsersListEnd->setNext(blockedOne);
						}
						else {
							headData->blockedUsersListHead=blockedOne;
						}


						blocked=headData->getBlocked();//number of blocked ones of username1 will be set here.
						blocked++;
						headData->setBlocked(blocked);


					}
					headData=headData->getNext();
				}
				cutTheFriendShip(head,username2,username1);//If a blocks b,b have to cut the relationship with a.If b follows a,after block command,this will be cut.
				deleteLike(head,username1,username2);//The likes of username1 into the username2's post will be deleted.
				cout<<username1<<" has blocked "<<username2<<endl;
				outfile<<username1<<" has blocked "<<username2<<endl;
			}
			else{
				cout<<"Err: '"<<username1<<"' has already blocked '"<<username2<<"'!"<<endl;
				outfile<<"Err: '"<<username1<<"' has already blocked '"<<username2<<"'!"<<endl;
			}
		}
	}

}

bool User::controlBlockedOrNot(User* headData,string username1,string username2){
	User* blocker=getTheAddress(headData,username1);//here the program will find the address of blocked.
	blocker->blockedUsersListTemp=blocker->blockedUsersListHead;
	while(blocker->blockedUsersListTemp!=NULL){
		if(blocker->blockedUsersListTemp->getName()==username2){
			return false;//if username1 had already been blocked username2 the program would have returned false.
		}
		blocker->blockedUsersListTemp=blocker->blockedUsersListTemp->getNext();
	}
	return true;//Else the program will return true.

}

void User::deleteLike(User* headData,string username1,string username2){
	LikePost* delObj=NULL;
	int numberOfLikes;
	while(headData!=NULL){
		if(headData->getUserName()==username2){//here the program will find the username2.
			headData->postedPostsTemp=headData->postedPostsHead;
			while(headData->postedPostsTemp!=NULL){//The program will control all posts of username2.
				headData->postedPostsTemp->likerListTemp=headData->postedPostsTemp->likerListHead;
				headData->postedPostsTemp->likerListCurr=headData->postedPostsTemp->likerListHead;
				while(headData->postedPostsTemp->likerListCurr!=NULL && headData->postedPostsTemp->likerListCurr->getName()!=username1){
					headData->postedPostsTemp->likerListTemp=headData->postedPostsTemp->likerListCurr;
					headData->postedPostsTemp->likerListCurr=headData->postedPostsTemp->likerListCurr->getNext();
				}//If there is a any like that belongs to the username1 ,this will be deleted by this function.

				if(headData->postedPostsTemp->likerListCurr!=NULL){
					delObj=headData->postedPostsTemp->likerListCurr;
					headData->postedPostsTemp->likerListCurr=headData->postedPostsTemp->likerListCurr->getNext();
					headData->postedPostsTemp->likerListTemp->setNext(headData->postedPostsTemp->likerListCurr);
					if(delObj==headData->postedPostsTemp->likerListHead){
						headData->postedPostsTemp->likerListHead=headData->postedPostsTemp->likerListHead->getNext();
						headData->postedPostsTemp->likerListTemp=NULL;
					}
					numberOfLikes=headData->postedPostsTemp->getLike();//Here the number of likes of any post will be set.
					numberOfLikes--;
					headData->postedPostsTemp->setLike(numberOfLikes);
					delete delObj;
				}
				headData->postedPostsTemp=headData->postedPostsTemp->getNext();
			}
		}
		headData=headData->getNext();
	}

}




