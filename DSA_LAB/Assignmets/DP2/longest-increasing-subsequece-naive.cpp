
#include<bits/stdc++.h>

// Global Variable
#define MAX_SIZE 100
int len[MAX_SIZE], prev[MAX_SIZE];
std::vector<int> v;

// Function Prototypes
void take_input();
int naive_approach();
void print_array(int a[], int n);
void print_subsequence();
void print_number_recursively(int index);

int main(){
  v.push_back((int)NULL); // to make index 0 null.
  take_input();
  int ans = naive_approach();
  printf("Longest Increasing Subsequence is: %d\n",ans);
  printf("The subsequence is: ");
  print_subsequence();
  return 0;
}

void take_input(){
  int n,temp;
  scanf("%d",&n);
  for(int i=0; i<n; i++){
    scanf("%d",&temp);
    v.push_back(temp);
  }
}

int naive_approach(){
  for(int i=0; i<v.size(); i++) len[i]=0;
  for(int i=0; i<v.size(); i++) prev[i]=-1;

  for(int i=1; i<v.size(); i++){
    int j=i-1;
    len[i]=1;
    while(j>0){
      if(v[i]>=v[j]){
	if(len[j]+1>=len[i]) prev[i] = j;
	len[i] = std::max(len[i],len[j]+1);
      } 
      j--;
    }
  }

  //print_array(len, v.size()+1);

  // Find Max
  int max=-1;
  for(int i=0; i<v.size(); i++){
    if(len[i]>=max) max=len[i];
  }
  return max;
}



void print_array(int a[], int n){
  for(int i=0; i<n; i++) printf("%d ",a[i]);
  printf("\n");
}

void print_subsequence(){
  //find max
  int max=-1, max_index=-1;
  for(int i=0; i<v.size(); i++){
    if(max<=len[i]){
      max=len[i];
      max_index=i;
    }
  }

  //print_array(len, v.size()+1);
  //print_array(prev, v.size()+1);
  // Printing
  print_number_recursively(max_index);
  printf("\n");
}

void print_number_recursively(int index){
  if(index==0) return;
  print_number_recursively(prev[index]);
  if(v[index]!=0)printf("%d ",v[index]);
}
