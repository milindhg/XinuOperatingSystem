#include "prodcons.h"

void producer(int count)
{
      n = 0;
	  while(n <= count)
	  {
		  printf("produced : %d\n",n);
		  n++;
	  }
}
