#ifndef DOCUMENT_H_
#define DOCUMENT_H_

#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class Document{
private:
	Document* next;
	Document* link;
	string name;

public:
	virtual string getType()=0;
	void setName(string);
	void setLink(Document*);
	void setNext(Document*);
	Document* getNext();
	Document* getLink();
	string getName();

};

#endif 