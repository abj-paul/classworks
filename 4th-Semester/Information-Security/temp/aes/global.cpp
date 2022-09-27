#include "global.h"

void print_bits_of_byte(byte old_byte){
  bool bits[8];
  int i = 0;
  while(i<8){
    bool bit = (old_byte>>i) & 1;
    bits[i]=bit;
    i++;
  }

  for(int i=7; i>=0; i--) std::cout<<bits[i];
}
