#include <DoublyLinkedNode.h>

Node * DoublyLinkedNode :: copy()
{
    Node *newNode = NULL;

    newNode = new DoublyLinkedNode(this -> getValue());

    newNode -> setAfter(this -> getAfter());
    newNode -> setPrior(this -> getPrior());

	return (newNode);
}
