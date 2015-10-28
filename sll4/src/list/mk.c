#include "list.h"

//////////////////////////////////////////////////////////////////////
//
// mklist() - a list library function to allocate and initialize a 
//            new list.
//
//  behavior: on error, return NULL.
//
//      note: you are to have only ONE return statement for this
//            entire function. Change the existing one as needed.
//
List *mklist(void)
{
    //declaring and initializing
    //variables and pointers
    List *myList = NULL;

    //allocating myList to size of List struct
    myList=(List *)malloc(sizeof(List));

    //setting myList's first and last pointers to NULL
    myList->first=NULL;
    myList->last=NULL;

    //setting new element in List struct, 
    //qty (quantity of nodes in list) to 0
    myList->qty = 0;

    //setting new element in List struct, 
    //after (pointing to list after current list) to NULL
    myList->after = NULL;

	return(myList); 
}
