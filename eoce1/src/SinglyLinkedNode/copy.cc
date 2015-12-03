#include <SinglyLinkedNode.h>

Node * SinglyLinkedNode :: copy()
{
	Node *newNode = NULL;
	
	newNode = new SinglyLinkedNode(this -> getValue());

	newNode -> setAfter(this -> getAfter());

	return (newNode);
}
