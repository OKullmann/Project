#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>

//TODO
//1.Tweak remove_if to ensure working all the time
//2.Implement printing vector to output file

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
    std::string propagator;
    for (int i = 0; i < clauses.size(); ++i){
      int clauseCount = ((clauses[i].length() +1) / 2);
      if (clauseCount == 2){
        size_t pos1 = 0;
        size_t pos2;
        pos2 = clauses[i].find(" ", pos1);
        propagator = clauses[i].substr(pos1, (pos2 -pos1)); 
        clauses.erase(
        std::remove_if(clauses.begin(), clauses.end(),[&](const std::string &s) {return s.find(propagator) != std::string::npos;}),clauses.end());
      }
    }
  }
}