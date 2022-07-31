#include<iostream>
#include"../global_constants.h"
#include<vector>

#define AES_ROW_SIZE 4
#define AES_COL_SIZE 4

std::vector<std::vector<abj::byte>> input_column_major_matrix(){
  std::string temp;
  std::cin>>temp;
  
  std::vector<std::vector<abj::byte>> input(AES_ROW_SIZE, std::vector<abj::byte>(AES_COL_SIZE));

  int string_iterator = 0;
  for(int r=0; r<AES_ROW_SIZE; r++){
    for(int c=0; c<AES_COL_SIZE; c++){
      abj::byte new_byte = temp[string_iterator];
      input[c][r] = new_byte;
      string_iterator++;
    }
  }
  return input;
}

void print_column_major_matrix(std::vector<std::vector<abj::byte>> m){
  for(int r=0; r<AES_ROW_SIZE; r++){
    for(int c=0; c<AES_COL_SIZE; c++){
      printf("%x ", m[r][c]);
    }
    printf("\n");
  }
}

int main(){
  std::cout << "Enter plain Text: ";
  print_column_major_matrix(input_column_major_matrix());
  return 0;
}
