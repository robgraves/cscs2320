#include <SinglyLinkedNode.h>

void SinglyLinkedNode :: setAfter(Node *nextNode)
{
	this -> after = nextNode;
}

Node * SinglyLinkedNode :: getAfter()
{
	return(this -> after);
}
