

#ifndef _SUBSTITUTION_H_
#define _SUBSTITUTION_H_

#include "global.h"

byte substitute_byte(byte);
byte inverse_substitute_byte(byte);
void test_substitution();

extern byte s_box[16][16];
extern byte inverse_s_box[16][16];

#endif
