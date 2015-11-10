#ifndef _LIST_H
#define _LIST_H

#include "node.h"                           // list relies on node to work

struct list {
    Node              *first;               // pointer to start of list
    Node              *last;                // pointer to end of list
};

code_t  mklist  (List **);                  // create new list struct
code_t  cplist  (List  *, List **);         // duplicate list contents 
code_t  rmlist  (List **);                  // deallocate empty list

code_t  insert  (List **, Node *, Node  *); // add node before given node
code_t  append  (List **, Node *, Node  *); // add node after given node
code_t  obtain  (List **, Node **);         // disconnect node  from list

code_t  display (List  *, int);             // display list start to end
code_t  find    (List  *, char,   Node **); // locate node with value

code_t  compare (List  *, List *, ulli  *); // compare two lists
code_t  empty   (List **);                  // empty an existing list

code_t  sortlist(List **, int);             // sort list by mode
code_t  swapnode(List **, Node *, Node  *); // swap nodes in list
#endif
