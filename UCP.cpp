#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>

int main(const int argc, const char* const argv[]) {
  std::vector<std::string> clauses;	
  std::ofstream outFile("output.txt");
  if (argc !=2)
    std::cout << "Usage: " << "./UCP <Input filename>\n";
  else{
	std::cout << "File has been read in \n";
    std::ifstream inFile(argv[1]);
    std::string line;
    while (std::getline(inFile, line)) {
      std::string c("c");
      std::string p("p");
      if(line.compare(0, c.length(), c)==0)
        outFile << line << "\n";
      else if(line.compare(0, p.length(), p)==0)
        outFile << line << "\n";
      else(clauses.push_back(line));
    } 
    std::cout << "Clauses added to vector \n";
    outFile << "c This file has been propagated \n" << "c Solution: ";
    std::string propagator;
    for (int i = 0; i < clauses.size(); ++i){
      int clauseCount = ((clauses[i].length() +1) / 2);
      if (clauseCount == 2){
        size_t pos1 = 0;
        size_t pos2;
        pos2 = clauses[i].find(" ", pos1);
        propagator = clauses[i].substr(pos1, (pos2 -pos1)); 
        outFile << propagator << " ";
        i = -1;
      }
      std::cout << "Currently propagating " << propagator << "\n";
      clauses.erase(std::remove_if(clauses.begin(), clauses.end(),[&](const std::string &s) {return s.find(propagator) != std::string::npos;}),clauses.end());
    }
    for (const auto &clause : clauses)
      outFile << clause << '\n';
  }
}