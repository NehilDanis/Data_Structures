#include "Directory.h"

string Directory::getType(){//This is for deciding the type of item.
	return "d";
}

Document* Directory::createLostDirectory(Document* headData,string lostDirectory){//Here the program will create lost directories for move,copy and mkdir commands.
	Document* newDirectory=new Directory();
	newDirectory->setName(lostDirectory);
	newDirectory->setLink(NULL);
	newDirectory->setNext(NULL);
	if(headData->getLink()==NULL){
		headData->setLink(newDirectory);
		return newDirectory;
	}
	else {
		headData=headData->getLink();
		while(headData->getNext()!=NULL){
			headData=headData->getNext();
		}
		headData->setNext(newDirectory);
		return newDirectory;
	}
	
}
	
void Directory::mkdir(Document* headData,string directory,char* outputFile){//Here the program will implement the make directory function.
	ofstream outObj(outputFile,ios::app);
	int counter=0;
	Document* newDirectory=new Directory();
	newDirectory->setName(directory);
	newDirectory->setLink(NULL);
	newDirectory->setNext(NULL);
	if(headData->getLink()==NULL){
		headData->setLink(newDirectory);
		if(outputFile!=""){
			cout<<"Make directory executed successfully."<<endl;
			outObj<<"Make directory executed successfully."<<endl;
		}
		else{
			cout<<"Make directory executed successfully."<<endl;
		}
	}
	else {
		headData=headData->getLink();
		while(headData->getNext()!=NULL){
			if(headData->getName()==directory){
				if(headData->getType()=="d"){
					counter++;
					break;
				}
			}
			headData=headData->getNext();
		}
		if(headData->getName()==directory){
			if(headData->getType()=="d"){
				counter++;
			}
		}
		if(counter==0){
			headData->setNext(newDirectory);
			if(outputFile!=""){
				cout<<"Make directory executed successfully."<<endl;
				outObj<<"Make directory executed successfully."<<endl;
			}
			else{
				cout<<"Make directory executed successfully."<<endl;
			}
		}
		else{//If the created directory is already exist the program will give an error message.
			if(outputFile!=""){
				cout<<"Error : There is already a directory that has the same name!"<<endl;
				outObj<<"Error : There is already a directory that has the same name!"<<endl;
			}
			else{
				cout<<"Error : There is already a directory that has the same name!"<<endl;
			}
		}
	}


}

void Directory::rmd(Document* url,string directory,Document* currData,char* outputFile){//This is for implementing the remove directory command
	ofstream outObj(outputFile,ios::app);
	Document* delDirectory=NULL;
	Document* tempHead;
	Document* currHead;
	if(currData->getName()==directory){//If you try to delete the current directory , the program will give an error message.
		if(outputFile!=""){
			cout<<"Error : You cannot delete the root directory!"<<endl;
			outObj<<"Error : You cannot delete the root directory!"<<endl;
		}
		else{
			cout<<"Error : You cannot delete the root directory!"<<endl;
		}
	}
	else {
		if(url->getLink()==NULL){//If the link pointer of ancestor directory is null , the program will give an error message.
			if(outputFile!=""){
				cout<<"Error : Directory didn't find!"<<endl;
				outObj<<"Error : Directory didn't find!"<<endl;
			}
			else{
				cout<<"Error : Directory didn't find!"<<endl;
			}
		}
		else{
			Document* currUrl=url;
			url=url->getLink();
			tempHead=url;
			currHead=url;
			while(currHead!=NULL ){//Here the program will reach the end of the ancestor directory's sub items.
				if(currHead->getName()==directory && currHead->getType()=="d"){
					break;
				}
				tempHead=currHead;
				currHead=currHead->getNext();
			}
			if(currHead==NULL){//If pointer is null,the program will give an error message.
				if(outputFile!=""){
					cout<<"Error : Directory didn't find!"<<endl;
					outObj<<"Error : Directory didn't find!"<<endl;
				}
				else{
					cout<<"Error : Directory didn't find!"<<endl;
				}	
				delete delDirectory;
			}
			else {
				if(currHead->getType()=="d"){
					delDirectory=currHead;
					currHead=currHead->getNext();
					tempHead->setNext(currHead);
					if(delDirectory==url){
						url=url->getNext();
						currUrl->setLink(url);
						tempHead=NULL;
					}
					delete delDirectory;
					if(outputFile!=""){
						cout<<"Remove directory executed successfully."<<endl;
						outObj<<"Remove directory executed successfully."<<endl;
					}
					else{
						cout<<"Remove directory executed successfully."<<endl;
					}
				}
				else{//If the item that we find is a file not a directory ,the program will give an error message.
					if(outputFile!=""){
						cout<<"Error : The destination url is a file not a directory!"<<endl;
						outObj<<"Error : The destination url is a file not a directory!"<<endl;
					}
					else{
						cout<<"Error : The destination url is a file not a directory!"<<endl;
					}
				}
			}
		}

	}

}

