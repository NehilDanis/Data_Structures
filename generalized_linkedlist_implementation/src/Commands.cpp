#include "Commands.h"


int Commands::split(string url,Document* currData){//This is for deciding the path.
	string str[20];
	string delimiter = "/";
	size_t pos = 0;
	string token;
	int counter=0;
	while ((pos = url.find(delimiter)) != std::string::npos) {
		token = url.substr(0, pos);
		str[counter]=token;
		url.erase(0, pos + delimiter.length());
		counter++;
	}
	str[counter]=url;
	for(int i=0;i<20;i++){
		if(str[i]!=""){
			if(str[0]==currData->getName()){
				return 1;
			}
			else if(str[0]!=currData->getName() && str[0]=="."){
				return 1;
			}
		}
	}
	return 0;
}


void Commands::changeDirectoryImplement(string destination,char* outputFile,Document* headData,Document* currDirectory,Document** curr){//This is for change directory implementation
	ofstream outObj(outputFile,ios::app);
	if(split(destination,currDirectory)==1){
		if(outputFile!=""){
			cout<<"Change directory "<<destination<<endl;
			outObj<<"Change directory "<<destination<<endl;
		}
		else{
			cout<<"Change directory "<<destination<<endl;
		}
	}
	else{
		if(outputFile!=""){
			cout<<"Change directory "<<currDirectory->getName()<<"/"<<destination<<endl;
			outObj<<"Change directory "<<currDirectory->getName()<<"/"<<destination<<endl;
		}
		else{
			cout<<"Change directory "<<currDirectory->getName()<<"/"<<destination<<endl;
		}

	}
	
	Document* tempDirectory;//This is for keeping the temporary directory address.
	File* itemFile=new File();//This is for reaching the file class functions.
	Directory* itemDirectory=new Directory();//This is for reaching the directory class functions.
	if(split(destination,headData)==1){//If the dot is in the give url,the program will execute this block.
		tempDirectory=headData;//Temp directory will equalize to the headdata.
	}
	else {//If there is no dot in the first item of given url , the program will execute this block.
		tempDirectory=currDirectory;//Temp directory will equalize to the current directory.
	}
		string delimiter = "/";//Here I used slash sign as a delimeter.
		size_t pos = 0;
		string token;
		int counter=0;
		while ((pos = destination.find(delimiter)) != std::string::npos) {
			token = destination.substr(0, pos);
			tempDirectory=search(tempDirectory,token,tempDirectory,"d");//Here the program calls the search function to find the address of destination url.
			if(tempDirectory==NULL){//If one of directory can't be found in the directory,the program will give an error!
					if(outputFile!=""){
						cout<<"Error : The destination url didn't find!\n"<<endl;
						outObj<<"Error : The destination url didn't find!\n"<<endl;
					}
					else{
						cout<<"Error : The destination url didn't find!\n"<<endl;
					}
					break;
			}
			else{
				currDirectory=tempDirectory;
			}
			destination.erase(0, pos + delimiter.length());
			counter++;
		}
		tempDirectory=search(currDirectory,destination,tempDirectory,"d");//B ecause of using delimeter for split implementation,always the last word or later after slash will be left.Because of that we have to control the existance of this directory too.
		if(counter==0 && currDirectory!=NULL){//The user can give just one name for changing directory!
			if(destination=="."){
				if(outputFile!=""){
					cout<<"Change directory executed successfully."<<endl;
					outObj<<"Change directory executed successfully."<<endl;
				}
				else{
					cout<<"Change directory executed successfully."<<endl;
				}
				*curr=headData;//Here we changed the real value of curr!
			}
			else if(tempDirectory==NULL){//If there is no url.
				if(outputFile!=""){
					cout<<"Error : The destination url didn't find!"<<endl;
					outObj<<"Error : The destination url didn't find!"<<endl;
				}
				else{
					cout<<"Error : The destination url didn't find!"<<endl;
				}
			}
			else{
				currDirectory=tempDirectory;
			}
		}
		else if(counter!=0 && tempDirectory==NULL){
				if(outputFile!=""){
					cout<<"Error : The destination url didn't find!"<<endl;
					outObj<<"Error : The destination url didn't find!"<<endl;
				}
				else{
					cout<<"Error : The destination url didn't find!"<<endl;
				}

		}
		if(tempDirectory!=NULL){//If the url was found.
			if(tempDirectory->getType()=="d"){
				if(destination!="."){
					if(outputFile!=""){
						cout<<"Change directory executed successfully."<<endl;
						outObj<<"Change directory executed successfully."<<endl;
					}
					else{
						cout<<"Change directory executed successfully."<<endl;
					}
					*curr=tempDirectory;
				}
				
			}
			else {
				if(outputFile!=""){
					cout<<"Error : This is not a directory,this is a file so you cannot change the current directory by using this url!"<<endl;
					outObj<<"Error : This is not a directory,this is a file so you cannot change the current directory by using this url!"<<endl;
				}
				else{
					cout<<"Error : This is not a directory,this is a file so you cannot change the current directory by using this url!"<<endl;
				}
			}
			
		}
		if(outputFile!=""){
			cout<<endl<<"--------------------"<<endl<<endl;
			outObj<<endl<<"--------------------"<<endl<<endl;
		}
		else{
			cout<<endl<<"--------------------"<<endl<<endl;
		}
}


