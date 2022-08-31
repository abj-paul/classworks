#include<pthread.h>
#include<stdio.h>
#include<stdlib.h>

#define ROW 3
#define COL 3000

int matrix[ROW][COL];
int shared_count;
pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;

int inputMatrix(){
	for(int i=0; i<ROW; i++){
		for(int j=0; j<COL; j++) scanf("%d ",&matrix[i][j]);
	}
}

int initialize(){
	//shared_count = (int*)malloc(sizeof(int));
	shared_count = 0;
}

void* doStuffWithSync(void* val){
	int row = *(int*)val;
	for(int i=0; i<COL; i++){
		pthread_mutex_lock(&lock);
		if(matrix[row][i]==1) shared_count++;
		pthread_mutex_unlock(&lock);
	}
		pthread_mutex_lock(&lock);
	printf("Debug: Ending thread for row %d, found count %d.\n",row, shared_count);
		pthread_mutex_unlock(&lock);
}

void testSync(){
	pthread_t threads[ROW];
	//With Synchronization
	initialize();
	for(int i=0; i<ROW; i++){
		int* save_i = (int*)malloc(sizeof(int));
		*save_i=i;
		pthread_create(&threads[i], NULL, doStuffWithSync, (void*)save_i);
	}
	for(int i=0; i<ROW; i++) pthread_join(threads[i],NULL);
	pthread_mutex_destroy(&lock);
	printf("Number of 1's(Synchronization): %d\n",shared_count);

}
int main(){
	inputMatrix();
	testSync();
return 0;
}
