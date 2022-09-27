#ifndef _SHA512_H_
#define _SHA512_H_

#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <bitset>


typedef unsigned long long int int64;

namespace abj{
  class SHA{
  private:
    static const int64 Constants[80];
    int64 Message[80]; // The schedeuled message . 80 <- 16
    
    // For printing I guess
    std::string getHexFrom4bit(std::string bin);
    std::string getHexFromDecimal(int64 deci);
    int64  getDecFromBin(std::string bin);
    
    // SHA512 Logic Functions
    int64 rotate_right(int64 x, int n);
    int64 shift_right(int64 x, int n);
    
    int64 maj(int64 a, int64 b, int64 c);
    int64 Ch(int64 e, int64 f, int64 g);
    
    int64 sum_1(int64 e);
    int64 sum_0(int64 a);
    
    void round(int64 a, int64 b, int64 c, int64& d, int64 e, int64 f, int64 g, int64& h, int K);
    void message_schedeuler(std::string getBlock);
  public:
    std::string hash(std::string myString);
  };
}


#endif
