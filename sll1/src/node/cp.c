#include "node.h"

//////////////////////////////////////////////////////////////////////
//
// cpnode() - a node library function to duplicate a node and its 
//            contents -- it must call other functions as needed, and
//            take care to ensure all aspects of the source node have
//            been successfully replicated in the copied node.
//
//  behavior: on error or NULL source node, return NULL.
//
//      NOTE: you are to have only ONE return statement for this
//            entire function. Change the existing one as needed.
//
//            the contents of the "after" pointer, if non-NULL,
//            should be pointing to any next node (even though we
//            are not copying it here).
//
Node *cpnode(Node *curNode)
{
	Node *this;                     //declaring Node pointer for this new node
	this=NULL;                      //setting this Node pointer to NULL
		
	if (curNode != NULL)           //if statement checking for if the passed Node is NULL to fall through
	{
		this=mknode(curNode->info); //creating a new node callign mknode() with info from passed node
		this->after=curNode->after; //setting the after pointer to the same as passed node's after
	}

	return(this);                   //returning pointer to this node
}
