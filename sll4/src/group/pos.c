#include "group.h"

//////////////////////////////////////////////////////////////////////
//
// lgetpos() - a group library utility function to identify the actual
//             position of a given list in an indicated list group.
//
//       note: Indexing of the group starts from 0
//
//   behavior: on error (NULL group or given list), return negative
//             value (-1), on out-of-bounds condition, return -2
//
//             you are to have only ONE return statement for this
//             entire function. Change the existing one as needed.
//
long int lgetpos(Group *myListGroup, List *given)
{
	// your implementation here (please remove this comment when done)
	return(-1);
}

//////////////////////////////////////////////////////////////////////
//
// lsetpos() - a group library utility function to set a list pointer
//             to the list at the indicated position of a group.
//
//       note: Indexing of the group starts from 0
//
//   behavior: on error (NULL group or negative/out-of-bounds pos),
//             return NULL.
//
//             you are to have only ONE return statement for this
//             entire function. Change the existing one as needed.
//
List *lsetpos(Group *myListGroup, long int pos)
{
	// your implementation here (please remove this comment when done)
	return(NULL);
}
