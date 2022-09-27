#include <stdio.h>
#include "task.h"
#include <semaphore.h>
#include <pthread.h>
#include <stdlib.h>

#define lock(x) sem_trywait(x)
#define unlock(x) sem_post(x)
#define max(a,b) (((a) < (b)) ? (b) : (a))

sem_t queueMutex;
sem_t exclusiveAccessMutex;
sem_t readerMutex;

int readerCount = 0;

void Reader(int threadId){
  lock(&queueMutex);

  lock(&readerMutex);
  readerCount++;
  if(readerCount==1) lock(&exclusiveAccessMutex);
  unlock(&queueMutex); // If I have locked the resource or find it locked, it means i can read the resource safely now. So i will exit the waiting queue now.
  unlock(&readerMutex);

  readResource(threadId);

  lock(&readerMutex);
  readerCount--;
  if(readerCount==0) unlock(&exclusiveAccessMutex);
  unlock(&readerMutex);
}

void Writer(int threadId){
  lock(&queueMutex);

  lock(&exclusiveAccessMutex);
  unlock(&queueMutex); // If i get exclusiveAccess, it means I can write now. So i will get out of the queue.

  writeResource(threadId);

  unlock(&exclusiveAccessMutex);
}

void* wrapperReader(void* value){
  int threadId = *(int*)value;
  Reader(threadId);
}

void* wrapperWriter(void* value){
  int threadId = *(int*)value;
  Writer(threadId);
}


int main(){
  int nWriter = 5;
  int nReader = 15;

  sem_init(&queueMutex, 0, 1);
  sem_init(&exclusiveAccessMutex, 0, 1);
  sem_init(&readerMutex, 0, 1);

  pthread_t thread_id[nWriter+nReader];

  for(int i=0; i<max(nWriter, nReader); i++){
    int* id = (int*)malloc(sizeof(int));
    *id = i;
    if(i<nWriter) pthread_create(&thread_id[i], NULL, wrapperWriter, (void*)id);
    if(i<nReader) pthread_create(&thread_id[nWriter+i], NULL, wrapperReader, (void*)id);
    //free(id);
  }

  for(int i=0; i<nWriter+nReader; i++) pthread_join(thread_id[i],NULL);
  return 0;
}
