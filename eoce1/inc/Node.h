#ifndef _NODE_H
#define _NODE_H

#include <cstdlib>

class Node {
    public:
             Node();
             Node(int);
        void setValue(int);
        int  getValue();
		virtual Node *copy() = 0;
		virtual void  setAfter(Node *) { };
		virtual Node *getAfter()       { return (NULL); };
		virtual void  setPrior(Node *) { };
		virtual Node *getPrior()       { return (NULL); };
		virtual ~Node();

    private:
        int  value;
};

#endif
