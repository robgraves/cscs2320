#ifndef _DOUBLY_NODE
#define _DOUBLY_NODE

#include <SinglyLinkedNode.h>

class DoublyLinkedNode : public SinglyLinkedNode {
    public:
        DoublyLinkedNode();
        DoublyLinkedNode(int);
        virtual Node *copy();
        void setPrior(Node *);
        Node *getPrior();
        ~DoublyLinkedNode();
    
    private:
        Node *prior;
};

#endif
