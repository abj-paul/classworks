#include<iostream>
#include<vector>
#include<string>
#include<set>
using namespace std;

// Input Variable
vector<vector<string>> transition_table; 
vector<string> states;
vector<string> alphabets;
string start_state;

// Output Variables
vector<pair<string,vector<string>>> dfa_table;
vector<pair<string,bool>>completed;


// Function Prototype
void take_input();
void print_output();
void create_state_transitions(string state);
string unite(vector<string> store_state);
string fetch(char c, int alphabet);
bool isCompleted(string state);
void print_dfa();

int main(){
    take_input();
    print_output();
    create_state_transitions(start_state);
    print_dfa();
return 0;
}

void take_input(){
    int number_of_states, number_of_alphabets;
    string state;

    cout<<"Number of states: ";
    cin>>number_of_states;
    cout<<"Enter states: ";
    for(int i=0; i<number_of_states; i++){
        cin>>state;
        states.push_back(state);
    }

    cout<<"Number of alphabets: ";
    cin>>number_of_alphabets;
    cout<<"Enter alphabets: ";
    string alphabet;
    for(int i=0; i<number_of_alphabets; i++){
        cin>>alphabet;
        alphabets.push_back(alphabet);
    }

    cout<<"Enter NFA transition table:(NO COMMA ALLOWED!)\n";
    for(int i=0; i<states.size(); i++){
      vector<string> row_states;
      for(int j=0; j<alphabets.size(); j++){
	//getline(std::cin, state);
	cin>>state;
	row_states.push_back(state);
      }
      transition_table.push_back(row_states);
    }

    cout<<"Enter start state: ";
    cin>>start_state;
}

void print_output(){
    cout<<"States are: ";
    for(int i=0; i<states.size(); i++) cout<<states[i]<<" ";
    cout<<endl;
    cout<<"Alphabets are: ";
    for(int i=0; i<alphabets.size(); i++) cout<<alphabets[i]<<" ";
    cout<<endl;

    cout<<"Transition table is:"<<endl;
    for(int i=0; i<states.size(); i++){
      cout<<states[i]<<": ";
        for(int j=0; j<alphabets.size(); j++){
	  cout<<transition_table[i][j]<<" ";
        }
        cout<<"\n";
    }
    cout<<"Start state: "<<start_state;
    cout<<endl;

}
bool isCompleted(string state){
  for(int i=0; i<completed.size(); i++){
    if(completed[i].first==state) return completed[i].second;
  }
  return false; // the state has not been created yet.
}

string fetch(char c, int alphabet){
  string s(1,c);
  int state_index = 0;
  for(int i=0; i<states.size(); i++)
    if(states[i]==s){
      state_index=i;
      break;
    }
  
  return transition_table[state_index][alphabet];
}

string unite(vector<string> store_state){
  // Splitting all combined states into characters
  set<char> split_s;
  for(int i=0; i<store_state.size(); i++){
    if(store_state[i]=="NULL") continue;
    for(int j=0; j<store_state[i].size(); j++){
      split_s.insert(store_state[i][j]);
    }
  }

  // Building the new state
  string new_state="";
  for(auto element: split_s) new_state+=element;
  return new_state;
  
}

void create_state_transitions(string state){
  if(isCompleted(state))return;

  vector<string> dfa_row;
  for(int a=0; a<alphabets.size(); a++){
    vector<string>store_state;
    for(int w=0; w<state.size(); w++){
      store_state.push_back(fetch(state[w], a));
    }
    string new_state = unite(store_state);
    dfa_row.push_back(new_state);
  }

  dfa_table.push_back(make_pair(state, dfa_row));
  completed.push_back(make_pair(state,true));

  // Now recursively call new states
  for(int i=0; i<dfa_row.size(); i++)
    if(dfa_row[i]!="NULL")
      create_state_transitions(dfa_row[i]);
}


void print_dfa(){
  cout<<"DFA transition table:\n";
  for(int i=0; i<dfa_table.size(); i++){
    cout<<dfa_table[i].first<<": ";
    for(int j=0; j<dfa_table[i].second.size(); j++){
      cout<<dfa_table[i].second[j]<<" ";
    }
    cout<<endl;
  }
  cout<<endl;
}
