
#ifndef _ROUND_H_
#define _ROUND_H_

#include "global.h"
#include "word.h"
#include "matrix.h"
#include "key_expansion.h"

extern matrix plaintext;
extern matrix ciphertext;
extern matrix key;
extern word* expanded_key; //[44];

void take_input(); //convert input into matrix and store it in global variables.
void round(int round_number); //changes the global variable
void inverse_round(int round_number); //changes the global variable

void encryption_algorithm();
void decryption_algorithm();

void test_round();
void test_aes();

#endif
