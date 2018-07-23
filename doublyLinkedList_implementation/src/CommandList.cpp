/*
 * CommandList.cpp
 *
 *  Created on: 10 Kas 2015
 *      Author: Nehil
 */

#include "CommandList.h"

int reversionOnOff=0;//This is for writing redo reversed or put,add or delete reversed.

CommandList::CommandList() {//This will initialize the head,tail and temp of the command linked list.
	head=NULL;//At first time that the program create the linked list,tail,head and temp will be initialized by NULL.
	tail=NULL;
	temp=NULL;
}

CommandList::~CommandList(){//This is deconstructor.This will delete the object that created from CommandList class after the program finished everything.
}

void CommandList::addCommand(string command,string value1,string type1,string value2,string type2,string value3,string type3){
	commandNodePtr obj;
	obj=new commandNode;
	obj->next=NULL;
	obj->val1=value1;
	obj->type1=type1;
	obj->val2=value2;
	obj->type2=type2;
	obj->val3=value3;
	obj->type3=type3;
	obj->command=command;
	if(head!=NULL){
		tail=head;
		while(tail->next!=NULL){
			tail=tail->next;
		}
		obj->prev=tail;
		tail->next=obj;//son itemin next ine yeni itemin adresi atandý. :)
		tail=obj;
		temp=tail;
	}
	else{
		obj->prev=NULL;
		head=obj;
		tail=obj;
		temp=tail;
	}
}


