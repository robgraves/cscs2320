#include "queue.h"

//////////////////////////////////////////////////////////////////////
//
//  rmqueue() - unset, nullify members, and de-allocate the given 
//              queue. You may want to call purge() to help.
//
//              be sure to utilize existing list and queue library
//              functions to facilitate your implementation.
//
// status code: this function can generate the following status codes
//                  DLQ_SUCCESS: no problems encountered
//                  DLQ_NULL:    normal operation
//                  DLQ_INVALID: queue does not exist
//                  DLQ_ERROR:   error encountered (or queue was
//                               already NULL)
//
//        note: you are to have only ONE return statement for this
//              entire function. Change the existing one as needed.
//
code_t rmqueue(Queue **curQueue)
{
	// to be implemented (remove this comment upon completion)
	return (DLQ_DEFAULT_FAIL);
}
