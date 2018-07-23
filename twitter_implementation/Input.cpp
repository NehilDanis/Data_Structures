/*
 * Input.cpp
 *
 *  Created on: 15 Kas 2015
 *      Author: User
 */

#include "Input.h"

 void Input::readInput(){//The program will read input file line by line.
	 string line;
	  ifstream myfile ("input.txt");
	  if (myfile.is_open())
	  {
	    while ( getline (myfile,line) )
	    {
	    	split(line);//After reading every line,the program will call the split function for dividing the line.
	    }
	    myfile.close();//After reading the file,input file will be closed.
	  }

	  else cout << "Unable to open file";
 }

 void Input::split(string line){//In this function each line of input will be devided by using space delimiter.
	 	  int counter=0;
		  string delimiter = " ";//This is the token that the program used to divide the line.
		  size_t pos = 0;
		  string token;
		  string token0;
		  string token1;
		  string token2;
		  string token3;
		  	  while ((pos = line.find(delimiter)) != std::string::npos) {
		  	    	token = line.substr(0, pos);
		  	    	line.erase(0, pos + delimiter.length());
		  	      if(counter==0){
		  	    	  token0=token;
		  	      }
		  	      else if(counter==1){
		  	    	  token1=token;
		  	      }
		  	      else if(counter==2){
		  	    	  token2=token;
		  	      }
		  	      else if(counter==3){
		  	    	  token3=token;
		  	      }
		  	      else if(counter==4){
		  	    	  cout<<"ERROR"<<endl;
		  	      }
		  	      counter++;
		  	  }

			  //token0 is for command.
			  if(token0=="AddUser"){//if token0 is equal to AddUser the program will call the getTheCommandDone function into the command class.
		  		  obj.getTheCommandDone(token0,token1,line,"","");
		  	  }
		  	  else if(token0=="ViewUser"){//if token0 is equal to ViewUser the program will call the getTheCommandDone function into the command class.
		  		  obj.getTheCommandDone(token0,line,"","","");
		  	  }
		  	  else if(token0=="FollowUser"){//if token0 is equal to FollowUser the program will call the getTheCommandDone function into the command class.
		  		obj.getTheCommandDone(token0,token1,line,"","");
		  	  }
		  	  else if(token0=="AddPost"){//if token0 is equal to AddPost the program will call the getTheCommandDone function into the command class.
		  		  if(counter==3){//This is for text post.
		  			  obj.getTheCommandDone(token0,token1,token2,line,"");
		  		  }
		  		  else if(counter==4){//This is for image post
		  			  obj.getTheCommandDone(token0,token1,token2,token3,line);
		  		  }
		  	  }
		  	  else if(token0=="Repost"){//if token0 is equal to Repost the program will call the getTheCommandDone function into the command class.
		  		obj.getTheCommandDone(token0,token1,token2,line,"");
		  	  }
		  	  else if(token0=="BlockUser"){//if token0 is equal to BlockUser the program will call the getTheCommandDone function into the command class.
		  		  obj.getTheCommandDone(token0,token1,line,"","");
		  	  }
		  	  else if(token0=="UnfollowUser"){//if token0 is equal to UnfollowUser the program will call the getTheCommandDone function into the command class.
		  		  obj.getTheCommandDone(token0,token1,line,"","");
		  	  }
		  	  else if(token0=="LikePost"){//if token0 is equal to LikePost the program will call the getTheCommandDone function into the command class.
		  		  obj.getTheCommandDone(token0,token1,token2,line,"");
		  	  }


 }