/* xsh_getmaxstklen.c - xsh_getmaxstklen */

#include <xinu.h>
#include <string.h>
#include <stdio.h>

/*------------------------------------------------------------------------
 * xsh_getmaxstklen - obtain username and print welcome message 
 *------------------------------------------------------------------------
 */
int factorial(int num)
{
	if(num==1)
	{
		return 1;
	}
	else
	{
		return num * factorial(num-1);
	}
}
 
shellcmd xsh_getmaxstklen(int nargs, char *args[]) {

	/* Output info for '--help' argument */

	if (nargs == 2 && strncmp(args[1], "--help", 7) == 0) {
		printf("Usage: %s\n\n", args[0]);
		printf("Description:\n");
		printf("\tDisplays the max stack length of the process to the user\n");
		printf("\t--help\tdisplay this help and exit\n");
		return 0;
	}

	/* Check argument count */

	if (nargs > 1) {
		fprintf(stderr, "%s: too many arguments\n", args[0]);
		fprintf(stderr, "Try '%s --help' for more information\n",
			args[0]);
		return 1;
	}


	if (nargs == 1) {
		pid32 mypid = getpid();
		struct procent myproc = proctab[mypid];
		char *mystkbase = myproc.prstkbase;
		char *mystkptr;
		mystkptr = myproc.prstkptr;
		uint32 mystklen = myproc.prstklen;
		char *start,*end;
		start=mystkptr;
		end = mystkbase - mystklen;
		while(start>end)
		{
			start--;
			*start = 'F';
			kprintf("Setting FFFFFF\n");
		}
		kprintf("end is: %d \n", end);
		kprintf("end value is: 0x%08x \n", *end);
		kprintf("end value is: %d \n", *end);
		kprintf("end value is: %d \n", *(end+1));
		
		factorial(5);
		char *trav;
		trav = end;
		uint32 i=0;
		kprintf("trav is: %d \n", trav);
		kprintf("trav value is: 0x%08x \n", *trav);
		kprintf("trav value is: %d \n", *trav);
		kprintf("trav value is: %d \n", *(trav+1));
		while(*trav=='F')
		{
			kprintf("Got FFFFFF!!! \n");
			trav++;
			i++;
		}
		
		uint32 maxstklen = mystklen - i;
		kprintf("The maximum stack space used by the process is: %d \n", maxstklen);
		kprintf("The mystklen is: %d \n", mystklen);
		kprintf("i is: %d \n", i);
		
		return 0;
	}
	
	return 0;

}
