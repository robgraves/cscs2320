#include "list.h"

//////////////////////////////////////////////////////////////////////
//
//   insert() - add a new node to the given list before the node
//              at the indicated place. insert() needs to manage
//              the necessary connections pointers) to maintain list
//              integrity, along with ensuring the start and end
//              indicators of the list remain relevant and up-to-date.
//
//    behavior: on a NULL list- allocate a list and proceed
//              on a NULL newNode- return list as is
//
//        note: you are expected to make use of the getpos() and
//              setpos() functions to aid you in accomplishing this
//              task. Don't needlessly reinvent the wheel.
//
//              as with the other functions, you may use no more
//              than one return() statement per function.
//
List *insert(List *myList, Node *place, Node *newNode)
{
    int pos = 0;        //declaring an integer for position initialized to 0
    int x = 0;          //declaring an integer for result of getpos() function
    Node *tmp = NULL;   //declaring a Node pointer called tmp and initializing to NULL

    if (myList == NULL)     //checking for a NULL list
    {
        myList = mklist();  //calling mklist() function assigning it to myList
        myList->first = newNode;    //setting myList's first pointer to the newNode
        myList->last = newNode;     //setting myList's second pointer to the newNode
    }
    else
    {
        if (newNode != NULL)        //check for newNode being NULL or drop out
        {
            pos = getpos(myList, place);    //assigning pos the result of getpos() with myList and place 
            if (pos == -1)                  //as arguments
            {
                myList->first = newNode;    //if pos is -1 set first pointer to newNode 
                myList->last = newNode;     //and set last pointer to newNode
            }
            else
            {
                if (place == myList->first)     //check for place being equal to first node
                {
                    newNode->after=myList->first;   //assigning newNode's after pointer to first pointer
                    myList->first=newNode;    //setting first pointer to newNode
                }
                else
                {
                    newNode->after=place;       //setting newNode's after to place pointer.
                    x=getpos(myList, place);    //seting x to result of getpos() w/ myList and place
                    tmp=setpos(myList,(x-1));   //setting tmp pointer to result of setpos() myList, x-1
                    tmp->after=newNode;         //setting the pointer after tmp to the newNode
                }
            }
        }
        else
        {
            //do nothing if newNode is NULL
        }
    }

	return(myList);     //returning pointer to myList
}
