#include "sha.h"

const int64 abj::SHA::Constants[80]= {
                0x428a2f98d728ae22, 0x7137449123ef65cd,
		0xb5c0fbcfec4d3b2f, 0xe9b5dba58189dbbc,
		0x3956c25bf348b538, 0x59f111f1b605d019,
		0x923f82a4af194f9b, 0xab1c5ed5da6d8118,
		0xd807aa98a3030242, 0x12835b0145706fbe,
		0x243185be4ee4b28c, 0x550c7dc3d5ffb4e2,
		0x72be5d74f27b896f, 0x80deb1fe3b1696b1,
		0x9bdc06a725c71235, 0xc19bf174cf692694,
		0xe49b69c19ef14ad2, 0xefbe4786384f25e3,
		0x0fc19dc68b8cd5b5, 0x240ca1cc77ac9c65,
		0x2de92c6f592b0275, 0x4a7484aa6ea6e483,
		0x5cb0a9dcbd41fbd4, 0x76f988da831153b5,
		0x983e5152ee66dfab, 0xa831c66d2db43210,
		0xb00327c898fb213f, 0xbf597fc7beef0ee4,
		0xc6e00bf33da88fc2, 0xd5a79147930aa725,
		0x06ca6351e003826f, 0x142929670a0e6e70,
		0x27b70a8546d22ffc, 0x2e1b21385c26c926,
		0x4d2c6dfc5ac42aed, 0x53380d139d95b3df,
		0x650a73548baf63de, 0x766a0abb3c77b2a8,
		0x81c2c92e47edaee6, 0x92722c851482353b,
		0xa2bfe8a14cf10364, 0xa81a664bbc423001,
		0xc24b8b70d0f89791, 0xc76c51a30654be30,
		0xd192e819d6ef5218, 0xd69906245565a910,
		0xf40e35855771202a, 0x106aa07032bbd1b8,
		0x19a4c116b8d2d0c8, 0x1e376c085141ab53,
		0x2748774cdf8eeb99, 0x34b0bcb5e19b48a8,
		0x391c0cb3c5c95a63, 0x4ed8aa4ae3418acb,
		0x5b9cca4f7763e373, 0x682e6ff3d6b2b8a3,
		0x748f82ee5defb2fc, 0x78a5636f43172f60,
		0x84c87814a1f0ab72, 0x8cc702081a6439ec,
		0x90befffa23631e28, 0xa4506cebde82bde9,
		0xbef9a3f7b2c67915, 0xc67178f2e372532b,
		0xca273eceea26619c, 0xd186b8c721c0c207,
		0xeada7dd6cde0eb1e, 0xf57d4f7fee6ed178,
		0x06f067aa72176fba, 0x0a637dc5a2c898a6,
		0x113f9804bef90dae, 0x1b710b35131c471b,
		0x28db77f523047d84, 0x32caab7b40c72493,
		0x3c9ebe0a15c9bebc, 0x431d67c49c100d4c,
		0x4cc5d4becb3e42b6, 0x597f299cfc657e2a,
		0x5fcb6fab3ad6faec, 0x6c44198c4a475817 };

std::string abj::SHA::getHexFrom4bit(std::string bin){ // Convert 4digit binary string to hex string format.
	if (bin == "0000") return "0";
	if (bin == "0001") return "1";
	if (bin == "0010") return "2";
	if (bin == "0011") return "3";
	if (bin == "0100") return "4";
	if (bin == "0101") return "5";
	if (bin == "0110") return "6";
	if (bin == "0111") return "7";
	if (bin == "1000") return "8";
	if (bin == "1001") return "9";
	if (bin == "1010") return "a";
	if (bin == "1011") return "b";
	if (bin == "1100") return "c";
	if (bin == "1101") return "d";
	if (bin == "1110") return "e";
	if (bin == "1111") return "f";
	return NULL;
}

std::string abj::SHA::getHexFromDecimal(int64 deci){
  std::string bin = std::bitset<64>(deci).to_string();
  std::string hex_str= "";
  std::string temp;
  
  for (unsigned int i = 0;i < bin.length(); i += 4) {
    temp = bin.substr(i, 4);
    hex_str += getHexFrom4bit(temp);
  }
  return hex_str;
}

int64 abj::SHA::getDecFromBin(std::string bin){
  int64 value = std::bitset<64>(bin).to_ullong();
  return value;
}

int64 abj::SHA::rotate_right(int64 x, int n){
  return (x >> n) | (x << (64 - n));
}

int64 abj::SHA::shift_right(int64 x, int n){
  return (x >> n);
}

