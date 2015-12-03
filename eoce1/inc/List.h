#ifndef _LIST_H
#define _LIST_H

#include <Node.h>

class List {
    public:
        List();

        virtual List *copy()                   = 0;
        int   getQuantity();

        virtual void  append(Node *, Node *)   = 0;
        virtual void  insert(Node *, Node *)   = 0;
        virtual Node *obtain(Node *)           = 0;

        virtual void  display(int)             = 0;
        virtual Node *find(int)                = 0;

        virtual Node *getFirst()               = 0;
        virtual Node *getLast()                = 0;

        virtual ~List();

    protected:
        void  setQuantity(int);

        virtual void  setFirst(Node *)         = 0;
        virtual void  setLast  (Node *)        = 0;

        virtual Node *setListPosition(int)     = 0;
        virtual int   getListPosition(Node *)  = 0;

    private:
        int   quantity;
};

#endif
