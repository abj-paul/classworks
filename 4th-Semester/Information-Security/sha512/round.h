
#ifndef _ROUND_H_
#define _ROUND_H_

#include "global.h"
#include "take_input.h"
#include "register.h"
#include "message_schedeuler.h"

extern std::uint64_t hash_inital[8]; 
extern std::uint64_t keys[80];

extern Register H[8];
extern Register k[80];

void single_round(int round);
void all_80_rounds();

Register T1(int round);
Register T2();

void round_test_function();
void block_test_function();

#endif

