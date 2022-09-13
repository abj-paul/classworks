#include<stdio.h>
#include<pthread.h>
#include<unistd.h>
#include<stdlib.h>
#include<semaphore.h>

#define MAX_WRITER 3
#define MAX_READER 10

sem_t secure;
sem_t write_access;
int reader_count = 0;

void* reader(void* temp){

  sem_trywait(&secure);
  int reader_id = *(int*)temp;
  reader_count++;
  sem_post(&secure);

  // If reader enters, then writer will be locked
  if(reader_count==1) sem_trywait(&write_access);

  printf("Reader %d has entered.\n",reader_id);
  sleep(1);
  printf("Reader %d has exited.\n",reader_id);

  sem_trywait(&secure);
  reader_count--;
  sem_post(&secure);

  if(reader_count==0) sem_post(&write_access);
}

void* writer(void* temp){
  sem_trywait(&write_access);
  int writer_id = *(int*)temp;
  printf("Writer %d has entered.\n",writer_id);
  sleep(3);
  printf("Writer %d has exited.\n",writer_id);
  sem_post(&write_access);
}


int main(){

  sem_init(&secure, 0, 1);
  sem_init(&write_access, 0, 1);

  pthread_t reader_thread_id[MAX_READER];
  pthread_t writer_thread_id[MAX_WRITER];

  for(int i=0; i< MAX_READER+MAX_WRITER; i++) {
    int chance = rand()%10;
    if(chance>3) pthread_create(&reader_thread_id[i], NULL, reader, &i);
    else pthread_create(&reader_thread_id[i], NULL, writer, &i);
  }

  for(int i=0; i< MAX_READER; i++) pthread_join(reader_thread_id[i], NULL);
  for(int i=0; i< MAX_WRITER; i++) pthread_join(writer_thread_id[i], NULL);
}
