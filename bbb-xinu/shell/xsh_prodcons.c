#include <prodcons.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/* Global variable definition */
int n;

shellcmd xsh_prodcons(int nargs, char *args[])
{
	int count = 2000;
	
	/* Output info for '--help' argument */

	if (nargs == 2 && strncmp(args[1], "--help", 7) == 0) {
		printf("Usage: %s [Integer]\n\n", args[0]);
		printf("Description:\n");
		printf("\tProducer Consumer Program\n");
		printf("\tInteger is optional int argument.");
		printf("Options (one per invocation):\n");
		printf("\t--help\tdisplay this help and exit\n");
		return 0;
	}
	
	/* Check argument count */

	if (nargs > 2) {
                fprintf(stderr, "%s: too many arguments\n", args[0]);
                fprintf(stderr, "Try '%s --help' for more information\n",
                        args[0]);
                return SYSERR;
        }

	if (nargs == 2) {
		int i;
		for(i=0; i<strlen(args[1]); i++)
		{
			if(!isdigit(args[1][i]))
			{
                fprintf(stderr, "%s: invalid argument. the argument should be an integer value.\n", args[0]);
                fprintf(stderr, "Try '%s --help' for more information\n",
                        args[0]);
                return SYSERR;
			}
		}
		int num = atoi(args[1]);
		count = num;
		return 0;
	}
		
		
	printf("count is %d",count);	
}
