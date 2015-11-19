#ifndef _STACK_H
#define _STACK_H

//////////////////////////////////////////////////////////////////////
//
// Stack relies on list (which relies on node) to work.
// See the layers?
//
#include "list.h"

//////////////////////////////////////////////////////////////////////
//
// Define the stack struct
//
struct stack {
    Node              *top;            // pointer to top of stack
    List              *data;           // pointer to stack data
    ulli               size;           // size of stack
};

code_t  mkstack(Stack **, ulli);       // create new stack of size
code_t  cpstack(Stack  *, Stack **);   // duplicate stack 
code_t  rmstack(Stack **);             // deallocate stack

code_t  push   (Stack **, Node   *);   // add new node onto stack
code_t  pop    (Stack **, Node  **);   // grab node off of stack
code_t  peek   (Stack  *, Node  **);   // show top node of stack

code_t  isempty(Stack  *);             // check stack emptiness

#endif
