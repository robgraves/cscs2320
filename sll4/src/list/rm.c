#include "list.h"

//////////////////////////////////////////////////////////////////////
//
// rmlist() - a list library function to deallocate an existing list;
//            care must be taken to ensure any component nodes have
//            been properly disposed of so as to prevent a memory
//            leak. The resulting list will be in a NULL state.
//
//      note: you are to have only ONE return statement for this
//            entire function. Change the existing one as needed.
//
List *rmlist(List *myList)
{
    //clearing myList
    myList = clearlist(myList);
    //deallocating myList
    free(myList);
    //setting myList pointer to NULL
    myList = NULL;

	return(myList);
}
