/**
 * Matrix (N*N) multiplication with multiple threads.
 */
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <pthread.h>

#define DIMENSION 9

int num_threads=DIMENSION;
double A[DIMENSION][DIMENSION] = 
{
{0,1,2,3,4,5,6,7,8},
{1,2,3,4,5,6,7,8,9},
{2,3,4,5,6,7,8,9,10},
{3,4,5,6,7,8,9,10,11},
{4,5,6,7,8,9,10,11,12},
{5,6,7,8,9,10,11,12,13},
{6,7,8,9,10,11,12,13,14},
{7,8,9,10,11,12,13,14,15},
{8,9,10,11,12,13,14,15,16}
};
double B[DIMENSION][DIMENSION] = {
{1,1,1,1,1,1,1,1,8},
{1,2,3,4,5,6,7,8,9},
{1,3,5,7,9,11,13,15,10},
{1,4,7,10,13,16,19,22,11},
{1,5,9,13,17,21,25,29,12},
{1,6,11,16,21,26,31,36,13},
{1,7,13,19,25,31,37,43,14},
{1,8,15,22,29,36,43,50,15},
{1,9,17,25,33,41,49,57,16}
};
double answer[DIMENSION][DIMENSION];

void initialize_answer(){
	for(int i=0; i<DIMENSION; i++)
		for(int j=0; j<DIMENSION; j++) answer[i][j]=0;
}


void multiply_A_with_row(int row){
	for(int col=0; col<DIMENSION; col++){
	/*answer[row][col]   =    A[row][0]*B[0][col] +
	 			A[row][1]*B[1][col] +
				A[row][2]*B[2][col] ;*/
		for(int i=0; i<DIMENSION; i++){
	//		printf("Doing (%d,%d)\n",row,col);
		       	answer[row][col] += A[row][i]*B[i][col];
		}
	}
}

void* doStuff(void* value){
	int row = *(int*)value;
	multiply_A_with_row(row);
}

void test_multiplication(){
	int* shared_i = (int*)malloc(sizeof(int));
	for(int i=0; i<DIMENSION; i++){
		//multiply_A_with_row(i);
		*shared_i = i;
		doStuff(shared_i);
	}
	print_matrix(answer);
}

void print_matrix(double m[DIMENSION][DIMENSION]){
	for(int i=0; i<DIMENSION; i++){
		for(int j=0; j<DIMENSION; j++) printf("%lf ",m[i][j]);
		printf("\n");
	}
}

int main(){
	//test_multiplication();
	
	initialize_answer();
	pthread_t threads[num_threads];
	int* shared_i = (int*)malloc(sizeof(int));
	for (int i = 0; i < DIMENSION; i++ ) {
	        *shared_i = i;
    		pthread_create( &threads[i], NULL, doStuff, (void*)shared_i );
	    	pthread_join(threads[i], NULL);
		//doStuff(shared_i);
	  }


	  for (int i = 0; i < num_threads; ++i ) {
	    pthread_join(threads[i], NULL);
  	}

  	print_matrix(answer);
	return 0;
}
