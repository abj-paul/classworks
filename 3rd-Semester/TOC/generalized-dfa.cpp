#include<iostream>
#include<vector>
#include<utility>
using namespace std;

// Global Variable
vector<char>alphabets;
vector<char>states;
char start_state, end_state;
vector<pair<char, vector<char>>>transition_table;
string str;
int flag=-1;
// Function Prototype
int get_state_index(char c);
int get_alphabet_index(char c);
void delta(int current_state_index, int current_string_index);
void take_input();


int main(){
  take_input();
  delta(get_state_index(start_state),0);
  cout<<flag;
  return 0;
}

void take_input(){
  int number_of_states,number_of_alphabets;
  std::cin>>number_of_alphabets;
  std::cin>>number_of_states;

  char alphabet;
  for(int i=0; i<number_of_alphabets; i++) {
    cin>>alphabet;
    alphabets.push_back(alphabet);
  }
  char state;
  for(int i=0; i<number_of_states; i++) {
    cin>>state;
    states.push_back(state);
  }
  cin>>start_state>>end_state;
  // Transition Table input
  for(int i=0; i<number_of_states; i++){
    vector<char>current_transitions;
    char transition_state;
    for(int i=0; i<number_of_alphabets; i++){
      cin>>transition_state;
      current_transitions.push_back(transition_state);
    }
    transition_table.push_back(make_pair(states[i],current_transitions));
  }
  cin>>str;

}

void delta(int current_state_index, int current_string_index){
  if(current_state_index>=states.size() || current_string_index>=str.size())return;

  int current_alphabet_index = get_alphabet_index(str[current_string_index]);
  char next_state = transition_table[current_state_index].second[current_alphabet_index];

  if(next_state==end_state) flag=1;
  else flag=0;

  cout<<next_state<<endl;
  delta(get_state_index(next_state), current_string_index+1);
  
}

int get_alphabet_index(char c){
  for(int i=0; i<alphabets.size(); i++)
    if(alphabets[i]==c) return i;
  return -1;
}

int get_state_index(char c){
  for(int i=0; i<states.size(); i++)
    if(states[i]==c) return i;
  return -1;
}
