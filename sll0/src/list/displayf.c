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
    Node *tmp;
    int i=0;

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

    if (myList == NULL)
    {
        printf("NULL\n");
    }
    else if ((myList->first==NULL) && (myList->last==NULL))
    {
        printf("-> NULL\n");
    }
    else
    {
        switch(mode)
        {
            case 0:
                tmp=myList->first;
                printf("%d -> ", tmp->info);
                while (tmp->after != NULL)
                {
                    tmp=tmp->after;
                    printf("%d -> ", tmp->info);
                }
                printf("NULL\n");
                break;
            case 1:
                tmp=myList->first;
                printf("[%d] %d -> ", i, tmp->info);
                while (tmp->after != NULL)
                {
                    i++;
                    tmp=tmp->after;
                    printf("[%d] %d -> ", i, tmp->info);
                }
                printf("NULL\n");

                break;
        }
        //printf("NULL\n");
    }

}
