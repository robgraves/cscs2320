#include <SinglyLinkedNode.h>

SinglyLinkedNode :: ~SinglyLinkedNode()
{
	this -> setValue(0);
	this -> after = NULL;
}
