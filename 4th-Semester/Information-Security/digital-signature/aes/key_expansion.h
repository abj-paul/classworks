#ifndef _KEY_EXPANSION_H_
#define _KEY_EXPANSION_H_

#include "word.h"
#include "substitution.h"

word* key_expansion_algorithm(byte*  key);
word substitute_word(word); // substitute all bytes in a word using s-box
void print_expanded_key(word* w);
void test_expanded_key();
extern byte round_constant[11];

#endif
