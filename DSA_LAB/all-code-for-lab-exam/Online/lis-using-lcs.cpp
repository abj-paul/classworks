
#include<bits/stdc++.h>
using namespace std;

// Global Variables
#define MAX_SIZE 100
int arr[MAX_SIZE],N;

// Function Prototypes
void take_input();
int longest_common_subsequence(int A[], int B[], int n);
void copy_and_sort(int original[], int new_arr[], int n);

int main(){
  take_input();
  int temp[MAX_SIZE];
  copy_and_sort(arr, temp, N);
  int ans = longest_common_subsequence(arr, temp, N);
  printf("Longest Increasing Subsequence: %d\n",ans);
  return 0;
}


// B is sorted
int longest_common_subsequence(int A[], int B[], int n){
  int c[MAX_SIZE][MAX_SIZE];
  for(int i=0; i<=n; i++) c[i][0]=0;
  for(int i=0; i<=n; i++) c[0][i]=0;

  for(int i=1; i<=n; i++){
    for(int j=1; j<=n; j++){
      if(A[i-1]==B[j-1]) c[i][j]=c[i-1][j-1]+1;
      else c[i][j] = max(c[i-1][j],c[i][j-1]);
    }
  }
  return c[n][n];
}

void take_input(){
  scanf("%d",&N);
  for(int i=0; i<N; i++) scanf("%d",&arr[i]);
}

void copy_and_sort(int original[], int new_arr[], int n){
  for(int i=0; i<n; i++) new_arr[i] = original[i];
  sort(new_arr, new_arr+n);
}
