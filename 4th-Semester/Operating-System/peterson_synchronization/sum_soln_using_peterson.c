#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <sys/shm.h>

#define PWT 0.1
#define CWT 0.1

int main(){
  int PRODUCER=0, CONSUMER=1;

  int number_fd = shmget(IPC_PRIVATE, sizeof(int), 0666 | IPC_CREAT);
  int turn_fd = shmget(IPC_PRIVATE, sizeof(int), 0666 | IPC_CREAT);
  int flags_fd = shmget(IPC_PRIVATE, sizeof(bool)*2, 0666 | IPC_CREAT);


  if(fork()==0){ // Producer
    int* number = shmat(number_fd, NULL, 0);
    int* turn = shmat(turn_fd, NULL, 0);
    bool* flags = shmat(flags_fd, NULL, 0);

    int sum=0;

    flags[PRODUCER] = true;
    *turn = CONSUMER;

    for(int i=0; i<10; i++) {
      while(*turn==CONSUMER && flags[CONSUMER]) ;
      // Critrical Section starts here
      *number=i, sum+=*number;
      printf("Producer produces %d\n",*number);
      // Critrical Section ends here
      flags[PRODUCER] = false;
      sleep(PWT);
    }
    printf("Producer sum = %d\n",sum);

    exit(EXIT_SUCCESS);
  }

  if(fork()==0){  //Consumer
    int* number = shmat(number_fd, NULL, 0);
    int* turn = shmat(turn_fd, NULL, 0);
    bool* flags = shmat(flags_fd, NULL, 0);

    int sum=0;
    /* sleep(CWT/10); */

    flags[CONSUMER] = true;
    *turn = PRODUCER;

    for(int i=0; i<10; i++) {
      while(*turn==PRODUCER && flags[PRODUCER]) ;
      // Critrical Section starts here
      sum+=*number;
      printf("Consumer Consumes %d\n",*number);
      // Critrical Section ends here
      flags[CONSUMER] = false;
      sleep(CWT);
    }
    printf("Consumer sum = %d\n",sum);

    exit(EXIT_SUCCESS);
  }
  
  return 0;
}

