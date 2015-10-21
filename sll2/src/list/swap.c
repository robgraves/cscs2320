#include "list.h"

//////////////////////////////////////////////////////////////////////
//
// swapnode() - swap the position of two given nodes in a list, being
//              sure to appropriately adjust any and all pertinent
//              pointers to ensure list integrity following the
//              operation (including potential changes to the list's
//              own first and last pointers, along with connectivity
//              between the nodes from the start to end of the list).
//
//        note: you are NOT to just adjust node info values. You must
//              disconnect the identified nodes from the list and 
//              reconnect them- the node is our unit of transaction,
//              NOT the data it contains.
//
//    behavior: on a NULL list- do nothing: return NULL
//              on an EMPTY list- do nothing: return list unchanged
//              on a NULL/invalid nodes to swap- do nothing: return
//                  the list unchanged
//
//        note: where applicable, make use of the getpos() and
//              setpos() functions to aid you in accomplishing this
//              task. Don't needlessly reinvent the wheel.
//
//              as with the other functions, you may use no more
//              than one return() statement per function.
//
List *swapnode(List *myList, Node *item1, Node *item2)
{
    //declaration and initialization of variables and pointers
    int item1pos = 0;
    int item2pos = 0;
    int pos = 0;

    Node *tmp = NULL;
    Node *tmp2 = NULL;
    
    //check for NULL list
    if (myList != NULL)
    {
        //check for EMPTY list
        if (myList->first != NULL)
        {
            //checking if either node is NULL
            if ((item1 == NULL) || (item2 == NULL))
            {
                //do nothing if either node is NULL   
            }
            else
            {
                if (item1 != item2)
                {
                    //getting index of both node items at starting positions
                    item1pos = getpos(myList, item1);
                    item2pos = getpos(myList, item2);
                    
                    //check for two node list
                    if (myList->first->after->after == NULL)
                    {
                        myList = obtain(myList, &item2);
                        myList = insert(myList, item1, item2);
                    }
                    else
                    {
                        if ((item1 == myList->first) || (item2 == myList->first))
                        {
                            //first pointer needs to be reassigned
                            if (item1 == myList->first)
                                myList->first = item1->after;
                            if (item2 == myList->first)
                                myList->first = item2->after;
                            myList = obtain(myList, &item2);
                            myList = insert(myList, item1, item2);
                            myList = obtain(myList, &item1);
                            myList = insert(myList, tmp, item1);

                        }
                        else if ((item1 == myList->last) || (item2 == myList->last))
                        {
                            //last pointer needs to be reassigned
                            if (item1 == myList->last)
                            {
                                pos = getpos(myList, item1);
                                myList->last = setpos(myList, pos-1);
                            }
                            if (item2 == myList->last)
                            {
                                pos = getpos(myList, item2);
                                myList->last = setpos(myList, pos-1);
                            }
                            myList = obtain(myList, &item2);
                            myList = insert(myList, item1, item2);
                            myList = obtain(myList, &item1);
                            myList = insert(myList, tmp, item1);
                        }
                        else
                        {
                            //all middle node cases
                            tmp = item1->after;
                            myList = obtain(myList, &item2);
                            myList = insert(myList, item1, item2);
                            myList = obtain(myList, &item1);
                            myList = insert(myList, tmp, item1);
                        }
                    }
                }
                else
                {
                    //do nothing if two nodes are the same    
                }

            }
        }
        else
        {
            //do nothing if an EMPTY list
        }

    }
    else
    {
        //do nothing if a NULL list
    }

	return(myList);
}
