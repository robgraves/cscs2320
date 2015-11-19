#include "queue.h"

//////////////////////////////////////////////////////////////////////
//
//   cpqueue() - duplicate a given queue (especially the state of
//               its contents), in a new queue.
//
//               be sure to utilize existing list and queue library
//               functions to facilitate your implementation. Do NOT
//               reinvent the wheel.
//
//  status code: this function can generate the following status code
//                 DLQ_SUCCESS:     normal operation
//                 DLQ_CREATE_FAIL: *newQueue already exists
//                 DLQ_EMPTY:       curQueue is EMPTY
//                 DLQ_NULL:        queue is NULL
//                 DLQ_INVALID:     queue does not exist
//                 DLQ_ERROR:       an error occurred
//
//         note: you are to have only ONE return statement for this
//               entire function. Change the existing one as needed.
//
code_t cpqueue(Queue *curQueue, Queue **newQueue)
{
	// to be implemented (remove this comment upon completion)
	return (DLQ_DEFAULT_FAIL);
}
