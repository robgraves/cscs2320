#include "list.h"

//////////////////////////////////////////////////////////////////////
//
// sortlist() - a list library function to sort an existing list
//              according to the mode indicated.
//
//              the original list is **preserved**, and the altered/
//              sorted list (a new list) is what is returned.
//
//   modes are: 0 - least to greatest (least is first)
//              1 - greatest to least (greatest is first)
//              2 - reverse order of original list
//
//    behavior: on error, return NULL.
//              on invalid mode, MOD by total modes and continue,
//                  performing whatever that result is.
//
//        note: you are to have only ONE return statement for this
//              entire function. Change the existing one as needed.
//
List *sortlist(List *myList, int mode)
{
    //declaration of variables and pointers
    List *sortList = NULL;

    //switch statement from mode argument
    switch(mode)
    {
        case 0:
            mode = 0;
            break;
        case 1:
            mode = 1;
            break;
        case 2:
            mode = 2;
            break;
        //mods any number not 0,1, or 2
        default:
            mode = mode % 3;
            break;
    }

    sortList = cplist(myList);


    return(sortList);
}
