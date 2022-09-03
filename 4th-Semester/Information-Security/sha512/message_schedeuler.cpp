#include "message_schedeuler.h"

Register w[80];

void message_schedeule(std::uint64_t* message){
  for(int i=0; i<16; i++){
    Register r;
    r.store(message[i]);
    w[i] = r;
  }

  for(int t=16; t<80; t++){
    w[t] = Register::sigma_0(w[t-15]) ^ Register::sigma_1(w[t-2]) ^ w[t-7] ^ w[t-16];
  }
}

void print_message_schedeule(){
  printf("Printing message schedeule:\n");
  for(int i=0; i<80; i++){
    printf("%d) ",i);
    w[i].print_hex();
  }
}


void test_message_schedeule(){
  printf("Testing message schedeule module: %s\n",DIVIDER);
  message_schedeule(convert_char_stream_to_uint64_array(take_input()));
  print_message_schedeule();
}
