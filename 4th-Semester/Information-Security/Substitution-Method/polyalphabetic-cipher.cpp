#include<vector>
#include<iostream>

using namespace std;

#define POSITION_COUNT 4
#define CHARACTER_COUNT 128
#define START_CHARATER '\0'

char mapping[CHARACTER_COUNT][POSITION_COUNT];

void generate_mapping_table();
void print_mapping_table();

string encrypt(string plainText);
char findSubstitution(int position, char decryptedCharacter);
string decrypt(string encryptedText);

int main(){
    generate_mapping_table();
    print_mapping_table();

    printf("Enter a string to encrypt: ");
    string input; 
    getline(cin, input);

    string encryptedText = encrypt(input);
    cout<<"Encrypted Text = "<< encryptedText<<endl;

    //cout<<findSubstitution(2, 'B')<<endl;

    cout << "Decrypted Text = " << decrypt(encryptedText) << endl;


    return 0;
}

void generate_mapping_table(){
    for(int i=0; i<POSITION_COUNT; i++){
        for(int j=0; j<CHARACTER_COUNT; j++){
            mapping[j][i] = START_CHARATER + (j + i)%CHARACTER_COUNT ;
        }
    }
}

void print_mapping_table(){
    FILE* fptr = fopen("MAPPING_TABLE.txt", "w");
    if(fptr==NULL){
        printf("Error opening the file. Exiting...\n");
        return;
    }

    for(int i=0; i<CHARACTER_COUNT; i++){
        fprintf(fptr, "%c) ", START_CHARATER+i);
        for(int j=0; j<POSITION_COUNT; j++) fprintf(fptr, "%c ", mapping[i][j]);
        fprintf(fptr, "\n");
    }

    fclose(fptr);
}

string encrypt(string plainText){
    string encryptedText = "";
    for(int i=0; i<plainText.size(); i++){
        char substitutedCharacter = mapping[plainText[i]-START_CHARATER][i%POSITION_COUNT];
        //encryptedText.append(1,substitutedCharacter);
        encryptedText += string(1, substitutedCharacter);
        printf("%c->%c\n", plainText[i], substitutedCharacter);
    }
    return encryptedText;
}

char findSubstitution(int position, char encryptedCharacter){
    for(int i = 0; i<CHARACTER_COUNT; i++){
        if(mapping[i][position]==encryptedCharacter) return START_CHARATER + i;
    }
}

string decrypt(string encryptedText){
    string plainText = "";
    for(int i=0; i<encryptedText.size(); i++){
        plainText += string(1, findSubstitution(i%POSITION_COUNT, encryptedText[i]));
    }
    return plainText;
}