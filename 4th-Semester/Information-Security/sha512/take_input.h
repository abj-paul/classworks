#ifndef _TAKE_INPUT_H_
#define _TAKE_INPUT_H_

// FOR NOW, We only handle SINGLE BLOCK

#include<iostream>
#include<string.h>
#include<vector>
#include<string>
#include "global.h"

#ifndef BLOCK_SIZE_IN_BIT
#define BLOCK_SIZE_IN_BIT 1024
#endif

#ifndef BLOCK_SIZE_IN_BYTE
#define BLOCK_SIZE_IN_BYTE 128
#endif


#ifndef BYTE_SIZE_IN_BIT
#define BYTE_SIZE_IB_BIT 8
#endif

#ifndef BYTE
#define BYTE unsigned char
#endif

#ifndef UINT64_DATA_SIZE_IN_BIT
#define UINT64_DATA_SIZE_IN_BIT 64
#endif

#ifndef UINT64_DATA_SIZE_IN_BYTE
#define UINT64_DATA_SIZE_IN_BYTE 8
#endif

#ifndef UINT128_DATA_SIZE_IN_BYTE
#define UINT128_DATA_SIZE_IN_BYTE 16
#endif



class HashInput {
private:
  char* pad_a_block(char* str_stream);
  char* add_inputSize_in_end(char* str_stream, int input_size);
  void reverse(char* int_stream);
  std::uint64_t* convert_char_stream_to_uint64(const char* char_stream);
  std::uint64_t* convert_char_stream_to_uint64_array(const char* char_stream);
  

public:
  std::uint64_t* convert_input_to_uint64_array(char* input); //service
  std::uint64_t** numerify_multiple_block_message(std::vector<std::string> blocks);
  void test_function();
};

#endif
