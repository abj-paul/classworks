#include<pthread.h>
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<semaphore.h>


#define ROW 3
#define COL 300000

int matrix[ROW][COL];
int shared_count;
sem_t lock;

int inputMatrix(){
	for(int i=0; i<ROW; i++){
		for(int j=0; j<COL; j++) scanf("%d ",&matrix[i][j]);
	}
}
int printMatrix(){
	for(int i=0; i<ROW; i++){
		for(int j=0; j<COL; j++) printf("%d ",matrix[i][j]);
		printf("\n");
	}
}

int initialize(){
	//shared_count = (int*)malloc(sizeof(int));
	shared_count = 0;
}

void* doStuffNormally(void* val){
	int row = *(int*)val;
	for(int i=0; i<COL; i++){
		if(matrix[row][i]==1) shared_count++;
	}
}


void* doStuffWithSync(void* val){
	int row = *(int*)val;
	for(int i=0; i<COL; i++){
		if(matrix[row][i]==1){
			sem_wait(&lock);
		       	shared_count++;
			sem_post(&lock);
		}
	}
}

void* doStuffWithoutSync(void* val){
	int row = *(int*)val;
	for(int i=0; i<COL; i++){
		if(matrix[row][i]==1) shared_count++;
	}
}



void testNormal(){
	clock_t begin_time = clock();
	pthread_t threads[ROW];
	//Real Answer
	initialize();
	for(int i=0; i<ROW; i++)doStuffNormally((void*)&i);
	clock_t end_time = clock();
	printf("Number of 1's(Sequential): %d. Time=%.2lf\n",shared_count,(double)(end_time-begin_time)/CLOCKS_PER_SEC);
}
void testThread(){
	clock_t begin_time = clock();
	pthread_t threads[ROW];
	//With Thread
	initialize();
	for(int i=0; i<ROW; i++){
		int* row = (int*)malloc(sizeof(int));
		*row=i;
		pthread_create(&threads[i], NULL, doStuffWithoutSync, (void*)row);
	}
	for(int i=0; i<ROW; i++) pthread_join(threads[i],NULL);
	clock_t end_time = clock();
	printf("Number of 1's(Thread): %d. Time=%.2lf\n",shared_count,(double)(end_time-begin_time)/CLOCKS_PER_SEC);

}
void testSync(){
	clock_t begin_time = clock();
	pthread_t threads[ROW];
	//With Synchronization
	initialize();
	for(int i=0; i<ROW; i++){
		int* save_i = (int*)malloc(sizeof(int));
		*save_i=i;
		pthread_create(&threads[i], NULL, doStuffWithSync, (void*)save_i);
	}
	for(int i=0; i<ROW; i++) pthread_join(threads[i],NULL);
	clock_t end_time = clock();
	printf("Number of 1's(Synchronization): %d. Time=%.2lf\n",shared_count,(double)(end_time-begin_time)/CLOCKS_PER_SEC);

}
int main(){
	sem_init(&lock, 0, 1);

	printf("Matrix %dX%d.\n",ROW,COL);
	inputMatrix();
	testNormal();
	testThread();
	testSync();
return 0;
}

