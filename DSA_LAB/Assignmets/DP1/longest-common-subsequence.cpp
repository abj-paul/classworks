#include<bits/stdc++.h>
using namespace std;

// Global Variable
#define MAX_SIZE 100
char A[MAX_SIZE];
char B[MAX_SIZE];

// Function Prototype
void take_input();
void print_input();
int get_string_length(char str[]);
int longest_common_subsequence();
void print_matrix(int m[][MAX_SIZE]);

int main(){
	take_input();
	print_input();
	printf("Longest Common Subsequence is=%d\n",longest_common_subsequence());
return 0;
}

void take_input(){
	scanf("%s",A);
	scanf("%s",B);
}
void print_input(){
	printf("%s - of size=%d\n",A,get_string_length(A));
	printf("%s - of size=%d\n",B,get_string_length(B));
}
int get_string_length(char str[]){
	int i=0;
	while(str[i]!='\0')i++;
	return i;
}

int longest_common_subsequence(){
	int n1 = get_string_length(A);
	int n2 = get_string_length(B);

	// i->A, j->B, m[row][col]
	int m[MAX_SIZE][MAX_SIZE]; 
	for(int i=0; i<=n1; i++) m[i][0]=0;
	for(int i=0; i<=n2; i++) m[0][i]=0;

	for(int i=1; i<=n1; i++){
		for(int j=1; j<=n2; j++){
			if(A[i]==B[j]) m[i][j] = m[i-1][j-1]+1;
			else m[i][j] = max(max(m[i-1][j-1],m[i][j-1]),m[i-1][j]);
		}
	}
	print_matrix(m);
	return m[n1][n2];
}

void print_matrix(int m[][MAX_SIZE]){
	int n1 = get_string_length(A);
	int n2 = get_string_length(B);

	printf("Matrix is:\n");
	for(int i=0; i<=n1; i++){
		for(int j=0; j<=n2; j++) printf("%d,",m[i][j]);
		printf("\n");
	}
}
