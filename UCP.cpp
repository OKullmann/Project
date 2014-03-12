#include <fstream>
#include <iostream>
#include <vector>

int main(const int argc, const char* const argv[]) {
  std::string line;
  std::string c("c");
  std::vector<std::string> comments;
  std::vector<std::string> clauses;	
  if (argc !=2)
    std::cout << "Usage: " << "./UCP <Input filename>\n";
  std::ifstream inFile(argv[1]);
  std::cout << "Cool \n";
  while (std::getline(inFile, line)) {
    if(line.compare(0, c.length(), c)==0)
      comments.push_back(line);
    else(clauses.push_back(line));
  }
}