#include<bits/stdc++.h>
using namespace std;

vector<int> naive_approach(string pattern, string text);

int main(){
  string text="acaabaabcaacaabc";
  string pattern="aab";
  cout<<"Text="<<text<<endl;
  cout<<"Pattern="<<pattern<<endl;

  vector<int>occurences = naive_approach(pattern, text);
  for(int i=0; i<occurences.size(); i++) cout<<occurences[i]<<" ";
  cout<<endl;
  return 0;
}

// Returns the indices of pattern occurence
vector<int> naive_approach(string pattern, string text){
  vector<int>pattern_occurence_indices;
  
  int n = text.size();
  int m = pattern.size();
  
  for(int s=0; s<=n-m; s++){
    if(pattern.compare(text.substr(s,m))==0){
      printf("Pattern found with shift %d.\n",s);
      pattern_occurence_indices.push_back(s);
    }
  }
  return pattern_occurence_indices;
}
