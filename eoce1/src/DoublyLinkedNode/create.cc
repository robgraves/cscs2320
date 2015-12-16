#include <DoublyLinkedNode.h>

DoublyLinkedNode :: DoublyLinkedNode()
{
    this -> setAfter(NULL);
    this -> prior = NULL;
    this -> setValue(0);
}

DoublyLinkedNode :: DoublyLinkedNode(int value)
{
    this -> setValue(value);
    this -> setAfter(NULL);
    this -> prior = NULL;
}
