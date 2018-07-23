#include "Input.h"
Commands *obj;

void Input::readInput(char* input,char* output,Document* headData,Document** currDirectory){//Here the program will read input file line by line.
	  string line;
	  ifstream myfile (input);
	  if (myfile.is_open())
	  {
	    while ( getline (myfile,line) )
	    {
			splitCommand(line,output,headData,currDirectory);//After reading one line,this line will send the splitcommand function.
	    }
	    myfile.close();//After reading the file,input file will be closed.
	  }

	  else cout << "Unable to open file";

}

void Input::splitCommand(string line,char* output,Document* headData,Document** curr){
	Document* currDirectory=*curr;//Here the program initialized the current directory value.
    string delimiter = " ";//Our delimiter is blank space .
	size_t pos = 0;
	string token;
	string token1;
	string token2;
	int counter=0;
	while ((pos = line.find(delimiter)) != std::string::npos) {
		if(counter==0){
			token = line.substr(0, pos);
		}
		else if(counter==1){
			token1= line.substr(0, pos);
		}
		else if(counter==2){
			token2=line.substr(0, pos);
		}
		line.erase(0, pos + delimiter.length());
		counter++;
	}
	if(counter==0){
		if(line=="ls"){//List command without any url
			obj->listImplement("",output,headData,currDirectory,curr);//list command
		}
	}
	else if(counter==1){
		if(token=="crtfl"){//create file
			obj->createFileImplement(line,output,headData,currDirectory,curr);

		}
		else if(token=="mkdir"){//make directory
			obj->makeDirectoryImplement(line,output,headData,currDirectory,curr);
		}
		else if(token=="cd"){//change directory command
			obj->changeDirectoryImplement(line,output,headData,currDirectory,curr);
		}
		else if(token=="ls"){//list command by using given url
			obj->listImplement(line,output,headData,currDirectory,curr);
		}
	}
	else if(counter==2){
		if(token=="rm"){//remove command
			obj->removeImplement(token1,line,output,headData,currDirectory,curr);
		}
	}
	else if(counter==3){
		if(token=="mv"){//move command
			obj->moveImplement(token1,token2,line,output,headData,currDirectory,curr);
		}
		else if(token=="cp"){//copy command
			obj->copyImplement(token1,token2,line,output,headData,currDirectory,curr);
		}
	}


}