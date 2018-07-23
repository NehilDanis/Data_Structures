#ifndef FILE_H_
#define FILE_H_


#include <iostream>
#include <string>
#include <fstream>
#include "Document.h"
using namespace std;

class File : public Document{
public:
	string getType();
	void crtfl(Document*,string,char*);
	void rmf(Document*,string,char*);
	void mvf(Document*,Document*,string,string,char*);
	void copyFile(Document*,Document*,string,char*);
	void moveCreateFile(Document*,string,char*);

};

#endif 