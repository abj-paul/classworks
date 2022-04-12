
#include<bits/stdc++.h>

// Global Variables
#define MAX_SIZE 30
#define INF 100;
std::vector<int> coin;
int given_weight;
int m[MAX_SIZE][MAX_SIZE];

// Function Prototypes
int minimum_coins();
void take_input();
void initialize();
void print_coins(int m[][MAX_SIZE], int i, int j);
void print_vector(std::vector<int>v);
void print_matrix();


int main(){
  initialize();
  take_input();
  int ans = minimum_coins();
  printf("Minimum coins for the exchange = %d\n",ans);
  print_coins(m, coin.size(), given_weight);
  printf("\n");
  //  print_vector(coin);
  //print_matrix();
  return 0;
}

void initialize(){
  coin.push_back((int)NULL);
}

void take_input(){
  int n,x;
  std::cin>>n;
  for(int i=0; i<n; i++){
    std::cin>>x;
    coin.push_back(x);
  }
  std::cin>>given_weight;
}

int minimum_coins(){
  std::sort(coin.begin(), coin.end());
  //initialze
  for(int j=1; j<=given_weight; j++) m[0][j]=INF;
  for(int i=0; i<coin.size(); i++) m[i][0]=0;

  // Algorithm
  for(int i=1; i<coin.size(); i++){
    for(int j=1; j<=given_weight; j++){
      if(coin[i]>j) m[i][j]=m[i-1][j];
      else m[i][j] = std::min(m[i-1][j], 1+m[i][j-coin[i]]);
    }
  }

  return m[coin.size()-1][given_weight];

}

void print_coins(int m[][MAX_SIZE], int i, int j){
  if(i==0 || j==0) return;
  if(m[i][j]==m[i-1][j]) print_coins(m,i-1,j);
  else if(m[i][j]<m[i-1][j]){
    if(m[i][j]!=0)printf("%d ",coin[i]);
    print_coins(m, i-1, j-coin[i]);
  }
  else return;// ERROR
}

void print_vector(std::vector<int>v){
  for(int i=0; i<v.size(); i++) printf("%d ",v[i]);
  printf("\n");
}

void print_matrix(){
  for(int i=0; i<coin.size(); i++){
    for(int j=0; j<=given_weight; j++) printf("%d ",m[i][j]);
    printf("\n");
  }
}

