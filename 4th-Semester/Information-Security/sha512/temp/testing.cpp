#include<iostrem>

std::uint64_t SHR(int n, std::uint64_t x){
  std::uint64_t val = x>>n;
	return val;
}

std::uint64_t ROTR(int n, std::uint64_t x){
  std::uint64_t ans = x>>n | x<<(DATA_SIZE-n);

  return ans;
}

std::uint64_t sigma_0(std::uint64_t x){
  return ROTR(1,x) ^ ROTR(8,x) ^ SHR(7,x);
}
std::uint64_t sigma_1(std::uint64_t x){
  return ROTR(19,x) ^ ROTR(61,x) ^ SHR(6,x);
}

#define RotR(x, n) ((x>>n)|(x<<((sizeof(x)<<3)-n)))
#define sig0(x) (RotR(x, 1)^RotR(x,8)^(x>>7))
#define sig1(x) (RotR(x, 19)^RotR(x,61)^(x>>6))

int main(){
	printf
return 0;
}
