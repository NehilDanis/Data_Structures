#include <iostream>
#include "Input.h"
using namespace std;

int main(int argc,char *argv[]) {//The program take two arguments.One of them is for an input file
	//The other one is for an output file.

	 if (argc != 3)//Here,the program controls the number of giving arguments.
	    {
	      cerr << "Usage: " << argv[0] << "inputFile outputFile" << endl;//If the number of arguments is not equal to three,the program will give an error message.
	      return -1;//After printing the error message to console,it will return minus one.
	    }
	  else{//If the number of arguments is equal to three,the program is going to start.
		  Input objectToReadInput;//I created an object that belongs to Input class.Because I want to call the function that stays in Input class.
		  objectToReadInput.readInputFile(argv[1],argv[2]);//By using the Input object,the program will invoke the function that reads the input file.
		  //This function takes two argument.First argument is for an input file,and the other one is for an output file.

	  }

	return 0;
}

