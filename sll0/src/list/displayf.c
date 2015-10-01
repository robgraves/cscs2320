#include <stdio.h>
#include "list.h"

//////////////////////////////////////////////////////////////////////
//
// displayf() - display the list in a specified orientation, also
//              with or without positional values (as indicated
//              by the mode parameter).
//
//       modes: 0 display the list forward, no positional values
//              1 display the list forward, with positional values
//     
//        note: positional values are indexed starting from 0
//     
//    behavior: on a NULL list, output "NULL"
//              on an EMPTY list, output "-> NULL"
//              on error (invalid mode): MOD by 2 and do the result
//                 (or the logical equivalent)
//
//      format: output is to be on a single line, with node values
//              space-padded. and separated by "->" sequences, flush
//              against the left margin, of the forms:
//
// for forward:   val0 -> val1 -> val2 -> ... -> valN-1 -> valN -> NULL
//
//              or, if being displayed with node positions:
//
// for forward: [0] val0 -> [1] val1 -> ... -> [N-1] valN-1 -> [N] valN -> NULL
//
//        note: ALL output ends with a newline character
//
void displayf(List *myList, int mode)
{
    Node *tmp = NULL;       //declaring a Node pointer called tmp and initializing it to NULL
    int i=0;                //declaring an integer i and initializing it to 0

    switch(mode)            //switch statement from mode argument to function
    {
        case 0:             //case of 0 sets it to 0
            mode = 0;
            break;
        case 1:             //case of 2 sets it to 1
            mode = 1;
            break;
        default:            //case of any other number modulates to its remainder as mode
            mode = mode % 2;
            break;
    }

    if (myList == NULL)     //if myList is NULL, prints "NULL"
    {
        printf("NULL\n");
    }
    else if ((myList->first==NULL) && (myList->last==NULL))  //if list is empty prints "-> NULL"
    {
        printf("-> NULL\n");
    }
    else
    {
        switch(mode)        //switch statement for actual mode 0 or 1
        {
            case 0:         //case of mode being 0
                tmp=myList->first;              //assigning the tmp pointer to the first node
                printf("%d -> ", tmp->info);    //displaying the value in the node's info variable
                while (tmp->after != NULL)      //loop for as long as we're not on last node
                {
                    tmp=tmp->after;             //move tmp pointer to next node
                    printf("%d -> ", tmp->info);    //print value of tmp's node's info variable
                }
                printf("NULL\n");                   //print "NULL" at the end of the list
                break;
            case 1:             //case of mode being 1
                tmp=myList->first;              //assigning the tmp pointer to the first node
                printf("[%d] %d -> ", i, tmp->info);    //displaying the value as above with added index
                while (tmp->after != NULL)              //loop for as long as we're not on the last node
                {   
                    i++;                                //incrementing i, the index variable
                    tmp=tmp->after;                     //move tmp pointer to next node
                    printf("[%d] %d -> ", i, tmp->info);//displaying the value as above with added index
                }
                printf("NULL\n");                   //printing "NULL" at the end of the list

                break;
        }
    }

}
