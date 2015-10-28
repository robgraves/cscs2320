#include "list.h"

//////////////////////////////////////////////////////////////////////
//
// cplist() - a list library function to duplicate or copy an existing
//            list and all its component nodes.
//
//            the operative idea here is "separate copies"; you may
//            want to make use of cpnode() to assist.
//
//  behavior: on error, return NULL.
//
//      note: you are to have only ONE return statement for this
//            entire function. Change the existing one as needed.
//
List *cplist(List *oldList)
{
    //declaring and initializing List pointer called newList 
    //and Node pointers called tmp and tmp2
    List *newList = NULL;
    Node *tmp = NULL;
    Node *tmp2 = NULL;
    int i = 0;

    //checking for NULL list
    if (oldList == NULL)
    {   
        newList = NULL;
    }
    else
    {
        //allocating newList
        newList = mklist();
        //checking for an empty list
        if ((oldList->first == NULL) && (oldList->last == NULL))
        {
            //setting newList's first and last pointers to NULL
            newList->first = NULL;
            newList->last = NULL;

            //setting myList's quantity to 0
            //newList->qty = 0;      //this is done in mklist, unnecessary here
            
            //setting newList's after pointer to NULL
            //newList->after = NULL;  //this is done in mklist, unnecessary here
        }
        else
        {
            //setting tmp to first node in oldList
            tmp = oldList->first;
            //copying first node in original list and pointing tmp2 pointer to it
            tmp2 = cpnode(tmp);
            //assigning newList's first pointer to newly created node
            newList->first = tmp2;
            //looping for as long as tmp's after isn;t nULL
            while (tmp->after != NULL)
            {
                //moving tmp pointer down original list
                tmp = tmp->after;
                //creating newnode after tmp2
                tmp2->after = cpnode(tmp);
                //moving tmp2 down the newList
                tmp2 = tmp2->after;

                //increment qty by 1 each iteration
                //newList->qty = newList->qty + 1;
                //i++;
            }
            //assigning newList's last pointer to last created node
            newList->last = tmp2;

            oldList->after = newList;

            //newList->qty=i;
        }
    }

	return(newList);
}
