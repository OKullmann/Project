#include <fstream>
#include <iostream>
#include <vector>

int main(const int argc, const char* const argv[]) {
  std::vector<std::string> comments;
  std::vector<std::string> clauses;	
  if (argc !=2)
    std::cout << "Usage: " << "./UCP <Input filename>\n";
  std::ifstream inFile(argv[1]);
  std::cout << "Cool \n";
  std::string line;
  while (std::getline(inFile, line)) {
	std::string c("c");
    if(line.compare(0, c.length(), c)==0)
      comments.push_back(line);
    else(clauses.push_back(line));
  }
}