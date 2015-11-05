/* xsh_getmaxstklen.c - xsh_getmaxstklen */

#include <xinu.h>
#include <string.h>
#include <stdio.h>

/*------------------------------------------------------------------------
 * xsh_hello - obtain username and print welcome message 
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
		printf("hello %s, Welcome to the world of Xinu!!\n", args[1]);	
		pid32 mypid = getpid();
		struct procent myproc = proctab[mypid];
		char *mystkbase = myproc.prstkbase;
		char *mystkptr = myproc.prstkptr;
		uint32 mystklen = myproc.prstklen;
		char *start,*end;
		start=mystkptr;
		end = mystkbase + mystklen;
		while(start<end)
		{
			start++;
			*start = 0xFFFFFFFF;
		}
		
		factorial(5);
		char *trav;
		trav = end;
		uint32 i=0;
		while(*trav==0xFFFFFFFF)
		{
			trav--;
			i++;
		}
		
		uint32 maxstklen = mystklen - i;
		printf("The maximum stack space used by the process is: %d", maxstklen);
		return 0;
	}
	
	return 0;

}
