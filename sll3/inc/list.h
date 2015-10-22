#ifndef _LIST_H
#define _LIST_H

#include "node.h"                       // list relies on node to work

struct list {
    Node              *first;           // pointer to start of list
    Node              *last;            // pointer to end of list
    struct list       *after;           // pointer to the next list
    unsigned long int  qty;             // number of nodes in list
};
typedef struct list            List;    // because we deserve nice things
typedef unsigned long long int ulli;    // short name for biggest space
typedef unsigned char          uc;      // shorter name for smallest space

List *mklist(void  );                   // create/allocate new list struct
List *cplist(List *);                   // duplicate list contents 
List *rmlist(List *);                   // deallocate empty list

List *insert (List *, Node *, Node *);  // add node before given node
List *append (List *, Node *, Node *);  // add node after given node
List *obtain (List *, Node **);         // obtain/disconnect node from list

void  displayf(List *, int);            // display list from start to end
void  displayb(List *, int);            // display list in reverse order

int   getpos(List *, Node *);           // retrieve position from given node
Node *setpos(List *, int   );           // seek to indicated node in list

uc    compare(List *, List *, ulli *);  // compare two lists for equality

Node *searchlist(List *, char);         // locate node containing value
List *clearlist(List *);                // empty an existing list

List *sortlist  (List *, int);          // sort list (according to mode)
List *swapnode(List *, Node *, Node *); // swap positions of given nodes in list

// return status codes
//
#define CMP_EQUALITY    0x00
#define CMP_L1_NULL     0x01
#define CMP_L1_EMPTY    0x02
#define CMP_L1_GREATER  0x04
#define CMP_L1_LESS     0x08
#define CMP_L2_NULL     0x10
#define CMP_L2_EMPTY    0x20
#define CMP_L2_GREATER  0x40
#define CMP_L2_LESS     0x80

#endif
