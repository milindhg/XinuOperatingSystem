/* future_set.c - future_set */

#include <xinu.h>
#include "future.h"

/*------------------------------------------------------------------------
 *  future_set  -  Set a value in a future and changes state from FUTURE_EMPTY or FUTURE_WAITING to FUTURE_VALID
 *------------------------------------------------------------------------
 */
syscall future_set
	(
		future *f, int *value
	)
{
	if(f->state==FUTURE_EMPTY || f->FUTURE_WAITING)
	{
		f->value = *value;
		f-state = FUTURE_VALID;
		return OK;
	}
	if(f->state==FUTURE_VALID)
	{
		return SYSERR;
	}
	return SYSERR;
}
