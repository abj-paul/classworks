#include<iostream>
#include<vector>
using namespace std;
#define MAX_SIZE 100

// String matching
int get_string_length(char* str);
vector<int> get_string_matching_index(char* text, char* pattern); //naive
void print_matching_strings(vector<int>indices, char* sentence, char* pattern);
void replace_string(char* text, int start_index, int end_index, char* replace_with);

// Tools for cfg
void replace_alphabets_with_variable(char* text);
void replace_pattern_at_index(char* text, vector<int>matched_indices, char* pattern, char* pattern_normalize);
void use_cfg_rules(char* text);

bool brute_force(char* text);

int main(){
    char text[MAX_SIZE];
    cin>>text;
    printf("Our input is=%s\n",text);
    replace_alphabets_with_variable(text);
    //use_cfg_rules(text);

    /*char pattern[] = "(E)";
    char pattern_normalize[] = "E";
    vector<int>matched_indices = get_string_matching_index(text, pattern);
    replace_pattern_at_index(text, matched_indices, pattern, pattern_normalize);
    printf("Our answer is = %s\n",text);*/

    printf("%d\n",brute_force(text));
    return 0;
}

void use_cfg_rules(char* text){
    char pattern_1[] = "E+E";
    char pattern_normalize[]="E";
    char pattern_2[] = "E*E";
    char pattern_3[] = "(E)";

    for(int i=0; i<100; i++){
    vector<int>matched_indices = get_string_matching_index(text, pattern_2);
    replace_pattern_at_index(text, matched_indices, pattern_1, pattern_normalize);

    matched_indices = get_string_matching_index(text, pattern_1);
    replace_pattern_at_index(text, matched_indices, pattern_1, pattern_normalize);

    matched_indices = get_string_matching_index(text, pattern_3);
    replace_pattern_at_index(text, matched_indices, pattern_1, pattern_normalize);
    }

    printf("After using CFG: %s\n",text);
}

void replace_pattern_at_index(char* text, vector<int>matched_indices, char* pattern, char* pattern_normalize){
    int pattern_size = get_string_length(pattern);

    for(int i=0; i<matched_indices.size(); i++){
        replace_string(text, matched_indices[i], matched_indices[i]+pattern_size, pattern_normalize);
    }
}

void replace_string(char* text, int start_index, int end_index, char* replace_with){
    int replace_string_size = get_string_length(replace_with);
    int text_size = get_string_length(text);

    char temp[MAX_SIZE];
    for(int i=0; i<start_index; i++) temp[i]=text[i];

    int j=0;
    for(int i=start_index; i<replace_string_size+start_index; i++) {
        temp[i]=replace_with[j];
        j++;
    }
    j=end_index;
    int i=0;
    for(i=start_index+replace_string_size; text[j]!='\0'; i++, j++){
        temp[i]=text[j];
    }
    temp[i]='\0';
    //printf("Temp is=%s\n",temp);
    //text=temp;


    // Copying to text
    int temp_size = get_string_length(temp);
    for(i=0; i<temp_size; i++) text[i]=temp[i];
    text[i]='\0';
}


void replace_alphabets_with_variable(char* text){
    int text_size = get_string_length(text);
    char variable = 'E';
    for(int i=0; i<text_size; i++){
        if(text[i]=='0' || text[i]=='1') text[i]=variable;
    }
}

vector<int> get_string_matching_index(char* text, char* pattern){ //naive
    vector<int> matched_string_indices;
    int pattern_size = get_string_length(pattern);

    int text_size = get_string_length(text);
    int patrern_size = get_string_length(pattern);

    int pattern_index=0, match_count=0;
    for(int i=0; i<text_size; i++){
        if(text[i]==pattern[pattern_index]) {
            match_count++;
            pattern_index++;
        }
        else{
            pattern_index=0;
            i=i-match_count;
            match_count=0;
        }
        if(match_count==pattern_size) matched_string_indices.push_back(i-pattern_size+1);
    }

    return matched_string_indices;

}

int get_string_length(char* str){
    int size=0;
    while(str[size]!='\0') size++;
    return size;
}

void print_matching_strings(vector<int>indices, char sentence[], char pattern[]){
    int pattern_size = get_string_length(pattern);

    printf("The string=%s\n",sentence);
    printf("The pattern=%s\n",pattern);
    for(int i=0; i<indices.size(); i++){
        printf("Starts from index %d.\n",indices[i]);
        for(int p=indices[i]; p<pattern_size+indices[i]; p++) printf("%c",sentence[p]);
        printf("\n");
    }
}

void test_function(){
    char text[]="aabaabcaabaabca";
    char pattern[]="aabc";
    vector<int>matching_indices = get_string_matching_index(text, pattern);
    print_matching_strings(matching_indices, text, pattern);

    //char text[]="(0+1)*(0*0)+1";
    replace_alphabets_with_variable(text);
    printf("After processing=%s\n",text);

    char* const_text = "I am abhijit paul.";// text[MAX_SIZE];
    for(int i=0; i<get_string_length(const_text); i++) text[i]=const_text[i];
    char replace_with[]="A";
    replace_string(text, 5, 8, replace_with);
    printf("After replacing=%s\n",text);
}


bool brute_force(char* text){
int text_size = get_string_length(text);
int left_brackets=0;
int right_brackets=0;
    for(int i=0; i<text_size; i++){
        if(text[i]=='(') left_brackets++;
        else if(text[i]==')') right_brackets++;
    }
    if(left_brackets!=right_brackets) return false;

    for(int i=0; i<text_size; i++){
        if(text[i]=='+' && text[i+1]=='*') return false;
        else if(text[i]=='*' && text[i+1]=='+') return false;
    }
    return true;
}
