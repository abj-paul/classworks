#include<iostream>
#include<stdint.h>

void temp1(){
__uint128_t x = 24;

  char* arr = (char*)&x;
  for(int i=16-1; i>=0; i--) printf("%x ",arr[i]);
  printf("\n");
}

void reverse(char* int_stream){
  unsigned char a = int_stream[0];
  unsigned char b = int_stream[1];
  unsigned char c = int_stream[2];
  unsigned char d = int_stream[3];

  unsigned char e = int_stream[4];
  unsigned char f = int_stream[5];
  unsigned char g = int_stream[6];
  unsigned char h = int_stream[7];


  int_stream[0] = h;
  int_stream[1] = g;
  int_stream[2] = f;
  int_stream[3] = e;

  int_stream[4] = d;
  int_stream[5] = c;
  int_stream[6] = b;
  int_stream[7] = a;
}

int main(){
  // Storing characters in a number
  char str[100]={'a','b','c','d','e','f','g','h'};

  std::uint64_t* num = (std::uint64_t*)malloc(sizeof(std::uint64_t));

  char* addr = (char*)num;

  for(int i=0; i<8; i++){
    *addr = str[i];
    addr++;
  }

  addr = (char*)num;
  //Now reverse it
  reverse(addr);
 

  for(int i=0; i<8; i++) printf("%x ",str[i]);
  printf("\n");
  for(int i=0; i<8; i++) printf("%x ",addr[i]);
  printf("\n");
  printf("%llx\n",*num);
  return 0;
}
