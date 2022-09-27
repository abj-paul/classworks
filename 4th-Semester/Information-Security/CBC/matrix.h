
#ifndef _MATRIX_H_
#define _MATRIX_H_

#include "global.h"
#include "substitution.h"
#include "galois_field.h"

class matrix {
private:
  void single_shift(int row);
  void single_inverse_shift(int row);
 public:
  byte storage[4][4];
  void make_matrix(byte byteInput[16]); // Column major matrix
  void print();

  matrix multiply_with_mix_column_matrix();
  matrix multiply_with_inverse_mix_column_matrix(); 

  matrix shift_rows();
  matrix inverse_shift_rows();

  matrix add_round_key(matrix key);

  matrix substitute();
  matrix inverse_substitute();

  matrix operator ^ (const matrix& obj);
  matrix operator = (const matrix& obj);
  void transpose();
  std::string getString();
  std::string getHexString();


  static void test_function();
};

#endif
