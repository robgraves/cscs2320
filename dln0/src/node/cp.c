#include "node.h"

//////////////////////////////////////////////////////////////////////
//
//    cpnode() - a node library function to duplicate a node and its 
//               contents -- it must call other functions as needed,
//               and take care to ensure all aspects of the source
//               node have been successfully replicated in the
//               copied/destination node.
//
//               be sure to utilize existing node library functions
//               to facilitate your implementation. Do NOT reinvent
//               the wheel.
//
// status codes:
//               DLN_SUCCESS:       no problems encountered
//               DLN_MALLOC_FAIL:   error on creation
//               DLN_ALREADY_ALLOC: destination node already exists
//               DLN_NULL:          node in NULL state
//               DLN_ERROR:         some error occurred
//               DLN_INVALID:       invalid use (NULL pointer)
//
//         NOTE: you are to have only ONE return statement for this
//               entire function. Change the existing one as needed.
//
//               the contents of the "after" and "prior" pointers,
//               if non-NULL in the source node, should also be
//               copied. Do not just set them to NULL.
//
//               payload's duplication is to focus on the pointer,
//               NOT to whatever it may point at.
//
code_t cpnode(Node *oldNode, Node **copiedNode)
{
	// to be implemented (please remove this comment upon completion)
	return(DLN_DEFAULT_FAIL);
}
