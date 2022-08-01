#include "../global_constants.h"

const int GALOIS_MODULAR = 0b100011011;
//const int GALOIS_MODULAR = 0b100000000;
//const int GALOIS_MODULAR = 0b11100101;

abj::byte galois_field(abj::byte a, abj::byte b){ // a * b
  int a_int = (int)a;
  int b_int = (int)b;

  int mul = (a_int * b_int)%GALOIS_MODULAR;

  a = a_int & 0b11111111;
  b = b_int & 0b11111111;
  abj::byte gf_mul = mul & 0b11111111;

  // printf("(%d X %d) mod %d = %d\n", a_int, b_int, GALOIS_MODULAR, mul);
  // printf("%x X %x = %x\n", a, b, gf_mul);
  // abj::print_bits_of_byte(a_int*b_int);
  // printf("\n");
  // abj::print_bits_of_byte(gf_mul);
  // printf("\n");

  return gf_mul;
}

int main(){
  //abj::byte ans = galois_field(0b11111111, 0b00000011);
  //abj::byte ans = galois_field(0x80, 0x2);
  abj::byte first = galois_field(0x87, 0x2);
  abj::byte second = galois_field(0x6e, 0x3);
  abj::byte third = 0x46;
  abj::byte fourth = 0xa6;

  abj::byte final_answer = first ^ second ^ third ^ fourth;
  printf("Final Answer:\n");
  abj::print_bits_of_byte(first); printf("\n");
  abj::print_bits_of_byte(second); printf("\n");
  abj::print_bits_of_byte(third); printf("\n");
  abj::print_bits_of_byte(fourth); printf("\n");
  abj::print_bits_of_byte(final_answer); printf("\n");
  printf("Answer = %x\n",final_answer);
  return 0;
}
