#include <DoublyLinkedNode.h>

void DoublyLinkedNode :: setPrior(Node *priorNode)
{
    this -> prior = nextNode;
}

Node * DoublyLinkedNode :: getPrior()
{
	return(this -> prior);
}
