#include<bits/stdc++.h>
using namespace std;

// Input Variables
vector<string> leftRules;
vector<vector<string>> rightRules;
vector<string> terminals;
vector<string> nonTerminals;

// Function Prototypes
vector<string> tokenize(string line);
void print_input();
void take_input();

void handleUnitProductions();


int main(){
    take_input();
    print_input();

    handleUnitProductions();
    cout<<"After unit production elimination:"<<endl;
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

}

void print_input(){
    for(int i=0; i<leftRules.size(); i++){
        cout<<leftRules[i]<<" ";
        for(int j=0; j<rightRules[i].size(); j++) cout<<rightRules[i][j]<<"|";
        cout<<endl;
    }
    for(int i=0; i<terminals.size(); i++) cout<<terminals[i]<<" ";
    cout<<endl;
    for(int i=0; i<nonTerminals.size(); i++) cout<<nonTerminals[i]<<" ";
    cout<<endl;
}

vector<string> tokenize(string line){
    vector <string> tokens;
    stringstream string_stream(line);

    string intermediate;
    while(getline(string_stream, intermediate, '|')) tokens.push_back(intermediate);

    return tokens;
}

void handleUnitProductions(){
  for(int i=0; i<rightRules.size(); i++){
    for(int j=0; j<rightRules[i].size(); j++){
      if(rightRules[i][j].size()==1){
	bool isTerminal = false;
	for(int k=0; k<terminals.size(); k ++){
	  if(terminals[k]==rightRules[i][j]) isTerminal=true;
	}
	if(!isTerminal) {
	  int unitIndex = 0;
	  for(unitIndex; unitIndex<terminals.size(); unitIndex++)
	    if(nonTerminals[unitIndex]==rightRules[i][j]) break;

	  rightRules[i].insert(rightRules[i].end(), rightRules[unitIndex].begin(), rightRules[unitIndex].end());
	  rightRules[i].erase(rightRules[i].begin() + j);
	}
      }
    }
  }
}
