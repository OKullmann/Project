#include <fstream>
#include <iostream>
#include <vector>

int main(const int argc, const char* const argv[]) {
  std::string line;
  std::vector<std::string> file;	
  if (argc !=2)
    std::cout << "Usage: " << "./UCP <Input filename>\n";
  std::ifstream inFile(argv[1]);
  while (std::getline(inFile, line)) {
    file.push_back(line);
  }
}