/****************************************************
** producerConsumer.c
** Evan Cummings
** CSCI 460 - Operating Systems
** Fall '11 - Doug Raiford
**
** Description:
**    A program which demonstrates the proper use
**    of POXIX threads and semaphores.
**    
*****************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>

#define TRUE 1

/* Let's assign a fancy name to our items to be 
produced and consumed. Now we can declare a variable
of type buffer_item when we want to produce or consume
an item*/
typedef int buffer_item;
#define BUFFER_SIZE 5

/* prototypes for insertion and removal functions  */
void insert_item(buffer_item item);
void remove_item(buffer_item *item);

/* declare buffer and three semaphores */
buffer_item buffer[BUFFER_SIZE];
pthread_mutex_t mutex;
sem_t empty;
sem_t full;

/*  Pointers for keeping track of where left off
    when inserting and removing */
int insertPointer = 0, removePointer = 0;

/*  prototypes for thread functions. When create a thread you
    pass the creation function a pointer to the function
    that you want the  thread to execute. These are them
    and they are definded below.*/
void *producer(void *param);
void *consumer(void *param);




int main(int argc, char *argv[])
{
  /* acquire the command line arguments. The user should pass
     the length of time that the program should run, how many
     producers there are and how many consumers
     usage: <run time> <num producers> <num consumers>
  
     Each producer and each consumer will be a thread.*/
  int i;
  int runTime;
  int numProducers;
  int numConsumers;
  int mutexInit;
  int emptyInit;
  int fullInit;
  
  /* make sure there were enough args. */
  if(argc != 4)
  {
    printf("need exactly 3 arguments\n");
    exit(0);
  }
  
  runTime = atoi(argv[1]);
  numProducers = atoi(argv[2]);
  numConsumers = atoi(argv[3]);
  
  /* Initialize the three locks */
  mutexInit = pthread_mutex_init(&mutex, NULL);
  if(mutexInit == 0) 
    printf("mutex inialized\n");
  else
    printf("error - mutex not inialized\n");
  
  emptyInit = sem_init(&empty, 0, BUFFER_SIZE);
  if(emptyInit == 0)
    printf("empty semaphore inialized\n");
  else
    printf("error - empty semaphore not inialized\n");
  
  fullInit = sem_init(&full, 0, 0);
  if(fullInit == 0)
    printf("full semaphore inialized\n");
  else
    printf("error - full semaphore not inialized\n");
  
  /* seed the random number generator with the time */
  srand(time(0));
  
  /* Create the producer threads */
  /* loop from 0 while less than number of producers */
  for(i = 0; i < numProducers; i++)
  {
    /* create a variable to store the thread id*/
    pthread_t tid;
    /* create a variable to store the thread attributes */
    pthread_attr_t attr;
    /* initialize the thread attributes */
    pthread_attr_init(&attr);
    /* create the thread */
    pthread_create(&tid, &attr, producer, NULL);
    /* Print the operation. */
    printf("created producer thread, id: %lu\n", (unsigned long)tid);
  }
  
  /* Create the consumer threads */
  /* loop from 0 while less than number of producers */
  for(i = 0; i < numProducers; i++)
  {
    /* create a variable to store the thread id*/
    pthread_t tid;
    /* create a variable to store the thread attributes */
    pthread_attr_t attr;
    /* initialize the thread attributes */
    pthread_attr_init(&attr);
    /* create the thread */
    pthread_create(&tid, &attr, consumer, NULL);
    /* Print the operation. */
    printf("created consumer thread, id: %lu\n", (unsigned long)tid);
  }
  
  /* Put this (the main) thread to sleap for a period of 
  time equal to the user passed argument for run time*/
  sleep(runTime);
  
  return 0;
}

void *producer(void *param)
{
  /* create a variable for a randomly generated buffer item */
  buffer_item item;
  
  /*  create a variable for randomly generated period of time 
      that producer will sleep just prior to producing each 
      item */
  int waitTime;
  
  /* infinite loop */
  while(TRUE)
  {
    /* generate a random number between 0 and 5 */
    waitTime = (rand() % 5);
    
    /* sleep for that period of time */
    sleep(waitTime);
    
    /*  generate a random number and store in variable 
        created above */
    item = rand();
    
    /*  Insert the item into the buffer using the insert_item 
        method (that you have to create, see below)*/
    insert_item(item);
    
  }

}


void *consumer(void *param)
{
  /* create a variable for a randomly generated buffer item */
  buffer_item *item = malloc(sizeof(buffer_item));
  
  /*  create a variable for randomly generated period of 
      time that producer will sleep just prior to 
      producing each item */
  int waitTime;
  
  /* infinite loop */
  while(TRUE)
  {
    /* generate a random number between 0 and 5 */
    waitTime = (rand() % 5);
    
    /* sleep for that period of time */
    sleep(waitTime);
    
    /* remove an item from the buffer utilizing the remove_item
    method (that you have to create, see below) */
    remove_item(item);
    
  }
  
}


void insert_item(buffer_item item)
{
  /* Acquire (wait on) Empty Semaphore */
  sem_wait(&empty);
  
  /* Acquire mutex lock to protect buffer */
  pthread_mutex_lock(&mutex);
  
  /*  Set the buffer at location "insertPointer" equal to the 
      passed item */
  buffer[insertPointer] = item;
  
  /* Increment the insertPointer */
  insertPointer += 1;
  
  /*  Mod the insertPointer with the buffer size in case it has
      to wrap around to beginning of buffer */
  insertPointer = insertPointer % BUFFER_SIZE;
  
  /* Release mutex lock and full semaphore */
  pthread_mutex_unlock(&mutex);
  sem_post(&full);
  
  /* Print the operation. */
  printf("produced id: %d\n", item);
  
}


void remove_item(buffer_item *item)
{
  /* Acquire (wait on) Full Semaphore */
  sem_wait(&full);
  
  /* Acquire mutex lock to protect buffer */
  pthread_mutex_lock(&mutex);
  
  /* Acquire item at location "removePointer" from buffer */
  *item = buffer[removePointer];
  
  /* Set value at that location in buffer to -1 */
  buffer[removePointer] = -1;
  
  /* Increment "removePointer" */
  removePointer += 1;
  
  /*  Mod removePointer with the size of of the buffer in case
      have wrapped in the buffer */
  removePointer = removePointer % BUFFER_SIZE;
  
  /* Release mutex lock and empty semaphore */
  pthread_mutex_unlock(&mutex);
  sem_post(&empty);
  
  /* Print the operation. */
  printf("consumed id: %d\n", *item);
  
}


