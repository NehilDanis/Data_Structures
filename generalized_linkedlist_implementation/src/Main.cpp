#include <iostream>
#include <string>
#include <fstream>
#include "Input.h"
#include "File.h"
#include "AddDocument.h"
#include "Document.h"
#include "Directory.h"

using namespace std;

int main(int argc,char *argv[]){
	AddDocument importObj;//This is an object for initializing part.
	Input readObj;//This is for calling split command function or read input file function.
	if(argc==2){//If there is just one argument , the program will execute this block.
		importObj.splitParameter(argv[1]);//Here the program will initialize.
		cout<<"System initialized."<<endl<<endl;
		string line;
		while(1){//The program will wait for a command until user write exit to the console.
			getline(cin,line);
			if(line=="exit"){
				break;
			}
			else{
				readObj.splitCommand(line,"",importObj.head,&importObj.currDirectory);//Here the program will send each command to the splitcommand function.

			}
		}
	}
	else if(argc==4){
		ofstream obj(argv[3],ios::app);
		importObj.splitParameter(argv[1]);//Here the program will initialize.
		cout<<"System initialized."<<endl<<endl;
		obj<<"System initialized."<<endl<<endl;
		readObj.readInput(argv[2],argv[3],importObj.head,&importObj.currDirectory);//Here the program will call the read input file function.

	}
	else{//If there is more then 3 or lower then one argument,the program will give error to the console. 
		cerr<<"Wrong parameter!!"<<endl;
	}
	getchar();


}