void Commands::createFileImplement(string destination,char* outputFile,Document* headData,Document* currDirectory,Document** curr){//This is for create file implementation.
	ofstream outObj(outputFile,ios::app);
	if(split(destination,currDirectory)==1){
		if(outputFile!=""){
			cout<<"Create file "<<destination<<endl;
			outObj<<"Create file "<<destination<<endl;
		}
		else{
			cout<<"Create file "<<destination<<endl;
		}

	}
	else{
		if(outputFile!=""){
			cout<<"Create file "<<currDirectory->getName()<<"/"<<destination<<endl;
			outObj<<"Create file "<<currDirectory->getName()<<"/"<<destination<<endl;
		}
		else{
			cout<<"Create file "<<currDirectory->getName()<<"/"<<destination<<endl;
		}

	}
	currDirectory=*curr;
	Document* tempDirectory;//This is for keeping the temporary directory address.
	File* itemFile=new File();//This is for reaching the file class functions.
	Directory* itemDirectory=new Directory();//This is for reaching the directory class functions.
	//The value of head and current can be different.In these cases,we have to use current directory address.
	if(headData==currDirectory){
		tempDirectory=headData;
	}
	else {
		tempDirectory=currDirectory;
	}

		string delimiter = "/";//Here I used slash sign as a delimeter.
		size_t pos = 0;
		string token;
		int counter=0;
		while ((pos = destination.find(delimiter)) != std::string::npos) {
			token = destination.substr(0, pos);
			tempDirectory=search(currDirectory,token,*curr,"d");//Here the program calls the search function to find the address of destination url.
			if(tempDirectory==NULL){//If one of directory can't be found in the directory,the program will give an error!
				if(outputFile!=""){
					cout<<"Error : The destination url didn't find!"<<endl;
					outObj<<"Error : The destination url didn't find!"<<endl;
				}
				else{
					cout<<"Error : The destination url didn't find!"<<endl;
				}
				break;
			}
			else{
				currDirectory=tempDirectory;
			}
			destination.erase(0, pos + delimiter.length());
			counter++;
		}
		if(tempDirectory!=NULL){
			itemFile->crtfl(tempDirectory,destination,outputFile);//we called the create file command!
		}
		if(outputFile!=""){
			cout<<endl<<"--------------------"<<endl<<endl;
			outObj<<endl<<"--------------------"<<endl<<endl;
		}
		else{
			cout<<endl<<"--------------------"<<endl<<endl;
		}
}


void Commands::makeDirectoryImplement(string destination,char* outputFile,Document* headData,Document* currDirectory,Document** curr){//This is for make directory implementation.
	ofstream outObj(outputFile,ios::app);
	if(split(destination,currDirectory)==1){
		if(outputFile!=""){
			cout<<"Make directory "<<destination<<endl;
			outObj<<"Make directory "<<destination<<endl;
		}
		else{
			cout<<"Make directory "<<currDirectory->getName()<<"/"<<destination<<endl;
		}

	}
	else{
		if(outputFile!=""){
			cout<<"Make directory "<<currDirectory->getName()<<"/"<<destination<<endl;
			outObj<<"Make directory "<<currDirectory->getName()<<"/"<<destination<<endl;
		}
		else{
			cout<<"Make directory "<<currDirectory->getName()<<"/"<<destination<<endl;
		}
	}
	currDirectory=*curr;
	Document* tempDirectory;//This is for keeping the temporary directory address.
	File* itemFile=new File();//This is for reaching the file class functions.
	Directory* itemDirectory=new Directory();//This is for reaching the directory class functions.
	//The value of head and current can be different.In these cases,we have to use current directory address.
	if(headData==currDirectory){
		tempDirectory=headData;
	}
	else {
		tempDirectory=currDirectory;
	}

		string delimiter = "/";
		size_t pos = 0;
		string token;
		int counter=0;
		while ((pos = destination.find(delimiter)) != std::string::npos) {
			token = destination.substr(0, pos);
			tempDirectory=search(currDirectory,token,*curr,"d");
			if(tempDirectory==NULL){//If the directory didn'T find in the system,the program will call the createLostDirectory function to create this lost directory.
				currDirectory=itemDirectory->createLostDirectory(currDirectory,token);
			}
			else{
				currDirectory=tempDirectory;
			}
			destination.erase(0, pos + delimiter.length());
			counter++;
		}

		//Then the program will call mkdir function by using directory object.
		itemDirectory->mkdir(currDirectory,destination,outputFile);
		if(outputFile!=""){
			cout<<endl<<"--------------------"<<endl<<endl;
			outObj<<endl<<"--------------------"<<endl<<endl;
		}
		else{
			cout<<endl<<"--------------------"<<endl<<endl;
		}


}


