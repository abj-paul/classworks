#include "global.h"
#include "substitution.h"
#include "word.h"
#include "key_expansion.h"
#include "matrix.h"
#include "round.h"
#include <vector>
#include <string>


int main(){
  // Multiple Block Input
  std::string plaintext, key, IVstr;
  std::cout<<"Insert key: ";
  getline(std::cin, key); 
  std::cout<<"Insert IV: ";
  getline(std::cin, IVstr); 
  std::cout<<"Insert Plaintext: ";
  getline(std::cin, plaintext);

  matrix IV;
  IV.make_matrix((unsigned char*)IVstr.data());
  
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

      if(i==0) aes.ciphertext = aes.plaintext ^ IV; //special reason
      else aes.ciphertext = aes.plaintext ^ aes_list[i-1].ciphertext;
      
      aes.encryption_algorithm();
      aes_list.push_back(aes);
    }

    std::cout<<"After Encryption: "<<std::endl;
    for(int i=0; i<aes_list.size(); i++)  std::cout<<i<<") "<<aes_list[i].ciphertext.getHexString()<<std::endl;
    
    for(int i=aes_list.size()-1; i>=0; i--){
      aes_list[i].decryption_algorithm();
      if(i==0) aes_list[i].ciphertext = aes_list[i].ciphertext ^ IV;
      else aes_list[i-1].ciphertext = aes_list[i].ciphertext ^ aes_list[i-1].ciphertext;
    }
    std::cout<<"After Decryption: "<<std::endl;
    for(int i=0; i<aes_list.size(); i++)  std::cout<<i<<") "<<aes_list[i].ciphertext.getString()<<std::endl;
  
  return 0;
}

