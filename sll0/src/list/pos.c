#include "list.h"

//////////////////////////////////////////////////////////////////////
//
// getpos() - a list library utility function to identify the actual
//            position of a given node in an indicated list.
//
//      note: Indexing of the list starts from 0
//
//  behavior: on error (NULL list or given node), return negative
//            value (-1), on out-of-bounds condition, return -2
//
//            you are to have only ONE return statement for this
//            entire function. Change the existing one as needed.
//
int getpos(List *myList, Node *given)
{
    int i = 0;
    Node *tmp = NULL;

    if (myList == NULL)
    {
        i = -1;
    }
    else
    {
        tmp = myList->first;
        if (myList->first == NULL)
        {
            i = -1;
        }
        else
        {
            while (tmp !=NULL && tmp != given)
            {
                tmp = tmp->after;
                i++;
            }
            if (tmp == NULL)
            {
                i = -2;
            }
        }
    }
        
	return(i);
}

//////////////////////////////////////////////////////////////////////
//
// setpos() - a list library utility function to set a node pointer
//            to the node at the indicated position of a list.
//
//      note: Indexing of the list starts from 0
//
//  behavior: on error (NULL list or negative/out-of-bounds pos),
//            return NULL.
//
//            you are to have only ONE return statement for this
//            entire function. Change the existing one as needed.
//
Node *setpos(List *myList, int pos)
{
    Node *tmp = NULL;
    int i = 0;

    if (myList == NULL)
    {
        tmp = NULL;
    }
    else
    {
        tmp = myList->first;
        if (myList->first == NULL)
        {
            tmp = NULL;
        }
        else
        {
            while (i != pos) 
            {
                if (tmp->after != NULL)
                {
                    i++;
                    tmp = tmp->after;
                }
                else
                {
                    tmp = NULL;
                    i = pos;
                }
            }
        }
    }

	return(tmp);
}
