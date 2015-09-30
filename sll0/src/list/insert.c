#include "list.h"

//////////////////////////////////////////////////////////////////////
//
//   insert() - add a new node to the given list before the node
//              at the indicated place. insert() needs to manage
//              the necessary connections pointers) to maintain list
//              integrity, along with ensuring the start and end
//              indicators of the list remain relevant and up-to-date.
//
//    behavior: on a NULL list- allocate a list and proceed
//              on a NULL newNode- return list as is
//
//        note: you are expected to make use of the getpos() and
//              setpos() functions to aid you in accomplishing this
//              task. Don't needlessly reinvent the wheel.
//
//              as with the other functions, you may use no more
//              than one return() statement per function.
//
List *insert(List *myList, Node *place, Node *newNode)
{
    int i = 0;
    int pos = 0;
    Node *tmp = NULL;

    if (myList == NULL)
    {
        myList = mklist();
        myList->first = newNode;
        myList->last = newNode;
    }
    else
    {
        if (newNode != NULL)
        {
            //newNode->after = getpos(myList, place);
            //setpos(myList, getpos(myList, place) - 1)->after = newNode;
            pos = getpos(myList, place);
            if (pos == -1)
            {
                myList->first = newNode; 
                myList->last = newNode;
            }
            else
            {
                if (myList->first->after == NULL)
                {
                    newNode->after=myList->first;
                    myList->first=newNode;
                }
                else
                {
                    tmp = myList->first;
                    while (pos != i)
                    {
                        i++;
                        tmp=tmp->after;
                    }
                    newNode->after = tmp;
                    i = 0;
                    while (i < pos)
                    {
                        i++;
                        tmp=tmp->after;
                    }
                    tmp->after = newNode;
                }
            }
        }
        else
        {
            //do nothing if newNode is NULL
        }
    }

	return(myList);
}