void Commands::removeImplement(string fileOrDirectory,string destination,char* outputFile,Document* headData,Document* currDirectory,Document** curr){//This is for remove command implementation.
	ofstream outObj(outputFile,ios::app);
	if(fileOrDirectory=="-f"){
		if(split(destination,currDirectory)==1){
			if(outputFile!=""){
				cout<<"Remove file "<<destination<<endl;
				outObj<<"Remove file "<<destination<<endl;
			}
			else{
				cout<<"Remove file "<<destination<<endl;
			}

		}
		else{
			if(outputFile!=""){
				cout<<"Remove file "<<currDirectory->getName()<<"/"<<destination<<endl;
				outObj<<"Remove file "<<currDirectory->getName()<<"/"<<destination<<endl;
			}
			else{
				cout<<"Remove file "<<currDirectory->getName()<<"/"<<destination<<endl;
			}

		}
	}
	else if(fileOrDirectory=="-d"){
		if(split(destination,currDirectory)==1){
			if(outputFile!=""){
				cout<<"Remove directory "<<destination<<endl;
				outObj<<"Remove directory "<<destination<<endl;
			}
			else{
				cout<<"Remove directory "<<destination<<endl;
			}

		}
		else{
			if(outputFile!=""){
				cout<<"Remove directory "<<currDirectory->getName()<<"/"<<destination<<endl;
				outObj<<"Remove directory "<<currDirectory->getName()<<"/"<<destination<<endl;
			}
			else{
				cout<<"Remove directory "<<currDirectory->getName()<<"/"<<destination<<endl;
			}

		}
	}
	currDirectory=*curr;
	Document * currData;
	currData=*curr;
	Document* tempDirectory;//This is for keeping the temporary directory address.
	File* itemFile=new File();//This is for reaching the file class functions.
	Directory* itemDirectory=new Directory();//This is for reaching the directory class functions.
	//The value of head and current can be different.In these cases,we have to use current directory address.
	if(headData==currDirectory){
		tempDirectory=headData;
	}
	else {
		tempDirectory=currDirectory;
	}



		string delimiter = "/";
		size_t pos = 0;
		string token;
		int counter=0;
		while ((pos = destination.find(delimiter)) != std::string::npos) {
			token = destination.substr(0, pos);
			tempDirectory=search(currDirectory,token,*curr,"d");
			if(tempDirectory==NULL){
				if(outputFile!=""){
					cout<<"Error : The destination url didn't find!"<<endl;
					outObj<<"Error : The destination url didn't find!"<<endl;
				}
				else{
					cout<<"Error : The destination url didn't find!"<<endl;
				}
				break;
			}
			else{
				currDirectory=tempDirectory;
			}
			destination.erase(0, pos + delimiter.length());
			counter++;
		}
		if(counter==0 && currDirectory!=NULL){
			if(fileOrDirectory=="-f"){
				tempDirectory=currDirectory;
			}
			else if(fileOrDirectory=="-d"){
				tempDirectory=currDirectory;
			}
			if(tempDirectory==NULL){
				if(outputFile!=""){
					cout<<"Error : The destination url didn't find!"<<endl;
					outObj<<"Error : The destination url didn't find!"<<endl;
				}
				else{
					cout<<"Error : The destination url didn't find!"<<endl;
				}
			}
			else{
				currDirectory=tempDirectory;
			}
		}
		if(tempDirectory!=NULL){//If the url was found!
			if(fileOrDirectory=="-f"){//remove file 
				
				itemFile->rmf(tempDirectory,destination,outputFile);
	
			}
			else if(fileOrDirectory=="-d"){//remove directory
				if(tempDirectory->getType()=="d"){
					itemDirectory->rmd(tempDirectory,destination,currData,outputFile);	
				}
				else{
					if(outputFile!=""){
						cout<<"Error : The destination url is a file not a directory!"<<endl;
						outObj<<"Error : The destination url is a file not a directory!"<<endl;
					}
					else{
						cout<<"Error : The destination url is a file not a directory!"<<endl;
					}
				}
			}
			
		}


		if(outputFile!=""){
			cout<<endl<<"--------------------"<<endl<<endl;
			outObj<<endl<<"--------------------"<<endl<<endl;
		}
		else{
			cout<<endl<<"--------------------"<<endl<<endl;
		}



}


