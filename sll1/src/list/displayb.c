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

    //switch statement for mode
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

    }
}
