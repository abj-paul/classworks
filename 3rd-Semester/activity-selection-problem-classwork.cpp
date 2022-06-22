
// ACTIVITY SELECTION PROBLEM
// Input
/*
7
1 3
3 4
2 5
0 7
5 9
8 10
11 12
*/


#include<bits/stdc++.h>
using namespace std;

// Global Variable
#define MAX_SIZE 100
vector<pair<int,int>>all_tasks;

// Function Prototypes
void take_input();
int max_task();
void print_all_tasks();
void read_from_file(char* filename);

int main(){
  //char file[] = "1201-input-activity-selection.txt";
  //read_from_file(file);
  take_input();
  print_all_tasks();
  printf("Maximum tasks possible: %d\n",max_task());
  print_all_tasks();

  //print_all_tasks();
  return 0;
}

void take_input(){
  int n;
  //printf("Enter task number: ");
  scanf("%d",&n);

  //printf("Enter Start and end time:(Separated by space)\n");
  int start_time[MAX_SIZE], end_time[MAX_SIZE];
  for(int i=0; i<n; i++){
    scanf("%d %d",&start_time[i],&end_time[i]);
    all_tasks.push_back(make_pair(start_time[i], end_time[i]));
  }
  printf("Done taking input!\n");
}

bool CustomComparator(pair<int, int>a, pair<int,int>b){
  if(a.second==b.second) return a.first<b.first; // Ascending
  else return a.second > b.second;
}

int max_task(){
  sort(all_tasks.begin(), all_tasks.end(), CustomComparator);

  int count=1;
  int first_task=all_tasks.size()-1;
  int next_task=all_tasks.size()-2;


  while(next_task<all_tasks.size()){
    if(all_tasks[first_task].second <= all_tasks[next_task].first){
    printf("Accepted task is (%d,%d)\n",all_tasks[first_task].first, all_tasks[first_task].second);

      first_task=next_task;
      next_task--;
      count++;
    } else next_task--;
  }
    printf("Accepted task is (%d,%d)\n",all_tasks[first_task].first, all_tasks[first_task].second);


  return count;
}

void print_all_tasks(){
  printf("The tasks are: ");
  for(int i=0; i<all_tasks.size(); i++){
    printf("(%d,%d)",all_tasks[i].first, all_tasks[i].second);
    if(i!=all_tasks.size()-1) printf(",");
  }
  printf("\n");
}

void read_from_file(char filename[]){ //comma separated
  int n, start_time[MAX_SIZE], end_time[MAX_SIZE];
  FILE* myFile;
  myFile = fopen(filename,"r");
  if (myFile == NULL){
        printf("Error Reading File\n");
        exit (0);
    }

  fscanf(myFile, "%d,", &n);
  for(int i=0; i<n; i++)
    fscanf(myFile, "%d,", &start_time[i]);
  for(int i=0; i<n; i++)
    fscanf(myFile, "%d,", &end_time[i]);
  fclose(myFile);

  for(int i=0; i<n; i++){
    all_tasks.push_back(make_pair(start_time[i], end_time[i]));
  }
}
