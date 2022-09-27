
#ifndef _WORD_H_
#define _WORD_H_
#include "global.h"

#define WORD_SIZE 4

class word {
private:
public:
  byte storage[WORD_SIZE];
  
  word make_word(byte a, byte b, byte c, byte d);
  word replace(byte a, byte b, byte c, byte d);
  word rotate_word();
  void print();
  void print_hex();
  word operator ^ (const word& obj);

  static void test_function();
};

#endif
