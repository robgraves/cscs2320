#ifndef _SINGLY_NODE
#define _SINGLY_NODE

#include <Node.h>

class SinglyLinkedNode : public Node {
	public:
			 SinglyLinkedNode();
			 SinglyLinkedNode(int);
		virtual Node *copy();
		void setAfter(Node *);
		Node *getAfter();
			~SinglyLinkedNode();
	
	private:
		Node *after;
};

#endif
