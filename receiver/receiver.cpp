#include <iostream>
#include <string>
#include <sstream>
#include "receiver.hpp"

void Receiver::receive(void){
  std::string line;
  while(std::getline(std::cin, line).good()){
    // std::cout << "Element: " << line << '\n';
    data_received.new_data(line);
#if REAL_TIME_STATISTICS
    this->process();
#endif
  }
}

void CSV_data::new_data(std::string line_of_data){
  line_of_data.push_back(',');//to add also last row to the same process
  std::stringstream SS;
  std::string element;
  SS << line_of_data;
  size_t CSV_column = 0;
  while(std::getline(SS, element, ',').good()){
    //at some point, in a real stream, data needs to be erased to avoid stack overflow
    if(is_number(element)){
      if(all_data.size() < (CSV_column + 1)){
        all_data.push_back(std::vector<float>(1, std::stof(element)));
      }else{
        all_data.at(CSV_column).push_back(std::stof(element));
      }
    }
    CSV_column++;
  }
}

bool CSV_data::is_number(std::string element){
  std::string::const_iterator it = element.begin();
  while (it != element.end() && (std::isdigit(*it) || *it == '.')) ++it;
  return !element.empty() && it == element.end();
}

std::vector<Statistics> CSV_data::processs(size_t last_N_floats){
  std::vector<Statistics> data_stats;
  if(all_data.empty()){
    std::cerr << "There is no available data yet!\n";
  }
  //Only process data if the vector is bigger than 5
  for(auto&& Column : all_data){
    if(Column.size() > last_N_floats){

      data_stats.push_back(this->calculate(&Column, last_N_floats));
    }
  }
  return data_stats;
}

Statistics CSV_data::calculate(std::vector<float>* array, int last_floats){
  float min, max, avg;
  min=array->front();
  max=array->front();
  avg = 0.0;
  for(auto&& single_float : *array){
    if(min > single_float) min = single_float;
    if(max < single_float) max = single_float;
  }
  for(std::vector<float>::iterator ptr = array->end() - 1; ptr > array->end() - 1 - last_floats; ptr--){
    // std::cout << "*" << *ptr << '\n';
    avg += *ptr;
  }
  avg /= last_floats;
  return {max,min,avg,std::string()};
}

void Receiver::process(void){
  _stats.clear();
  //input with stored data less than 5 will not be processed
  _stats = data_received.processs(5);
  //I'm gonna hard code this here because the CSV stream does not include units
  _stats.at(0).units = "Amps";
  _stats.at(1).units = std::string("\370") + std::string("F");
}

void Receiver::print_stats(void){
  if(!_stats.empty()){
    size_t column = 1;
    std::cout << "\n\tStatistics:";
    for(auto&& STAT : _stats){
      std::cout << "\n\t|======================================================\n";
      std::cout << "\t|Column #" << column++ << '\n';
      std::cout << "\t|\tMin: " << STAT.minimum << '[' << STAT.units << ']' <<'\n';
      std::cout << "\t|\tMax: " << STAT.maximum << '[' << STAT.units << ']' <<'\n';
      std::cout << "\t|\tSimple Moving Average(last 5 samples): " << STAT.average << '[' << STAT.units << ']' <<'\n';
      std::cout << "\t|======================================================\n";
    }
  }else{
    std::cerr << "No stats to be printed, sorry\n";
  }
}
