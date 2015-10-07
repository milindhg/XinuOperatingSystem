/* future_alloc.c - future_alloc */

#include <xinu.h>
#include "future.h"

/*------------------------------------------------------------------------
 *  future_alloc  -  allocate a new future in given mode. (Allocate memory to future)
 *------------------------------------------------------------------------
 */
future*	future_alloc(
	  int future_flags
	)
{
	struct future *f;  	/* Pointer to future */
	int *value;
	int flag, state;
	pid32 pid;

	*f = getmem(sizeof *f);
	if(f)
	{
		*value = getmem(sizeof *value);
		flag = future_flags;
		state = FUTURE_EMPTY;
		pid = *(sizeof pid32);
		return f;
	}
	else
	{
		return NULL;
	}

}
