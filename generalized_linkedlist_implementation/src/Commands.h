#ifndef COMMANDS_H_
#define COMMANDS_H_

#include <iostream>
#include <string>
#include <fstream>
#include "Document.h"
#include "File.h"
#include "Directory.h"
using namespace std;

class Commands{
public: 
	Document* search(Document*,string,Document*,string);
	Document* nextSearch(Document*,string,Document*,string);

	void changeDirectoryImplement(string,char*,Document*,Document*,Document**);//url,outputFile,headData,currData,address of currData
	void createFileImplement(string,char*,Document*,Document*,Document**);//url,outputFile,headData,currData,address of currData
	void makeDirectoryImplement(string,char*,Document*,Document*,Document**);//url,outputFile,headData,currData,address of currData
	void removeImplement(string,string,char*,Document*,Document*,Document**);//fileOrDirectory,url,headData,currData,address of currData
	void moveImplement(string,string,string,char*,Document*,Document*,Document**);//fileOrDirectory,sourceUrl,destinationUrl,headData,currData,address of currData
	void copyImplement(string,string,string,char*,Document*,Document*,Document**);//fileOrDirectory,sourceUrl,destinationUrl,headData,currData,address of currData
	void listImplement(string,char*,Document*,Document*,Document**);

	void printDirectory(Document*,int,char*);
	void printInside(Document*,int,char*);

	void createCopyDirectory(Document*,Document*,char*);
	void copyDirectory(Document*,Document*,string,char*);

	int split(string,Document*);

};





#endif