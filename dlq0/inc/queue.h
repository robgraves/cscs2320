#ifndef _QUEUE_H
#define _QUEUE_H

//////////////////////////////////////////////////////////////////////
//
// Queue relies on list (which relies on node) to work.
//
#include "list.h"

//////////////////////////////////////////////////////////////////////
//
// Define the queue struct
//
struct queue {
    Node *front;                       // pointer to front of queue
    Node *back;                        // pointer to back of queue
    List *data;                        // pointer to queue data
    ulli  buffer;                      // queue length (0- unbounded)
};

code_t    mkqueue(Queue **, ulli    ); // create new queue (of length)
code_t    cpqueue(Queue  *, Queue **); // create a copy of a queue
code_t    rmqueue(Queue **          ); // de-allocate a queue

code_t    purge  (Queue **          ); // clear an existing queue

code_t    enqueue(Queue **, Node  * ); // add node to back of queue
code_t    dequeue(Queue **, Node ** ); // grab node at front of queue

#endif
