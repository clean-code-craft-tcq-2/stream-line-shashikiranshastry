#ifndef RECEIVER_HPP
#define RECEIVER_HPP
#include <vector>

#define REAL_TIME_STATISTICS False

struct Statistics{
  float maximum;
  float minimum;
  float average;
  std::string units;
};

class CSV_data{
private:
  std::vector<std::vector<float>> all_data;
  bool is_number(std::string element);
public:
  void new_data(std::string line_of_data);
  std::vector<Statistics> processs(size_t last_N_floats);
  
  //Be able to output the complete object with my own format
  friend auto operator<<(std::ostream& os, CSV_data const& m) -> std::ostream& {
    for(size_t i = 0; i < m.all_data.at(0).size(); i++){
      os << '\t';
      for(size_t j = 0; j < m.all_data.size(); j++){
        std::string number = std::to_string(m.all_data.at(j).at(i));
        number.resize(7,' ');//Only 7 characters allowed
        os << "| " << number << " \t\t|";
      }
      os << '\n';
    }
    return os;
  }
};

class Receiver{
private:
  CSV_data data_received;
  std::vector<Statistics> _stats;
public:
  void receive(void);
  void process(void);
  void print_stats(void);

  //Be able to output the complete object with my own format
  friend auto operator<<(std::ostream& os, Receiver const& m) -> std::ostream& {
    os << "\n\tALL RECEIVED DATA:\n\t";
    for(size_t i = 0; i < m._stats.size(); i++){
      std::string Units = '[' + m._stats.at(i).units + ']';
      Units.resize(10,' ');//only 10 characters allowed
      os << "| Column " << Units << " \t|";
    }
    os << "\n";
    os << m.data_received;
    return os;
  }

};


#endif
