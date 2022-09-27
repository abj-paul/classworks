#include "word.h"


word word::make_word(byte a, byte b, byte c, byte d){
  this->storage[0]=a;
  this->storage[1]=b;
  this->storage[2]=c;
  this->storage[3]=d;

  return *this;
}

word word::replace(byte a, byte b, byte c, byte d){
  return this->make_word(a,b,c,d);
}

word word::rotate_word(){
  byte a = this->storage[0];
  byte b = this->storage[1];
  byte c = this->storage[2];
  byte d = this->storage[3];

  this->storage[0] = b;
  this->storage[1] = c;
  this->storage[2] = d;
  this->storage[3] = a;

  return *this;
}


void word::print_hex(){
  for(int i=0; i<4; i++) printf("%x ",this->storage[i]);
}

void word::print(){
  for(int i=0; i<4; i++){
    print_bits_of_byte(this->storage[i]);
    printf(" ");
  }
}

word word::operator ^ (const word& obj){
  byte a = this->storage[0] ^ obj.storage[0]; 
  byte b = this->storage[1] ^ obj.storage[1]; 
  byte c = this->storage[2] ^ obj.storage[2]; 
  byte d = this->storage[3] ^ obj.storage[3]; 

  word new_word;
  new_word.make_word(a,b,c,d);
  
  return new_word;
}



void word::test_function(){
  printf("Testing word module:----------------------- \n");
  word word_one, word_two;
  word_one.make_word('a','b','c','d');
  word_two.make_word('w','x','y','z');

  word xor_word = word_one ^ word_two;

  word_one.print();
  printf("\n");
  word_two.print();
  printf("\nXOR\n");
  xor_word.print();
  printf("\n");

  printf("Rotate: \n");
  word_one.rotate_word();
  word_one.print();
  printf("\n");
}
