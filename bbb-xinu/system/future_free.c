/* future_free.c - future_free */

#include <xinu.h>
#include "future.h"

/*------------------------------------------------------------------------
 *  future_free  -  Free the allocated future
 *------------------------------------------------------------------------
 */
syscall future_free
	(
		future* f
	)
{
	uint32 nbytes;
	
	nbytes = sizeof(f);
	freemem(f, nbytes);
	return OK;
}
