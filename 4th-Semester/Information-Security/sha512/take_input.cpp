#include "take_input.h"


char* HashInput::pad_a_block(char* str_stream){
  char* pad_str = (char*)malloc(BLOCK_SIZE_IN_BYTE);
  
  int pad_length = BLOCK_SIZE_IN_BYTE - (strlen(str_stream) + UINT128_DATA_SIZE_IN_BYTE);

  for(int i=0; i<strlen(str_stream); i++) pad_str[i] = str_stream[i];
  
  for(int pi=0; pi<pad_length; pi++){
    if(pi!=0) pad_str[pi+strlen(str_stream)] = 0b0;
    else if(pi==0) pad_str[pi+strlen(str_stream)] = 0x80;
  }

  return pad_str;
}

char* HashInput::add_inputSize_in_end(char* str_stream, int input_size){
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

void HashInput::reverse(char* int_stream){
  unsigned char a = int_stream[0];
  unsigned char b = int_stream[1];
  unsigned char c = int_stream[2];
  unsigned char d = int_stream[3];

  unsigned char e = int_stream[4];
  unsigned char f = int_stream[5];
  unsigned char g = int_stream[6];
  unsigned char h = int_stream[7];

  int_stream[0] = h;
  int_stream[1] = g;
  int_stream[2] = f;
  int_stream[3] = e;

  int_stream[4] = d;
  int_stream[5] = c;
  int_stream[6] = b;
  int_stream[7] = a;
}


std::uint64_t* HashInput::convert_char_stream_to_uint64(const char* char_stream){
  std::uint64_t* num = (std::uint64_t*)malloc(sizeof(std::uint64_t));
  char* addr = (char*)num;

  for(int i=0; i<8; i++){
    *addr = char_stream[i];
    addr++;
  }

  addr = (char*)num;
  //Now reverse it
  reverse(addr);

  return num;
}

std::uint64_t* HashInput::convert_char_stream_to_uint64_array(const char* char_stream){
  int num_of_uint64 = 16;
  uint64_t* arr = (uint64_t*)malloc(num_of_uint64*sizeof(uint64_t));
  for(int i=0; i<num_of_uint64; i++){
    arr[i] = *(this->convert_char_stream_to_uint64(char_stream));
    char_stream = char_stream + 8;
  }

  return arr;
}


std::uint64_t* HashInput::convert_input_to_uint64_array(char* input_str){
  char* pad_str = pad_a_block(input_str);
  char* final_str = add_inputSize_in_end(pad_str, strlen(input_str)*8);

  std::uint64_t* arr = convert_char_stream_to_uint64_array(final_str);
  return arr;
 }

int test_input(){
  printf("Testing input module:%s\n",DIVIDER);
  printf("Enter text to hash:\n");

  std::string temp;
  std::getline(std::cin, temp);
  char* input = temp.data();

  HashInput hi;
  std::uint64_t* arr = hi.convert_input_to_uint64_array(input);

  for(int i=0; i<128/8; i++) printf("%lx ",arr[i]);
  printf("\n");

  return 0;
}

std::uint64_t** HashInput::numerify_multiple_block_message(std::vector<std::string> blocks){
  std::uint64_t** numerified_blocks = (std::uint64_t**)malloc(sizeof(std::uint64_t*)*blocks.size());
  for(int i=0; i<blocks.size()-1; i++) {
    std::uint64_t* arr = convert_char_stream_to_uint64_array(blocks[i].data());
    numerified_blocks[i] = arr; 
  }

  // The Last block
  char* pad_str = pad_a_block(blocks.back().data());
  char* final_str = add_inputSize_in_end(pad_str, strlen(blocks.back().data())*8);
  std::uint64_t* arr = convert_char_stream_to_uint64_array(final_str);
  numerified_blocks[blocks.size()-1] = arr;
  
  return numerified_blocks;

}
