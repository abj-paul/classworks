#include "round.h"
#include<vector>
#include<string>

  Register previous_hash[8];

std::uint64_t hash_inital[8] = { 0x6a09e667f3bcc908ULL, 
								0xbb67ae8584caa73bULL, 
								0x3c6ef372fe94f82bULL, 
								0xa54ff53a5f1d36f1ULL, 
								0x510e527fade682d1ULL, 
								0x9b05688c2b3e6c1fULL, 
								0x1f83d9abfb41bd6bULL, 
								0x5be0cd19137e2179ULL
};
std::uint64_t keys[80] = {0x428a2f98d728ae22ULL, 0x7137449123ef65cdULL, 0xb5c0fbcfec4d3b2fULL, 0xe9b5dba58189dbbcULL, 0x3956c25bf348b538ULL, 
              0x59f111f1b605d019ULL, 0x923f82a4af194f9bULL, 0xab1c5ed5da6d8118ULL, 0xd807aa98a3030242ULL, 0x12835b0145706fbeULL, 
              0x243185be4ee4b28cULL, 0x550c7dc3d5ffb4e2ULL, 0x72be5d74f27b896fULL, 0x80deb1fe3b1696b1ULL, 0x9bdc06a725c71235ULL, 
              0xc19bf174cf692694ULL, 0xe49b69c19ef14ad2ULL, 0xefbe4786384f25e3ULL, 0x0fc19dc68b8cd5b5ULL, 0x240ca1cc77ac9c65ULL, 
              0x2de92c6f592b0275ULL, 0x4a7484aa6ea6e483ULL, 0x5cb0a9dcbd41fbd4ULL, 0x76f988da831153b5ULL, 0x983e5152ee66dfabULL, 
              0xa831c66d2db43210ULL, 0xb00327c898fb213fULL, 0xbf597fc7beef0ee4ULL, 0xc6e00bf33da88fc2ULL, 0xd5a79147930aa725ULL, 
              0x06ca6351e003826fULL, 0x142929670a0e6e70ULL, 0x27b70a8546d22ffcULL, 0x2e1b21385c26c926ULL, 0x4d2c6dfc5ac42aedULL, 
              0x53380d139d95b3dfULL, 0x650a73548baf63deULL, 0x766a0abb3c77b2a8ULL, 0x81c2c92e47edaee6ULL, 0x92722c851482353bULL, 
              0xa2bfe8a14cf10364ULL, 0xa81a664bbc423001ULL, 0xc24b8b70d0f89791ULL, 0xc76c51a30654be30ULL, 0xd192e819d6ef5218ULL, 
              0xd69906245565a910ULL, 0xf40e35855771202aULL, 0x106aa07032bbd1b8ULL, 0x19a4c116b8d2d0c8ULL, 0x1e376c085141ab53ULL, 
              0x2748774cdf8eeb99ULL, 0x34b0bcb5e19b48a8ULL, 0x391c0cb3c5c95a63ULL, 0x4ed8aa4ae3418acbULL, 0x5b9cca4f7763e373ULL, 
              0x682e6ff3d6b2b8a3ULL, 0x748f82ee5defb2fcULL, 0x78a5636f43172f60ULL, 0x84c87814a1f0ab72ULL, 0x8cc702081a6439ecULL, 
              0x90befffa23631e28ULL, 0xa4506cebde82bde9ULL, 0xbef9a3f7b2c67915ULL, 0xc67178f2e372532bULL, 0xca273eceea26619cULL, 
              0xd186b8c721c0c207ULL, 0xeada7dd6cde0eb1eULL, 0xf57d4f7fee6ed178ULL, 0x06f067aa72176fbaULL, 0x0a637dc5a2c898a6ULL, 
              0x113f9804bef90daeULL, 0x1b710b35131c471bULL, 0x28db77f523047d84ULL, 0x32caab7b40c72493ULL, 0x3c9ebe0a15c9bebcULL, 
              0x431d67c49c100d4cULL, 0x4cc5d4becb3e42b6ULL, 0x597f299cfc657e2aULL, 0x5fcb6fab3ad6faecULL, 0x6c44198c4a475817ULL };

Register H[8];
Register k[80];

void initialize(){
  for(int i=0; i<8; i++)
    H[i].store(hash_inital[i]);

  for(int i=0; i<80; i++) k[i].store(keys[i]);
}

