/*
 * List.cpp
 *
 *  Created on: 10 Kas 2015
 *      Author: Nehil
 */

#include "List.h"

List::List() {//Here the program will be initialize the head ,tail ,temp and the number of items of item linked list.
	itemNumber=0;
	headOfList=NULL;
	tailOfLits=NULL;
	tempOfList=NULL;

}

List::~List(){//This is deconstructor.This will delete the object that created from List class after the program finished everything.
}

void List::deleteFromItemList(int onOff){
	if(onOff==0){//If the onOff is zero,the item will be deleted from head of the list.
		itemNodePtr delObj=NULL;//The delObj is created.
		tempOfList=headOfList;
		tailOfLits=headOfList;
		delObj=headOfList;
		if(headOfList==NULL){//This means there is no item into the item list,because of that the deletion will be ignored.
			delete delObj;
		}
		else if(delObj == headOfList){//If the delObj is equal to the head of the item list,the obj will be deleted.
				headOfList=headOfList->next;
				tempOfList=NULL;
				delete delObj;
				itemNumber--;//The number of items in linked list is decreased by one.
		}

	}
	else if(onOff==1){//If the onOff is one,the item will be deleted from tail of the list.
		if(headOfList->next==NULL){//If the next item of head of the list is NULL,the program will execute this block.This means there is one item into the item list.
			itemNodePtr delObj=headOfList;
			headOfList=NULL;
			tailOfLits=NULL;
			tempOfList=NULL;
			delete delObj;
			itemNumber--;//The number of items in linked list is decreased by one.


		}
		else{//If there are more than one items,the program will execute this block.
			itemNodePtr delObj=NULL;
			tempOfList=headOfList;
			tailOfLits=headOfList;
			while(tailOfLits->next!=NULL){
				tailOfLits=tailOfLits->next;
			}
			while(tempOfList->next!=tailOfLits){
				tempOfList=tempOfList->next;
			}
			delObj=tempOfList->next;
			tempOfList->next=NULL;
			tailOfLits=tempOfList;
			tempOfList=NULL;
			delete delObj;
			itemNumber--;//The number of items in linked list is decreased by one.
		}
	}

}
void List::putToTheItemList(string data,string dataType,int onOff){

	if(onOff==0){//The program will put the item to the end of the item list.
		itemNodePtr obj;
		obj=new itemNode;
		obj->next=NULL;
		obj->value=data;
		obj->type=dataType;
		if(headOfList!=NULL){
			tailOfLits=headOfList;
			while(tailOfLits->next!=NULL){
				tailOfLits=tailOfLits->next;
			}
			tailOfLits->next=obj;
		}
		else{
			headOfList=obj;
		}
	}
	else if(onOff==1){//The program will put the item to the head of the item list.
		itemNodePtr obj;
		obj=new itemNode;
		obj->next=headOfList;
		obj->value=data;
		obj->type=dataType;
		headOfList=obj;
	}
	itemNumber++;//The number of items is increased by one.

}
void List::printTheItemList(char * outputFile){//Here the list is printed to the output file.
	ofstream outputObj(outputFile,ios::app);
	if(headOfList==NULL){
		outputObj<<endl;
	}
	else{
		tailOfLits=headOfList;
			while(tailOfLits!=NULL){
				if(tailOfLits->type=="d"){
					double valueDouble=stringToDoubleConverter(tailOfLits->value);
					outputObj<<setprecision(15)<<valueDouble;//To prevent the values that are different from zero stays after dot,we used setprecision.
				}
				else {
					outputObj<<tailOfLits->value;
				}
				tailOfLits=tailOfLits->next;
			}
			outputObj<<"\n";
	}
}


string List::getFirstItem(){//This is a getter to take first item of item List.
	return headOfList->value;
}
string List::getSecondItem(){//This is a getter to take second item of item List.
	return headOfList->next->value;
}
string List::getFirstItemType(){//This is a getter to take first item's type of item List.
	return headOfList->type;
}
string List::getSecondItemType(){//This is a getter to take second item's type of item List.
	return headOfList->next->type;
}

int List::getItemNumber(){//This is a getter to take the number of items into the igtem list.
	return itemNumber;
}

double List::stringToDoubleConverter(string x){//This converts strings to doubles.
	double num = atof( x.c_str() );
	setprecision(10);
	return num;
}




