#include <iostream>
#include "receiver.hpp"
int main(){
  Receiver CSV_reader;
  CSV_reader.receive();
  CSV_reader.process();
  CSV_reader.print_stats();
  std::cout << CSV_reader;
  return false;
}
