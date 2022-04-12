#include<bits/stdc++.h>
using namespace std;

#define INF 10000
#define MAX_SIZE 100
// Input Variable
vector<int> profit;
vector<int> max_profit(MAX_SIZE, -INF);
int rod_size;

int  top_down_rod_cutting(int piece);
void take_input();


int main(){
  take_input();

  // Algorithm
  max_profit[0]=0;
  cout<<"Max profit="<<top_down_rod_cutting(rod_size);
  
  return 0;
}

int  top_down_rod_cutting(int piece){
  if(max_profit[piece]>=0) return max_profit[piece];

  int max_revenue = -INF;
  for(int i=1; i<=min((int)max_profit.size()-1, piece); i++){
    max_revenue = max(max_revenue, profit[i]+top_down_rod_cutting(piece-i));
  }
  max_profit[piece]=max_revenue;
  return max_profit[piece];
}

void take_input(){
  int vector_size;
  cin>>vector_size;

  for(int i=0; i<vector_size; i++){
    int current_profit;
    cin>>current_profit;
    profit.push_back(current_profit);
  }
  cin>>rod_size;
}
