#include<string>
#include<vector>
#include<iostream>


int main(){
  const char PAD_CHAR = '*';
  
  //Taking Input
  std::string str;
  getline(std::cin, str); 

  //Splitting it into blocks
  std::vector<std::string> v;
  for (unsigned i = 0; i < str.length(); i += 16) {
    v.push_back(str.substr(i, 16));
  }

  // Padding
  if(v.back().size()<16){
    for(int i=v.back().size(); i<16; i++) v[v.size()-1] = v.back() + PAD_CHAR;
  }
  for(int i=0; i<v.size(); i++) std::cout<<v[i]<<std::endl;
  return 0;
}
