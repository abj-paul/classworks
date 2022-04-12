
#include<bits/stdc++.h>
#define MAX_SIZE 50

// Global Variables
std::vector<int>coin;
int given_weight;

// Function Prototype
int maximum_ways_to_change_coin();
void take_input();
void initialize();

int main(){
  initialize();
  take_input();
  int ans = maximum_ways_to_change_coin();
  printf("Maximum number of ways=%d\n",ans);
  
  return 0;
}

void initialize(){
  coin.push_back((int)NULL);
}

void take_input(){
  int num_of_coin=0;
  std::cin>>num_of_coin;
  for(int i=0; i<num_of_coin; i++){
    int x;
    std::cin>>x;
    coin.push_back(x);
  }
  std::cin>>given_weight;
}

int maximum_ways_to_change_coin(){
  int ways[MAX_SIZE][MAX_SIZE];

  // Initializing
  for(unsigned int i=0; i<=coin.size(); i++) ways[i][0]=1;
  for(int i=0; i<=given_weight; i++) ways[0][i]=0;

  // Algorithm
  for(unsigned int i=1; i<=coin.size(); i++){
    for(int j=1; j<=given_weight; j++){
      if(j<coin[i]) ways[i][j]=ways[i-1][j];
      else ways[i][j] = ways[i-1][j] + ways[i][j-coin[i]];
    }
  }
  return ways[coin.size()][given_weight];
}
