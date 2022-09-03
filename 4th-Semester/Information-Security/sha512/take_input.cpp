#include "take_input.h"

char* take_input(){
  char* str = (char*)calloc(BLOCK_SIZE_IN_BYTE*100, sizeof(char));

  scanf("%[^\n]%*c", str);
  return str;
}

char* pad_a_block(char* str_stream){
  char* pad_str = (char*)malloc(BLOCK_SIZE_IN_BYTE);
  
  int pad_length = BLOCK_SIZE_IN_BYTE - (strlen(str_stream) + UINT128_DATA_SIZE_IN_BYTE);

  for(int i=0; i<strlen(str_stream); i++) pad_str[i] = str_stream[i];
  
  for(int pi=0; pi<pad_length; pi++){
    if(pi!=0) pad_str[pi+strlen(str_stream)] = 0b0;
    else if(pi==0) pad_str[pi+strlen(str_stream)] = 0x80;
  }

  return pad_str;
}

char* add_inputSize_in_end(char* str_stream, int input_size){
  char* final_str = (char*)calloc(128, sizeof(char));
  
  __uint128_t x = input_size;
  char* arr = (char*)&x;

  int itr=128-16;
  for(int i=16-1; i>=0; i--){
    str_stream[itr] = arr[i];
    itr++;
  }

  //Copying to final_str
  for(int i=0; i<128; i++) final_str[i] = str_stream[i];

  return final_str; 
}

std::uint64_t* convert_char_stream_to_uint64_array(char* char_stream){
  
}

int test_input(){
  printf("Testing input module:%s\n",DIVIDER);
  printf("Enter text to hash:\n");
  char* input_str = take_input();
  char* pad_str = pad_a_block(input_str);
  char* final_str = add_inputSize_in_end(pad_str, strlen(input_str)*8);

  for(int i=0; i<128; i++) {
    printf("%d) %x\t ",i,final_str[i]);
    print_bits_of_byte(final_str[i]);
    printf("\n");
  }
  for(int i=0; i<128; i++) printf("%x ",final_str[i]);
  printf("\n");

  return 0;
}
