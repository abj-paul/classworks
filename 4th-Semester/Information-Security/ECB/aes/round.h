
#ifndef _ROUND_H_
#define _ROUND_H_

#include <string>
#include "global.h"
#include "word.h"
#include "matrix.h"
#include "key_expansion.h"

class AES {
 private:
  matrix key;
  word* expanded_key; //[44];


  //convert input into matrix and store it in global variables.
void initialize_using_byte(byte byte_input[16], byte byte_key[16]);
void round(int round_number); //changes the global variable
void inverse_round(int round_number); //changes the global variable

 public:
  matrix plaintext;
  matrix ciphertext;

 static const char PAD_CHAR = '\0';

 void init(std::string input, std::string key);
 void encryption_algorithm();
 void decryption_algorithm();

 static void test_function();
 static void test_function_for_single_block(); //for debug purpose
};

#endif
