#ifndef _SINGLY_LIST_H
#define _SINGLY_LIST_H

#include <List.h>
#include <SinglyLinkedNode.h>

class ListOfSinglyLinkedNodes : public List {
    public:
        ListOfSinglyLinkedNodes();

        virtual List *copy();

        virtual void  append(Node *, Node *);
        virtual void  insert(Node *, Node *);
        virtual Node *obtain(Node *);

        virtual void  display(int);
        virtual Node *find(int);

        Node *getFirst();
        Node *getLast();

        virtual ~ListOfSinglyLinkedNodes();

    protected:
        void  setFirst(Node *);
        void  setLast  (Node *);

        virtual Node *setListPosition(int);
        virtual int   getListPosition(Node *);
    
    private:
        Node *first;
        Node *last;
};

#endif
