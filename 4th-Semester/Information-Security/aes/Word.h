#ifndef _WORD_H_
#define _WORD_H_
#include<iostream>
#include "global_constants.h"

#define WORD_SIZE 4

namespace abj{
  class Word {
  private:
  public:
    abj::byte storage[WORD_SIZE];
    
    void make_word(abj::byte a, abj::byte b, abj::byte c, abj::byte d);
    void replace(abj::byte a, abj::byte b, abj::byte c, abj::byte d);
    void rotate_word();
    void print();
    abj::Word operator ^ (const abj::Word& obj);

    static void test_function();
  };
}

#endif
