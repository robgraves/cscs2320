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
    Node *tmp = NULL;
    
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
                //checking that nodes are notthe same
                if (item1 != item2)
                {
                    //copies the first node
                    tmp = cpnode(item1);
                    //inserts copied node before the original
                    myList = insert(myList, item1, tmp);
                    //disconnects the original item1 node
                    myList = obtain(myList, &item1);
                    //inserts item1 node before item2 node
                    myList = insert(myList, item2, item1);
                    //obtains, disconnecting the item2 node
                    myList = obtain(myList, &item2);
                    //inserts item2 node before the co[pied item1 node
                    myList = insert(myList, tmp, item2);
                    //pulls out the copied item1 node at tmp
                    myList = obtain(myList, &tmp);
                    //deallocates node at tmp
                    tmp = rmnode(tmp);
                    //set tmp pointer back to NULL
                    tmp = NULL;

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
