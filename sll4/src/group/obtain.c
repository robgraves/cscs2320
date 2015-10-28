#include "group.h"

//////////////////////////////////////////////////////////////////////
//
//  lobtain() - take and isolate indicated list out of group of lists,
//              through a careful adjustment of necessary pointers.
//              lobtain() needs to maintain group of lists integrity.
//              
//    behavior: on a NULL Group- do nothing; return NULL.
//              on a NULL thatList- do nothing; return Group as is
//
//        note: you are expected to make use of the lgetpos() and
//              lsetpos() functions to aid you in accomplishing this
//              task. Don't needlessly reinvent the wheel.
//
//              it is important to acknowledge that thatList, the one
//              being isolated from the group, is being passed in as a
//              double pointer (we're passing the List pointer by
//              reference). As such, you need to be mindful that you
//              need to dereference it once on each usage when in this
//              function to use it as you expect.
//
//              as with the other functions, you may use no more
//              than one return() statement per function.
//
Group *lobtain(Group *myListGroup, List **thatList)
{
	// your implementation here (please remove this comment when done)
	return(NULL);
}
