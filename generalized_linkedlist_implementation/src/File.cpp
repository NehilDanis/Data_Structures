#include "File.h"



string File::getType(){//This is for deciding the type of item.
	return "f";
}

void File::copyFile(Document* sourceUrl,Document* destinationUrl,string file,char* outputFile){//This is for copy file command.
	ofstream outObj(outputFile,ios::app);
	int counter=0;
	if(sourceUrl!=NULL){
			Document* newFile=new File();
			newFile->setName(file);
			newFile->setLink(NULL);
			newFile->setNext(NULL);
			if(destinationUrl->getLink()==NULL){
				destinationUrl->setLink(newFile);
				if(outputFile!=""){
					cout<<"Copy file executed succesfully."<<endl;
					outObj<<"Copy file executed succesfully."<<endl;
				}
				else{
					cout<<"Copy file executed succesfully."<<endl;
				}
			}
			else{
				destinationUrl=destinationUrl->getLink();
				Document* temp=destinationUrl;
				while(temp!=NULL){
					if(temp->getName()==file){
						if(temp->getType()=="f"){
							counter++;
						}
					}
					temp=temp->getNext();
				}
				if(counter!=0){//If there is another file that has the same name with the copied file,the program will give an error message.
					if(outputFile!=""){
						cout<<"Error : There is already a file that has the same name with the copied file!"<<endl;
						outObj<<"Error : There is already a file that has the same name with the copied file!"<<endl;
					}
					else{
						cout<<"Error : There is already a file that has the same name with the copied file!"<<endl;
					}
				}
				else if(counter==0){
					while(destinationUrl->getNext()!=NULL){
						destinationUrl=destinationUrl->getNext();
					}
					destinationUrl->setNext(newFile);
					if(outputFile!=""){
						cout<<"Copy file executed succesfully."<<endl;
						outObj<<"Copy file executed succesfully."<<endl;
					}
					else{
						cout<<"Copy file executed succesfully."<<endl;
					}
				}
			}
	}
}


void File::crtfl(Document* url,string file,char* outputFile){//This is for create new file command.
	ofstream outObj(outputFile,ios::app);
	int counter=0;
	Document* newFile=new File();
	newFile->setName(file);
	newFile->setLink(NULL);
	newFile->setNext(NULL);
	if(url->getLink()==NULL){
		url->setLink(newFile);
		if(outputFile!=""){
			cout<<"Create file executed successfully."<<endl;
			outObj<<"Create file executed successfully."<<endl;
		}
		else{
			cout<<"Create file executed successfully."<<endl;
		}
	}
	else {
		url=url->getLink();
		while(url->getNext()!=NULL){
			if(url->getName()==file){
				if(url->getType()=="f"){
					counter++;
					break;
				}
			}
			url=url->getNext();
		}
		if(url->getName()==file){
			if(url->getType()=="f"){
				counter++;
			}
		}
		if(counter==0){
			url->setNext(newFile);
			if(outputFile!=""){
				cout<<"Create file executed successfully."<<endl;
				outObj<<"Create file executed successfully."<<endl;
			}
			else{
				cout<<"Create file executed successfully."<<endl;
			}
		}
		else{//If there is another file that has the same name,the program will give an error message.
			if(outputFile!=""){
				cout<<"Error : There is already a file that has the same name!"<<endl;
				outObj<<"Error : There is already a file that has the same name!"<<endl;
			}
			else{
				cout<<"Error : There is already a file that has the same name!"<<endl;
			}
		}
		
	}
}

void File::moveCreateFile(Document* url,string file,char* outputFile){//when we implement the move file command we need this function to create new file in the new location.
	ofstream outObj(outputFile,ios::app);
	int counter=0;
	Document* newFile=new File();
	newFile->setName(file);
	newFile->setLink(NULL);
	newFile->setNext(NULL);
	if(url->getLink()==NULL){
		url->setLink(newFile);
	}
	else {
		url=url->getLink();
		while(url->getNext()!=NULL){
			if(url->getName()==file){
				if(url->getType()=="f"){
					counter++;
					break;
				}
			}
			url=url->getNext();
		}
		if(url->getName()==file){
			if(url->getType()=="f"){
				counter++;
			}
		}
		if(counter==0){
			url->setNext(newFile);
		}
		else{//If there is another file that has the same name ,the program will give an error message.
			if(outputFile!=""){
				cout<<"Error : There is already a file that has the same name!"<<endl;
				outObj<<"Error : There is already a file that has the same name!"<<endl;
			}
			else{
				cout<<"Error : There is already a file that has the same name!"<<endl;
			}
		}
		
	}

}