void Directory::mvd(Document* sourceDirectory,Document* destinationDirectory,string movedDirectory,string moving,Document* currData,char* outputFile){//This function is for implementing move directory command.
	ofstream outObj(outputFile,ios::app);
	Document* tempHead;
	Document* currHead;
	Document* delDirectory=NULL;
	int counter=0;
	if(sourceDirectory->getLink()==NULL){
		if(outputFile!=""){
			cout<<"Error : The directory that we wanted to move didn't find in the source directory!"<<endl;
			outObj<<"Error : The directory that we wanted to move didn't find in the source directory!"<<endl;
		}
		else{
			cout<<"Error : The directory that we wanted to move didn't find in the source directory!"<<endl;
		}
	}
	else if(currData->getName()==movedDirectory){//If the directory that we wanted to move is current directory ,the program will give an error message.
		if(outputFile!=""){
			cout<<"Error : You cannot moved root directory!"<<endl;
			outObj<<"Error : You cannot moved root directory!"<<endl;
		}
		else{
			cout<<"Error : You cannot moved root directory!"<<endl;
		}
	}
	else{
		Document* currUrl=sourceDirectory;
		sourceDirectory=sourceDirectory->getLink();
		tempHead=sourceDirectory;
		currHead=sourceDirectory;
		while(currHead!=NULL ){//Here the program will reach the end of the ancestor directory's sub items.
				if(currHead->getName()==movedDirectory && currHead->getType()=="d"){
					break;
				}
				tempHead=currHead;
				currHead=currHead->getNext();
		}
		if(currHead==NULL){
			if(outputFile!=""){
				cout<<"Error : The directory that we wanted to move didn't find in the source directory!"<<endl;
				outObj<<"Error : The directory that we wanted to move didn't find in the source directory!"<<endl;
			}
			else{
				cout<<"Error : The directory that we wanted to move didn't find in the source directory!"<<endl;
			}
			delete delDirectory;
		}
		else {
			if(currHead->getType()=="d"){
				delDirectory=currHead;
				if(delDirectory==sourceDirectory){
					sourceDirectory=sourceDirectory->getNext();
					currUrl->setLink(sourceDirectory);
					delDirectory->setNext(NULL);
					tempHead=NULL;
				}
				else{
					currHead=currHead->getNext();
					tempHead->setNext(currHead);
					delDirectory->setNext(NULL);
				}
				counter++;
			}
			else{
				if(outputFile!=""){
					cout<<"Error : The source url is a directory not a file!"<<endl;
					outObj<<"Error : The source url is a directory not a file!"<<endl;
				}
				else{
					cout<<"Error : The source url is a directory not a file!"<<endl;
				}
			}
		}
	}
	if(counter!=0 && delDirectory->getName()!=currData->getName()){
		Document* tempUrl;
		int value=0;
		if(destinationDirectory->getLink()==NULL){
			delDirectory->setName(moving);
			destinationDirectory->setLink(delDirectory);
		}
		else{
			tempUrl=destinationDirectory->getLink();
			while(tempUrl!=NULL){
				if(tempUrl->getName()==movedDirectory){
					if(tempUrl->getType()=="d"){
						value++;
					}
				}
				tempUrl=tempUrl->getNext();
			}
			if(value==0){
				delDirectory->setName(moving);
				tempUrl=destinationDirectory->getLink();
				while(tempUrl->getNext()!=NULL){
					tempUrl=tempUrl->getNext();
				}
				tempUrl->setNext(delDirectory);
			}
			else{
				if(outputFile!=""){
					cout<<"Error : There is another directory that has the same name in the destination url!"<<endl;
					outObj<<"Error : There is another directory that has the same name in the destination url!"<<endl;
				}
				else{
					cout<<"Error : There is another directory that has the same name in the destination url!"<<endl;
				}
			}
		}
		if(outputFile!=""){
			cout<<"Move directory executed successfully."<<endl;
			outObj<<"Move directory executed successfully."<<endl;
		}
		else{
			cout<<"Move directory executed successfully."<<endl;
		}
	}

}

