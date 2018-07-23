#ifndef DIRECTORY_H_
#define DIRECTORY_H_


#include <iostream>
#include <string>
#include <fstream>
#include "Document.h"
using namespace std;

class Directory : public Document{
public:
	string getType();
	Document* createLostDirectory(Document*,string);
	void mkdir(Document*,string,char*);
	void rmd(Document*,string,Document*,char*);
	void mvd(Document*,Document*,string,string,Document*,char*);
};

#endif