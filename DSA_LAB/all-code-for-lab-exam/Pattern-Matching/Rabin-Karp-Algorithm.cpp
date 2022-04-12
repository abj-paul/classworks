#include<bits/stdc++.h>
using namespace std;

#define NO_PREV_HASH -1

int to_int(char c);
vector<int> Rabin_Karp_algorithm(string pattern, string text);

// Different Hash Functions
int rolling_hash_int(string arr, int start_index, int end_index, int prev_hash, int number_of_alphabets);
int rolling_hash_coded(string arr, int start_index, int end_index, int prev_hash){

int main(){
  string text="acaabaabcaacaabc";
  string pattern="aab";
  cout<<"Text="<<text<<endl;
  cout<<"Pattern="<<pattern<<endl;

  vector<int>occurences = Rabin_Karp_algorithm(pattern, text);
  for(int i=0; i<occurences.size(); i++) cout<<occurences[i]<<" ";
  cout<<endl;
  return 0;
}

vector<int> Rabin_Karp_algorithm(string pattern, string text){
  vector<int>pattern_occurence_indices;
  int number_of_alphabets=3;
  
  int n = text.size();
  int m = pattern.size();
  int hash_pattern = rolling_hash_int(pattern, 0, pattern.size()-1, NO_PREV_HASH, number_of_alphabets);
  int hash_text = rolling_hash_int(text, 0, m-1, NO_PREV_HASH, number_of_alphabets);

  for(int s=0; s<=n-m; s++){
    // printf("DEBUG: hash value=%d\n",hash_text);
    if(hash_pattern==hash_text){
      if(pattern.compare(text.substr(s,m))==0){
	printf("Valid hit at shift %d.\n",s);
	pattern_occurence_indices.push_back(s);
      }else{
	printf("Spurious hit at shift %d.\n",s);
      }
    }
    if(s<n-m){
      hash_text = rolling_hash_int(text, s+1, s+1+m-1, hash_text, number_of_alphabets);
    }
  }
  return pattern_occurence_indices;
}


// NOT PART OF ALGO, just different hashing functions

int rolling_hash_int(string arr, int start_index, int end_index, int prev_hash, int number_of_alphabets){
  int sum=0;
  if(prev_hash==NO_PREV_HASH){
    for(int i=start_index; i<=end_index; i++){
      sum = sum*number_of_alphabets + to_int(arr[i]);
    }
  }else{
    int pattern_size = end_index - start_index + 1;
    sum = ( prev_hash-to_int(arr[start_index-1])*pow(number_of_alphabets,pattern_size-1) )*number_of_alphabets + to_int(arr[end_index]);
  }
  return sum;
}

int rolling_hash_coded(string arr, int start_index, int end_index, int prev_hash){
  int new_hash=0;
  if(prev_hash==NO_PREV_HASH) {
    for(int i=start_index; i<=end_index; i++) new_hash += to_int(arr[i]);
  }
  else new_hash = prev_hash - to_int(arr[start_index-1]) + to_int(arr[end_index]);

  return new_hash;
}

int to_int(char c){
  return c-'a'+1;
}