void Commands::moveImplement(string fileOrDirectory,string source,string destination,char* outputFile,Document* headData,Document* currDirectory,Document** curr){//This is for move command implementation.
		ofstream outObj(outputFile,ios::app);
		int result1=split(source,currDirectory);
		int result2=split(destination,currDirectory);
		if(fileOrDirectory=="-f"){
			if(result1==1 && result2==1){
				if(outputFile!=""){
					cout<<"Move file "<<source<<" "<<destination<<endl;
					outObj<<"Move file "<<source<<" "<<destination<<endl;
				}
				else{
					cout<<"Move file "<<source<<" "<<destination<<endl;
				}

			}
			else if(result1==1 && result2==0){
				if(outputFile!=""){
					cout<<"Move file "<<source<<" "<<currDirectory->getName()<<"/"<<destination<<endl;
					outObj<<"Move file "<<source<<" "<<currDirectory->getName()<<"/"<<destination<<endl;
				}
				else{
					cout<<"Move file "<<source<<" "<<currDirectory->getName()<<"/"<<destination<<endl;
				}

			}
			else if(result1==0 && result2==1){
				if(outputFile!=""){
					cout<<"Move file "<<currDirectory->getName()<<"/"<<source<<" "<<destination<<endl;
					outObj<<"Move file "<<currDirectory->getName()<<"/"<<source<<" "<<destination<<endl;
				}
				else{
					cout<<"Move file "<<currDirectory->getName()<<"/"<<source<<" "<<destination<<endl;
				}

			}
			else if(result1==0 && result2==0){
				if(outputFile!=""){
					cout<<"Move file "<<currDirectory->getName()<<"/"<<source<<" "<<currDirectory->getName()<<"/"<<destination<<endl;
					outObj<<"Move file "<<currDirectory->getName()<<"/"<<source<<" "<<currDirectory->getName()<<"/"<<destination<<endl;
				}
				else{
					cout<<"Move file "<<currDirectory->getName()<<"/"<<source<<" "<<currDirectory->getName()<<"/"<<destination<<endl;
				}

			}
		}
		else if(fileOrDirectory=="-d"){
			if(result1==1 && result2==1){
				if(outputFile!=""){
					cout<<"Move directory "<<source<<" "<<destination<<endl;
					outObj<<"Move directory "<<source<<" "<<destination<<endl;
				}
				else{
					cout<<"Move directory "<<source<<" "<<destination<<endl;
				}

			}
			else if(result1==1 && result2==0){
				if(outputFile!=""){
					cout<<"Move directory "<<source<<" "<<currDirectory->getName()<<"/"<<destination<<endl;
					outObj<<"Move directory "<<source<<" "<<currDirectory->getName()<<"/"<<destination<<endl;
				}
				else{
					cout<<"Move directory "<<source<<" "<<currDirectory->getName()<<"/"<<destination<<endl;
				}

			}
			else if(result1==0 && result2==1){
				if(outputFile!=""){
					cout<<"Move directory "<<currDirectory->getName()<<"/"<<source<<" "<<destination<<endl;
					outObj<<"Move directory "<<currDirectory->getName()<<"/"<<source<<" "<<destination<<endl;
				}
				else{
					cout<<"Move directory "<<currDirectory->getName()<<"/"<<source<<" "<<destination<<endl;
				}

			}
			else if(result1==0 && result2==0){
				if(outputFile!=""){
					cout<<"Move directory "<<currDirectory->getName()<<"/"<<source<<" "<<currDirectory->getName()<<"/"<<destination<<endl;
					outObj<<"Move directory "<<currDirectory->getName()<<"/"<<source<<" "<<currDirectory->getName()<<"/"<<destination<<endl;
				}
				else{
					cout<<"Move directory "<<currDirectory->getName()<<"/"<<source<<" "<<currDirectory->getName()<<"/"<<destination<<endl;
				}

			}
		}
		currDirectory=*curr;
		Document* currData;
		currData=*curr;
		Document* tempDirectory;//This is for keeping the temporary directory address.
		File* itemFile=new File();//This is for reaching the file class functions.
		Directory* itemDirectory=new Directory();//This is for reaching the directory class functions.
		//The value of head and current can be different.In these cases,we have to use current directory address.
		if(headData==currDirectory){
			tempDirectory=headData;
		}
		else {
			tempDirectory=currDirectory;
		}
		Document* movingsDirectoryAddress=NULL;
		string movingName;
		string delimiter = "/";
		size_t pos = 0;
		string token;
		int counter=0;
		while ((pos = source.find(delimiter)) != std::string::npos) {
			token = source.substr(0, pos);
			tempDirectory=search(currDirectory,token,*curr,"d");
			if(tempDirectory==NULL){
				if(outputFile!=""){
					cout<<"Error : The source url didn't find!"<<endl;
					outObj<<"Error : The source url didn't find!"<<endl;
				}
				else{
					cout<<"Error : The source url didn't find!"<<endl;	
				}
				break;
			}
			else{
				currDirectory=tempDirectory;
			}
			source.erase(0, pos + delimiter.length());
			counter++;
		}
		//If the url is contain one word ord letter!
		Document* control=search(currDirectory,source,*curr,"d");//This will control the existance of source url.
		if(counter==0){
			if(fileOrDirectory=="-f"){
				tempDirectory=currDirectory;
			}
			else if(fileOrDirectory=="-d"){
				if(source==currData->getName()){//If the source url and currdata url are equal the program will give an error.Because you cannot moved the current directory.
					if(outputFile!=""){
						cout<<"Error : You cannot moved root directory!"<<endl;
						outObj<<"Error : You cannot moved root directory!"<<endl;
					}
					else{
						cout<<"Error : You cannot moved root directory!"<<endl;
					}
					tempDirectory=NULL;
				}
				else {
					tempDirectory=currDirectory;
				}
			}
		}
		else{
			if(fileOrDirectory=="-f"){
				tempDirectory=currDirectory;
			}
			else {
				tempDirectory=currDirectory;
			}
		}

		if(tempDirectory!=NULL){
			//The directory was found!
			movingsDirectoryAddress=tempDirectory;
			movingName=source;
		}
		else {
			movingName=source;
			movingsDirectoryAddress=NULL;
			if(currData->getName()!=movingName){
				if(outputFile!=""){
					cout<<"Error : Source url didn't find!"<<endl;
					outObj<<"Error : Source url didn't find!"<<endl;
				}
				else{
					cout<<"Error : Source url didn't find!"<<endl;
				}
			}
		}

		currDirectory=*curr;
		string delimiter1 = "/";
		size_t pos1 = 0;
		string token1;
		int counter1=0;
		while ((pos1 = destination.find(delimiter1)) != std::string::npos) {
			token1 = destination.substr(0, pos1);
			tempDirectory=search(currDirectory,token1,*curr,"d");
			if(tempDirectory==NULL){
				//we didn't find the directory,so here we called the function for creating this directory.
				//currdirectory is equalized this new created directory s address.
				if(control!=NULL){//If the source url was found,the program create lost directory.
					currDirectory=itemDirectory->createLostDirectory(currDirectory,token1);
				}
			}
			else{
				currDirectory=tempDirectory;
			}
			destination.erase(0, pos1 + delimiter1.length());
			counter1++;
		}
		tempDirectory=search(currDirectory,destination,*curr,"d");
		Document* moved;
		if(tempDirectory==NULL){
			if(fileOrDirectory=="-f"){
				if(movingsDirectoryAddress!=NULL){
					itemFile->mvf(movingsDirectoryAddress,currDirectory,movingName,destination,outputFile);
				}
			}
			else if(fileOrDirectory=="-d"){
				if(movingsDirectoryAddress!=NULL){
					if(control!=NULL){
						moved=itemDirectory->createLostDirectory(currDirectory,destination);//adding url.
						itemDirectory->mvd(movingsDirectoryAddress,moved,movingName,movingName,currData,outputFile);
					}
					else{
						if(outputFile!=""){
							cout<<"Error : The directory that we wanted to move didn't find in the source directory!"<<endl;
							outObj<<"Error : The directory that we wanted to move didn't find in the source directory!"<<endl;
						}
						else{
							cout<<"Error : The directory that we wanted to move didn't find in the source directory!"<<endl;
						}

					}
				}
			}
		}
		else{
			moved=tempDirectory;
			if(fileOrDirectory=="-f"){
				if(movingsDirectoryAddress!=NULL){
					itemFile->mvf(movingsDirectoryAddress,moved,movingName,movingName,outputFile);
				}
			}
			else if(fileOrDirectory=="-d"){
				if(movingsDirectoryAddress!=NULL){
					itemDirectory->mvd(movingsDirectoryAddress,moved,movingName,movingName,currData,outputFile);
				}
			}
		}
		if(outputFile!=""){
			cout<<endl<<"--------------------"<<endl<<endl;
			outObj<<endl<<"--------------------"<<endl<<endl;
		}
		else{
			cout<<endl<<"--------------------"<<endl<<endl;
		}
}