void File::rmf(Document* url,string file,char* outputFile){//This is for remove file command.
	ofstream outObj(outputFile,ios::app);
	Document* delFile=NULL;
	Document* tempHead;
	Document* currHead;
		if(url->getLink()==NULL){//If the link pointer of current url is null,the program will give an error message.
			if(outputFile!=""){
				cout<<"Error : File didn't find!"<<endl;
				outObj<<"Error : File didn't find!"<<endl;
			}
			else{
				cout<<"Error : File didn't find!"<<endl;
			}
		}
		else{
			Document* currUrl=url;
			url=url->getLink();
			tempHead=url;
			currHead=url;
			while(currHead!=NULL){//Else we will go through the sub list of current list until find the removing file .
				if( currHead->getName()==file && currHead->getType()=="f"){
					break;
				}
				tempHead=currHead;
				currHead=currHead->getNext();
			}
			if(currHead==NULL){//If we don't find any thing ,the program will give an error message.
				if(outputFile!=""){
					cout<<"Error : File didn't find!"<<endl;
					outObj<<"Error : File didn't find!"<<endl;
				}
				else{
					cout<<"Error : File didn't find!"<<endl;
				}
				delete delFile;
			}
			else {
				if(currHead->getType()=="f"){
					delFile=currHead;
					currHead=currHead->getNext();
					tempHead->setNext(currHead);
					if(delFile==url){
						url=url->getNext();
						currUrl->setLink(url);
						tempHead=NULL;
					}
					delete delFile;
					if(outputFile!=""){
						cout<<"Remove file executed successfully."<<endl;
						outObj<<"Remove file executed successfully."<<endl;
					}
					else{
						cout<<"Remove file executed successfully."<<endl;
					}
				}
				else{
					if(outputFile!=""){
						cout<<"Error : The destination url is a directory not a file!"<<endl;
						outObj<<"Error : The destination url is a directory not a file!"<<endl;
					}
					else{
						cout<<"Error : The destination url is a directory not a file!"<<endl;
					}
				}
			}
		}


}

void File::mvf(Document* sourceDirectory,Document* destinationDirectory,string movedFile,string moving,char* outputFile){//This is for remove file command.
	ofstream outObj(outputFile,ios::app);
	Document* tempHead;
	Document* currHead;
	Document* delFile=NULL;
	int counter=0;
	if(sourceDirectory->getLink()==NULL){//If the link of sourcedirectory is null,the program will give an error message.
		if(outputFile!=""){
			cout<<"Error : The file that we wanted to move didn't find in the source directory!"<<endl;
			outObj<<"Error : The file that we wanted to move didn't find in the source directory!"<<endl;
		}
		else{
			cout<<"Error : The file that we wanted to move didn't find in the source directory!"<<endl;
		}
	}
	else{
		Document* currUrl=sourceDirectory;
		sourceDirectory=sourceDirectory->getLink();
		tempHead=sourceDirectory;
		currHead=sourceDirectory;
		while(currHead!=NULL ){//Else we will go through the sub list of current list until find the moving file .
			if(currHead->getName()==movedFile && currHead->getType()=="f"){
				break;
			}
			tempHead=currHead;
			currHead=currHead->getNext();
		}
		if(currHead==NULL){//If we don't fin anything,the program will give an error message.
			if(outputFile!=""){
				cout<<"Error : The file that we wanted to move didn't find in the source directory!"<<endl;
				outObj<<"Error : The file that we wanted to move didn't find in the source directory!"<<endl;
			}
			else{
				cout<<"Error : The file that we wanted to move didn't find in the source directory!"<<endl;
			}
			delete delFile;
		}
		else {
			if(currHead->getType()=="f"){
				delFile=currHead;
				currHead=currHead->getNext();
				tempHead->setNext(currHead);
				if(delFile==sourceDirectory){
					sourceDirectory=sourceDirectory->getNext();
					currUrl->setLink(sourceDirectory);
					tempHead=NULL;
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
	if(counter!=0){
		moveCreateFile(destinationDirectory,moving,outputFile);
		if(outputFile!=""){
			cout<<"Move file executed successfully."<<endl;
			outObj<<"Move file executed successfully."<<endl;
		}
		else{
			cout<<"Move file executed successfully."<<endl;
		}
	}


}