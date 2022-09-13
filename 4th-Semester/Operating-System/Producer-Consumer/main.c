// Thread

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

#define MAX_JOB 100
int job_list[MAX_JOB];
int latest_job_index = 0;

pthread_mutex_t mutex;

void print_array(char* msg, int arr[], int arr_size){
  printf("%s",msg);
  for(int i=0; i<arr_size; i++) printf("%d ",arr[i]);
  printf("\n");
}

void* producer(void* temp){
  while(1){
  int rand_num = rand() % 1000;

  pthread_mutex_lock(&mutex);
  job_list[latest_job_index] = rand_num;
  latest_job_index++;
  printf("Producer has produced %d\n",rand_num);
  print_array("Jobs: ", job_list, latest_job_index);

  latest_job_index %= MAX_JOB;
  pthread_mutex_unlock(&mutex);
  }
}
void* consumer(void* temp){
  while(1){
  pthread_mutex_lock(&mutex);
  int consumedValue = job_list[latest_job_index-1];
  latest_job_index--;
  printf("Consumer has consumed %d\n",consumedValue);
  print_array("Jobs: ", job_list, latest_job_index);

  latest_job_index = latest_job_index>0?latest_job_index % MAX_JOB : 0;
  pthread_mutex_unlock(&mutex);
  }
}


int main(){

  pthread_t thread_id[2];
  pthread_create(&thread_id[0], NULL, producer,(void*)NULL);
  pthread_create(&thread_id[1], NULL, consumer,(void*)NULL);

  for(int i=0; i<2; i++) pthread_join(thread_id[0],NULL);
  
  return 0;
}
