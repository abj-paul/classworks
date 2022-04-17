//https://www.geeksforgeeks.org/cyk-algorithm-for-context-free-grammar/
#include<bits/stdc++.h>
using namespace std;

// Global Variable
const int MAX_SIZE=100;
#define EPSILON "e"
#define cell vector<string>
vector<string> EMPTY_SET;
vector<vector<cell>>cyk_table; 

// Function Definitions
vector<string> fetch_nonTerminal(string state, vector<vector<string>>productions, vector<string>nonTerminal);
vector<string> operator*(const vector<string>& A, const vector<string>& B); // {A,C} * {B,D} = {AB AD CB CD}
vector<string> valid_kartesian_productions(int i,int j, vector<vector<string>>productions, vector<string>nonTerminal);

void initialize(int string_length);
bool run(string input);

void print_CYK_table(string input);


int main(){
    string input;
    cin>>input;
    cout<<"Ans:"<<run(input)<<endl;
    print_CYK_table(input);

  return 0;
}

bool run(string input){
  initialize(input.size());
  
    int number_of_rules = 4;
    string start_symbol = "S";
    vector<string>nonTerminal = {"S","A","B", "C"};
    vector<vector<string>> productions = {
        {"AB","BC"},
        {"BA", "a"},
        {"CC","b"},
        {"AB","a"}
    };


    // STEP 2
    if(input==EPSILON){
        vector<string>matches = fetch_nonTerminal(input, productions, nonTerminal);
        for(int i=0; i<matches.size(); i++)
	  if(matches[i]==EPSILON){
	    printf("Epsilon inserted and accepted.\n");
	    return true;
	  }
    }

    // STEP 3
    for(int i=0; i<input.size(); i++){
      string temp(1,input[i]);
      cyk_table[i][i] = fetch_nonTerminal(temp, productions, nonTerminal);
    }

    // STEP 4
    int n = input.size();
    for(int l=2; l<=n; l++){
      for(int i=0; i<n-l+1; i++){
	int j = i+l-1;
	cyk_table[i][j] = valid_kartesian_productions(i,j, productions, nonTerminal);
      }
    }

    //Step 5
    // Does X15 contains S
    if(find(cyk_table[0][n-1].begin(), cyk_table[0][n-1].end(), start_symbol)!=cyk_table[0][n-1].end()) return true;
    else return false;
}

vector<string> fetch_nonTerminal(string state, vector<vector<string>>productions, vector<string>nonTerminal){
    vector<string>matches;
    for(int i=0; i<productions.size(); i++){
        for(int j=0; j<productions[i].size(); j++){
            if(state==productions[i][j]) matches.push_back(nonTerminal[i]);
        }
    }
    return matches;
}



vector<string> operator*(const vector<string>& A, const vector<string>& B){ // {A,C} * {B,e} = {AB AD CB CD}
  vector<string>ans = {EPSILON};

  //A=e

  for(int i=0; i<A.size(); i++){
    for(int j=0; j<B.size(); j++){
      if(A[i]==EPSILON || B[j]==EPSILON)  continue;
      string concatenated_string = A[i]+B[j];
      ans.push_back(concatenated_string);
    }
  }

  return ans;
}

vector<string> operator+(const vector<string>& A, const vector<string>& B){ // {A,C} * {B,D} = {AB AD CB CD}
  set<string>temp;

  for(int i=0; i<A.size(); i++) temp.insert(A[i]);
  for(int i=0; i<B.size(); i++) temp.insert(B[i]);

  vector<string>ans(temp.begin(), temp.end());

  return ans;
}


vector<string> valid_kartesian_productions(int i,int j, vector<vector<string>>productions, vector<string>nonTerminal){
  vector<string> all_kartesian_products;
  vector<string> answer;
  
  for(int k=i; k<j; k++){
     all_kartesian_products = all_kartesian_products + cyk_table[i][k]*cyk_table[k+1][j]; // vector.push(NULL)
  }

  // Valid
  for(int i=0; i<all_kartesian_products.size(); i++){
    answer = answer + fetch_nonTerminal(all_kartesian_products[i], productions, nonTerminal);
  }
  return answer;
}

void initialize(int string_length){
  for(int i=0; i<string_length; i++){
    vector<cell>row;
    for(int j=0; j<string_length; j++){
      cell c;
      // c.push_back(EPSILON);
      row.push_back(c);
    }
    cyk_table.push_back(row);
  }
}

void print_CYK_table(string input){
  for(int i=0; i<cyk_table.size(); i++){
    for(int j=0; j<cyk_table[i].size(); j++){
      cout<<"{";
      for(int k=0; k<cyk_table[i][j].size(); k++) cout<<cyk_table[i][j][k]<<",";
      cout<<"}";
      cout<<" ";
    }
    cout<<endl;
  }
}
