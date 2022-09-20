#include "message_schedeuler.h"

Register w[80];

void message_schedeule(std::uint64_t* message){
  for(int i=0; i<16; i++){
    Register r;
    r.store(message[i]);
    w[i] = r;
  }

  for(int t=16; t<80; t++){
    w[t].store(Register::sigma_0(w[t-15]).get_data_dump() + Register::sigma_1(w[t-2]).get_data_dump() + w[t-7].get_data_dump() + w[t-16].get_data_dump());
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
  message_schedeule(convert_input_to_int64_arr(take_input()));
  print_message_schedeule();
}
