#include <ListOfSinglyLinkedNodes.h>

ListOfSinglyLinkedNodes :: ~ListOfSinglyLinkedNodes()
{
	// Breaking it up into separate steps...
/*	Node *tmpNode              = NULL;
	while (this -> getFirst() != NULL)
	{
		tmpNode                = this -> getFirst();
		tmpNode                = this -> obtain(tmpNode);
		delete (tmpNode);
	} */

	// Optimizing the above, doing it in one step...
	while (this -> getFirst() != NULL)
	{
		delete (this -> obtain(this -> getFirst()));
	}

	// Set members to sane values...
	this -> setFirst(NULL);
	this -> setLast  (NULL);
	this -> setQuantity(0);
}
