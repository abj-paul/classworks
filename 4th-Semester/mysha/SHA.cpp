#include "SHA.h"
#include <iomanip>

void SHA::add_length_to_end(int length, uint64& lo, uint64& hi){
	lo = length;
	hi = HIGH_NULL;
}

uint64** SHA::preprocess(char* input, int* number_of_buffers){
	int message_len = strlen(input);
	int message_len_in_bits = message_len * 8; 
	int zero_padding = (896-1-message_len_in_bits) % 1024; // -1 because we are excluding 1 from padding len. We will add '1' separately. 
	*number_of_buffers = (message_len_in_bits+1+zero_padding+128) / 1024;

	uint64** blocks = new uint64*[*number_of_buffers];

	for(int i=0; i<*number_of_buffers; i++) blocks[i] = new uint64[16]; // Each block comprises of 16 registers. 16*64 = 1024. As we know, the first 16 data of message schedeuler are ~message block~ data.

	uint64 in;
	int index;

	// Either copy existing message, add 1 bit or add 0 bit
	for(int i=0; i<*number_of_buffers; i++){
	  for(int j=0; j<16; j++){ // For each block
	    in = 0x0ULL;
	    for(int k=0; k<8; k++){ // For each bit
	      index = i*128+j*8+k;
	      if(index < message_len){
		in = in<<8 | (uint64)input[index];
	      }else if(index == message_len){
		in = in<<8 | 0x80ULL;
	      }else{
		in = in<<8 | 0x0ULL;
	      }
	    }
	    blocks[i][j] = in;
	  }
	}

	// Append the length to the last two 64-bit blocks
	add_length_to_end(message_len_in_bits, blocks[*number_of_buffers-1][16-1], blocks[*number_of_buffers-1][16-2]);
	return blocks;
}

void SHA::process(uint64** buffer, int nBuffer, uint64* h){
	uint64 s[8];
	uint64 w[80]; 

	memcpy(h, hPrime, 8*sizeof(uint64)); //initializing registers

	for(int i=0; i<nBuffer; i++){
		// copy over to message schedule
		memcpy(w, buffer[i], 16*sizeof(uint64));

		// Prepare the message schedule
		for(int j=16; j<80; j++){
			w[j] = w[j-16] + sig0(w[j-15]) + w[j-7] + sig1(w[j-2]);
		}
		// Initialize the working variables
		memcpy(s, h, 8*sizeof(uint64));

		// Compression
		for(int j=0; j<80; j++){
			uint64 temp1 = s[7] + Sig1(s[4]) + Ch(s[4], s[5], s[6]) + k[j] + w[j];
			uint64 temp2 = Sig0(s[0]) + Maj(s[0], s[1], s[2]);

			s[7] = s[6];
			s[6] = s[5];
			s[5] = s[4];
			s[4] = s[3] + temp1;
			s[3] = s[2];
			s[2] = s[1];
			s[1] = s[0];
			s[0] = temp1 + temp2;
		}

		// Compute the intermediate hash values
		for(int j=0; j<8; j++){
			h[j] += s[j];
		}
	}

}

std::string SHA::digest(uint64* h){
	std::stringstream stream;
	for(size_t i=0; i<8; i++){
		stream << std::hex << std::setw(16) << std::setfill('0') << h[i];
	}
	return stream.str();
}

std::string SHA::hash(const std::string input){
  int* nBuffer = (int*)malloc(sizeof(int)); // amount of message blocks
  uint64** buffer; // message block buffers (each 1024-bit = 16 64-bit words)
  uint64* h = new uint64[8]; // buffer holding the message digest (512-bit = 8 64-bit words)
  
  buffer = preprocess((char*) input.c_str(), nBuffer);
  process(buffer, *nBuffer, h);
  return digest(h);
}


int main(){

	SHA sha512;
	std::string input;
	getline(std::cin, input);

	std::cout << "SHA512:" << sha512.hash(input) << std::endl;

	return 0;
}
