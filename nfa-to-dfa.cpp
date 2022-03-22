#include<sstream>
#include<iostream>
#include<vector>
#include<string>
using namespace std;


//vector<vector<vector<string>>> transition_table; // For 0, we can have {a,b}. So {a,b} is vector, they form the vector row and
// all rows together form a tranistion table. So there is three vectors.
vector<vector<string>> transition_table;
vector<string> states;
vector<string> alphabets;
string start_state;

vector<pair<string,vector<string>>> dfa_table;
vector<pair<string,bool>>completed;


// Function Prototype
void take_input();
void print_output();
void create_state_transitions(string state);
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

    cout<<"Enter transition table:(NO COMMA ALLOWED!)\n";
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

//     cout<<"Enter transition table: ";
//     vector<vector<vector<string>>> transition_table;
//     string input;
//     for(int i=0; i<states.size(); i++){
//       vector<vector<string>> row;
//       for(int j=0; j<alphabets.size(); j++){
// 	getline(cin, input);
// 	string single_state;
// 	vector<string> state;
// 	stringstream str_stream(input);
// 	while(getline(str_stream,single_state,',')){
// 	  state.push_back(single_state);
// 	}
	
//       }
//     }
//
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
        cout<<endl;
    }
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
  string new_state="";
  for(int i=0; i<store_state.size(); i++){
    if(store_state[i]!="NULL") new_state+=store_state[i];
  }
  if(new_state.size()==0) return "NULL";
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
  for(int i=0; i<dfa_row.size(); i++) create_state_transitions(dfa_row[i]);
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
