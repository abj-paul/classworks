#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <stdlib.h>

int readcount, writecount;
sem_t rmutex, wmutex, readTry, resource;

int shared_value = 1;

#define lock(x) sem_wait(x)
#define unlock(x) sem_post(x)


void* reader(void* value){

	lock(&readTry); // To prioritize writier. Reader can now no longer wantonly enter read section. 
	int thread_no = *(int*)value;
	printf("Reader %d is trying to read.\n", thread_no);

		lock(&rmutex);
			readcount++;
			if(readcount==1) lock(&resource);
		unlock(&rmutex);
	unlock(&readTry);

	// Perform read
	int read_value = shared_value;
	printf("Reader %d reads %d.\n",thread_no, read_value);
	sleep(1);
	
	lock(&rmutex);
		readcount--;
		if(readcount==0) unlock(&resource);
	unlock(&rmutex);
}

void* writer(void* value){

	lock(&wmutex);	
	int thread_no = *(int*)value;
	printf("Writer %d is trying to write.\n", thread_no);

		writecount++;
		if(writecount==1) lock(&readTry);
	unlock(&wmutex);	

	// Perform Writing
	lock(&resource);
		int write_value = shared_value+4;
		shared_value = write_value;
		printf("Writer %d writes %d.\n",thread_no, write_value);
	sleep(1);
	unlock(&resource);

	lock(&wmutex);
		writecount--;
		if(writecount==0) unlock(&readTry);
	unlock(&wmutex);
}
int main(){
	int rc = 5;
	int wc = 5;

	sem_init(&rmutex, 0, 1);
	sem_init(&wmutex, 0, 1);
	sem_init(&resource, 0, 1);

	pthread_t thread_id[wc+rc];

	for(int i=0; i<wc; i++){ //writer
		int* id = (int*)malloc(sizeof(int));
		*id = i;
		pthread_create(&thread_id[rc+i], NULL, writer, (void*)id);
		pthread_create(&thread_id[i], NULL, reader, (void*)id);
	}

	// Join
	for(int i=0; i<rc+wc; i++) pthread_join(thread_id[i],NULL);

return 0;
}
