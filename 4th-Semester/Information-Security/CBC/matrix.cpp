#include "matrix.h"
#include <sstream>

void matrix::make_matrix(byte byteInput[16]){ // Column major matrix
  int input_index=0;

  for(int col=0; col<4; col++){
    for(int row=0; row<4; row++){
      this->storage[row][col] = byteInput[input_index];
      input_index++;
    }
  }
}
matrix matrix::operator ^ (const matrix& obj){
  //matrix ans;
  for(int i=0; i<4; i++){
    for(int j=0; j<4; j++) this->storage[i][j]  = this->storage[i][j] ^ obj.storage[i][j];
  }

  return *this;
}


void matrix::transpose(){
  byte transpose_s[4][4];
  for (int c = 0; c < 4; c++)
    for (int d = 0; d < 4; d++)
      transpose_s[d][c] = storage[c][d];

  //copying
  for(int i=0; i<4; i++){
    for(int j=0; j<4; j++) storage[i][j] = transpose_s[i][j];
  }
}

void matrix::print(){
  for(int row=0; row<4; row++){
    for(int col=0; col<4; col++){
      printf("%x ",this->storage[row][col]);
    }
    printf("\n");
  }
}

std::string matrix::getString(){
  std::ostringstream stream;

  this->transpose();
  for(int i=0; i<4; i++){
    for(int j=0; j<4; j++) stream << this->storage[i][j];
  }
  this->transpose();
  return stream.str();
}

std::string matrix::getHexString(){
  std::ostringstream stream;

  this->transpose();
  for(int i=0; i<4; i++){
    for(int j=0; j<4; j++) stream <<std::hex<< (int)this->storage[i][j];
  }
  this->transpose();
  return stream.str();
}

matrix matrix::multiply_with_mix_column_matrix(){
  matrix new_matrix;

  for(int col=0; col<4; col++){
    new_matrix.storage[0][col] = multiply(0x2, this->storage[0][col])  ^
                                 multiply(0x3, this->storage[1][col])  ^
                                               this->storage[2][col]   ^
                                               this->storage[3][col];

    new_matrix.storage[1][col] =               this->storage[0][col]   ^
                                 multiply(0x2, this->storage[1][col])  ^
                                 multiply(0x3, this->storage[2][col])  ^
                                               this->storage[3][col];

    new_matrix.storage[2][col] =
                    this->storage[0][col] ^
                    this->storage[1][col] ^
      multiply(0x2, this->storage[2][col])^
      multiply(0x3, this->storage[3][col]);

    new_matrix.storage[3][col] =
      multiply(0x3, this->storage[0][col])^
                    this->storage[1][col] ^
                    this->storage[2][col] ^
      multiply(0x2, this->storage[3][col]);
  }
  
  //copying
  for(int i=0; i<4; i++)
    for(int j=0; j<4; j++) this->storage[i][j] = new_matrix.storage[i][j];

  return *this;
}

// ERROR HERE_---------------------------------------------------------
matrix matrix::multiply_with_inverse_mix_column_matrix(){ 
  matrix new_matrix;
  for(int col=0; col<4; col++){
  new_matrix.storage[0][col] =
    multiply(0xe,this->storage[0][col]) ^
    multiply(0xb,this->storage[1][col]) ^
    multiply(0xd,this->storage[2][col]) ^
    multiply(0x9,this->storage[3][col]);

  new_matrix.storage[1][col] =
    multiply(0x9,this->storage[0][col]) ^
    multiply(0xe,this->storage[1][col]) ^
    multiply(0xb,this->storage[2][col]) ^
    multiply(0xd,this->storage[3][col]);
  new_matrix.storage[2][col] =
    multiply(0xd,this->storage[0][col]) ^
    multiply(0x9,this->storage[1][col]) ^
    multiply(0xe,this->storage[2][col]) ^
    multiply(0xb,this->storage[3][col]);
  new_matrix.storage[3][col] =
    multiply(0xb,this->storage[0][col]) ^
    multiply(0xd,this->storage[1][col]) ^
    multiply(0x9,this->storage[2][col]) ^
    multiply(0xe,this->storage[3][col]);
  }
  //copying
  for(int i=0; i<4; i++)
    for(int j=0; j<4; j++) this->storage[i][j] = new_matrix.storage[i][j];

  return *this;
}


void matrix::single_shift(int row){
  byte a0 = this->storage[row][0];
  byte a1 = this->storage[row][1];
  byte a2 = this->storage[row][2];
  byte a3 = this->storage[row][3];

  this->storage[row][0] = a1;
  this->storage[row][1] = a2;
  this->storage[row][2] = a3;
  this->storage[row][3] = a0;
}


void matrix::single_inverse_shift(int row){
  byte a0 = this->storage[row][0];
  byte a1 = this->storage[row][1];
  byte a2 = this->storage[row][2];
  byte a3 = this->storage[row][3];

  this->storage[row][0] = a3;
  this->storage[row][1] = a0;
  this->storage[row][2] = a1;
  this->storage[row][3] = a2;
}


matrix matrix::shift_rows(){
  for(int row=0; row<4; row++){
    for(int rotate_count=1; rotate_count<=row; rotate_count++){
      this->single_shift(row);
    }
  }
  return *this;
}


matrix matrix::inverse_shift_rows(){
  for(int row=0; row<4; row++){
    for(int rotate_count=1; rotate_count<=row; rotate_count++){
      this->single_inverse_shift(row);
    }
  }
  return *this;
}


matrix matrix::add_round_key(matrix key){
  for(int i=0; i<4; i++){
    for(int j=0; j<4; j++)
      this->storage[i][j] = this->storage[i][j] ^ key.storage[i][j];
  }
  return *this;
}


matrix matrix::substitute(){
  for(int i=0; i<4; i++){
    for(int j=0; j<4; j++) this->storage[i][j] = substitute_byte(this->storage[i][j]);
  }
  return *this;
}

matrix matrix::inverse_substitute(){
  for(int i=0; i<4; i++){
    for(int j=0; j<4; j++) this->storage[i][j] = inverse_substitute_byte(this->storage[i][j]);
  }
  return *this;
}

void matrix::test_function(){
  // Using this example for testing
  //https://www.kavaliro.com/wp-content/uploads/2014/03/AES.pdf
  printf("Testing mix column: ------------\n");
  byte byte_input[16], byte_key[16];
  printf("Enter input(16 byte): ");
  for(int i=0 ;i<16; i++) scanf("%x ",&byte_input[i]);
  // printf("Enter key(16 byte): ");
  // for(int i=0 ;i<16; i++) scanf("%x ",&byte_key[i]);

  matrix matrix_input; /*, matrix_key;*/
  matrix_input.make_matrix(byte_input);
  // matrix_key.make_matrix(byte_key);


  printf("Input:\n");
  matrix_input.print();

  printf("Shift Row Operation: \n");
  matrix_input.shift_rows();
  matrix_input.print();

  // printf("Key:\n");
  // matrix_key.print();
  printf("After multiplication:\n");
  matrix_input.multiply_with_mix_column_matrix();
  matrix_input.print();
  printf("After inverse multiplication:\n");
  matrix_input.multiply_with_inverse_mix_column_matrix();
  matrix_input.print();

  printf("After Inverse Shift Row: \n");
  matrix_input.inverse_shift_rows();
  matrix_input.print();

  printf("After substitution:\n");
  matrix_input.substitute();
  matrix_input.print();
  printf("After Inverse substitution:\n");
  matrix_input.inverse_substitute();
  matrix_input.print();

  // printf("Add round key: \n");
}
