/*
 * Input.cpp
 *
 *  Created on: 10 Kas 2015
 *      Author: Nehil
 */

#include "Input.h"

CommandList item;//I create the object here.Because if I had created into all functions that I used this function,it would have called the CommandList constructor more than one.
//If the commandList class's constructor calls more than one,the program will create a new linked list every time that I invoke.Because of that I define the object in here.

void Input::readInputFile(char * input,char * output){//This is for reading the input file line by line.
	  string line;
		  ifstream myfile (input);//This is for input file stream.
		  if (myfile.is_open())//If the file is open,the program will start to read the lines.
		  {
		    while ( getline (myfile,line) )//This will read input line by line.In every time,the program will read one line.
		    {
		    	split(line,output);//After reading the line,the program will call the split function.Because we have to split the line.
		    }
		    myfile.close();//After reading the input file,input file will be closed.
		  }

		  else{//Otherwise it will give an error message to the console.
			  cout << "Unable to open file";
		  }


}

void Input::split(string line,char *output){
	 ofstream outputObj(output,ios::app);//This is my output file stream.Because in here the program has to write something to the output file.
	 //I used ios::app to prevent the delete the file every time.
	  string type;
	  string delimiter = " ";//This is the token that the program used to divide the line.
	  size_t pos = 0;
	  int counter=0;//The counter keeps the number of token.
	  string token;
	  	  while ((pos = line.find(delimiter)) != std::string::npos) {
	  	      token = line.substr(0, pos);
	  	      line.erase(0, pos + delimiter.length());
	  	      counter++;
	  	      if(counter!=0){//If the counter is one,the program will break.And it will records the words after token into the one string.
	  	    	  break;
	  	      }
	  	  }
	  	  if(counter!=0){//If there are more than one word into one line,the program will execute from here.
	  		  if(token=="ADD" || token=="PUT" || token=="DELETE" || token=="PRINT" || token=="UNDO" || token=="REDO"){
		  		  type=decideToType(line);//By calling this function,we will decide the type of putting value.
		  		  if(type=="Ss"){//If it is string,the program will execute this line.
		  			string str1=line.substr(1,line.length()-2);//Here the program is going to vanish the quetos into the string value.
		  			addToTheCommandList(token,str1,type,output);//After that the program will send the seperated line to the add command function.
		  		  }
		  		  else if (type=="i" || type=="d"){//If the putting value's type is equal to double or integer,the program will execute after this line.
		  			addToTheCommandList(token,line,type,output);//After that the program will send the seperated line to the add command function.
		  		  }
		  		  else{//If the putting value is not into the double,integer or string type,the program will give an error message to the output file.
		  			  outputObj<<"UNKNOWN COMMAND OR DATA TYPE"<<endl;
		  		  }
	  		  }

	  		  else{//If the command is not equal to the one of these commands,the program will give an error message to the output file.
	  			  outputObj<<"UNKNOWN COMMAND OR DATA TYPE"<<endl;
	  		  }

	  	  }
	  	  else {//If there is one word into one line,the program will execute from here.
	  		  if(line=="ADD" || line=="PUT" || line=="DELETE" || line=="PRINT" || line=="UNDO" || line=="REDO"){
		  		 addToTheCommandList(line,"","",output);//After that the program will send the seperated line to the add command function.
	  		  }

	  		  else{//If the command is not equal to the one of these commands,the program will give an error message to the output file.
	  			  outputObj<<"UNKNOWN COMMAND OR DATA TYPE"<<endl;
	  		  }
	  	  }


}

string Input::decideToType(string phrase){
	const char *cstr = phrase.c_str();//The program will turn the string to the char array.
	int countQuotos=0;//This will keep the number of quotos.
	int countnumber=0;
	int countDots=0;//This will keep the number of dots.
	for(unsigned int i=0;i<phrase.length();i++){
		if(cstr[i]=='.'){//If the char element is dot,the program will increase the countDots by one.
			countDots++;
		}
		else if(cstr[i]=='\"'){//If the char element is quoto,the program will increase the countQuotos by one.
			countQuotos++;
		}
	}

	if(countQuotos==2){//If there are two quotos,the value is in string type.
			return "Ss";
	}
	else if(countDots==1){//If the number of dot equal to one,the type will be double.
		return "d";
	}
	else if(countDots==0 && countQuotos==0){//If there are no dots and quotos and the value is being just numbers,the type will be integer.
		for(unsigned i=0;i<phrase.length();i++){
			if(cstr[i]=='0' || cstr[i]=='1' ||cstr[i]=='2' || cstr[i]=='3' || cstr[i]=='4' || cstr[i]=='5' || cstr[i]=='6' || cstr[i]=='7' ||cstr[i]=='8' || cstr[i]=='9'  ){
				countnumber++;
			}
			else{
				return "e";
			}
		}
		return "i";
	}
	return "e";//If the value isn't into integer,double or string type,the program will return e.

}

void Input::addToTheCommandList(string command,string value,string type,char *outputFile){

	item.doTheJob(command,value,type,outputFile);//This will call the doTheJob function that stays into CommandList class.

}




