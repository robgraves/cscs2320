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
    int i = 0;      //declaring an integer i and initializing it to 0
    Node *tmp = NULL;  //declaring a Node pointer tmp and intitalizing it to NULL

    if (myList == NULL)     //check for myList being NULL
    {
        i = -1;             //setting i to -1 in the event of a NULL list
    }
    else
    {
        tmp = myList->first;    //setting tmp pointer to the myList's first pointer
        if (myList->first == NULL)  //checking for an empty list
        {
            i = -1;             //setting it o -1 in the event of an empty list
        }
        else
        {
            while (tmp !=NULL && tmp != given)      //checking for tmp pointer not being at end of list
            {                                       //or not equal to given pointer
                tmp = tmp->after;                   //moving tmp pointer down the list
                i++;                                //incrementing i
            }
            if (tmp == NULL)                        //if tmp equals NULL then
            {
                i = -2;                             //sets i to -2
            }
        }
    }
        
	return(i);                              //returns i as the postition value
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
    Node *tmp = NULL;       //Declaring a Node pointer and intializing it to NULL
    int i = 0;              //Declaring an integer i and initializing to 0

    if (myList == NULL)     //testing if myList is NULL
    {
        tmp = NULL;         //sets tmp pointer to NULL
    }
    else
    {
        tmp = myList->first;        //setting tmp pointer to myList's first pointer
        if (myList->first == NULL)  //if first pointer is NULL
        {
            tmp = NULL;             //sets tmp pointer to NULL                 
        }
        else
        {
            while (i != pos)        //loop while i is not at the given position (pos) 
            {
                if (tmp->after != NULL) //check for tmp being at the end of the list
                {
                    i++;                //incremenet i
                    tmp = tmp->after;   //move tmp pointer down the list
                }
                else
                {
                    tmp = NULL;     //assigning tmp pointer to NULL
                    i = pos;        //assigning i to position to end loop
                }
            }
        }
    }

	return(tmp);                    //returning tmp pointer
}
