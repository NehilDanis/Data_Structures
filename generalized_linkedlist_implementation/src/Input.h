#ifndef INPUT_H_
#define INPUT_H_

#include <fstream>
#include <iostream>
#include <string>
#include "Document.h"
#include "File.h"
#include "Directory.h"
#include "Commands.h"
using namespace std;

class Input{

public:
	void readInput(char*,char*,Document*,Document**);
	void splitCommand(string,char*,Document*,Document**);
};

#endif