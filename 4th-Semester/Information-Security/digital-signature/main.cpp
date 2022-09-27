#include <iostream>
#include <string>
#include <vector>
#include <fstream>

#include "aes/round.h"
#include "sha/sha.h"

int main(){

  std::string input="", line;
  std::ifstream input_stream("input.txt");
  while ( input_stream ) { // equivalent to myfile.good()
    std::getline (input_stream, line);
    if(line.size()!=0)input += line + "\n"; //SPECIAL CUSTOM CASE!@!!!!!
  } 
  std::cout<<input<<std::endl;

  std::string key="";
  std::ifstream key_stream("key.txt");
  for( std::string line; getline( key_stream, line ); ){
    key+=line;
  }
  key_stream.close();
  std::cout<<key<<std::endl;

  abj::SHA sha;
  std::string sha_digest = sha.hash(input);

  std::cout<<"SHA Digest: "<<sha_digest<<std::endl;


  // AES
  //Splitting it into blocks
  std::vector<std::string> blocks;
  for (unsigned i = 0; i < sha_digest.length(); i += 16) {
    blocks.push_back(sha_digest.substr(i, 16));
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

  std::string temp="";
  for(int i=0; i<aes_list.size(); i++) temp+= aes_list[i].ciphertext.getString();
  std::cout<<temp<<std::endl;
  
return 0;
}
