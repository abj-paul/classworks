#include<bits/stdc++.h>
using namespace std;

// Input Variables
vector<string> leftRules;
vector<vector<string>> rightRules;

// Function Prototypes
vector<string> tokenize(string line);
void print_input();
void take_input();
void find_nullable_nonTerminals();
void update_nullable_nonTerminals();

// Global Variables
vector<int>nullable_nonTerminal_indices;


int main(){
    take_input();
    print_input();
    update_nullable_nonTerminals();
    cout<<"After eliminating epsilon:"<<endl;
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
}

void print_input(){
    for(int i=0; i<leftRules.size(); i++){
        cout<<leftRules[i]<<" ";
        for(int j=0; j<rightRules[i].size(); j++) cout<<rightRules[i][j]<<"|";
        cout<<endl;
    }
}

vector<string> tokenize(string line){
    vector <string> tokens;
    stringstream string_stream(line);

    string intermediate;
    while(getline(string_stream, intermediate, '|')) tokens.push_back(intermediate);

    return tokens;
}

void find_nullable_nonTerminals(){
    for(int i=0; i<rightRules.size(); i++){
        for(int j=0; j<rightRules[i].size(); j++){
            if(rightRules[i][j]=="NULL") {
                nullable_nonTerminal_indices.push_back(i);
                // Remove NULL
                rightRules[i].erase(rightRules[i].begin() + j);
                continue;
            }
        }
    }
}

void update_nullable_nonTerminals(){
    find_nullable_nonTerminals();
    for(int i=0; i<nullable_nonTerminal_indices.size(); i++){
        string target = leftRules[nullable_nonTerminal_indices[i]];

        for(int r1=0; r1<rightRules.size(); r1++){
            for(int r2=0; r2<rightRules[r1].size(); r2++){
                int index = rightRules[r1][r2].find(target);
                if(index!=-1){
                    string new_nonTerminal = rightRules[r1][r2];
                    new_nonTerminal.replace(new_nonTerminal.find(target), 1, "");
                    rightRules[r1].push_back(new_nonTerminal);
                }
            }
        }
    }
}

