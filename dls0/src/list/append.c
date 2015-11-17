#include "list.h"

//////////////////////////////////////////////////////////////////////
//
//   append() - add a new node to the given list after the node
//              at the indicated place. append() needs to manage
//              the necessary connections (pointers) to maintain list
//              integrity, along with ensuring the first and last
//              indicators of the list remain relevant and up-to-date.
//
//    behavior: do NOT create a list if NULL
//
// status code: this function can generate the following status codes
//                DLN_NULL:    newNode is NULL
//                DLN_ERROR:   place or newNode NULL (list not EMPTY)
//                DLL_SUCCESS: normal operation (success!)
//                DLL_NULL:    list is NULL
//                DLL_EMPTY:   list ends up EMPTY
//                DLL_ERROR:   error encountered
//                DLL_INVALID: invalid condition (place not in list)
//
//              as with the other functions, you may use no more
//              than one return() statement per function.
//
code_t append(List **myList, Node *place, Node *newNode)
{
    //variables declarations and initialization 
    code_t result = DLL_SUCCESS;

    if (myList == NULL)
    {
        result = DLL_INVALID + DLL_ERROR;
    }
    else
    {
        //checking if newNode is NULL
        if (newNode == NULL)
        {
            result = DLN_NULL + DLN_ERROR;
        }
        else
        {
            //checking for empty list
            if ((*myList)->first == NULL)
            {
                //empty list   
            }
            else
            {
                //attaching after and prior on appended node
                newNode->after=place->after;
                newNode->prior=place;

                //attaching pointers before and after appended node
                place->after->prior=newNode;
                place->after=newNode;

                //incrementing qty element in list
                (*myList)->qty++;
                //(*myList)->qty=((*myList)->qty + 1);

                //setting result to success code
                result = DLL_SUCCESS;
            }
        }
    }

	return(result);
}
