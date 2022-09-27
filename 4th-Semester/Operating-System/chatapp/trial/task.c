#include "task.h"

int sharedData=0;

void writeResource(int threadId){
  sharedData += 2;
  printf("Thread %d wrote %d\n",threadId, sharedData);
}

void readResource(int threadId){
  printf("Thread %d reads %d\n",threadId, sharedData);
}
