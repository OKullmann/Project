#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <cstdlib>

int main(const int argc, const char* const argv[]) {
  std::string line;
  std::string watched;
  const int clauseCount = 3;

  if (argc !=2)
    std::cout << "Usage: " << "./UCP <Input filename>\n";
  else {
    const std::ifstream inFile(argv[1]);
    std::ofstream outFile;
    std::stringstream buffer;

    if(inFile.is_open()) {
      buffer << inFile.rdbuf();
      line = buffer.str();
      std::size_t pos0 = 0;
      std::size_t pos1;

      outFile.open("output.txt");
      std::cout << " ** FILE ** \n";
      std::string clause[255];
      for (int i = 0; i <= clauseCount; ++i) {
	pos1 = line.find("0", pos0);
	clause[i] = line.substr(pos0, pos1 -pos0 -1);
	std::cout << clause[i];
	pos0 = pos1+1;
      }
      std::cout << "\n\nSolution\n";

      for (int j = 0; j <= clauseCount; ++j)
	if(clause[j].length() == 1) {
	  watched = clause[j];
	  std::cout << watched;
	  clause[j] = "Currently being watched";
	  for (int k = j; k <= 3; ++k)
	    if(clause[k].find(watched)) clause[k] = "n";
	  std::cout << clause[j];
	}
      outFile.close();
    }
    else std::cout << "No good\n";
  }
}
