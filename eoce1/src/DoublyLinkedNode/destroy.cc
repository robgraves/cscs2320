#include <DoublyLinkedNode.h>

DoublyLinkedNode :: ~DoublyLinkedNode()
{
    this -> setValue(0);
    this -> setAfter(NULL);
    this -> prior = NULL;
}
