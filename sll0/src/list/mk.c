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
    List *myList = NULL;

    myList=(List *)malloc(sizeof(List));
    myList->first=NULL;
    myList->last=NULL;

	return(myList);
}
