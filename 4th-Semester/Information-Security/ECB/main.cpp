#include <iostream>
#include <string>
#include <vector>

#include "aes/round.h"

int main(){

	std::string input, key;
	std::cout<<"Insert Input: ";
	std::getline(std::cin, input);
	std::cout<<"Insert Key: ";
	std::getline(std::cin, key);

	if(key.size()!=16) {
		printf("Key must be 128 bit or 16byte. Exiting...\n");
		exit(1);
	}

	//Make Blocks
	std::vector<std::string> blocks;
	for(int i=0; i<input.size(); i+=16){
		blocks.push_back(input.substr(i,16));
	}

	//Padding
	for(int i=blocks.back().size(); i<16; i++)
		blocks[blocks.size()-1]+='-';	

	for(int i=0; i<blocks.size(); i++){
		std::cout<<i+1<<") "<<blocks[i]<<" Len: "<<blocks[i].size()<<std::endl;
	}

	AES aes;
	for(int i=0; i<blocks.size(); i++){
	aes.init(blocks[i],key);
	std::cout<<"Plaintext of block "<<i<<std::endl;
	aes.plaintext.print();
	std::cout<<"Encrypting block "<<i<<std::endl;
	aes.encryption_algorithm();
	aes.ciphertext.print();
	std::cout<<"Decrypting block "<<i<<std::endl;
	aes.decryption_algorithm();
	aes.ciphertext.print();
	}
	
return 0;
}
