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

    //checking for NULL list
    if (myList != NULL)
    {    
        //checking for empty list
        if (myList->first != NULL)
        {
            //while the list is populated
            while (myList->first != NULL)
            {
                //setting tmp to beginning of list
                tmp = myList->first;
                //setting tmp2 to 2nd element in list
                tmp2 = tmp->after;

                //obtaining node at beginning of list
                myList = obtain(myList, (&tmp));
                //deallocting node
                tmp = rmnode(tmp);
                //assigning myList's first to node at tmp2 
                myList->first = tmp2;
            }

            //setting myList's first and last pointer to NULL
            myList->first = NULL;
            myList->last = NULL;
        }
    }

	return(myList);
}