void Commands::copyImplement(string fileOrDirectory,string source,string destination,char* outputFile,Document* headData,Document* currDirectory,Document** curr){//This is for copy command implementation.
	ofstream outObj(outputFile,ios::app);
			int result1=split(source,currDirectory);
		int result2=split(destination,currDirectory);
		if(fileOrDirectory=="-f"){
			if(result1==1 && result2==1){
				if(outputFile!=""){
					cout<<"Copy file "<<source<<" "<<destination<<endl;
					outObj<<"Copy file "<<source<<" "<<destination<<endl;
				}
				else{
					cout<<"Copy file "<<source<<" "<<destination<<endl;
				}

			}
			else if(result1==1 && result2==0){
				if(outputFile!=""){
					cout<<"Copy file "<<source<<" "<<currDirectory->getName()<<"/"<<destination<<endl;
					outObj<<"Copy file "<<source<<" "<<currDirectory->getName()<<"/"<<destination<<endl;
				}
				else{
					cout<<"Copy file "<<source<<" "<<currDirectory->getName()<<"/"<<destination<<endl;
				}

			}
			else if(result1==0 && result2==1){
				if(outputFile!=""){
					cout<<"Copy file "<<currDirectory->getName()<<"/"<<source<<" "<<destination<<endl;
					outObj<<"Copy file "<<currDirectory->getName()<<"/"<<source<<" "<<destination<<endl;
				}
				else{
					cout<<"Copy file "<<currDirectory->getName()<<"/"<<source<<" "<<destination<<endl;
				}

			}
			else if(result1==0 && result2==0){
				if(outputFile!=""){
					cout<<"Copy file "<<currDirectory->getName()<<"/"<<source<<" "<<currDirectory->getName()<<"/"<<destination<<endl;
					outObj<<"Copy file "<<currDirectory->getName()<<"/"<<source<<" "<<currDirectory->getName()<<"/"<<destination<<endl;
				}
				else{
					cout<<"Copy file "<<currDirectory->getName()<<"/"<<source<<" "<<currDirectory->getName()<<"/"<<destination<<endl;
				}

			}
		}
		else if(fileOrDirectory=="-d"){
			if(result1==1 && result2==1){
				if(outputFile!=""){
					cout<<"Copy directory "<<source<<" "<<destination<<endl;
					outObj<<"Copy directory "<<source<<" "<<destination<<endl;
				}
				else{
					cout<<"Copy directory "<<source<<" "<<destination<<endl;
				}

			}
			else if(result1==1 && result2==0){
				if(outputFile!=""){
					cout<<"Copy directory "<<source<<" "<<currDirectory->getName()<<"/"<<destination<<endl;
					outObj<<"Copy directory "<<source<<" "<<currDirectory->getName()<<"/"<<destination<<endl;
				}
				else{
					cout<<"Copy directory "<<source<<" "<<currDirectory->getName()<<"/"<<destination<<endl;
				}

			}
			else if(result1==0 && result2==1){
				if(outputFile!=""){
					cout<<"Copy directory "<<currDirectory->getName()<<"/"<<source<<" "<<destination<<endl;
					outObj<<"Copy directory "<<currDirectory->getName()<<"/"<<source<<" "<<destination<<endl;
				}
				else{
					cout<<"Copy directory "<<currDirectory->getName()<<"/"<<source<<" "<<destination<<endl;
				}

			}
			else if(result1==0 && result2==0){
				if(outputFile!=""){
					cout<<"Copy directory "<<currDirectory->getName()<<"/"<<source<<" "<<currDirectory->getName()<<"/"<<destination<<endl;
					outObj<<"Copy directory "<<currDirectory->getName()<<"/"<<source<<" "<<currDirectory->getName()<<"/"<<destination<<endl;
				}
				else{
					cout<<"Copy directory "<<currDirectory->getName()<<"/"<<source<<" "<<currDirectory->getName()<<"/"<<destination<<endl;
				}

			}
		}
	currDirectory=*curr;
	Document* tempDirectory;//This is for keeping the temporary directory address.
	File* itemFile=new File();//This is for reaching the file class functions.
	Directory* itemDirectory=new Directory();//This is for reaching the directory class functions.
	//The value of head and current can be different.In these cases,we have to use current directory address.
	if(headData==currDirectory){
		tempDirectory=headData;
	}
	else {
		tempDirectory=currDirectory;
	}



		Document* copyDirectoryAddress=NULL;
		string copyName;
		string delimiter = "/";
		size_t pos = 0;
		string token;
		int counter=0;
		while ((pos = source.find(delimiter)) != std::string::npos) {
			token = source.substr(0, pos);
			tempDirectory=search(currDirectory,token,*curr,"d");
			if(tempDirectory==NULL){
				if(outputFile!=""){
					cout<<"Error : The source url didn't find!"<<endl;
					outObj<<"Error : The source url didn't find!"<<endl;
				}
				else{
					cout<<"Error : The source url didn't find!"<<endl;
				}
				break;
			}
			else{
				currDirectory=tempDirectory;
			}
			source.erase(0, pos + delimiter.length());
			counter++;
		}
		if(counter!=0 && currDirectory!=NULL){
			if(fileOrDirectory=="-f"){
				if(search(currDirectory,source,*curr,"f")!=NULL){
					tempDirectory=currDirectory;
				}
				else {
					tempDirectory=NULL;
				}
			}
			else if(fileOrDirectory=="-d"){
				tempDirectory=search(currDirectory,source,*curr,"d");
			}

		}
		else if(counter==0 && currDirectory!=NULL){
			if(fileOrDirectory=="-f"){
				if(search(currDirectory,source,*curr,"f")!=NULL){
					tempDirectory=currDirectory;
				}
				else {
					tempDirectory=NULL;
				}
			}
			else if(fileOrDirectory=="-d"){
				tempDirectory=search(currDirectory,source,*curr,"d");
			}
		}
		if(tempDirectory!=NULL){
			//The source directory was found.
			copyDirectoryAddress=tempDirectory;
			copyName=source;
		}
		else if(tempDirectory==NULL){
			if(outputFile!=""){
				cout<<"Error : The source url didn't find!"<<endl;
				outObj<<"Error : The source url didn't find!"<<endl;
			}
			else{
				cout<<"Error : The source url didn't find!"<<endl;
			}
			copyDirectoryAddress=NULL;
			copyName=source;
		}

		currDirectory=*curr;
		string delimiter1 = "/";
		size_t pos1 = 0;
		string token1;
		int counter1=0;
		while ((pos1 = destination.find(delimiter1)) != std::string::npos) {
			token1 = destination.substr(0, pos1);
			tempDirectory=search(currDirectory,token1,*curr,"d");
			if(tempDirectory==NULL){
				//we didn't find the directory,so here we called the function for creating this directory.
				//currdirectory is equalized this new created directory s address.
				if(copyDirectoryAddress!=NULL){//If the source url was found,the program will create lost directory.
					currDirectory=itemDirectory->createLostDirectory(currDirectory,token1);
				}
			}
			else{
				currDirectory=tempDirectory;
			}
			destination.erase(0, pos1 + delimiter1.length());
			counter1++;
		}
		tempDirectory=search(currDirectory,destination,*curr,"d");
		Document* copied;
		if(fileOrDirectory=="-f"){
			if(tempDirectory==NULL){
				if(copyDirectoryAddress!=NULL){
					itemFile->copyFile(copyDirectoryAddress,currDirectory,destination,outputFile);
				}
			}
			else{
				copied=tempDirectory;
				if(copyDirectoryAddress!=NULL){
					itemFile->copyFile(copyDirectoryAddress,copied,copyName,outputFile);
				}
			}

		}

		else if(fileOrDirectory=="-d"){
			if(tempDirectory==NULL){
				if(copyDirectoryAddress!=NULL){
					tempDirectory=itemDirectory->createLostDirectory(currDirectory,destination);
					copyDirectory(copyDirectoryAddress,tempDirectory,copyName,outputFile);
				}
			}
			else{
				copied=tempDirectory;
				if(copyDirectoryAddress!=NULL){
					copyDirectory(copyDirectoryAddress,copied,copyName,outputFile);
				}
			}
		}
		if(outputFile!=""){
			cout<<endl<<"--------------------"<<endl<<endl;
			outObj<<endl<<"--------------------"<<endl<<endl;
		}
		else{
			cout<<endl<<"--------------------"<<endl<<endl;
		}
}


