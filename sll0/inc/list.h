#ifndef _LIST_H
#define _LIST_H

#include "node.h"                       // list relies on node to work

struct list {
    Node *first;                        // pointer to start of list
    Node *last;                         // pointer to end of list
};
typedef struct list List;               // because we deserve nice things

List *mklist(void  );                   // create/allocate new list struct
List *insert (List *, Node *, Node *);  // add node before given node
void  displayf(List *, int);            // display list from start to end
int   getpos(List *, Node *);           // retrieve position from given node
Node *setpos(List *, int);              // seek to indicated node in list

#endif
