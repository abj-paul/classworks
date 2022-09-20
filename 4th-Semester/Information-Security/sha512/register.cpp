#include "register.h"

void Register::store(std::uint64_t data){
  this->storage = data;
}

std::uint64_t Register::get_data_dump() const{
  return this->storage;
}

void Register::print_hex(){
  printf("%llx\n",this->storage); // THIS PORTION IS NOT PORABLE!!!!!!!!!
}
void Register::print_bin(){
  std::uint64_t old = this->storage;
  
  bool bits[DATA_SIZE];
  int i = 0;
  while(i<DATA_SIZE){
    bool bit = (old>>i) & 1;
    bits[i]=bit;
    i++;
  }

  for(int i=DATA_SIZE-1; i>=0; i--) std::cout<<bits[i];
  printf("\n");
}

Register Register::operator^(const Register v){
  std::uint64_t temp = this->storage^v.get_data_dump();
  Register r;
  r.store(temp);
  return r;
}


Register Register::ch(Register e, Register f, Register g){
  //(e AND f) (NOT e AND g)
  std::uint64_t ans = (e.get_data_dump() & f.get_data_dump()) ^ ((~e.get_data_dump()) & g.get_data_dump());

  Register r;
  r.store(ans);
  return r;
}

Register Register::maj(Register a, Register b, Register c){
  //(a AND b) (a AND c) (b AND c)
  std::uint64_t ans = (a.get_data_dump() & b.get_data_dump())^(a.get_data_dump() & c.get_data_dump())^(b.get_data_dump() & c.get_data_dump());

  Register r;
  r.store(ans);
  return r;
}

Register Register::SHR(int n, Register x){
  std::uint64_t val = x.get_data_dump()>>n;

  Register r;
  r.store(val);
  return r;
}



Register Register::ROTR(int n, Register x){
  std::uint64_t ans = x.get_data_dump()>>n | x.get_data_dump()<<(DATA_SIZE-n);

  Register r;
  r.store(ans);
  return r;
}

Register Register::sigma_0(Register x){
  return ROTR(1,x) ^ ROTR(8,x) ^ SHR(7,x);
}
Register Register::sigma_1(Register x){
  return ROTR(19,x) ^ ROTR(61,x) ^ SHR(6,x);
}


Register Register::sum(int upper_sum_val, int lower_sum_val, Register x){
  if(lower_sum_val==0) return ROTR(28,x) ^ ROTR(34,x) ^ ROTR(39,x);
  else if(lower_sum_val==1) return ROTR(14,x) ^ ROTR(18,x) ^ ROTR(41,x);
  else printf("Unknown lower sum value! Exiting...\n"),exit(1);
}


void Register::test_function(){
  printf("Testing register module: %s\n",DIVIDER);
  printf("Testing XOR:\n");
  Register a,b,c;
  a.store(0x2a00444400004444LL);
  b.store(0x08675309);
  a.print_bin();
  b.print_bin();

  c = a^b;
  c.print_bin();

  printf("Testing maj and ch:\n");

  a.store(0b01100110101);
  b.store(0b00101010000);
  c.store(0b01101010000);

  a.print_bin();
  b.print_bin();
  c.print_bin();
  maj(a,b,c).print_bin();
  ch(a,b,c).print_bin();

  printf("Testing ROTR: \n");
  a.store(0xa1cd4ef4ab094134LL);
  a.print_bin();
  ROTR(2,a).print_bin();

  a.store(0x510E527FADE682D1);
  printf("Testing sum(512,0):\n");
  a.print_hex();
  a.print_bin();
  Register temp;
  temp.store(a.get_data_dump());
  sum(512,0,a).print_bin();
  sum(512,0,a).print_hex();

  printf("Manually doing it:\n");
  ROTR(28,temp).print_bin();
  ROTR(34,temp).print_bin();
  ROTR(39,temp).print_bin();
  printf("Do they match?They do!\n");

  printf("Testing sum(512,1):\n");
  a.print_bin();
  temp.store(a.get_data_dump());
  sum(512,1,a).print_bin();
  sum(512,1,a).print_hex();

  printf("Manually doing it:\n");
  ROTR(14,temp).print_bin();
  ROTR(18,temp).print_bin();
  ROTR(41,temp).print_bin();
  printf("Do they match?They do!\n");

  
}
