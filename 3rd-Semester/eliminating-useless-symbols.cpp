
#include<bits/stdc++.h>
using namespace std;

// Input Variables
vector<string> leftRules;
vector<vector<string>> rightRules;
vector<string> terminals;
vector<string> nonTerminals;
string start_nonTerminal;

// Function Prototypes
vector<string> tokenize(string line);
void print_input();
void take_input();
void find_nonGenerative();
void handle_nonGeneratative();
void handle_reachability();

// Global Variables
vector<string>nonGeneratative_nonterminals;



int main(){
    take_input();
    print_input();
    handle_nonGeneratative();
    cout<<"After eliminating nonGeneratives:"<<endl;
    print_input();
    handle_reachability();
    cout<<"After eliminating unReachable:"<<endl;
    print_input();
return 0;
}

void take_input(){
    int number_of_rules;
    cin>>number_of_rules;

    string left;
    string right;
    for(int i=0; i<number_of_rules; i++){
        cin>>left;
        cin>>right;
        leftRules.push_back(left);
        rightRules.push_back(tokenize(right));
    }

    int number_of_terminals;
    cin>>number_of_terminals;
    for(int i=0; i<number_of_terminals; i++) {
      string terminal;
      cin>>terminal;
      terminals.push_back(terminal);
    }

    int number_of_nonterminals;
    cin>>number_of_nonterminals;
    for(int i=0; i<number_of_nonterminals; i++) {
      string nonterminal;
      cin>>nonterminal;
      nonTerminals.push_back(nonterminal);
    }

    cin>>start_nonTerminal;

}

void print_input(){
    for(int i=0; i<leftRules.size(); i++){
        cout<<leftRules[i]<<" ";
        for(int j=0; j<rightRules[i].size(); j++) cout<<rightRules[i][j]<<"|";
        cout<<endl;
    }
    printf("Done printing CFG.\n");
    for(int i=0; i<terminals.size(); i++) cout<<terminals[i]<<" ";
    cout<<endl;
    for(int i=0; i<nonTerminals.size(); i++) cout<<nonTerminals[i]<<" ";
    cout<<endl;
    cout<<start_nonTerminal<<endl;
}

vector<string> tokenize(string line){
    vector <string> tokens;
    stringstream string_stream(line);

    string intermediate;
    while(getline(string_stream, intermediate, '|')) tokens.push_back(intermediate);

    return tokens;
}

void handle_nonGeneratative(){
  find_nonGenerative();
  for(int ng=0; ng<nonGeneratative_nonterminals.size(); ng++){
    for(int i=0; i<rightRules.size(); i++){
      for(int j=0; j<rightRules[i].size(); j++){
	if(rightRules[i][j].find(nonGeneratative_nonterminals[ng])!=-1)
	  rightRules[i].erase(rightRules[i].begin() + j);
      }
    }
  }
}

void find_nonGenerative(){
  for(int i=0; i<nonTerminals.size(); i++){
    bool flag = false;
    for(int j=0; j<leftRules.size(); j++){
      if(leftRules[i]==nonTerminals[i]) {flag=true; continue;}
    }
    if(flag==false) nonGeneratative_nonterminals.push_back(nonTerminals[i]); 
  }
}

void handle_reachability(){
  vector<string>visited;
  visited.push_back(start_nonTerminal);
  vector<int> remove_indices;
  
  for(int i=0; i<rightRules.size(); i++){
    if(find(visited.begin(), visited.end(), leftRules[i])==visited.end()){
      remove_indices.push_back(i);
      continue;
    }
    for(int j=0; j<rightRules[i].size(); j++){
      for(int c=0; c<rightRules[i][j].size(); c++){
	string nonTerminal(1,rightRules[i][j][c]);
	visited.push_back(nonTerminal);
      }
    } 
  }

  // Remove unreachables
  for(int i=0; i<remove_indices.size(); i++){
    rightRules.erase(rightRules.begin() + i);
    leftRules.erase(leftRules.begin() + i);
  }
}
