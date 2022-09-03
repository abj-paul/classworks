#ifndef _REGISTER_H_
#define _REGISTER_H_

#include<iostream>
#include<cstdint>

#include "global.h"

#ifndef DATA_SIZE
#define DATA_SIZE 64
#endif


class Register{
 private:
  std::uint64_t storage;
 public:
  void store(std::uint64_t data);
  std::uint64_t get_data_dump() const;
  void print_hex();
  void print_bin();
  Register operator^(const Register v);

  
  static Register ROTR(int n, Register x);
  static Register SHR(int n, Register x);
  static Register sum(int upper_sum_val, int lower_sum_val, Register x);
  static Register sigma_0(Register x);
  static Register sigma_1(Register x);
  static Register ch(Register e, Register f, Register g);
  static Register maj(Register a, Register b, Register c);

  static void test_function();
};

#endif
