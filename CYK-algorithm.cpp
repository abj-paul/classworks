//https://www.geeksforgeeks.org/cyk-algorithm-for-context-free-grammar/
#include<bits/stdc++.h>
using namespace std;

// Global Variable
#define EPSILON 'e'
#define MAX_SIZE 50


int main(){



    return 0;
}

void run(){
    int number_of_rules = 4;
    vector<string>nonTerminal = {"S","A","B", "C"};

    vector<vector<string>> productions = {
        {"AB","BC"},
        {"BA", "a"},
        {"CC"},
        {"AB","a"}
    };

    string input;
    cin>>input;

    // STEP 2
    if(input[0]==EPSILON){
        vector<string>matches = fetch_nonTerminal(input[0], productions, nonTerminal);
        for(int i=0; i<matches.size(); i++)
            if(matches[i]==EPSILON) return true;
    }

    // STEP 3
    string[MAX_SIZE][MAX_SIZE] cyk_table;
    for(int i=0; i<input.size(); i++){
        cyk_table[i][i] = fetch_nonTerminal(input[i]);
    }

    // STEP 4
    for(int l=1; l<input.size(); i++){
        for(int i=0; i<n-l+1)
    }
}

vector<string> fetch_nonTerminal(string state, vector<vector<string>>productions, vector<string>nonTerminal){
    vector<string>matches;
    for(int i=0; i<productions.size(); i++){
        `for(int j=0; j<productions[i].size(); j++){
            if(state==productions[i][j]) matches.push_back(nonTerminal[i]);
        }
    }
    return matches;
}


