
#include<bits/stdc++.h>
using namespace std;

// Global Variable
#define MAX_SIZE 100
int previous[MAX_SIZE];
std::vector<int> numbers;

// Function Prototypes
void take_input();
int nlogn_approach();
int binarySearch(vector<int>lis, int target);

int main(){
  take_input();
  int ans = nlogn_approach();
  printf("Longest Increasing Subsequence is: %d\n",ans);
  return 0;
}

void take_input(){
  int n,temp;
  scanf("%d",&n);
  for(int i=0; i<n; i++){
    scanf("%d",&temp);
    numbers.push_back(temp);
  }
}

int index_of_previous_element(vector<int> lis, int index){
  if(index==0) return -1;
  int target = lis[index-1];

  for(int i=0; i<numbers.size(); i++){
    if(numbers[i]==target) return i;
  }
}

int nlogn_approach(){
  for(int i=0; i<numbers.size(); i++) previous[i]=-1;

  vector<int>lis;
  lis.push_back(numbers[0]);
  for(int i=1; i<numbers.size(); i++){
    int min_index = binarySearch(lis, numbers[i]);
    if(min_index==-1) // NOT FOUND, its the max element
      lis.push_back(numbers[i]);
    else lis[min_index]=numbers[i];

    if(min_index==-1) previous[i]=index_of_previous_element(lis, lis.size()-1);
    else previous[i] = index_of_previous_element(lis, min_index);
  }


  // PRINTING
  printf("\nThe subsequence is: ");
  int last_lis_index = numbers.size()-1;
  for(int i=0; i<numbers.size(); i++){
    if(numbers[i]==lis[lis.size()-1]) {
      last_lis_index=i;
      break;
    }
  }
  for(int i=last_lis_index; i!=-1; i=previous[i]) printf("%d ",numbers[i]);
  return lis.size();
}

int binarySearch(vector<int>lis, int target){
  int low=0, high=lis.size()-1;
  int ans = INT_MAX;
  while(low<=high){
    int mid = low + (high-low)/2;
    if(lis[mid]>=target) {
      high = mid - 1;
      ans = min(ans, mid);;
    } else low = mid + 1;
  }

  if(ans==INT_MAX) return -1;
  return ans;
}
