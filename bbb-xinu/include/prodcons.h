#include <xinu.h>
#include <stddef.h>
#include <stdio.h>
//#include <semaphore.h>

/* Global variable for producer and consumer */
extern int n;

/*declare the required semaphores*/
extern sid32 consumed, produced;

/* function prototype */
void consumer(int count);
void producer(int count);
