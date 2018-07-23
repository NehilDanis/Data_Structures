#include "AddDocument.h"

AddDocument::AddDocument(){//These are for the generalized list.When we initialize the system,automatically these pointers will be initialized too.
	head=NULL;
	temp=NULL;
	curr=NULL;
}

void AddDocument::splitParameter(string x){//Here the program assign char* array to the string array.In this way we can create file or directory names in words.
  string str;
  int j=0;
  str=x;
  string token;
  string strCurr[200];
  for(int i=0;i<x.length();i++){//The program will continue till the end of the char * array.
	  if(str[i]=='('){
		   if(str[i-1]!=',' && str[i-1]!=')' && str[i-1]!='(' ){
			  j++;
		  }
		  token="";
		  strCurr[j]=str[i];
		  j++;
	  }
	  else if(str[i]==')'){
		  token="";
		  if(str[i-1]!=',' && str[i-1]!=')' && str[i-1]!='(' ){
			  j++;
		  }
		  strCurr[j]=str[i];
		  j++;
	  }
	  else if(str[i]==','){
		  token="";
		  if(str[i-1]!=',' && str[i-1]!=')' && str[i-1]!='(' ){
			  j++;
		  }
		  strCurr[j]=str[i];
		  j++;
	  }
	  else{
		  token+=str[i];
		  strCurr[j]=token;
	  }
  }
  //After assign each value to the string array , the program will call the splitline function.
  int counter=0;
  splitLine("",&counter,strCurr,j,head);

}

void AddDocument::splitLine(string curr,int *counter,string str[],int j,Document* headData){
	string currentDirectory=curr;
	string temp;
	Document* currDirectoryData=headData;
	Document* tempData;
	while(*counter<j){
		Document* directoryObj=new Directory();
		Document* fileObj=new File();
		if(str[*counter]!="(" && str[*counter]!=")" && str[*counter]!=","){
			if(str[(*counter)+1]=="("){//If the next element is ( ,then the item will be directory.
				temp=str[*counter];

				if(head==NULL){
					directoryObj->setName(temp);
					directoryObj->setNext(NULL);
					directoryObj->setLink(NULL);
					head=directoryObj;
					currDirectory=directoryObj;
					headData=head;
					currDirectoryData=headData;
				}
				else if(headData!=NULL && headData->getLink()==NULL){
					directoryObj->setName(temp);
					directoryObj->setNext(NULL);
					directoryObj->setLink(NULL);
					headData->setLink(directoryObj);
					currDirectoryData=directoryObj;
				}
				else if(headData!=NULL && headData->getLink()!=NULL){
					currDirectoryData=headData;
					directoryObj->setName(temp);
					directoryObj->setNext(NULL);
					directoryObj->setLink(NULL);
					tempData=headData->getLink();
					while(tempData->getNext()!=NULL){
						tempData=tempData->getNext();
					}
					tempData->setNext(directoryObj);
					currDirectoryData=directoryObj;

				}
				//If the item is directory the function will call itself again,to initialize the sub values of this directory.
				(*counter)++;
				splitLine(temp,counter,str,j,currDirectoryData);
			}
			else{//If the item is an file , the program will execute this block.
				temp=str[*counter];
				fileObj->setName(temp);
				fileObj->setLink(NULL);
				fileObj->setNext(NULL);
				if(headData->getLink()==NULL){
					headData->setLink(fileObj);
				}
				else{
					tempData=headData->getLink();
					while(tempData->getNext()!=NULL){
						tempData=tempData->getNext();
					}
					tempData->setNext(fileObj);

				}
			}

		}
		else if(str[*counter]==","){
			//
		}
		else if(str[*counter]==")"){
			return ;
		}
		(*counter)++;
	}

	

}
