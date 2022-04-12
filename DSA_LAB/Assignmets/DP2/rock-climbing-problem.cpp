
#include<bits/stdc++.h>
#define MAX_SIZE 50
#define INF 99

int row, col, risk[MAX_SIZE][MAX_SIZE];
int min_risk[MAX_SIZE][MAX_SIZE];

// Function Prototypes
int find_minimum_risk();
void take_input();
void initialize();
void print_matrix(int arr[][MAX_SIZE], int row, int col);
int min_value_index(int i, int j, int m[][MAX_SIZE]);
void print_steps(int i, int j);

int main(){
  initialize();
  take_input();
  int ans = find_minimum_risk();
  printf("\n");
  printf("Minimum risk=%d\n",ans);
  return 0;
}

void initialize(){
  for(int i=0; i<row; i++){
    risk[i][0]=INF;
    risk[i][col+1]=INF;
  }
  for(int i=0; i<col; i++) risk[0][i]=0;
}

void take_input(){
  std::cin>>row>>col;

  int curr_risk;
  for(int i=1; i<=row; i++){
    for(int j=1; j<=col; j++){
      std::cin>>curr_risk;
      risk[i][j]=curr_risk;
    }
  }
}

int find_minimum_risk(){
  
  // Initialize
  for(int i=0; i<=row; i++){
    min_risk[i][0]=INF;
    min_risk[i][col+1]=INF;
  }
  for(int i=1; i<=col; i++) min_risk[row][i]=risk[row][i];

  
  for(int i=row-1; i>=1; i--){
    for(int j=1; j<=col; j++){
      min_risk[i][j] = std::min(min_risk[i+1][j-1], std::min(min_risk[i+1][j], min_risk[i+1][j+1]) ) + risk[i][j];
    }
  }

  // Finding Answer
  int min_index=0;
  for(int i=0; i<=col; i++){
    if(min_risk[1][i]<min_risk[1][min_index]) min_index=i;
  }

  print_steps(1,min_index);

  //  print_matrix(min_risk, row, col+1);
  return min_risk[1][min_index];
}

void print_matrix(int arr[][MAX_SIZE], int row, int col){
  for(int i=0; i<=row; i++){
    for(int j=0; j<=col; j++) printf("%d ",arr[i][j]);
    printf("\n");
  }
}

void print_steps(int i, int j){
  if(i>row || j>col) return;
  printf("%d->",risk[i][j]);

  print_steps(i+1, min_value_index(i+1, j, min_risk));
}

int min_value_index(int i, int j, int m[][MAX_SIZE]){
  int first_min=0;
  if(m[i][j-1]<m[i][j]) first_min=j-1;
  else first_min=j;

  int second_min=0;
  if(m[i][first_min]<m[i][j+1]) second_min=first_min;
  else second_min=j+1;

  return second_min;
}
