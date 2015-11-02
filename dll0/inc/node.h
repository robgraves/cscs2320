#ifndef _NODE_H
#define _NODE_H

//////////////////////////////////////////////////////////////////////
//
// Additional useful information in data.h
//
#include "data.h"

//////////////////////////////////////////////////////////////////////
//
// node struct definition
//
struct node {
    union  info      payload;
    struct node     *after;
    struct node     *prior;
};

//////////////////////////////////////////////////////////////////////
//
// function prototypes
//
code_t mknode(Node **, char);    // allocate new node containing value
code_t cpnode(Node  *, Node **); // duplicate node
code_t rmnode(Node **);          // deallocate node

#endif
