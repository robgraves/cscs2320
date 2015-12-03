#include <SinglyLinkedNode.h>

SinglyLinkedNode :: SinglyLinkedNode()
{
	this -> after = NULL;
	this -> setValue(0);
}

SinglyLinkedNode :: SinglyLinkedNode(int value)
{
	this -> setValue(value);
	this -> after = NULL;
}