void Commands::listImplement(string destination,char* outputFile,Document* headData,Document* currDirectory,Document** curr){//This is for list command implementation.
	ofstream outObj(outputFile,ios::app);
	if(split(destination,currDirectory)==1){
		if(outputFile!=""){
			cout<<"List "<<destination<<endl;
			outObj<<"List "<<destination<<endl;
		}
		else{
			cout<<"List "<<destination<<endl;
		}

	}
	else{
		if(destination==""){
			if(currDirectory->getName()!="."){
				if(outputFile!=""){
					cout<<"List "<<"./"<<currDirectory->getName()<<endl;
					outObj<<"List "<<"./"<<currDirectory->getName()<<endl;
				}
				else{
					cout<<"List "<<"./"<<currDirectory->getName()<<endl;
				}

			}
			else{
				if(outputFile!=""){
					cout<<"List "<<currDirectory->getName()<<endl;
					outObj<<"List "<<currDirectory->getName()<<endl;
				}
				else{
					cout<<"List "<<currDirectory->getName()<<endl;
				}

			}

		}
		else{
			if(outputFile!=""){
				cout<<"List "<<currDirectory->getName()<<"/"<<destination<<endl;
				outObj<<"List "<<currDirectory->getName()<<"/"<<destination<<endl;
			}
			else{
				cout<<"List "<<currDirectory->getName()<<"/"<<destination<<endl;
			}

		}

	}
	currDirectory=*curr;
	Document* tempDirectory;//This is for keeping the temporary directory address.
	File* itemFile=new File();//This is for reaching the file class functions.
	Directory* itemDirectory=new Directory();//This is for reaching the directory class functions.
	//The value of head and current can be different.In these cases,we have to use current directory address.
	if(destination==""){
		tempDirectory=currDirectory;
		printDirectory(tempDirectory,0,outputFile);
	}
	else {//If there is a given url.

		if(headData==currDirectory){
		tempDirectory=headData;
		}
		else {
			tempDirectory=currDirectory;
		}

			string delimiter = "/";//Here I used slash sign as a delimeter.
			size_t pos = 0;
			string token;
			int counter=0;
			while ((pos = destination.find(delimiter)) != std::string::npos) {
				token = destination.substr(0, pos);
				tempDirectory=search(currDirectory,token,*curr,"d");//Here the program calls the search function to find the address of destination url.
				if(tempDirectory==NULL){//If one of directory can't be found in the directory,the program will give an error!
					if(outputFile!=""){
						cout<<"Error : The destination url didn't find!"<<endl;
						outObj<<"Error : The destination url didn't find!"<<endl;
					}
					else{
						cout<<"Error : The destination url didn't find!"<<endl;
					}
					break;
				}
				else{
					currDirectory=tempDirectory;
				}
				destination.erase(0, pos + delimiter.length());
				counter++;
			}
			tempDirectory=search(currDirectory,destination,*curr,"d");

			if(tempDirectory!=NULL){
				printDirectory(tempDirectory,0,outputFile);
			}
			else{
				if(outputFile!=""){
					cout<<"Error : The destination url didn't find!"<<endl;
					outObj<<"Error : The destination url didn't find!"<<endl;
				}
				else{
					cout<<"Error : The destination url didn't find!"<<endl;
				}
			}

	}
	if(outputFile!=""){
			cout<<endl<<"--------------------"<<endl<<endl;
			outObj<<endl<<"--------------------"<<endl<<endl;
		}
		else{
			cout<<endl<<"--------------------"<<endl<<endl;
	}


}


