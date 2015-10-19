#include "list.h"

//////////////////////////////////////////////////////////////////////
//
//   obtain() - take and isolate indicated node out of list, through
//              a careful adjustment of necessary pointers. obtain()
//              needs to maintain list integrity.
//              
//    behavior: on a NULL list- do nothing; return NULL.
//              on a NULL thatNode- do nothing; return list as is
//
//        note: you are expected to make use of the getpos() and
//              setpos() functions to aid you in accomplishing this
//              task. Don't needlessly reinvent the wheel.
//
//              it is important to acknowledge that thatNode, the one
//              being isolated from the list, is being passed in as a
//              double pointer (we're passing the Node pointer by
//              reference). As such, you need to be mindful that you
//              need to dereference it once on each usage when in this
//              function to use it as you expect.
//
//              as with the other functions, you may use no more
//              than one return() statement per function.
//
List *obtain(List *myList, Node **thatNode)
{
    //declaration and initialization of variable(s)
    int x = 0;

    //checking for a NULL list
    if (myList != NULL)
    {
        //checking if thatNode is NULL
        if (thatNode != NULL)
        {
            //checking if thatNode pointer is NULL
            if ((*thatNode) != NULL)
            {
                //checking to see if one node list
                if (myList->first == myList->last)    
                {
                    myList->first = NULL;
                    myList->last = NULL;
                }
                else
                {
                    //checking if thatNode is first node in list
                    if (myList->first == (*thatNode))
                    {
                        myList->first = (*thatNode)->after;
                        (*thatNode)->after = NULL;
                    }
                    else
                    {
                        //checking if thatNode is last node in list
                        if ((*thatNode)->after == NULL)
                        {
                            x = getpos(myList, (*thatNode)); 
                            myList->last = setpos(myList, (x-1));
                            myList->last->after = NULL;
                        }
                        else
                        {

                        }
                    }
                }
            }
            else
            {
                //do nothing on NULL thatNode pointer
            }
        }
        else
        {
            //do nothing if thatNode is NULL
        }
    }
    else
    {
        //do nothing on NULL list
    }
	return(myList);
}
