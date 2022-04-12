
#include<bits/stdc++.h>
using namespace std;

// Global Variables
#define MAX_SIZE 100
char main_word[MAX_SIZE], compare_word[MAX_SIZE];

// Function Prototypes
void take_input();
void print_input();
int get_string_length(char s[]);
int minimum_edit_distance();
int max_(int a, int b, int c);
void print_matrix(int m[][100]);

int main(){
	take_input();
	print_input();
	printf("Minimum Edit Distance: %d\n",minimum_edit_distance());
return 0;
}

void take_input(){
	//printf("First String: ");
	scanf("%s",main_word);
	//printf("Second String: ");
	scanf("%s",compare_word);
}

int get_string_length(char s[]){
	int i=0;
	while(s[i]!='\0') i++;
	return i;
}

void print_input(){
	printf("%s - %d\n",main_word,get_string_length(main_word));
	printf("%s - %d\n",compare_word,get_string_length(compare_word));
}

int minimum_edit_distance(){
	int m[MAX_SIZE][MAX_SIZE];
	int n1 = get_string_length(main_word);
	int n2 = get_string_length(compare_word);

	// i -> A, j -> B, m[row][col]
	for(int i=0; i<=n1; i++) m[i][0]=i;
	for(int j=0; j<=n2; j++) m[0][j]=j;

	for(int i=1; i<=n1; i++){
		for(int j=1; j<=n2; j++){
			if(main_word[i-1]==compare_word[j-1]) m[i][j] = m[i-1][j-1];
			else m[i][j] = min(min(m[i-1][j-1],m[i][j-1]),m[i-1][j]) + 1;
		}
	}
	//print_matrix(m);
	return m[n1][n2];
}

int max_(int a, int b, int c){
	if(a>=b>=c || a>=c>=b) return a;
	if(b>=a>=c || b>=c>=a) return b;
	if(c>=a>=b || c>=b>=a) return c;
	return -1;
}

void print_matrix(int m[][100]){
	printf("The matrix is: \n");
	int n1=get_string_length(main_word);
	int n2=get_string_length(compare_word);
	for(int i=0; i<=n1; i++){
		for(int j=0; j<=n2; j++) printf("%d,",m[i][j]);
		printf("\n");
	}
}
