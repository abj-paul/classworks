#include<stdio.h>
#include<pthread.h>
#include<unistd.h>
#include<stdlib.h>

#define MAX_WRITER 3
#define MAX_READER 10

FILE *fptr;

void* reader(void* temp){
  int reader_id = *(int*)temp;
  printf("Reader %d has entered.\n",reader_id);
  sleep(rand()%10);
  printf("Reader %d has exited.\n",reader_id);
}

void* writer(void* temp){
   int writer_id = *(int*)temp;
   printf("Writer %d has entered.\n",writer_id);
   sleep(rand()%10);
   printf("Writer %d has exited.\n",writer_id);
}


int main(){
  fptr = fopen("test_file.txt","w");

  pthread_t reader_thread_id[MAX_READER];
  pthread_t writer_thread_id[MAX_WRITER];

  for(int i=0; i< MAX_READER; i++) pthread_create(&reader_thread_id[i], NULL, reader, &i);
  for(int i=0; i< MAX_WRITER; i++) pthread_create(&writer_thread_id[i], NULL, writer, &i);

  for(int i=0; i< MAX_READER; i++) pthread_join(reader_thread_id[i], NULL);
  for(int i=0; i< MAX_WRITER; i++) pthread_join(writer_thread_id[i], NULL);
}
