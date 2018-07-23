#include <iostream>
#include <fstream>
#include "Input.h"
using namespace std;

int main() {

	Input inputObj;//This is for calling a function that stays into the input class.
	inputObj.readInput();//For reading the input we called this function.
	getchar();//End of the program I want the console to hang on the screen.Because of that I used getchar().Until the user 
	//put any button the console will hang on the screen.
	return 0;
}