#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file

#include <iostream>
#include "../test/catch.hpp"
#include "receiver.hpp"


Receiver CSV_reader;
Test_receiver tester(CSV_reader);

TEST_CASE("Check Data is filled correctly before processing"){
  CSV_reader.receive();
  REQUIRE(tester.GetAllData()->size() == 2);
  REQUIRE(tester.GetAllData()->at(0).size() == 50);
  REQUIRE(tester.GetAllData()->at(1).size() == 50);
}
TEST_CASE("Check Data is processed correctly before processing"){
  CSV_reader.process();
  REQUIRE(tester.GetStatistics()->size() == 2);
  REQUIRE(tester.GetStatistics()->at(0).minimum == (float)0.3346);
  REQUIRE(tester.GetStatistics()->at(0).maximum == (float)9.9414);
  REQUIRE(tester.GetStatistics()->at(0).average == (float)3.35076);
  REQUIRE(tester.GetStatistics()->at(1).minimum == (float)33);
  REQUIRE(tester.GetStatistics()->at(1).maximum == (float)110);
  REQUIRE(tester.GetStatistics()->at(1).average == (float)58.4);
}

TEST_CASE("Check that the function to identify a number in a string is working"){
  std::string test_word = "NOT a number";
  std::string test_number = "0.15235";
  //weird looking syntax is used to call the member function on an object using a pointer-to-member-function
  REQUIRE((tester.data2Btested->*tester.GetFunction2Test())(test_word) == false);
  REQUIRE((tester.data2Btested->*tester.GetFunction2Test())(test_number) == true);
}

std::string GetFormatting(std::string column, std::string min, std::string max, std::string avg, std::string unit){
  std::string ret;
  ret.append("\n\t|======================================================\n");
  ret.append("\t|Column #"+column+"\n");
  ret.append("\t|\tMin: "+min+"["+unit+"]\n");
  ret.append("\t|\tMax: "+max+"["+unit+"]\n");
  ret.append("\t|\tSimple Moving Average(last 5 samples): "+avg+"["+unit+"]\n");
  ret.append("\t|======================================================\n");
  return ret;
}

TEST_CASE("Check output if stats are not filled or filled correctly using the input example"){
  std::string printedstats =  "\n\tStatistics:";
  printedstats.append(GetFormatting("1","0.3346","9.9414","3.35076","Amps"));
  printedstats.append(GetFormatting("2","33","110","58.4","\370F"));
  std::ostringstream streambuffer_cerr, streambuffer_cout;
  std::streambuf* Original_CERR = std::cerr.rdbuf(streambuffer_cerr.rdbuf());
  std::streambuf* Original_COUT = std::cout.rdbuf(streambuffer_cout.rdbuf());
  Receiver CSV_reader2;//new reader that has not processed the data
  CSV_reader2.print_stats();
  CSV_reader.print_stats();
  std::string streamoutput = streambuffer_cerr.str();
  REQUIRE(streamoutput == std::string("No stats to be printed, sorry\n"));
  streamoutput = streambuffer_cout.str();
  REQUIRE(streamoutput == printedstats);
  std::cerr.rdbuf(Original_CERR);
  std::cout.rdbuf(Original_COUT);
}
