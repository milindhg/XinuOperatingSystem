/* xsh_reset.c - xsh_reset */

#include <xinu.h>
#include <string.h>
#include <stdio.h>

/*------------------------------------------------------------------------
 * xsh_reset - to reset the BBB 
 *------------------------------------------------------------------------
 */
shellcmd xsh_reset(int nargs, char *args[]) {

	if (nargs == 2 && strncmp(args[1], "--help", 7) == 0) {
		printf("Usage: %s [Integer]\n\n", args[0]);
		printf("Description:\n");
		printf("\tReset Program\n");
		printf("\t--help\tdisplay this help and exit\n");
		return 0;
	}

	/* Check argument count */

	if (nargs < 2) {
		volatile uint32 *prm_rstctrl = (volatile uint32 *) 0x44E00F00;


*prm_rstctrl = 0x01;

        return 0;
	
	}

	if (nargs > 1) {
                fprintf(stderr, "%s: too many arguments\n", args[0]);
                fprintf(stderr, "Try '%s --help' for more information\n",
                        args[0]);
                return 1;
        }


}
