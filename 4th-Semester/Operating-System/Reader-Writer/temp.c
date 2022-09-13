#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include <pthread.h>
int values[10];
int i;
pthread_mutex_t lock;

void *producer(void *temp)
{
time_t t;
 srand((unsigned) time(&t));
 while(1)
   {
     if(i==10) break;
     
     pthread_mutex_lock(&lock);
     values[i] = rand()%50;
     printf("producer prodcued %d at position %d\n",values[i],i);
     i++;
     pthread_mutex_unlock(&lock);
   }
}

void *consumer( void *temp)
{
  while(1)
    {
      pthread_mutex_lock(&lock);
      printf("consumer consumed %d at position %d\n",values[i-1],i);
      values[i-1] = -1;
      i--;
      pthread_mutex_unlock(&lock);
      if(i<=0) break;
    }    
}

int main()
{
  pthread_t t1,t2;
  pthread_create(&t1,NULL,producer,(void*)NULL);
  pthread_create(&t2,NULL,consumer,(void*)NULL);
  pthread_join(t1,NULL);
  pthread_join(t2,NULL);
  
}
