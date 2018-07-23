/*
 * ViewUser.cpp
 *
 *  Created on: 16 Kas 2015
 *      Author: User
 */

#include "ViewUser.h"

void ViewUser::viewUser(User* headData,string userNameData){

	ofstream outfile ("output.txt",ios::app);
	headData=existanceOfUser(headData,userNameData);//By calling this function the program control the existance of the user that we want to view.
	//The existanceOfUser returns the address of user.If there is no user that matched the userNameData the function will return NULL.
	if(headData==NULL){//If headData is equal to NULL.The program will give an error message.
		cout<<"Err: The user "<<userNameData<<" could not be found!"<<endl;
		outfile<<"Err: The user '"<<userNameData<<"' could not be found!"<<endl;
	}
	else{//If the user that we want to view is in the user list,the program view all informations about this user.
		cout<<"------------------------------------------------"<<endl;
		outfile<<"------------------------------------------------"<<endl;
		cout<<userNameData<<" following ["<<headData->getFollowed()<<"] - blocked ["<<headData->getBlocked()<<"] users - ["<<headData->getPosted()<<"] posts."<<endl;
		outfile<<userNameData<<" following ["<<headData->getFollowed()<<"] - blocked ["<<headData->getBlocked()<<"] users - ["<<headData->getPosted()<<"] posts."<<endl;
		cout<<headData->getPersonalComment()<<endl;
		outfile<<headData->getPersonalComment()<<endl;

		cout<<"---------------------Tweets---------------------"<<endl;
		outfile<<"---------------------Tweets---------------------"<<endl;
		headData->postedPostsTemp=headData->postedPostsHead;
		while(headData->postedPostsTemp!=NULL){
			cout<<headData->postedPostsTemp->getPostText();
			outfile<<headData->postedPostsTemp->getPostText();
			if(headData->postedPostsTemp->getSize()>0){//This is for image posts.
				cout<<" - TotalSize: ["<<headData->postedPostsTemp->getSize()<<" pixels] - Likes: "<<headData->postedPostsTemp->getLike()<<endl;
				outfile<<" - TotalSize: ["<<headData->postedPostsTemp->getSize()<<" pixels] - Likes: "<<headData->postedPostsTemp->getLike()<<endl;
			}
			else{//This is for text posts.
				cout<<" - Likes: "<<headData->postedPostsTemp->getLike()<<endl;
				outfile<<" - Likes: "<<headData->postedPostsTemp->getLike()<<endl;
			}

			headData->postedPostsTemp=headData->postedPostsTemp->getNext();
		}
		cout<<"------------------------------------------------"<<endl;
		outfile<<"------------------------------------------------"<<endl;
	}
}

User* ViewUser::existanceOfUser(User* headData,string userNameData){//Here the existance of user that we wanted to view will be controlled.
	while(headData!=NULL){
		if(userNameData==headData->getUserName()){
			return headData;//If the user is found,the program will return the address of user.
		}
		headData=headData->getNext();
	}
	headData=NULL;//If there is no user that matched the user that we wanted to view,the function will return NULL.
	return headData;

}