void abj::SHA::message_schedeuler(std::string single_block){
  int nChunk = 0;

  for (int i = 0;i < (int)single_block.length(); i += 64, ++nChunk)this->Message[nChunk] = getDecFromBin(single_block.substr(i, 64));

  for (int g = 16; g < 80; ++g) {
    
    int64 WordA = rotate_right(Message[g - 2], 19) ^ rotate_right(Message[g - 2], 61) ^ shift_right(Message[g - 2], 6);
    int64 WordB = Message[g - 7];
    int64 WordC = rotate_right(Message[g - 15], 1) ^ rotate_right(Message[g - 15], 8) ^ shift_right(Message[g - 15], 7);
    int64 WordD = Message[g - 16];
    
    int64 T = WordA + WordB + WordC + WordD;
    
    Message[g] = T;
  }
}

int64 abj::SHA::maj(int64 a, int64 b, int64 c){
	return (a & b) ^ (b & c) ^ (c & a);
}

int64 abj::SHA::Ch(int64 e, int64 f, int64 g){
	return (e & f) ^ (~e & g);
}

int64 abj::SHA::sum_1(int64 e){
  return rotate_right(e, 14) ^ rotate_right(e, 18) ^ rotate_right(e, 41);
}

int64 abj::SHA::sum_0(int64 a){
  return rotate_right(a, 28) ^ rotate_right(a, 34) ^ rotate_right(a, 39);
}

void abj::SHA::round(int64 a, int64 b, int64 c,int64& d, int64 e, int64 f,int64 g, int64& h, int K){
  int64 T1 = h + Ch(e, f, g) + sum_1(e) + Message[K] + Constants[K];
  int64 T2 = sum_0(a) + maj(a, b, c);

  d = d + T1;
  h = T1 + T2;
}

std::string abj::SHA::hash(std::string msg){
  int64 A = 0x6a09e667f3bcc908;
  int64 B = 0xbb67ae8584caa73b;
  int64 C = 0x3c6ef372fe94f82b;
  int64 D = 0xa54ff53a5f1d36f1;
  int64 E = 0x510e527fade682d1;
  int64 F = 0x9b05688c2b3e6c1f;
  int64 G = 0x1f83d9abfb41bd6b;
  int64 H = 0x5be0cd19137e2179;
  
  std::stringstream fixedstream;
  for (int i = 0; i < (int)msg.size(); ++i) fixedstream << std::bitset<8>(msg[i]);
  
  std::string padded_str;
  padded_str = fixedstream.str();
  
  int msglen_inbits = padded_str.length();
  int pad_len;

  int last_blk_len = padded_str.length() % 1024;
  
  if (1024 - last_blk_len >= 128) pad_len = 1024 - last_blk_len;
  else pad_len = 2048 - last_blk_len; // We need to add a new block to store the address so 2048.
  
  padded_str += "1";
  for(int i = 0; i < pad_len - 129; i++)// 128 num + 1 = 129
    padded_str += "0";

  std::string lengthbits = std::bitset<128>(msglen_inbits).to_string();
  
  padded_str += lengthbits; // Appending length at the end of the padded string.
  
  int nBlock = padded_str.length() / 1024;
  int iBlock = 0;
  
  std::string Blocks[nBlock];
  for (int i = 0; i < padded_str.length();i += 1024, ++iBlock) Blocks[iBlock] = padded_str.substr(i, 1024);
  
  // Main Hashing Algorithm Part
  int64 previous_A, previous_B, previous_C, previous_D, previous_E, previous_F, previous_G, previous_H; // To store the previous hash
  for (int letsgo = 0; letsgo < nBlock; ++letsgo){
    message_schedeuler(Blocks[letsgo]);
    previous_A = A;
    previous_B = B;
    previous_C = C;
    previous_D = D;
    previous_E = E;
    previous_F = F;
    previous_G = G;
    previous_H = H;

    int nRound = 0;
    for (int i = 0; i < 10; i++) { //REQUIRES EDITTTTT
      round(A, B, C, D, E, F, G, H, nRound);
      nRound++;
      round(H, A, B, C, D, E, F, G, nRound);
      nRound++;
      round(G, H, A, B, C, D, E, F, nRound);
      nRound++;
      round(F, G, H, A, B, C, D, E, nRound);
      nRound++;
      round(E, F, G, H, A, B, C, D, nRound);
      nRound++;
      round(D, E, F, G, H, A, B, C, nRound);
      nRound++;
      round(C, D, E, F, G, H, A, B, nRound);
      nRound++;
      round(B, C, D, E, F, G, H, A, nRound);
      nRound++;
    }
    
    A += previous_A;
    B += previous_B;
    C += previous_C;
    D += previous_D;
    E += previous_E;
    F += previous_F;
    G += previous_G;
    H += previous_H;
  }
  
  std::stringstream output;

  output << getHexFromDecimal(A);
  output << getHexFromDecimal(B);
  output << getHexFromDecimal(C);
  output << getHexFromDecimal(D);
  output << getHexFromDecimal(E);
  output << getHexFromDecimal(F);
  output << getHexFromDecimal(G);
  output << getHexFromDecimal(H);
  
  return output.str();
}

/*
int main(){
  SHA sha;

  std::string input;
  std::cin>>input;
  
  cout << input << "\nSHA: " << sha.hash(input) << endl;
  
  return 0;
}
*/
