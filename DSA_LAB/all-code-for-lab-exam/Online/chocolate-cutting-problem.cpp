#include<bits/stdc++.h>
using namespace std;

// Global Variable
#define MAX_SIZE 100
int M, N, profit[MAX_SIZE][MAX_SIZE]; //M=ROW, N=column
int cake_M, cake_N;
int max_profit[MAX_SIZE][MAX_SIZE];

// Function Prototype
void take_input();
void print_input();
void print_matrix(int [][MAX_SIZE]);
int fun_max_profit();
int cc(int m, int n);

int main(){
	take_input();
	print_input();

	printf("Max profit from cutting chocolate is: %d\n",fun_max_profit());
return 0;
}

void take_input(){
	scanf("%d %d",&M,&N); 	
	for(int i=1; i<=M; i++){
		for(int j=1; j<=N; j++) scanf("%d",&profit[i][j]);
	}
	scanf("%d %d",&cake_M, &cake_N);
}

void print_input(){
	printf("M=%d, N=%d\n",M,N);
	print_matrix(profit);
	printf("Cake Size: %d,%d\n",cake_M, cake_N);

}

void print_matrix(int [][MAX_SIZE]){
	printf("The matrix is:\n");
	for(int i=1; i<=M; i++){
		for(int j=1; j<=N; j++) printf("%d,",profit[i][j]);
		printf("\n");
	}
}

int fun_max_profit(){
	for(int i=0; i<=M; i++) max_profit[i][0]=0;
	for(int i=0; i<=N; i++) max_profit[0][i]=0;

	for(int i=1; i<=M; i++){
		for(int j=1; j<=N; j++) max_profit[i][j]=-1;
	}
	// Done initializing the max_profit matrix.
	
	int ans =  cc(cake_M, cake_N);
	print_matrix(max_profit);
	return ans;
}

int cc( int m, int n){
	if(m==0 | n==0) return 0;
	if(max_profit[m][n]!=-1) return max_profit[m][n];
	
	max_profit[m][n] = max(max_profit[m][n], profit[m][n]);
	for(int i=1; i<=m/2; i++){
		int optimal_soln = cc(i, n) + cc(m-i, n);
		max_profit[m][n] = max(max_profit[m][n], optimal_soln);
	}
	for(int i=1; i<=n/2; i++){
		int optimal_soln = cc(m, i) + cc(m, n-i);
		max_profit[m][n] = max(max_profit[m][n], optimal_soln);
	}
	return max_profit[m][n];

}
