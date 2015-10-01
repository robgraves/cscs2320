#include "list.h"

//////////////////////////////////////////////////////////////////////
//
//   append() - add a new node to the given list after the node
//              at the indicated place. append() needs to manage
//              the necessary connections (pointers) to maintain list
//              integrity, along with ensuring the first and last
//              indicators of the list remain relevant and up-to-date.
//
//    behavior: on a NULL list- do nothing; return NULL.
//              on a NULL newNode- do nothing; return list as is
//
//              the NULL list behavior differs from that of insert();
//              this is merely to spice things up a bit, and does
//              not indicate any sort of conceptual distinction.
//
//        note: you are expected to make use of the getpos() and
//              setpos() functions to aid you in accomplishing this
//              task. Don't needlessly reinvent the wheel.
//
//              as with the other functions, you may use no more
//              than one return() statement per function.
//
List *append(List *myList, Node *place, Node *newNode)
{
    //variable and pointer declarations and initializations
    int pos = 0;
    int x = 0;
    Node *tmp = NULL;
    
    if (myList == NULL)
    {
        // do nothing
    }
    else
    {
        //check for NULL list
        if (newNode == NULL)
        {
            //do nothing
        }
        else
        {
            //check for empty list
            if (myList->first == NULL)
            {
                //set first and last pointers to newNode
                myList->first = newNode;
                myList->last = newNode;
            }
            else
            {
                //check for if at end of list
                if (place == myList->last)
                {
                    //appends newNode to end of list and adjusts last pointer
                    place->after = newNode;
                    newNode->after = NULL;
                    myList->last = newNode;
                }
                else
                {
                    //appends newNode after place pointer
                    newNode->after = place->after;
                    place->after = newNode;
                }
            }
        }
    }


	return(myList);
}