Register T1(int round){
  /*Register h,e,f,g;
  e.store(H[4].get_data_dump());
  f.store(H[5].get_data_dump());
  g.store(H[6].get_data_dump());
  h.store(H[7].get_data_dump());*/
  /*
  printf("Printing T1 for round %d:\n",round);
  printf("h\t");h.print_hex();
  printf("ch(e,f,g)\t");Register::ch(e,f,g).print_hex();
  printf("sum(512,1,e)\t");Register::sum(512,1,e).print_hex();
  printf("w[%d]\t",round);w[round].print_hex();
  printf("k[%d]\t",round);k[round].print_hex();
  printf("Result: ");

  (h^Register::ch(e,f,g)^Register::sum(512,1,e)^w[round]^k[round]).print_bin();
  (h^Register::ch(e,f,g)^Register::sum(512,1,e)^w[round]^k[round]).print_hex();
  */
  std::uint64_t temp1 = (H[7].get_data_dump() + Register::sum(512,1,H[4]).get_data_dump() + Register::ch(H[4], H[5], H[6]).get_data_dump() + k[round].get_data_dump() + w[round].get_data_dump()) & 0xFFFFFFFFFFFFFFFF;
  Register ans;
  ans.store(temp1);
  return ans;
}

Register T2(){
  Register a,b,c;
  a.store(H[0].get_data_dump());
  b.store(H[1].get_data_dump());
  c.store(H[2].get_data_dump());

  /*
  printf("Printing T2:\n");
  printf("Sum(512,0,a):");
  Register::sum(512,0,a).print_bin();
  printf("Maj(a,b,c):\n");
  a.print_bin();
  b.print_bin();
  c.print_bin();
  Register::maj(a,b,c).print_bin();
  printf("Done!\n");*/

  /*  (Register::sum(512,0,a) ^ Register::maj(a,b,c)).print_bin();
      (Register::sum(512,0,a) ^ Register::maj(a,b,c)).print_hex();*/

  std::uint64_t temp2 = (Register::sum(512,0,H[0]).get_data_dump()+ Register::maj(H[0], H[1], H[2]).get_data_dump()) & 0xFFFFFFFFFFFFFFFF;
  Register ans;
  ans.store(temp2);
  return ans;
}

void single_round(int round){
  Register t1 = T1(round);
  Register t2 = T2();

  Register a = H[0];
  Register b = H[1];
  Register c = H[2];
  Register d = H[3];
  Register e = H[4];
  Register f = H[5];
  Register g = H[6];
  Register h = H[7];
  
  h=g;
  g=f;
  f=e;
  e.store( (d.get_data_dump() + t1.get_data_dump()) & 0xFFFFFFFFFFFFFFFF);
  d=c;
  c=b;
  b=a;
  a.store((t1.get_data_dump() + t2.get_data_dump()) & 0xFFFFFFFFFFFFFFFF);

  H[0] = a;
  H[1] = b;
  H[2] = c;
  H[3] = d;
  H[4] = e;
  H[5] = f;
  H[6] = g;
  H[7] = h;
}

static void print_8_registers(int round){
  printf("Round=%d:\n",round);
  for(int i=0; i<8; i++)
    printf("%lx ", H[i].get_data_dump());
  printf("\n");
}

static void print_8_registers(){
  for(int i=0; i<8; i++)
    printf("%lx ", H[i].get_data_dump());
  printf("\n");
}



void all_80_rounds(){
  for(int i=0; i<8; i++) previous_hash[i].store(H[i].get_data_dump());
  initialize();
  for(int i=0; i<80; i++){
    single_round(i);
	print_8_registers(i);
  }

  for(int i=0; i<8; i++) H[i].store( (previous_hash[i].get_data_dump() + H[i].get_data_dump()) & 0xFFFFFFFFFFFFFFFF);
}



void round_test_function(){

    printf("Enter text to hash:\n");
    std::string temp ;
    getline(std::cin, temp);
    char* input_str = temp.data();

    HashInput hi;
    message_schedeule(hi.convert_input_to_uint64_array(input_str));
    print_message_schedeule();

    initialize();
    print_8_registers();
    all_80_rounds(); 
    
    printf("Final message digest:\n");
    print_8_registers();
}

void block_test_function(){

  // Take Input
  printf("Enter text to hash:\n");
  std::string input_str ;
  getline(std::cin, input_str);
  
  // Block
  std::vector<std::string> blocks;
  for (unsigned i = 0; i < input_str.length(); i += 128) {
    blocks.push_back(input_str.substr(i, 128));
  }

  HashInput hi;
  std::uint64_t** numerified_msg = hi.numerify_multiple_block_message(blocks);

  printf("Printing numerified message: %d\n",DIVIDER);
  for(int i=0; i< input_str.size()/8; i++) printf("%d\ %lx\n",i+1, numerified_msg[i]);
  
  initialize();
  for(int i=0; i<blocks.size(); i++){
    printf("BLOCK %d-----------------------------------------------------------------------\n",i);
    message_schedeule(numerified_msg[i]);
    print_message_schedeule();
    
    print_8_registers();
    all_80_rounds(); 
    
  }
  printf("Final message digest:\n");
  print_8_registers();
}
