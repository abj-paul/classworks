#include "round.h"
#include <vector>
#include <string>

void AES::initialize_using_byte(byte byte_input[16], byte byte_key[16]){ //convert input into matrix and store it
  this->plaintext.make_matrix(byte_input);
  this->ciphertext.make_matrix(byte_input);
  this->key.make_matrix(byte_key);
  this->expanded_key = key_expansion_algorithm(byte_key);
}

void AES::init(std::string input, std::string key){
	byte byte_input[16], byte_key[16];
	if(input.size()!=16) {printf("The input is not 16byte!(128bit). Exiting....\n");exit(1);}
	if(key.size()!=16) {printf("The key is not 16byte!(128bit). Exiting....\n");exit(1);}

	for(int i=0; i<input.size(); i++) byte_input[i] = input[i];
	for(int i=0; i<key.size(); i++) byte_key[i] = key[i];
	this->initialize_using_byte(byte_input, byte_key);	
}

void AES::round(int round_number){ 
  matrix round_key;

  for(int i=0; i<4; i++){
    for(int j=0; j<4; j++){
      round_key.storage[j][i] = expanded_key[round_number*4+i].storage[j];
    }
  }

  if(round_number==0){
    ciphertext.add_round_key(round_key);
  }else if(round_number==10){
    ciphertext.substitute();
    ciphertext.shift_rows();
    ciphertext.add_round_key(round_key);
 }else{
    ciphertext.substitute();
    ciphertext.shift_rows();
    ciphertext.multiply_with_mix_column_matrix();
    ciphertext.add_round_key(round_key);
 }
}

void AES::inverse_round(int round_number){ 
  matrix round_key;
  for(int i=0; i<4; i++){
    for(int j=0; j<4; j++){
      round_key.storage[j][i] = expanded_key[40-round_number*4+i].storage[j];
    }
  }
  
  if(round_number==0){
    ciphertext.add_round_key(round_key);
  }
  else if(round_number==10){
    ciphertext.inverse_shift_rows();
    ciphertext.inverse_substitute();
    ciphertext.add_round_key(round_key);
  }
  else{
    ciphertext.inverse_shift_rows();
    ciphertext.inverse_substitute();
    ciphertext.add_round_key(round_key);
    ciphertext.multiply_with_inverse_mix_column_matrix();
  }
}

void AES::encryption_algorithm(){
  for(int rnd=0; rnd<=10; rnd++) this->round(rnd);
}

void AES::decryption_algorithm(){
  for(int rnd=0; rnd<=10; rnd++) this->inverse_round(rnd);
}

void AES::test_function_for_single_block(){
  //Taking input
  byte byte_input[16], byte_key[16];
  printf("Enter Input: ");
  for(int i=0 ;i<16; i++) scanf("%x ",&byte_input[i]);
  printf("Enter key: ");
  for(int i=0 ;i<16; i++) scanf("%x ",&byte_key[i]);

  
  // AES Algorithm
  AES aes;
  aes.initialize_using_byte(byte_input, byte_key);
  printf("Printing Plaintext:\n");
  aes.plaintext.print();
  aes.encryption_algorithm();
  printf("Printing Ciphertext:\n");
  aes.ciphertext.print();
  aes.decryption_algorithm();
  printf("Printing Decrypted Ciphertext:\n");
  aes.ciphertext.print(); //NOTICE THAT WE ARE PRINTING CIPHER TEXT HERE.
  
}

void AES::test_function(){
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
      aes.initialize_using_byte((unsigned char*)blocks[i].data(), (unsigned char*)key.data());

      // Printing plaintexts, we can use it later to vertify decryption
      std::cout<<i+1<<") "<<blocks[i]<<std::endl;
      aes.plaintext.print();

      
      aes.encryption_algorithm();
      aes_list.push_back(aes);
    }

    for(int i=0; i<aes_list.size(); i++){
      std::cout<< i+1 << ") Plaintext: "<< blocks[i] << std::endl;
      aes_list[i].ciphertext.print();
    }

    std::cout<<"Encryption has been completed! Now time to decrypt the blocks!!!!!-----------------------------------------------"<<std::endl;


    for(int i=0; i<aes_list.size(); i++) aes_list[i].decryption_algorithm();

    for(int i=0; i<aes_list.size(); i++){
      std::cout<< i+1 << ") Plaintext: "<< blocks[i] << std::endl;
      aes_list[i].ciphertext.print();
    }

}

