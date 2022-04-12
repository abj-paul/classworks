
#include<bits/stdc++.h>
using namespace std;

// Global Variable
#define INF 1000000
#define MAX_SIZE 100
int k_table[MAX_SIZE][MAX_SIZE];

struct meta_data {
  int row;
  int col;
  int input_serial;
};
vector<meta_data>db;


// Function Prototype
void take_input();
void print_db();
void print_input();
bool is_eligible_for_multiplication();
void clear_heap();
int minimum_multiplication();
void print_matrix(int m[][MAX_SIZE], int n);
void print_array(int a[], int n);
int minimum_multiplication_save_states();
void print_multiplication_way();

int main(){
  take_input();
  print_input();
  if(is_eligible_for_multiplication()){
    //clear_heap();
    int ans = minimum_multiplication_save_states();
    printf("Minimum multiplication required is: %d\n",ans);
  }else printf("Not eligible for multiplication!\n");

  print_multiplication_way();
  
  return 0;
}

void take_input(){
  int number_of_matrices;
  scanf("%d",&number_of_matrices);

  int row, col, index=0;
  for(int i=0; i<number_of_matrices; i++){
    scanf("%d %d",&row,&col);
    struct meta_data* m = (struct meta_data*)malloc(sizeof(struct meta_data));
    m->row=row;
    m->col=col;
    m->input_serial=index;
    db.push_back(*m);

    index++;
  }
}

void print_input(){
  printf("Printing the input: \n");
  print_db();
}

void print_db(){
  for(int i=0; i<db.size(); i++){
    printf("(%d,%d,%d)",db[i].input_serial, db[i].row, db[i].col);
    if(i!=db.size()-1) printf(",");
  }
  printf("\n");
}

void clear_heap(){
  printf("Clearing heap.\n");
  for(int i=0; i<db.size(); i++){
    free(&db[i]);
  }
  printf("Freed the heap allocation.");
}

bool is_eligible_for_multiplication(){
  if(db.size()<2) return false;
  
  int last_col=db[0].col, current_row=0;
  for(int i=1; i<db.size(); i++){
    current_row=db[i].row;
    if(current_row!=last_col) return false;
    last_col=db[i].col;
  }
  return true;
}

int minimum_multiplication(){
  int c[MAX_SIZE][MAX_SIZE], d[MAX_SIZE];

  // Building serial array
  int i2=0;
  for(int i=0; i<db.size(); i++){
    if(d[i2-1]!=db[i].row){
      d[i2]=db[i].row;
      i2++;
      d[i2]=db[i].col;
      i2++;
    }
  }
  d[i2]=db[db.size()-1].col;

  // Initializing count matrix
  for(int i=1; i<=db.size(); i++) c[i][i]=0;
  for(int i=1; i<=db.size(); i++){
    for(int j=1; j<=db.size(); j++){
      if(i!=j) c[i][j]=INF;
    }
  }

  // Building count matrix
  // L=Chain Length
  for(int L=1; L<=db.size(); L++){
    for(int i=1; i<=db.size()-L; i++){
      int j=i+L;
      for(int k=1; k<j; k++){
	int ans = c[i][k]+c[k+1][j]+d[i-1]*d[k]*d[j];
	c[i][j] = min(c[i][j],ans);
      }
    }
  }
  
  //print_array(d,db.size());
  //print_matrix(c,db.size());
  return c[1][db.size()];

}

void print_matrix(int m[][MAX_SIZE], int n){
  printf("The matrix is:\n");
  for(int i=1; i<=n; i++){
    for(int j=1; j<=n; j++){
      printf("%d",m[i][j]);
      if(j!=n)printf(",");
    }
    printf("\n");
  }
}

void print_array(int a[], int n){
  for(int i=0; i<=n; i++){
    printf("%d",a[i]);
    if(i!=n) printf(",");
  }
  printf("\n");
}

int minimum_multiplication_save_states(){
  int c[MAX_SIZE][MAX_SIZE], d[MAX_SIZE];

  // Building serial array
  int i2=0;
  for(int i=0; i<db.size(); i++){
    if(d[i2-1]!=db[i].row){
      d[i2]=db[i].row;
      i2++;
      d[i2]=db[i].col;
      i2++;
    }
  }
  d[i2]=db[db.size()-1].col;

  // Initializing count matrix
  for(int i=1; i<=db.size(); i++) c[i][i]=0;
  for(int i=1; i<=db.size(); i++){
    for(int j=1; j<=db.size(); j++){
      if(i!=j) c[i][j]=INF;
    }
  }

  // Building count matrix
  // L=Chain Length
  for(int L=1; L<=db.size(); L++){
    for(int i=1; i<=db.size()-L; i++){
      int j=i+L;
      k_table[i][j] = 1; //Initializing
      for(int k=1; k<j; k++){
	int ans = c[i][k]+c[k+1][j]+d[i-1]*d[k]*d[j];
	if(c[i][j]>ans) k_table[i][j]=k;
	c[i][j] = min(c[i][j],ans);
      }
    }
  }
  
  //print_array(d,db.size());
  //print_matrix(c,db.size());
  print_matrix(k_table, db.size());
  return c[1][db.size()];

}

void print_multiplication_way(){
  vector<pair<int,int>>parenthesis(db.size());
  int LEFT_PARENTHESIS=1, RIGHT_PARENTHESIS=-1;


  for(int j=db.size(); j>=1; j--){
    parenthesis[k_table[1][j]].second+=RIGHT_PARENTHESIS;
    parenthesis[k_table[1][j]+1].first+=LEFT_PARENTHESIS;

    parenthesis[1].first = LEFT_PARENTHESIS;
    parenthesis[j].second = RIGHT_PARENTHESIS;
  }


  for(int i=1; i<=db.size(); i++){
    while(parenthesis[i].first>0){
      printf("(");
      parenthesis[i].first--;
    }
    printf(" A%d ",i);
    while(parenthesis[i].second<0){
      printf(")");
      parenthesis[i].second++;
    }
  }
printf("\n");
}
