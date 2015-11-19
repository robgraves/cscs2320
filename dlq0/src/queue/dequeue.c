#include "queue.h"

//////////////////////////////////////////////////////////////////////
//
//  dequeue() - grab node off front of queue (queue is modified)
//              
//              be sure to utilize existing list and queue library
//              functions to facilitate your implementation. Do NOT
//              reinvent the wheel.
//
//              the front of the queue should follow the first of
//              the underlying list; the back of the queue should
//              follow the last node of the list.
//
//              the dequeued node pointer, if it exists, does not
//              need to be NULL; any existing content will be
//              discarded.
//
// status code: this function generates the following status codes
//                  DLN_INVALID:  dequeued node does not exist
//                  DLQ_SUCCESS:  normal operation
//                  DLQ_UNDERRUN: tried to dequeue() when empty
//                  DLQ_EMPTY:    queue is EMPTY
//                  DLQ_NULL:     queue is NULL
//                  DLQ_INVALID:  queue does not exist
//                  DLQ_ERROR:    error occurred (queue is NULL,
//                                underrun occurred, etc.)
//
//              as with the other functions, you may use no more
//              than one return() statement per function.
//
code_t dequeue(Queue **myQueue, Node **newNode)
{
	// to be implemented (remove this comment upon completion)
	return (DLQ_DEFAULT_FAIL);
}
