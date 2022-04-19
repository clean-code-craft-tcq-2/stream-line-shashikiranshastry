#include <iostream>
#include <string>
int main(){
  std::string line;
  while(std::getline(std::cin, line).good()){
    std::cout << "Element: " << line << '\n';
  }
  return false;
}
