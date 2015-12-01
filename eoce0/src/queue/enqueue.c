#include "queue.h"

//////////////////////////////////////////////////////////////////////
//
//  enqueue() - place newNode onto back of given queue
//
//              be sure to utilize existing list and queue library
//              functions to facilitate your implementation. Do NOT
//              reinvent the wheel.
//
//              be mindful of bounded queue limits. A bounded
//              queue can overrun, an unbounded queue cannot.
//
//              the front of the queue should follow the first of
//              the underlying list; the back of the queue should
//              follow the last node of the list.
//
// status code: this function generates the following status codes
//                  DLQ_SUCCESS: normal operation (success!)
//                  DLQ_NULL:    queue is NULL
//                  DLQ_OVERRUN: tried to enqueue onto a full
//                               bounded queue (considered an error)
//                  DLQ_INVALID: queue does not exist
//                  DLQ_ERROR:   error encountered
//
//        note: you are to have only ONE return statement for this
//              entire function. Change the existing one as needed.
//
code_t enqueue(Queue **myQueue, Node *newNode)
{
    //variable and pointer declarations and initializations
    code_t result = 0;

	return (result);
}
