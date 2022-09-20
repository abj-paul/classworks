#include<iostream>
#include<string>
#include<cmath>
#include<vector>

int main(){
  std::string str;
  std::cin>>str;

  int number_of_blocks = ceil(str.size()/128);
  std::vector<char*> blocks;

  std::cout<<str<<std::endl;
  std::cout<<"Number of blocks: "<<number_of_blocks<<std::endl;
  
  int i=0;
  for(i=0; i<number_of_blocks-1; i++) {
    char* curr_block = (char*)malloc(sizeof(char)*128);
    for(int j=0; j<128; j++) curr_block[j] = str[i*128+j];
    blocks.push_back(curr_block);
  }

  int last_block_size = str.size() % 128;
  char* curr_block = (char*)malloc(sizeof(char)*128);
  for(int j=0; j<last_block_size; j++) curr_block[j] = str[i*128+j];
  
  for(int i=0; i<blocks.size(); i++) printf("%d) %s\n",i+1, blocks[i]);
  
  return 0;
}
