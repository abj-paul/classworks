#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>
#include <stdlib.h>

int numberOfSeatsWR = 3;

#define MAX_CUSTOMER 7

#define wait(x) sem_wait(&x)
#define signal(x) sem_post(&x)

sem_t barberReady;
sem_t accessWRSeats;
sem_t customerReady;

// Functions
void* barber(void* temp);
void* customer(void* temp);

int main(){
	sem_init(&barberReady, 0, 1);
	sem_init(&accessWRSeats, 0, 1);
	sem_init(&customerReady, 0, 1);
	
	wait(barberReady);	
	wait(customerReady);	

	pthread_t thread_id[MAX_CUSTOMER];
	pthread_t barber_id;
	pthread_create(&barber_id, NULL, barber, (void*)NULL);
	for(int i=0; i<MAX_CUSTOMER; i++){
		int* copied_i = (int*)malloc(sizeof(int));
		*copied_i = i;
		pthread_create(&thread_id[i], NULL, customer, (void*)copied_i);
	}

	for(int i=0; i<MAX_CUSTOMER; i++) pthread_join(thread_id[i],NULL);
	wait(customerReady); //EDIT
	pthread_join(barber_id, NULL);

return 0;
}

void* barber(void* temp){
	while(1){
		wait(customerReady);
		printf("A customer has arrived to his room.\n");

		wait(accessWRSeats);
		numberOfSeatsWR++;
		signal(accessWRSeats);

		signal(barberReady);
		// Cut hair
		printf("The barber is serving the customer now.\n");
		sleep(1);
	}	
}

void* customer(void* temp){
	int customer_id = *(int*)temp;
	printf("Customer %d has arrived!\n",customer_id);
	wait(accessWRSeats);
	if(numberOfSeatsWR>0){
		numberOfSeatsWR--;
		signal(accessWRSeats);
		printf("Customer %d has sat in waiting room.\n",customer_id);
		signal(customerReady);
		wait(barberReady);
		printf("Customer %d is being served.\n",customer_id);
	}
	else{
		printf("Customer %d is leaving the shop as no seat is empty.\n",customer_id);
	       	signal(accessWRSeats);
	}
	return (void*)NULL;
}
