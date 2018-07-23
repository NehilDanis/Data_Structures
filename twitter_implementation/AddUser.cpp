/*
 * AddUser.cpp
 *
 *  Created on: 16 Kas 2015
 *      Author: User
 */

#include "AddUser.h"

AddUser::AddUser() {
	head=NULL;
	end=NULL;
	temp=NULL;
}

void AddUser::addNewUser(string name,string comment){
	ofstream outfile ("output.txt",ios::app);
	if(controlTheNewUserExistance(name)==1){
	    // Create a new node
	    User* newNode = new User();
	    newNode->SetNext(NULL);
	    newNode->setUserName(name);
	    newNode->setPersonalComment(comment);
	    newNode->setBlocked(0);
	    newNode->setFollowed(0);
	    newNode->setPosted(0);
		if(head!=NULL){
			end=head;
			while(end->getNext()!=NULL){
				end=end->getNext();
			}
			end->SetNext(newNode);
			end->getNext()->followedListHead=NULL;
			end->getNext()->postedPostsHead=NULL;
			end->getNext()->unfollowedListHead=NULL;
			end->getNext()->blockedUsersListHead=NULL;
		}
		else{
			head=newNode;
			head->followedListHead=NULL;
			head->postedPostsHead=NULL;
			head->unfollowedListHead=NULL;
			head->blockedUsersListHead=NULL;
		}
	   
	    cout<<"User '"<<name<<"' has been created"<<endl;
	    outfile<<"User '"<<name<<"' has been created"<<endl;
	}
}

bool AddUser::controlTheNewUserExistance(string userName){
	ofstream outfile ("output.txt",ios::app);
	temp=head;
	while(temp!=NULL){
		if(userName==temp->getUserName()){
			cout<<"Err: The user '"<<userName<<"' has already been created!"<<endl;
			outfile<<"Err: The user '"<<userName<<"' has already been created!"<<endl;
			return false;
		}
		temp=temp->getNext();
	}
	temp=NULL;
	return true;
}