Document* Commands::search(Document* headData,string word,Document* curr,string fileOrDirectory){
	Document* result;
	Document* result1;
	//head data is current directory
	if(headData==curr && headData->getName()==word){//This means we try to find the current directory.
		return headData;
	}
	result=nextSearch(headData->getLink(),word,curr,fileOrDirectory);//Here we will look for siblings under the current directory function.
	if(result!=NULL){
		return result;
	}
	if(result==NULL){//If the result equal to null,the function returns zero.
		return 0;
	}

}
Document* Commands::nextSearch(Document* headData,string word,Document* curr,string fileOrDirectory){//Here the program will look to the sub list of any directory.
	if(headData==NULL){
		return 0;
	}
	else {
		while(headData!=NULL){
			if(headData->getName()==word){
				if(headData->getType()==fileOrDirectory){
					return headData;
				}
			}
			headData=headData->getNext();
		}
		return 0;

	}
}


void Commands::printDirectory(Document* headData,int value,char* outputFile){//This is for print the lists.
	ofstream outObj(outputFile,ios::app);
	int counter=value;
	if(outputFile!=""){
		cout<<"<"<<headData->getName()<<">"<<endl;
		if(value==0){
			outObj<<"<"<<headData->getName()<<">"<<endl;
		}
	}
	else{
		cout<<"<"<<headData->getName()<<">"<<endl;
	}
	counter++;
	headData=headData->getLink();
	printInside(headData,counter,outputFile);

}
void Commands::printInside(Document* headData,int value,char* outputFile){//This is for print the lists.
	ofstream outObj(outputFile,ios::app);
	if(headData==NULL){
		return;
	}
	else {
		while(headData!=NULL){
			if(outputFile!=""){
				cout<<" ";
				outObj<<" ";
			}
			else{
				cout<<" ";
			}
			for(int i=0;i<value;i++){
				if(i==value-1){
					if(outputFile!=""){
						cout<<"|";
						outObj<<"|";
					}
					else{
						cout<<"|";
					}
				}
				else{
					if(outputFile!=""){
						cout<<"|    ";
						outObj<<"|    ";
					}
					else{
						cout<<"|    ";
					}
				}
			}
			if(headData->getType()=="d"){
				if(outputFile!=""){
					cout<<"---";
					outObj<<"---"<<"<"<<headData->getName()<<">"<<endl;
				}
				else{
					cout<<"---";
				}
				printDirectory(headData,value,outputFile);
			}
			else {
				if(outputFile!=""){
					cout<<"--- "<<headData->getName()<<endl;
					outObj<<"--- "<<headData->getName()<<endl;
				}
				else{
					cout<<"--- "<<headData->getName()<<endl;
				}
			}

			headData=headData->getNext();
		}

	}

}