void CommandList::doTheJob(string command,string value,string type,char * outputFile){//After reading input the program will continue to execute from here.
	ofstream outputObj(outputFile,ios::app);//This is output file stream.
	string data1,type1;
	string data2,type2;
	string result,resultType;
	int itemNumber;//This is for keeping the number of items into the item linked list that stays into the List class.

	if (command=="ADD"){//If the command is add,the program will continue to execute from here.
		if(getItemNumber()<2){//If the number of items is lower than 2,the program will give an error message.
			outputObj<<"ADDITION IGNORED"<<endl;
		}

		else{//If the number of items is equal or greater than 2,the program will call athe addFirstTwoItems function.
			addFirstTwoItems(outputFile);
			reversionOnOff=0;//The reversionOnOff equalized to the zero.
		}

	}

	else if(command=="PUT"){//If the command is put,the program will continue to execute from here.

		if(type=="Ss"){//If the putting values type is string,the program will print a message to the output.
			outputObj<<"A STRING ADDED TO COLLECTION"<<endl;
		}

		else if(type=="i"){//If the putting values type is integer,the program will print a message to the output.
			int valueInt=stringToIntConverter(value);//To vanish the unnecessary zeros at the end of the value,we turned it to integer,and then turned into a string again.
			value=intToStringConverter(valueInt);
			outputObj<<"AN INTEGER ADDED TO COLLECTION"<<endl;
		}

		else if(type=="d"){//If the putting values type is double,the program will print a message to the output.
			outputObj<<"A DOUBLE ADDED TO COLLECTION"<<endl;
		}

		addCommand(command,value,type,"","","","");//The command will add to the command list with the values that the command used.
		putToTheItemList(value,type,0);//The program will call the putToTheItemList function that stays into the List class.By executing this line the putting value will be added to the item list with its type.
		reversionOnOff=0;//The reversionOnOff equalized to the zero.

	}

	else if(command=="DELETE"){//If the command is delete,the program will continue to execute from here.

		itemNumber=getItemNumber();//The number of items into the itemList is assigned to the itemNumber.
		if(itemNumber==0){//If the number of items is equal to zero.The deletion will be ignored.
			outputObj<<"DELETION IGNORED"<<endl;//The program will print an error message to the output file.
		}
		else if(itemNumber>0){//If the number of items is greater to zero,the program will continue to execute from here.
			data1=getFirstItem();//The first item of the itemList will be assigned to the data1.
			type1=getFirstItemType();//The first item of the itemList's type will be assigned to the type1.

			if(type1=="Ss"){//If the type is equal to string,the program print a message to the output file.
				outputObj<<"A STRING DELETED"<<endl;
			}

			else if(type1=="i"){//If the type is equal to integer,the program print a message to the output file.
				outputObj<<"AN INTEGER DELETED"<<endl;
			}

			else if(type1=="d"){//If the type is equal to double,the program print a message to the output file.
				outputObj<<"A DOUBLE DELETED"<<endl;
			}

			deleteFromItemList(0);//The very first item of the itemList will be deleted by calling this function.
			addCommand(command,data1,type1,"","","","");//The command will add to the command list with the values that the command used.
			reversionOnOff=0;//The reversionOnOff equalized to the zero.
		}


	}

	else if(command=="PRINT"){//If the command is print,the program will call the printTheItemList function that stays into the List class.
		printTheItemList(outputFile);
	}

	else if(command=="UNDO"){//If the command is undo,the program will continue to execute from here.
		//Here we will reversed the commands that the program implemented.
		if(temp==NULL){//If the temp pointer of the command list is equal to NULL,I mean the number of elements into the command list is equalt to zero,The program
			//will give an error message to the output file.
			outputObj<<"UNDO IGNORED"<<endl;
		}
		else{
			if(temp->command=="PUT"){//If the command value of last node into the command list is put,the program will reverse this command.
				if(reversionOnOff!=0){//If there is a redo command that comes before undo,the program will execute this if block.
					outputObj<<"REDO REVERSED"<<endl;
					reversionOnOff=0;//The reversionOnOff equalized to the zero.
				}
				else{
					outputObj<<"PUTTING REVERSED"<<endl;
				}
				deleteFromItemList(1);//The reverse command of put is delete.If we add the item from the tail of linked list,we have to delete the last item of itemList.
				//Because of that we send 1 as an argument.
			}

			else if(temp->command=="DELETE"){//If the command value of last node into the command list is delete,the program will reverse this command.
				if(reversionOnOff!=0){//If there is a redo command that comes before undo,the program will execute this if block.
					outputObj<<"REDO REVERSED"<<endl;
					reversionOnOff=0;//The reversionOnOff equalized to the zero.
				}
				else{
					outputObj<<"DELETION REVERSED"<<endl;
				}
				data1=temp->val1;//The value and the type of deleted object.
				type1=temp->type1;
				putToTheItemList(data1,type1,1);//The reverse command of delete is put.If we delete the item from the head of linked list,we have to put the item from head of the list.
				//Because of that we send 1 as an argument.
			}
			else if(temp->command=="ADD"){//If the command value of last node into the command list is add,the program will reverse this command.
				if(reversionOnOff!=0){//If there is a redo command that comes before undo,the program will execute this if block.
					outputObj<<"REDO REVERSED"<<endl;
					reversionOnOff=0;//The reversionOnOff equalized to the zero.
				}
				else{
					outputObj<<"ADDITION REVERSED"<<endl;
				}
				data1=temp->val1;//Data1 and data1 are the adding objects.And type1 and type2 is these values' types.
				type1=temp->type1;
				data2=temp->val2;
				type2=temp->type2;
				deleteFromItemList(1);//At first we have to delete last item.Because the sum of first to nodes of item linked list was added to the end of the list.
				//Because of that the program has to delete last item.
				putToTheItemList(data2,type2,1);//The adding values have to be put head of the item linked list.
				putToTheItemList(data1,type1,1);
				//Because of that we send 1 as an argument.

			}

			temp=temp->prev;//At the end of the undo command the program will equalized the temp pointer to the previous node of temp.
		}

	}

	else if(command=="REDO"){//If the command is redo,the program will continue to execute from here.
		if(temp==tail){//If the temp value haven't been equalized before by temp->prev value,the program will give an error message to the output file.
			outputObj<<"REDO IGNORED"<<endl;
		}
		else{
			reversionOnOff++;
			outputObj<<"UNDO REVERSED"<<endl;
			if(temp==NULL){//If the temp value is equal to NULL,the program hasn't got a next item because of that I used if else blocks.
				temp=head;//The temp is equalized yo the head of the command list.
				if(temp->command=="PUT"){//If the command value of last node into the command list is put,the program will reverse the undo command of put.
					data1=temp->val1;
					type1=temp->type1;
					putToTheItemList(data1,type1,0);//The reverse command of undo for put.The program will put the item at the end of the item list again.
					//Because of that we send 0 as an argument.

				}
				else if(temp->command=="DELETE"){//If the command value of last node into the command list is delete,the program will reverse the undo command of delete.
					deleteFromItemList(0);//The reverse command of undo for delete.The program will delete first item of the item list again.
					//Because of that we send 0 as an argument.
				}
				else if(temp->command=="ADD"){//If the command value of last node into the command list is add,the program will reverse the undo command of add.
					result=temp->val3;
					resultType=temp->type3;
					deleteFromItemList(0);
					deleteFromItemList(0);
					putToTheItemList(result,resultType,0);//The reverse command of undo for add.The program add the sum of fisrt two items at the end of the list again.
					//And the program has to delete first two items again.
				}

			}
			else{
				if(temp->next->command=="PUT"){//If the command value of last node into the command list is put,the program will reverse the undo command of put.
					data1=temp->next->val1;
					type1=temp->next->type1;
					putToTheItemList(data1,type1,0);//The reverse command of undo for put.The program will put the item at the end of the item list again.
					//Because of that we send 0 as an argument.

				}

				else if(temp->next->command=="DELETE"){//If the command value of last node into the command list is delete,the program will reverse the undo command of delete.
					deleteFromItemList(0);//The reverse command of undo for delete.The program will delete first item of the item list again.
					//Because of that we send 0 as an argument.
				}

				else if(temp->next->command=="ADD"){//If the command value of last node into the command list is add,the program will reverse the undo command of add.
					result=temp->next->val3;
					resultType=temp->next->type3;
					deleteFromItemList(0);
					deleteFromItemList(0);
					putToTheItemList(result,resultType,0);//The reverse command of undo for add.The program add the sum of fisrt two items at the end of the list again.
					//And the program has to delete first two items again.
				}


				temp=temp->next;//At the end of the redo command the program will equalized the temp pointer to the next node of temp.
			}

		}

	}

}

