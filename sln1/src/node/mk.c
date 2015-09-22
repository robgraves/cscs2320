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
    Node *this;                         //declaring pointer to this working node called this 

    this=(Node *)malloc(sizeof(Node));  //memory allocation for a Node pointer
    this->info=value;                   //setting the info inside Node to the value passed to function
    this->after=NULL;                   //setting the after pointer to NULL

	return(this);                       //returning pointer to this newly created node
}
