#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include<sys/shm.h>

#define PWT 0.1
#define CWT 0.1


int main(){
  int number_fd = shmget(IPC_PRIVATE, sizeof(int), 0666 | IPC_CREAT);

  if(fork()==0){
    int* number = shmat(number_fd, NULL, 0);

    int sum=0;
    for(int i=0; i<10; i++) *number=i, sum+=i, sleep(PWT);
    printf("Producer found sum = %d\n",sum);
    exit(EXIT_SUCCESS);
  }

  if(fork()==0){
    int* number = shmat(number_fd, NULL, 0);

    int sum=0;
    for(int i=0; i<10; i++) printf("Got number %d.\n",*number), sum+=*number, sleep(CWT);
    printf("Consumer found sum = %d\n",sum);
    exit(EXIT_SUCCESS);
  }

  printf("Main Process Exiting.\n");
  return 0;
}
