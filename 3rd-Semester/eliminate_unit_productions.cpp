

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
