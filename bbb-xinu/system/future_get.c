/* future_get.c - future_get */

#include <xinu.h>
#include "future.h"

/*------------------------------------------------------------------------
 *  future_get  -  Get the value of a future set by an operation
 *------------------------------------------------------------------------
 */
syscall future_get
	(
		future *f, int *value
	)
{
	if(f->state==FUTURE_EMPTY)
	{
		f-state = FUTURE_WAITING;
	}
	if(f->state==FUTURE_WAITING)
	{
		return SYSERR;
	}
	if(f->state==FUTURE_VALID)
	{
		*value = f->value;
		f->state = FUTURE_EMPTY;
		return OK;
	}
	return SYSERR;
}

