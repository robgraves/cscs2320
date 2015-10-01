#include <stdio.h>
#include "list.h"

//////////////////////////////////////////////////////////////////////
//
// displayb() - display the list in a reversed orientation, also
//              with or without positional values (as indicated
//              by the mode parameter).
//
//       modes: 0 display the list backward, no positional values
//              1 display the list backward, with positional values
//     
//        note: positional values are indexed starting from 0
//     
//    behavior: on a NULL list, output "NULL"
//              on an EMPTY list, output "NULL <-"
//              on error (invalid mode): MOD by 2 and do the result
//                 (or the logical equivalent)
//
//      format: output is to be on a single line, with node values
//              space-padded. and separated by "<-" sequences, flush
//              against the left margin, of the forms:
//
//   backwards:   NULL <- 9 <- 7 <- 6 <- 4
//
//              or, if being displayed with node positions:
//
//   backwards:   NULL <- [3] 9 <- [2] 7 <- [1] 6 <- [0] 4
//
//        note: ALL output ends with a newline character
//
void displayb(List *myList, int mode)
{
    //variable and pointer declarations
    Node *tmp = NULL;
    int i = 0;
    int x = 0;

    //switch statement for mode, modulate invalid entries to 0 or 1
    switch(mode)
    {
        case 0:
            mode = 0;
            break;
        case 1:
            mode = 1;
            break;
        default:
            mode = mode % 2;
            break;
    }
    
    //checking for NULL list
    if (myList == NULL)
    {
        printf("NULL\n");
    }
    //check for empty list
    else if ((myList->first == NULL) && (myList->last == NULL))
    {
        printf("NULL <-\n");
    }
    //code for a populated list
    else
    {
        tmp = myList->first;
        //switch statement for actual mode
        switch(mode)
        {
            //case 0 displays without indices
            case 0:
                //moving tmp pointer to last node in list
                //while (tmp->after != NULL)
                //{
                //    tmp = tmp->after;
                //}
                //check for one node list
                if (tmp == myList->first)
                {
                    //print NULL and value of node's info variable
                    printf("NULL ");
                    printf("<- %d \n", tmp->info);
                }
                //else for multi-node list
                else
                {
                    while (tmp->after != NULL)
                    {
                        tmp = tmp->after;
                    }
                    //calling getpos() function, passing myList and tmp pointer
                    x = getpos(myList, tmp);
                    //printing NULL and value of last node
                    printf("NULL ");
                    printf("<- %d ", tmp->info);
                    //loop for as long as not at beginning of list
                    while (tmp != myList->first)
                    {
                        tmp = setpos(myList, (x-1));
                        //print value of current node's info variable
                        printf("<- %d ", tmp->info);
                    }
                    //print first node
                    printf("<- %d \n", tmp->info);
                }
                break;
            //case 1 displays with indices
            case 1:
                //moving tmp pointer to last node in list
                //while (tmp->after != NULL)
                //{
                //    tmp = tmp->after;
                //}
                //check for one node list
                if (tmp == myList->first)
                {
                    //print NULL and value of node's info variable
                    printf("NULL ");
                    printf("<- %d [%d]\n", tmp->info, i);
                }
                //else for multi-node list
                else
                {
                    while (tmp->after != NULL)
                    {
                        tmp = tmp->after;
                    }
                    //calling getpos() function, passing myList and tmp pointer
                    x = getpos(myList, tmp);
                    //printing NULL and value of last node
                    i = x;  //gets index of final node
                    printf("NULL ");
                    printf("<- %d [%d]", tmp->info, i);
                    //loop for as long as not at beginning of list
                    while (tmp != myList->first)
                    {
                        i--;
                        tmp = setpos(myList, (x-1));
                        //print value of current node's info variable
                        printf("<- %d [%d]", tmp->info, i);
                    }
                    //print first node
                    printf("<- %d \n", tmp->info);
                }
                break;
        }
    }
}
