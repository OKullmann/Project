#include <iostream>
#include <fstream>
using namespace std;

int main(int argc, char *argv[]) {
	string line;
	
	if (argc !=2)
		cout << "Usage: " << argv[0] << " <Input filename>" << endl; //Error for wrong input
	else {
		ifstream inFile (argv[1]);
	
		if(inFile.is_open())
			cout << "file accepted" << endl;
			line = inFile.getline(1);
		else {
			cout << "No good" << endl;
		}
	}
}
