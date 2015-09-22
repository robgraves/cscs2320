#include "node.h"

//////////////////////////////////////////////////////////////////////
//
// rmnode() - a node library function to clear and deallocate an 
//            existing node
//
//      NOTE: you are to have only ONE return statement for this
//            entire function. Change the existing one as needed.
//
Node *rmnode(Node *oldNode)
{
	if (oldNode != NULL)      //if statement checking that passed Node isn't set to NULL, exits if it is
	{
		oldNode->after=NULL;  //setting the after pointer in the to be deallocated node to NULL
		free(oldNode);        //deallocating the passed node
		oldNode=NULL;         //setting OldNode to NULL
	}

	return(oldNode);         
}
