#ifndef RECEIVER_HPP
#define RECEIVER_HPP
#include <vector>

#define REAL_TIME_STATISTICS False

struct Statistics{
  float maximum;
  float minimum;
  float average;
};

class CSV_data{
private:
  std::vector<std::vector<float>> all_data;
  bool is_number(std::string element);
public:
  void new_data(std::string line_of_data);
  std::vector<Statistics> processs(size_t last_N_floats);
};

class Receiver{
private:
  CSV_data data_received;
  std::vector<Statistics> _stats;
public:
  void receive(void);
  void process(void);
  void print_stats(void);

};


#endif
