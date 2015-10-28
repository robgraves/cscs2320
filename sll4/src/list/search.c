#include "list.h"

//////////////////////////////////////////////////////////////////////
//
// searchlist() - a list library utility function to locate a node in
//                an existing list by value it contains.
//
//      note: unlike getpos()/setpos(), which worked in units of list
//            positional offsets, searchlist() focuses on the actual
//            content of what is in the nodes, returning a pointer to
//            the first node that contains the matching value (from 
//            the start of the list).
//
//  behavior: on error (NULL list, NULL node, no match), return NULL
//
//            you are to have only ONE return statement for this
//            entire function. Change the existing one as needed.
//
Node *searchlist(List *myList, char value)
{
    //declaring and initializing tmp pointer to NULL
    Node *tmp = NULL;

    //checking for NULL list
    if (myList == NULL)
    {
        //do nothing
    }
    else
    {
        //checking for empty list
        if ((myList->first == NULL) && (myList->last == NULL))
        {
            //do nothing
        }
        else
        {
            //setting tmp to first node
            tmp = myList->first;
            //looping while current node doesn't contain value and
            //not at the end of the list
            while ((value != tmp->info) && (tmp->after != NULL)) 
            {   
                    //moving tmp down the list
                    tmp = tmp->after;
            }
            //checking for value not being in list
            if ((tmp->after == NULL) && (tmp->info != value))
            {
                tmp = NULL;
            }
        }
    }

	return(tmp);
}
