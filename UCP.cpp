#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

int main(const int argc, const char* const argv[]) {
  std::string line;
  std::string watched;
  const int clauseCount = 3;

  if (argc !=2) //If no file is entered for input
    std::cout << "Usage: " << "./UCP <Input filename>" << std::endl;
  else {
    const std::ifstream inFile(argv[1]);
    std::ofstream outFile;
    std::stringstream buffer;

    if(inFile.is_open()) {
      buffer << inFile.rdbuf();
      line = buffer.str();
      //Cursors for array
      size_t pos0 = 0;
      size_t pos1;

      outFile.open("output.txt");
      //outFile << "c This file has had the Unit Clause Propagation applied to it" << std::endl;
      std::cout << " ** FILE ** " << std::endl;
      std::string clause[255]; //Array to store clauses
      for (int i = 0; i <= clauseCount; i++) {
	pos1 = line.find("0", pos0); //Searches for the 0 at the end of the line
	clause[i] = line.substr(pos0, pos1 -pos0 -1); //Substring each clause minus 0
	std::cout << clause[i];//.length() <<std::endl;
	pos0 = pos1+1;
      }
      std::cout << std::endl << std::endl << "Solution" << std::endl;

      for (int j = 0; j <= clauseCount; j++) {
	if(clause[j].length() == 1) {
	  watched = clause[j];
	  std::cout << watched;
	  clause[j] = "Currently being watched";
	  for (int k = j; k <= 3; k++) {
	    if(clause[k].find(watched)){
	      clause[k] = "n";
	    }
	  }
	  std::cout << clause[j];
	}
      }
      outFile.close();
    }
    else {
      std::cout << "No good" << std::endl;
    }
  }
}
