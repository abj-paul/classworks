//#include<bits/stdc++.h>
#include<iostream>
#include<utility>
#include<vector>
#include<string>
using namespace std;

vector<char>alphabets;
vector<char>states;
vector<pair<char, vector<char>>>transition_table;
char start_state, end_state;
string str;
int flag=-1;
vector<char>path;

// function prototype
void take_input();
void print_input();
void delta(int current_state_index, int current_alphabet_index);
int index_of(char state);

int main(){
take_input();
print_input();

path.push_back(states[0]);
delta(0,0);
//cout<<"Answer: "<<flag<<endl;
if(flag==1) cout<<"Reached finish state."<<endl;
else cout<<"Did not reach finish state."<<endl;
for(int i=0; i<path.size(); i++) cout<<path[i]<<" ";
cout<<endl;
return 0;
}

void take_input(){
    int number_of_states, number_of_alphabets;
    cout<<"Number of alphabets: ";
    cin>>number_of_alphabets;
    cout<<"Number of states: ";
    cin>>number_of_states;

    char alphabet;

    cout<<"All alphabets: "<<endl;
    for(int i=0; i<number_of_alphabets; i++){
        cin>>alphabet;
        alphabets.push_back(alphabet);
    }

    cout<<"All states: "<<endl;
    char state;
    for(int i=0; i<number_of_states; i++){
        cin>>state;
        states.push_back(state);
    }

    /*cout<<"Start State: ";
    cin>>start_state;
    cout<<"End State: ";
    cin>>end_state;*/
    // Take transition table as input
    for(int i=0; i<number_of_states; i++){
        cout<<"Enter transition for state "<<states[i]<<": ";
        vector<char>transitions;
        char transition;
        for(int i=0; i<number_of_alphabets; i++){
             cin>>transition;
             transitions.push_back(transition);
        }
        transition_table.push_back(make_pair(states[i],transitions));
    }

    cin>>str;
    cout<<"Done taking input!"<<endl;
}

void print_input(){
cout<<"Printing State."<<endl;
    cout<<start_state<<" "<<end_state<<endl;
    for(int i=0; i<transition_table.size(); i++){
        cout<<transition_table[i].first<<": ";
        for(int j=0; j<transition_table[i].second.size(); j++){
            cout<<transition_table[i].second[j]<<" ";
        }
        cout<<endl;
    }
    cout<<str<<endl;
}


// Returns next state
// returns -1  if finished and at end state
// returns  -2 if finished but not at end state
// out of bound -> returns -3
void delta(int current_state_index, int current_alphabet_index){
printf("State: %d, alphabet=%d\n",current_state_index, current_alphabet_index);
    if(current_alphabet_index>=str.size()) return ;//-3;
    if(current_state_index>=states.size()) return ;//-3;

    char state = transition_table[current_state_index].second[current_alphabet_index];
    if(state==end_state) flag=1;
    else flag=0;

    // Afte reaching final state, we can go to any non-final state
    //path.push_back(state);
    delta(index_of(state),current_alphabet_index+1);

}

int index_of(char state){
    for(int i=0; i<states.size(); i++){
        if(states[i]==state) return i;
    }
    return -1;
}
