#ifndef _NODE_H
#define _NODE_H

#include <stdlib.h>

struct node {
	char         info;
	struct node *after;
};
typedef struct node Node;

Node *mknode(char  );     // allocate new node containing value
Node *rmnode(Node *);     // deallocate node
Node *cpnode(Node *);     // duplicate node

#endif
