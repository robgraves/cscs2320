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
    List *myList = NULL;        //declaring a List pointer and setting to NULL

    myList=(List *)malloc(sizeof(List));    //Allocating a List the size of List and calling it myList
    myList->first=NULL;                     //setting myList's first pointer to NULL
    myList->last=NULL;                      //setting myList's last pointer to NULL

	return(myList);                         //returning pointer to myList
}
