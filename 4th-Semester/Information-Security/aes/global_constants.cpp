#include "global_constants.h"

void abj::print_bits_of_byte(abj::byte c){
  bool is_set[8];
  for(int i=0; i<8; i++){
    is_set[i] = (c>>i) & 1;
  }

  for(int i=7; i>=0; i--){
    std::cout<<is_set[i];
  }
}
