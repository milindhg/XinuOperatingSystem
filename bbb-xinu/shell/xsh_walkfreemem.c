/* xsh_walkfreemem.c - xsh_walkfreemem */

#include <xinu.h>
#include <string.h>
#include <stdio.h>

/*------------------------------------------------------------------------
 * xsh_walkfreemem - obtain username and print welcome message 
 *------------------------------------------------------------------------
 */
shellcmd xsh_walkfreemem(int nargs, char *args[]) {

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
		printf("Printing free memory block addresses and sizes respectively. \n");
		intmask	mask;			/* Saved interrupt mask		*/
		struct	memblk	*prev, *curr;
		mask = disable();
		curr = memlist.mnext;
		while(curr!=NULL)
		{
			printf("Address: (0x%08x)", curr);
			//printf("%10d bytes (0x%08x) of Xinu code\n", code, code);M
			printf("\tLength: %10d bytes", curr->mlength);
			printf("\n");
			curr = curr->mnext;
		}
		restore(mask);		
		return 0;
	}
	
	return 0;

}
