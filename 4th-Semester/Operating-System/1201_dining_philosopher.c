#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#define NUM_PHILOSOPHERS 5
#define NUM_CHOPSTICKS 5

void dine(int n);
pthread_t philosopher[NUM_PHILOSOPHERS];
sem_t chopstick[NUM_CHOPSTICKS];

int main(){
  int status_message;
  void *msg;

  for (int i = 1; i <= NUM_CHOPSTICKS; i++){
    status_message = sem_init(&chopstick[i], 0, 1);
    if (status_message == -1){ printf("\n Mutex initialization failed");exit(1); }
  }

  for (int i = 1; i <= NUM_PHILOSOPHERS; i++){
    status_message = pthread_create(&philosopher[i], NULL, (void *)dine, (int *)i);
    if (status_message != 0){ printf("\n Thread creation error \n"); exit(1);}
  }

  for (int i = 1; i <= NUM_PHILOSOPHERS; i++){
    status_message = pthread_join(philosopher[i], &msg);
    if (status_message != 0){
      printf("\n Thread join failed \n");
      exit(1);
    }
  }

  return 0;
}
void dine(int n)
{
  printf("\nPhilosopher % d is thinking ", n);

  sem_trywait(&chopstick[n]);
  sem_trywait(&chopstick[(n + 1) % NUM_CHOPSTICKS]);
  printf("\nPhilosopher % d is eating ", n);
  sleep(3);
  sem_post(&chopstick[n]);
  sem_post(&chopstick[(n + 1) % NUM_CHOPSTICKS]);

  printf("\nPhilosopher % d Finished eating ", n);
} 

