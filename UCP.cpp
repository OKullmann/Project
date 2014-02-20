#include <iostream>
#include <fstream>
using namespace std;

int main(int argc, char *argv[]){
	string line;
	
	if (argc !=2) //If no file is entered for input
		cout << "Usage: " << argv[0] << " <Input filename>" << endl; 
	else {
		ifstream inFile (argv[1]);
	
		if(inFile.is_open()){
			cout << "** File accepted **" << endl;
			cout << inFile.rdbuf() << endl; //Prints file contents to terminal
		} else {
			cout << "No good" << endl;
		}
	}
}
