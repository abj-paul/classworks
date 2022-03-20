#include<iostream>
#include<vector>
<<<<<<< HEAD
=======
#include<string>
>>>>>>> 04655eef5311839a1cc71778f86dfb8b3e1fc8d7
using namespace std;


vector<vector<vector<string>>> transition_table; // For 0, we can have {a,b}. So {a,b} is vector, they form the vector row and
// all rows together form a tranistion table. So there is three vectors.
vector<string> states;
vector<string> alphabets;

// Function Prototype
void take_input();
void print_output();

int main(){
    take_input();
    print_output();
return 0;
}

void take_input(){
    int number_of_states, number_of_alphabets;

    cout<<"Number of states: ";
    cin>>number_of_states;
    cout<<"Enter states: ";
    string state;
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

    cout<<"Enter transition table: ";
    for(int i=0; i<number_of_states; i++){
<<<<<<< HEAD
        vector<vector<string>> curr_transition_row;
	string input;
	for(int i=0; i<alphabets.size(); i++){
		cin>>input;
	}
	
=======
        vector<string> curr_transition_row;
        string transition_state;
        for(int j=0; j<number_of_alphabets; j++){
            cin>>transition_state;
            curr_transition_row.push_back(transition_state);
        }
>>>>>>> 04655eef5311839a1cc71778f86dfb8b3e1fc8d7
        transition_table.push_back(curr_transition_row);
    }
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
        for(int j=0; j<alphabets.size(); j++){
            cout<<transition_table[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;

}