void Commands::createCopyDirectory(Document* sourceUrl,Document* destinationUrl,char* outputFile){//This is for copy directory command.
	ofstream outObj(outputFile,ios::app);
	if(sourceUrl->getLink()!=NULL){
		sourceUrl=sourceUrl->getLink();
		while(sourceUrl!=NULL){
			Document * temp=destinationUrl;
			if(sourceUrl->getType()=="f"){
				Document* newFile=new File();
				newFile->setName(sourceUrl->getName());
				newFile->setLink(NULL);
				newFile->setNext(NULL);
				if(temp->getLink()==NULL){
					temp->setLink(newFile);
				}
				else if(temp->getLink()!=NULL){
					temp=temp->getLink();
					while(temp->getNext()!=NULL){
						temp=temp->getNext();
					}
					temp->setNext(newFile);
				}
			}
			else if(sourceUrl->getType()=="d"){
				Document* tempUrl=destinationUrl;
				Document* newDirectory=new Directory();
				newDirectory->setName(sourceUrl->getName());
				newDirectory->setLink(NULL);
				newDirectory->setNext(NULL);
				if(tempUrl->getLink()==NULL){
					tempUrl->setLink(newDirectory); 
					createCopyDirectory(sourceUrl,tempUrl->getLink(),outputFile);
				}
				else if(tempUrl->getLink()!=NULL){
					tempUrl=tempUrl->getLink();
					while(tempUrl->getNext()!=NULL){
						tempUrl=tempUrl->getNext();
					}
					tempUrl->setNext(newDirectory);
					createCopyDirectory(sourceUrl,tempUrl->getNext(),outputFile);
				}

			}
			sourceUrl=sourceUrl->getNext();
		}
		if(outputFile!=""){
			cout<<"Copy directory executed succesfully."<<endl;
			outObj<<"Copy directory executed succesfully."<<endl;
		}
		else{
			cout<<"Copy directory executed succesfully."<<endl;
		}
	}

}


void Commands::copyDirectory(Document* sourceUrl,Document* destinationUrl,string copiedDirectory,char* outputFile){//This is for copy directory command.
	ofstream outObj(outputFile,ios::app);
	int counter=0;
	if(sourceUrl!=NULL){
			Document* newDirectory=new Directory();
			newDirectory->setName(copiedDirectory);
			newDirectory->setLink(NULL);
			newDirectory->setNext(NULL);
			if(destinationUrl->getLink()==NULL){
				destinationUrl->setLink(newDirectory);
				//adding will be done here.
				createCopyDirectory(sourceUrl,destinationUrl->getLink(),outputFile);
			}
			else {
				destinationUrl=destinationUrl->getLink();
				Document* temp=destinationUrl;
				while(temp!=NULL){
					if(temp->getName()==copiedDirectory){
						if(temp->getType()=="d"){
							counter++;
						}
					}
					temp=temp->getNext();
				}
				if(counter!=0){
					if(outputFile!=""){
						cout<<"Error : There is already a directory that has the same name with the copied directory!"<<endl;
						outObj<<"Error : There is already a directory that has the same name with the copied directory!"<<endl;
					}
					else{
						cout<<"Error : There is already a directory that has the same name with the copied directory!"<<endl;
					}
				}
				else{
					while(destinationUrl->getNext()!=NULL){
						destinationUrl=destinationUrl->getNext();
					}
					destinationUrl->setNext(newDirectory);
					createCopyDirectory(sourceUrl,destinationUrl->getNext(),outputFile);
					//adding will be done here.


				}

			}

	}
}