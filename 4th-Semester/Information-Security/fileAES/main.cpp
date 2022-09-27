#include "global.h"
#include "substitution.h"
#include "word.h"
#include "key_expansion.h"
#include "matrix.h"
#include "round.h"
#include <vector>
#include <string>


int main(){
  /*
  test_substitution();
  word::test_function();
  // test_expanded_key();
  test_galois_multiplication();
  matrix::test_function();
  test_round();
  */

  //AES::test_function_for_single_block();
  // AES::test_function();

  //Taking input
  /*byte byte_input[16], byte_key[16];
  printf("Enter key: ");
  for(int i=0 ;i<16; i++) scanf("%x ",&byte_key[i]);
  printf("Enter Input: ");
  for(int i=0 ;i<16; i++) scanf("%x ",&byte_input[i]);*/


  // Doing string input
  /* std::string plaintext, key;
  std::cout<<"Insert key: ";
  getline(std::cin, key); 
  std::cout<<"Insert Plaintext: ";
  getline(std::cin, plaintext); 

  for(int i=0; i<16; i++) byte_input[i] = (unsigned char)plaintext[i];
  for(int i=0; i<16; i++) byte_key[i] = (unsigned char)key[i];

  AES aes = AES::single_block(byte_input, byte_key);*/


  // Multiple Block Input
  std::string plaintext, key;
  std::cout<<"Insert key: ";
  getline(std::cin, key); 
  std::cout<<"Insert Plaintext: ";
  getline(std::cin, plaintext); 
  
  //Splitting it into blocks
  std::vector<std::string> blocks;
  for (unsigned i = 0; i < plaintext.length(); i += 16) {
    blocks.push_back(plaintext.substr(i, 16));
  }


  // Padding
  if(blocks.back().size()<16){
    for(int i=blocks.back().size(); i<16; i++) blocks[blocks.size()-1] = blocks.back() + AES::PAD_CHAR;
  }

    //Encryption
    std::vector<AES> aes_list;
    for(int i=0; i<blocks.size(); i++){
      AES aes;
      aes.initialize((unsigned char*)blocks[i].data(), (unsigned char*)key.data());
      aes.encryption_algorithm();
      aes_list.push_back(aes);
    }

    std::cout<<"After Encryption: "<<std::endl;
    for(int i=0; i<aes_list.size(); i++)  std::cout<<i<<") "<<aes_list[i].ciphertext.getHexString()<<std::endl;
    
    for(int i=0; i<aes_list.size(); i++) aes_list[i].decryption_algorithm();
    std::cout<<"After Decryption: "<<std::endl;
    for(int i=0; i<aes_list.size(); i++)  std::cout<<i<<") "<<aes_list[i].ciphertext.getString()<<std::endl;
  
  return 0;
}

