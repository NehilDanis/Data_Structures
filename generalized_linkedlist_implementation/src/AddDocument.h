#ifndef ADDDOCUMENT_H_
#define ADDDOCUMENT_H_

#include "Document.h"
#include "Directory.h"
#include "File.h"
#include <iostream>
#include <string>

using namespace std;

class AddDocument{
public:
	AddDocument();
	Document* head;
	Document* temp;
	Document* curr;
	Document* currDirectory;

	void splitParameter(string);
	void splitLine(string curr,int *deger,string str[],int j,Document* headData);

};


#endif