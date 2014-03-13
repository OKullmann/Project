#include <fstream>
#include <iostream>
#include <vector>

int main(const int argc, const char* const argv[]) {
  std::vector<std::string> clauses;	
  std::ofstream outFile("output.txt");
  if (argc !=2)
    std::cout << "Usage: " << "./UCP <Input filename>\n";
  else{
    std::ifstream inFile(argv[1]);
    std::cout << "Cool \n";
    std::string line;
    while (std::getline(inFile, line)) {
      std::string c("c");
      if(line.compare(0, c.length(), c)==0)
        outFile << line << "\n";
      else(clauses.push_back(line));
    } 
    outFile << "c This file has been propagated";
  }
  for (int i = 0; i < 6; ++i){
    int clauseCount = ((clauses[i].length() +1) / 2);
    if (clauseCount == 2)
      std::cout << clauses[i] << "\n";
  }
}
