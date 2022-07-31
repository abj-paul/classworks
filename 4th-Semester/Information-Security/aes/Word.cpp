#include "Word.h"


void abj::Word::make_word(abj::byte a, abj::byte b, abj::byte c, abj::byte d){
  this->storage[0] = a;
  this->storage[1] = b;
  this->storage[2] = c;
  this->storage[3] = d;
}


void abj::Word::replace(abj::byte a, abj::byte b, abj::byte c, abj::byte d){
  this->make_word(a,b,c,d);
}

void abj::Word::rotate_word(){
  this->replace(
		  this->storage[3],
		  this->storage[0],
		  this->storage[1],
		  this->storage[2]
		  );
}


void abj::Word::print(){
  for(int i=0; i<WORD_SIZE; i++){
    abj::print_bits_of_byte(this->storage[i]);
    std::cout<<" ";
  }
  std::cout<<"\n";
}


abj::Word abj::Word::operator ^ (const abj::Word& obj){
  abj::byte a = this->storage[0] ^ obj.storage[0]; 
  abj::byte b = this->storage[1] ^ obj.storage[1]; 
  abj::byte c = this->storage[2] ^ obj.storage[2]; 
  abj::byte d = this->storage[3] ^ obj.storage[3]; 

  this->replace(a,b,c,d);
}


void abj::Word::test_function(){
  abj::Word word_one, word_two;
  word_one.make_word('a','b','c','d');
  word_two.make_word('w','x','y','z');

  abj::Word xor_word = word_one ^ word_two;

  word_one.print();
  word_two.print();
  xor_word.print();

  word_one.rotate_word();
  word_one.print();
}
