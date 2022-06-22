//(0+0*1*(0+1)+0)
#include<bits/stdc++.h>
using namespace std;

vector<string> rules_rightSide;
vector<string> rules_leftSide;
string input;
bool solution();
void print_input();

// Function Prototype
void take_input();
vector<int> matchedIndices(string toSearch);
void replaceRuleMatching();

int main(){
    take_input();
    print_input();
    bool answer = solution();
    cout<<answer<<endl;
return 0;
}


void take_input(){
    int number_of_rules;
    // space separated rules
    cin>>number_of_rules;
    string left_side, right_side;
    for(int i=0; i<number_of_rules; i++){
        cin>>left_side>>right_side;
        rules_leftSide.push_back(left_side);
        rules_rightSide.push_back(right_side);
    }
    // Insert Test String
    cin>>input;
}

void replaceRuleMatching(){
    for(int i=0; i<rules_rightSide.size(); i++){
        vector<int>indices = matchedIndices(rules_rightSide[i]);
        for(int j=0; j<indices.size(); j++) {
            input.replace(indices[j], rules_rightSide[i].size(), rules_leftSide[i]);
            cout<<input<<endl;

        }
    }

}

vector<int> matchedIndices(string toSearch){
    vector<int>vec;
    int pos = input.find(toSearch);
    while( pos != std::string::npos){
        vec.push_back(pos);
        pos =input.find(toSearch, pos + toSearch.size());
    }
    return vec;
}

bool solution(){
    for(int i=0; i<input.size(); i++){
        replaceRuleMatching();
    }
    if(input.size()==1) return true;
    return false;
}

void print_input(){
    for(int i=0; i<rules_leftSide.size(); i++){
        cout<<rules_leftSide[i]<<" "<<rules_rightSide[i]<<endl;
    }
    // Insert Test String
    cout<<input<<endl;
}
