// Source: https://www.codesdope.com/course/algorithms-rod-cutting/
#include<bits/stdc++.h>
using namespace std;

#define INF 100000
#define MAX_SIZE 100000
int maximum_profit[MAX_SIZE];
int parent[MAX_SIZE];

// Input Variable
int profit_array_size, rod_size;
int given_profit[MAX_SIZE];
// Function Prototypes
int max_profit(int piece_size);
void print_input();
void take_input();
void initialize();
void print_path();
int max_profit_save_path(int piece_size);

int main(){
  take_input();
  print_input();
  initialize();
  cout<<"Max Profit="<<max_profit_save_path(rod_size)<<endl;
  print_path();
  return 0;
}

void initialize(){
  for(int i=0; i<MAX_SIZE; i++) {
    maximum_profit[i]=-1*INF;
    parent[i]=i;
  }
}
void take_input(){
  cin>>profit_array_size;
  for(int i=0; i<profit_array_size; i++) cin>>given_profit[i];
  cin>>rod_size;
}
void print_input(){
  cout<<profit_array_size<<endl;
  for(int i=0; i<profit_array_size; i++) cout<<given_profit[i]<<" ";
  cout<<endl;
  cout<<rod_size<<endl;
}

int max_profit(int piece_size){
    if(maximum_profit[piece_size]>=0) return maximum_profit[piece_size];

    int maximum_revenue = 0;
    for(int i=1; i<=piece_size; i++){
      int cost = given_profit[i]+max_profit(piece_size-i);
      maximum_revenue = max(maximum_revenue, cost);
      //printf("Piece:(%d,%d)=%d\n",i,piece_size-i, cost);
    }
    maximum_profit[piece_size] = maximum_revenue;
    return maximum_profit[piece_size];
}


int max_profit_save_path(int piece_size){
    if(maximum_profit[piece_size]>=0) return maximum_profit[piece_size];

    int maximum_revenue = 0;
    int max_index=piece_size;
    for(int i=1; i<=piece_size; i++){
      int cost = given_profit[i]+max_profit(piece_size-i);
      if(cost>maximum_revenue){
	maximum_revenue = cost;
	max_index = i;
      }
      // printf("Piece:(%d,%d)=%d\n",i,piece_size-i, cost);
    }
    maximum_profit[piece_size] = maximum_revenue;
    parent[piece_size]=max_index;
    return maximum_profit[piece_size];
}

void print_path(){
  printf("Format:(size,cost).\n");
  int iteration_count=0;
  int i;
  while(rod_size>=0 || i!=0){
    for(i=parent[rod_size]; i!=parent[i]; i=parent[i]){
      if(i!=0)printf("(%d,%d),(%d,%d)\n",i, maximum_profit[i]);
    }
    if(i!=0) printf("(%d,%d),",i, maximum_profit[i]); // For the one whose i = parent[i]
    rod_size-=i;
  iteration_count++;
  if(iteration_count>=20) break;
  }

  printf("\n");
}

void recursively_print_path(int piece){
}
