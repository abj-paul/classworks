
#include<bits/stdc++.h>
using namespace std;

// Global Variable
#define MAX_SIZE 100
vector<int> num;

// Function Prototype
void take_input();
void lis_modified();
void recursively_print(int index, vector<int>prev);
void print_vector(vector<int> x, const char* msg);
int immediate_previous_index(vector<int>L, int last_index);
int bs(int L[], int x, int L_size);
void lis_modified_bs();
void print_array(int a[], int n, const char* msg);
int immediate_previous_index_2(int L[], int L_size, int last_index);


int main(){
  num.push_back((int)NULL);
  take_input();
  lis_modified();
  
  return 0;
}

void take_input(){
  int n,x;
  scanf("%d",&n);
  for(int i=0; i<n; i++){
    scanf("%d",&x);
    num.push_back(x);
  }
}

void lis_modified(){
  vector<int>prev(num.size());
  vector<int>L;

  prev[0]=-1;
  for(int i=1; i<num.size(); i++){
    if(L.size()==0) {
      L.push_back(num[i]);
      prev[i]=-1;
    }
    else {
      int j=L.size()-1;
      while(num[i]<L[j] && j>=0){
	j--;
      }
      if(j+1>=L.size()){
	L.push_back(num[i]);
      }else L[j+1]=num[i];
      prev[i] = immediate_previous_index(L,j+1);
    }
    //    print_vector(L,"Debug: ");
  }

  // Recursively Print
  //print_vector(prev,"Previous Vector:\n");
  //print_vector(L, "L Vector:\n");
  printf("Output is: ");
  recursively_print(L[L.size()-1],prev);
  printf("\n");
}

int immediate_previous_index(vector<int>L, int last_index){
  if(L.size()==0) return -1;
  else if(L.size()==1) return -1;
  else if(last_index==0) return -1;

  int number = L[last_index-1];
  for(int j=0; j<num.size(); j++){
    if(num[j]==number) return j;
  }
  return -1;
}

void recursively_print(int index, vector<int>prev){
  if(index==-1) return;
  printf("%d ",num[index]);
  recursively_print(prev[index],prev);
}

void print_vector(vector<int> x, const char* msg){
  printf("%s",msg);
  for(int i=0; i<x.size(); i++) printf("%d,",x[i]);
  printf("\n");
}


void lis_modified_bs(){
  vector<int>prev(num.size());
  int L[MAX_SIZE],L_size=0;

  prev[0]=-1;
  for(int i=1; i<num.size(); i++){
    if(L_size==0) {
      L[0]=num[i];
      prev[i]=-1;
      L_size++;
    }
    else {
      int j = bs(L,num[i],L_size);
      printf("J=%d, L.size()=%d\n",j,L_size);
      if(num[i]>L[j]) {L[j+1]=num[i];L_size++;}
      else L[j]=num[i];
      prev[i] = immediate_previous_index_2(L,L_size,j-1);
    }
    //    print_array(L,L_size,"Debug: ");
  }

  // Recursively Print
  //print_vector(prev,"Previous Vector:\n");
  //print_array(L,L_size, "L Vector:\n");
  printf("Output is: ");
  recursively_print(L[L_size-1],prev);
  printf("\n");
}

int bs(int L[], int num, int L_size){
  int s=0, e=L_size-1, flag=0;
  while(s<=e){
    int mid=(s+e)/2;
    if(L[mid]==num){
      flag=1;
      //printf("Found it at %d.\n",mid);
      return mid;
    }else if(L[mid]>num) e=mid-1;
    else s=mid+1;
  }
  //if(flag==0)printf("Not found. End indes of s=%d, e=%d.\n",s,e); //start
  return s;
}

void print_array(int a[], int n, const char* msg){
  printf("%s",msg);
  for(int i=0; i<n; i++) printf("%d ",a[i]);
  printf("\n");
}
int immediate_previous_index_2(int L[], int L_size, int last_index){
  if(L_size==0) return -1;
  else if(L_size==1) return -1;
  else if(last_index==0) return -1;

  int number = L[last_index-1];
  for(int j=0; j<num.size(); j++){
    if(num[j]==number) return j;
  }
  return -1;
}
