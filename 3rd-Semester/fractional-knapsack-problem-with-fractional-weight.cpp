// FRACTIONAL KNAPSACK PROBLEM
/* INPUT
7
10 2
5 3
15 5
7 7
6 1
18 4
3 1
15
*/


#include<bits/stdc++.h>
using namespace std;

struct object {
  float weight;
  int profit;
  float per_kg_profit;
};

// Global Variables
vector<object> all_objects;
int knapsack_size;
#define MAX_SIZE 1000000

// Function Prototypes
void take_input();
void print_all_objects();
bool comparator(struct object a, struct object b);
float find_max_profit();
void debug_message(char message[100]);
void read_from_file(char filename[]);


int main(){
  //char file[] = "1201-input-fractional-knapsack.txt";
  //read_from_file(file);
  take_input();
  //print_all_objects();
  printf("Max profit: %.2f\n",find_max_profit());
  return 0;
}

void take_input(){
  int n; // Number of objects
  scanf("%d",&n);
  struct object* obj = (struct object*)malloc(sizeof(struct object));

  for(int i=0; i<n; i++){
    scanf("%d",&obj->profit);
    scanf("%f",&obj->weight);
    obj->per_kg_profit = (float)obj->profit / (float)obj->weight;

    all_objects.push_back(*obj);
  }
  scanf("%d",&knapsack_size);
}

void print_all_objects(){
  int n=all_objects.size();
  printf("Format(profit,weight,per kg profit): ");
  for(int i=0; i<n; i++){
    printf("(%d,%f,%.2f)",all_objects[i].profit, all_objects[i].weight,all_objects[i].per_kg_profit);
  }
  printf("\nKnapsack Size: %d",knapsack_size);
  printf("\n");
}

bool comparator(struct object a, struct object b){
  if(a.per_kg_profit==b.per_kg_profit) return a.weight<b.weight;
  else return a.per_kg_profit>b.per_kg_profit;
}

float find_max_profit(){
  sort(all_objects.begin(), all_objects.end(), comparator);

  float profit=0;
  float weight=0;
  int i=0;
  while(weight<=knapsack_size){
    weight=weight+all_objects[i].weight;
    if(weight<=knapsack_size){
      profit=profit + all_objects[i].profit;
      printf("Taking object %d: Weight=%f, profit=%.2d\n",i,all_objects[i].weight, all_objects[i].profit);
    }else{
      weight=weight-all_objects[i].weight;
      float left_space = knapsack_size-weight;
      if(left_space==0) break;
      else{
	profit = profit + all_objects[i].per_kg_profit * left_space;
	weight+=left_space;
	printf("Taking object %d: Weight=%f, profit=%.2f\n",i,left_space, all_objects[i].per_kg_profit*left_space);
      }
    }
    i++;
  }
  return profit;
}

void debug_message(char message[100]){
  printf("%s",message);
}

void read_from_file(char filename[]){ //comma separated
  int n, profit[MAX_SIZE], weight[MAX_SIZE];
  FILE* myFile;
  myFile = fopen(filename,"r");
  if (myFile == NULL){
        printf("Error Reading File\n");
        exit (0);
    }

  fscanf(myFile, "%d,", &n);  // number of objects
  fscanf(myFile, "%d", &knapsack_size);

  for(int i=0; i<n; i++)
    fscanf(myFile, "%d,", &profit[i]);
  for(int i=0; i<n; i++)
    fscanf(myFile, "%d,", &weight[i]);
  fclose(myFile);

  for(int i=0; i<n; i++){
      struct object* obj = (struct object*)malloc(sizeof(struct object));
      obj->profit=profit[i];
      obj->weight=weight[i];
      obj->per_kg_profit = (float)obj->profit / (float)obj->weight;

      all_objects.push_back(*obj);
  }

}

