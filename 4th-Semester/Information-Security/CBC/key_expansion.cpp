#include "key_expansion.h"

byte round_constant[11] = { // 11 because index 0 is NULL
  (byte)NULL, 0x1, 0x2, 0x4, 0x8, 0x10, 0x20, 0x40, 0x80, 0x1b, 0x36
};

word* key_expansion_algorithm(byte*  key){
  word temp;

  word* w = (word*)malloc(sizeof(word)*44);
  for(int i=0; i<4; i++){
    w[i].make_word(
		   key[4*i],
		   key[4*i+1],
		   key[4*i+2],
		   key[4*i+3]
		   );
  }
  word rc;
  for(int i=4; i<44; i++){
    temp = w[i-1];
    if(i%4==0){
      // printf("Special case at round %d, byte %d\n",i/4,i);
      temp = substitute_word(temp.rotate_word()) ^ rc.make_word(round_constant[i/4], 0,0,0);
    }

    w[i] = w[i-4] ^ temp;
  }

  return w;
}


word substitute_word(word w){
  word new_word;
  for(int i=0; i<4; i++){
    new_word.storage[i] = substitute_byte(w.storage[i]);
  }
  return new_word;
}

void print_expanded_key(word* w){
  for(int i=0; i<44; i=i+4){
    printf("Round %d: ",i);
    for(int j=0; j<4; j++){
      w[i+j].print_hex();
    }
    printf("\n");
  }
}

void test_expanded_key(){
  // Sample input output for key expansion
  //https://www.kavaliro.com/wp-content/uploads/2014/03/AES.pdf 
  printf("Enter key(16 byte): ");

  byte key[16];
  for(int i=0; i<16; i++) scanf("%x ",&key[i]);

  word* expanded_key = key_expansion_algorithm(key);

  printf("Expansion key module: -------------------------\n");
  for(int i=0; i<16; i++) printf("%x ",key[i]);
  printf("\n");
  print_expanded_key(expanded_key);
  printf("\n");
}
