#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

int main(int argc, char *argv[]){
	string line;
	int clauseCount = 4;
	
	if (argc !=2) //If no file is entered for input
		cout << "Usage: " << argv[0] << " <Input filename>" << endl; 
	else {
		ifstream inFile (argv[1]);
		stringstream buffer;
		ofstream outFile;
	
		if(inFile.is_open()){
			cout << "** File accepted **" << endl;
			buffer << inFile.rdbuf();
			line = buffer.str();
			//Cursors for array
			size_t pos0 = 0;
			size_t pos1;
			
			string clause[3]; //Array to store clauses
			for (int i=0; i<=(clauseCount); i++) {
				pos1 = line.find("0", pos0); //Searches for the 0 at the end of the line
				clause[i] = line.substr(pos0, (pos1 -pos0)); //Substring each clause minus 0
				cout << clause[i];
				pos0 = pos1+1;
			}
			cout << endl;
			cout << endl <<"End of file" << endl;
			
		} else {
			cout << "No good" << endl;
		}
	}
}
