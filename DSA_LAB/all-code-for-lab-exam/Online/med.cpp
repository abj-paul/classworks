#include<bits/stdc++.h>
using namespace std;
#define MAX_WORD_SIZE 34
#define DELETION_DOWN_ARROW 1
#define INSERTION_RIGHT_ARROW 2
#define SAME_CHARACTER_DIAGONAL_ARROW 3
#define SUBSTITUTION_DIAGONAL_ARROW 4
#define TRANSPOSITION_ARROW 5
#define NO_OPERATION 6

// Function Prototypes
int minimum_edit_distance(string A, string B);
void backtracking(int i, int j, int d[][MAX_WORD_SIZE], vector<int>* backtrack_path);
void print_direction(int d[][MAX_WORD_SIZE], string A, string B);
void print_med_direction(int direction_Value);

int main(){
  string A = "fedca";
  string B = "abdde";

  cout<<minimum_edit_distance(A,B)<<endl;
  return 0;
}


int minimum_edit_distance(string A, string B){
  // Converting A to B
  int m[MAX_WORD_SIZE][MAX_WORD_SIZE];
  int direction[MAX_WORD_SIZE][MAX_WORD_SIZE];
  vector<int> backtrack_path;
  
  for(int i=0; i<=A.size(); i++) {
    m[i][0]=i;
    direction[i][0]=DELETION_DOWN_ARROW;
  }
  for(int j=0; j<=B.size(); j++){
    direction[0][j]=INSERTION_RIGHT_ARROW;
    m[0][j]=j;
  }
  direction[0][0]=NO_OPERATION;
  m[0][0]=0;

  // DONE INITIALIZING --------------------------------------
  int cost=0;
  // A,B indexing starts from 1 and m's indexing starts from 0 according to the algorithm. But our A,B starts from 0. So to compensate that, we start from 1 in the loop but subtract 1 (i-1 or j-1) when accessing A or B.
  for(int i=1; i<=A.size(); i++){
    for(int j=1; j<=B.size(); j++){
      if(A[i]==B[j]) cost=0;
      else cost=1;

      m[i][j] = std::min(m[i-1][j]+1,                //deletion
			std::min(m[i][j-1]+1,       //insertion
				 m[i-1][j-1]+cost));//substitution
      // Direction
      if(m[i][j]==m[i-1][j]+1) direction[i][j]=DELETION_DOWN_ARROW;
      else if(m[i][j]==m[i][j-1]+1) direction[i][j]=INSERTION_RIGHT_ARROW;
      else if(m[i-1][j-1]==m[i][j]) direction[i][j]=SAME_CHARACTER_DIAGONAL_ARROW;
      else if(m[i-1][j-1]+1==m[i][j]) direction[i][j]=SUBSTITUTION_DIAGONAL_ARROW;
    }
  }

  //print_direction(direction, A, B);
  backtracking(A.size(), B.size(), direction, &backtrack_path);
  // backtrack_path.reverse();
  for(int i=0; i<backtrack_path.size(); i++) print_med_direction(backtrack_path[i]);
  cout<<endl;
  
  return m[A.size()][B.size()];
}

void backtracking(int i, int j, int d[][MAX_WORD_SIZE], vector<int>* backtrack_path){
  if(i<0 || j<0) return;
  backtrack_path->push_back(d[i][j]);

  if(d[i][j]==INSERTION_RIGHT_ARROW) backtracking(i, j-1, d, backtrack_path);
  else if(d[i][j]==DELETION_DOWN_ARROW) backtracking(i-1, j, d, backtrack_path);
  else if(d[i][j]==SAME_CHARACTER_DIAGONAL_ARROW) backtracking(i-1, j-1, d, backtrack_path);
  else if(d[i][j]==SUBSTITUTION_DIAGONAL_ARROW) backtracking(i-1, j-1, d, backtrack_path);
  else if(d[i][j]==TRANSPOSITION_ARROW) backtracking(i-2, j-2, d, backtrack_path);

  return;
}

void print_direction(int d[][MAX_WORD_SIZE], string A, string B){
  for(int i=0; i<=A.size(); i++){
    for(int j=0; j<=B.size(); j++){
      print_med_direction(d[i][j]);
    }
    printf("\n");
  }
}
void print_med_direction(int direction_Value){
      if(direction_Value==INSERTION_RIGHT_ARROW) printf("IN ");
      else if(direction_Value==DELETION_DOWN_ARROW) printf("DW ");
      else if(direction_Value==SAME_CHARACTER_DIAGONAL_ARROW) printf("SM ");
      else if(direction_Value==SUBSTITUTION_DIAGONAL_ARROW) printf("ST ");
      else if(direction_Value==TRANSPOSITION_ARROW) printf("TP ");
      else if(direction_Value==NO_OPERATION) printf("NA ");
}

