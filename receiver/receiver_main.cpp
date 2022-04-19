#include <iostream>
#include <string>
#include "receiver.hpp"
int main(){
  Receiver CSV_reader;
  CSV_reader.receive();
  CSV_reader.process();
  CSV_reader.print_stats();
  return false;
}
