/* xsh_consumemory.c - xsh_consumemory */

#include <xinu.h>
#include <string.h>
#include <stdio.h>

/*------------------------------------------------------------------------
 * xsh_consumemory - consume memory but not release it 
 * //program introduced to avoid freeing stack space for process consumememory - assignment 6 Text problem 9.4
 *------------------------------------------------------------------------
 */
shellcmd xsh_consumemory(int nargs, char *args[]) {

	/* Output info for '--help' argument */

	if (nargs == 2 && strncmp(args[1], "--help", 7) == 0) {
		printf("Usage: %s\n\n", args[0]);
		printf("Description:\n");
		printf("\tConsumes memory\n");
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
		printf("Printing free memory block addresses and sizes respectively. \n");
		intmask	mask;			/* Saved interrupt mask		*/
		mask = disable();
		pid32 mypid = getpid();
		struct procent myproc = proctab[mypid];
		myproc.nofreestkflag = 1;
		char *value = (char)getmemory(sizeof(char));
		restore(mask);		
		return 0;
	}
	
	return 0;

}
