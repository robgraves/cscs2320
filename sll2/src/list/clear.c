#include "list.h"

//////////////////////////////////////////////////////////////////////
//
// clearlist() - a list library function to clear an existing list of
//               any and all of its component nodes (deallocate them).
//               The list itself continues to exist, but is in an
//               empty state following the successful call to
//               clearlist().
//
//     behavior: on error, return NULL.
//
//         note: you are to have only ONE return statement for this
//               entire function. Change the existing one as needed.
//
List *clearlist(List *myList)
{
    //declaring and initializing variables and pointers
    Node *tmp = NULL;
    Node *tmp2 = NULL;

    if (myList != NULL)
    {    
        if (myList->first != NULL)
        {
            while (myList->first != NULL)
            {
                tmp = myList->first;
                tmp2 = tmp->after;

                myList = obtain(myList, (&tmp));
                tmp = rmnode(tmp);
                myList->first = tmp2;
            }
            myList->first = NULL;
            myList->last = NULL;
        }
    }

	return(myList);
}
