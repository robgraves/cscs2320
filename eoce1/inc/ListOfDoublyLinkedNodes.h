#ifndef _DOUBLY_LIST_H
#define _DOUBLY_LIST_H

#include <DoublyLinkedNode.h>
#include <ListOfSinglyLinkedNodes.h>

class ListOfDoublyLinkedNodes : public ListOfSinglyLinkedNodes {
	public:
		ListOfDoublyLinkedNodes();

		virtual List *copy();

		virtual void  append(Node *, Node *);
		virtual void  insert(Node *, Node *);
		virtual Node *obtain(Node *);

		virtual void  display(int);
		virtual Node *find(int);

		virtual ~ListOfDoublyLinkedNodes();

	protected:
		virtual Node *setListPosition(int)    { return (NULL); };
		virtual int   getListPosition(Node *) { return (-1);   };
};

#endif