void CommandList::addFirstTwoItems(char* outputFile){//This function will add first two item of item list.And send the result to the putToTheItemList function putting the item list.
	//And this will delete the first two node after finding sum of them.
	ofstream outputObj(outputFile,ios::app);
	string data1,data2,result;
	string type1,type2;
	data1=getFirstItem();
	data2=getSecondItem();
	type1=getFirstItemType();
	type2=getSecondItemType();
	if(type1=="Ss" || type2=="Ss"){//If one of the first two nodes is string the program will execute this if block.And the result of this sum will be in string type.
		if(type1=="Ss" && type2=="d"){
			string dat=data2;
			double valueDouble=stringToDoubleConverter(dat);
			dat=doubleToStringConverter(valueDouble);
			result=data1+dat;//After finding the sum of two item the program will be assign this result to the result value.
			addCommand("ADD",data1,type1,data2,type2,result,"Ss");//The command will add to the command list with the values that the command used.
		}
		else if(type1=="d" && type2=="Ss"){
			string dat=data1;
			double valueDouble=stringToDoubleConverter(dat);
			dat=doubleToStringConverter(valueDouble);
			result=dat+data2;//After finding the sum of two item the program will be assign this result to the result value.
			addCommand("ADD",data1,type1,data2,type2,result,"Ss");//The command will add to the command list with the values that the command used.
		}
		else{
			result=data1+data2;//After finding the sum of two item the program will be assign this result to the result value.
			addCommand("ADD",data1,type1,data2,type2,result,"Ss");//The command will add to the command list with the values that the command used.
		}
		putToTheItemList(result,"Ss",0);//The new item will be put at the and of the item list.
		deleteFromItemList(0);//And first two nodes will be deleted.
		deleteFromItemList(0);
		if(type1=="Ss" && type2=="Ss"){
			outputObj<<"A STRING ADDED TO A STRING AND NEW STRING PUT END OF THE COLLECTION"<<endl;
		}
		else if(type1=="Ss" && type2=="i"){
			outputObj<<"AN INTEGER ADDED TO A STRING AND NEW STRING PUT END OF THE COLLECTION"<<endl;
		}
		else if(type1=="Ss" && type2=="d"){
			outputObj<<"A DOUBLE ADDED TO A STRING AND NEW STRING PUT END OF THE COLLECTION"<<endl;
		}
		else if(type1=="i" && type2=="Ss"){
			outputObj<<"A STRING ADDED TO AN INTEGER AND NEW STRING PUT END OF THE COLLECTION"<<endl;
		}
		else if(type1=="d" && type2=="Ss"){
			outputObj<<"A STRING ADDED TO A DOUBLE AND NEW STRING PUT END OF THE COLLECTION"<<endl;
		}

	}

	else if(type1=="i" && type2=="d"){//If the first node is in integer type and the next one is in double type the program will execute this block.
		int intData=stringToIntConverter(data1);
		double doubleData=stringToDoubleConverter(data2);
		double sum=intData+doubleData;
		result=doubleToStringConverter(sum);
		addCommand("ADD",data1,type1,data2,type2,result,"d");
		putToTheItemList(result,"d",0);
		deleteFromItemList(0);
		deleteFromItemList(0);//The new double will be added to the item list and first two nodes will be deleted.
		outputObj<<"A DOUBLE ADDED TO AN INTEGER AND NEW DOUBLE PUT END OF THE COLLECTION"<<endl;
	}

	else if(type1=="d" && type2=="i"){//If the first node is in double type and the next one is in integer type the program will execute this block.
		double doubleData=stringToDoubleConverter(data1);
		int intData=stringToIntConverter(data2);
		double sum=doubleData+intData;
		result=doubleToStringConverter(sum);
		addCommand("ADD",data1,type1,data2,type2,result,"d");
		putToTheItemList(result,"d",0);
		deleteFromItemList(0);
		deleteFromItemList(0);//The new double will be added to the item list and first two nodes will be deleted.
		outputObj<<"AN INTEGER ADDED TO A DOUBLE AND NEW DOUBLE PUT END OF THE COLLECTION"<<endl;

	}

	else if(type1=="i" && type2=="i"){//If the first two nodes is in the integer type,the program will execute this block.
		int intData1=stringToIntConverter(data1);
		int intData2=stringToIntConverter(data2);
		int sum=intData1+intData2;
		result=intToStringConverter(sum);
		addCommand("ADD",data1,type1,data2,type2,result,"i");
		putToTheItemList(result,"i",0);
		deleteFromItemList(0);
		deleteFromItemList(0);//The new integer will be added to the item list and first two nodes will be deleted.
		outputObj<<"AN INTEGER ADDED TO AN INTEGER AND NEW INTEGER PUT END OF THE COLLECTION"<<endl;

	}

	else if(type1=="d" || type2=="d"){//If the first two nodes is in the double type,the program will execute this block.
		double doubleData1=stringToDoubleConverter(data1);
		double doubleData2=stringToDoubleConverter(data2);
		double sum=doubleData1+doubleData2;
		result=doubleToStringConverter(sum);
		addCommand("ADD",data1,type1,data2,type2,result,"d");
		putToTheItemList(result,"d",0);
		deleteFromItemList(0);
		deleteFromItemList(0);//The new double will be added to the item list and first two nodes will be deleted.
		outputObj<<"A DOUBLE ADDED TO A DOUBLE AND NEW DOUBLE PUT END OF THE COLLECTION"<<endl;

	}



}

int CommandList::stringToIntConverter(string x){//This converts strings to the integers.
	int num = atoi(x.c_str());
	return num;
}
double CommandList::stringToDoubleConverter(string x){//This converts strings to the doubles.
	double num = atof( x.c_str() );
	setprecision(10);
	return num;
}
string CommandList::doubleToStringConverter(double x){//This converts doubles to the strings.
	stringstream ss;
	ss << x;
	string str = ss.str();
	return str;


}
string CommandList::intToStringConverter(int x){//This converts integers to the string.
	stringstream ss;
	ss << x;
	string str = ss.str();
	return str;
}

//These are for + operator overloading.
double CommandList::operator +(const double val){
	string str=this->getSecondItem();
	double val2=stringToDoubleConverter(str);
	double result=val+val2;
	return result;
}

double CommandList::operator +(const int val){
	string str=this->getSecondItem();
	double val2=stringToDoubleConverter(str);
	double result=val+val2;
	return result;
}

string CommandList::operator +(const string val){
	string str=this->getSecondItem();
	return val+str;

}

