#include "prodcons.h"

void consumer(int count)
{
	while(n<=count)
	{
		wait(produced);	
		printf("consumed : %d\n", n);
		signal(consumed);	
	}
}
