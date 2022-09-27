#include "global.h"
#include "substitution.h"
#include "word.h"
#include "key_expansion.h"
#include "matrix.h"
#include "round.h"
#include <vector>
#include <string>
#include <sstream>
#include <stdint.h>


int main(){
  // Multiple Block Input
  std::string plaintext, key, CTRstr;
  std::cout<<"Insert key: ";
  getline(std::cin, key); 
  std::cout<<"Insert IV: ";
  getline(std::cin, CTRstr); 
  std::cout<<"Insert Plaintext: ";
  getline(std::cin, plaintext);

  std::string save_counter = CTRstr;

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
  for(int i=0; i<(int)blocks.size(); i++){
    AES aes;
    aes.initialize((unsigned char*)CTRstr.data(), (unsigned char*)key.data());
    aes.encryption_algorithm();

    matrix plainT;
    plainT.make_matrix((unsigned char*)blocks[i].data());

    aes.ciphertext = aes.ciphertext ^ plainT;
    aes_list.push_back(aes);

    // Incrementing Counter
    __int128 temp = (__int128)CTRstr.data() + 1 ;
    /*std::ostringstream ss;
    ss << (char*)temp;
    CTRstr = ss.str();*/
    std::string tempstr((char*)temp);
    CTRstr = tempstr;
  }
  
  std::cout<<"After Encryption: "<<std::endl;
  for(int i=0; i<aes_list.size(); i++)  std::cout<<i<<") "<<aes_list[i].ciphertext.getHexString()<<std::endl;
  
  //Decryption
  CTRstr = save_counter;
  std::vector<AES> decrypted_aes_list;
  for(int i=0; i<(int)blocks.size(); i++){
    AES aes;
    aes.initialize((unsigned char*)CTRstr.data(), (unsigned char*)key.data());
    aes.encryption_algorithm();

    aes.plaintext = aes.ciphertext ^ aes_list[i].ciphertext;
    decrypted_aes_list.push_back(aes);

    // Incrementing counter
    __int128 temp = (__int128)CTRstr.data() + 1 ;
    /*std::ostringstream ss;
    ss << (char*)temp;
    CTRstr = ss.str();*/
    std::string tempstr((char*)temp);
    CTRstr = tempstr;
  }

    
  std::cout<<"After Decryption: "<<std::endl;
  for(int i=0; i<aes_list.size(); i++)  std::cout<<i<<") "<<decrypted_aes_list[i].plaintext.getString()<<std::endl;
  
  return 0;
}

