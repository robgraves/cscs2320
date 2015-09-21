#include "node.h"

//////////////////////////////////////////////////////////////////////
//
// mknode() - a node library function to allocate and initialize a 
//            new node.
//
//  behavior: on error, return NULL.
//
//      NOTE: you are to have only ONE return statement for this
//            entire function. Change the existing one as needed.
//
Node *mknode(char value)
{
    Node *this; 

    this=(Node *)malloc(sizeof(Node));
    this->info=value;
    this->after=NULL;

	return(this);
}
