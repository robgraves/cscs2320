#include "group.h"

//////////////////////////////////////////////////////////////////////
//
//  linsert() - add a new list to the given list group before the list
//              at the indicated place. linsert() needs to manage
//              the necessary connections (pointers) to maintain list
//              group integrity, along with ensuring the first and
//              last indicators of the list group remain relevant
//              and up-to-date.
//
//    behavior: on a NULL group- do nothing; return NULL.
//              on a NULL newList- do nothing; return group as is
//
//        note: you are expected to make use of the lgetpos() and
//              lsetpos() functions to aid you in accomplishing this
//              task. Don't needlessly reinvent the wheel.
//
//              as with the other functions, you may use no more
//              than one return() statement per function.
//
Group *linsert(Group *myListGroup, List *place, List *newList)
{
	// your implementation here (please remove this comment when done)
	return(NULL);
}
