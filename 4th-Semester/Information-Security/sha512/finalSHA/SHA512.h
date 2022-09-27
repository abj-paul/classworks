#ifndef _SHA512_H_
#define _SHA512_H_

#include <bits/stdc++.h>
using namespace std;


typedef unsigned long long int int64;

class SHA512{
 private:
  static const int64 Constants[80];
  int64 Message[80]; // The schedeuled message . 80 <- 16

  // For printing I guess
  string getHexFrom4bit(string bin);
  string getHexFromDecimal(int64 deci);
  int64  getDecFromBin(string bin);

  // SHA512 Logic Functions
  int64 rotate_right(int64 x, int n);
  int64 shift_right(int64 x, int n);

  int64 maj(int64 a, int64 b, int64 c);
  int64 Ch(int64 e, int64 f, int64 g);

  int64 sum_1(int64 e);
  int64 sum_0(int64 a);

  void round(int64 a, int64 b, int64 c, int64& d, int64 e, int64 f, int64 g, int64& h, int K);
  void message_schedeuler(string getBlock);
 public:
  string hash(string myString);

};


#endif
