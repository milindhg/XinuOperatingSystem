/* xsh_hello.c - xsh_hello */

#include <xinu.h>
#include <string.h>
#include <stdio.h>

/*------------------------------------------------------------------------
 * xsh_hello - obtain username and print welcome message 
 *------------------------------------------------------------------------
 */
shellcmd xsh_hello(int nargs, char *args[]) {

	/* Output info for '--help' argument */

	if (nargs == 2 && strncmp(args[1], "--help", 7) == 0) {
		printf("Usage: %s\n\n", args[0]);
		printf("Description:\n");
		printf("\tDisplays the information about free memory blocks\n");
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
		printf("Printing free memoery block addresses and sizes respectively. ");
		intmask	mask;			/* Saved interrupt mask		*/
		struct	memblk	*prev, *curr;
		mask = disable();
		curr = memlist.mnext;
		while(curr!=null)
		{
			printf("Address: %p", &curr);
			printf("Length: %d", curr.mlength);
			printf("\n");
			curr = curr.mnext;
		}
		return 0;
	}
	
	return 0;

}
