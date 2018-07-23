#include "Document.h"

void Document::setName(string nameData){//This is a setter for name of file or directory.
	name=nameData;
}
void Document::setLink(Document* linkData){//This is a setter for link pointer of file or directory.
	link=linkData;
}
void Document::setNext(Document* nextData){//This is a setter for next pointer of file or directory.
	next=nextData;
}
Document* Document::getNext(){//This is a getter for name of file or directory.
	return next;
}
Document* Document::getLink(){//This is a getter for link pointer of file or directory.
	return link;
}
string Document::getName(){//This is a getter for next pointer of file or directory.
	return name;
}

