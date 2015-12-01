#include "list.h"

//////////////////////////////////////////////////////////////////////
//
// compare() - a list library utility function to compare two lists,
//             and to return a result indicating equality, or the lack
//             thereof.
//
//       note: if difference is initially NULL, care should be taken
//             not to assign any values to it.
//
//             a difference of 0 indicates a NULL or EMPTY list is
//             our point of difference. Any actual list node
//             positions will start from 1 (be aware of this)
//
//             the condition of both lists should be reflected in
//             the code that is ultimately returned. In the event 
//             of a NULL or EMPTY list, those conditions trump 
//             any greater/less/equality status.
//
//   examples: a few examples for reference.
//
//             list1:        NULL
//             list2:        NULL
//             code:         CMP_L1_NULL  | CMP_L2_NULL
//             difference:   0
//
//             list1:        EMPTY
//             list2:        EMPTY
//             code:         CMP_L1_EMPTY | CMP_L2_EMPTY
//             difference:   0
//
//             list1:        NULL
//             list2:        EMPTY
//             code:         CMP_L1_NULL  | CMP_L2_EMPTY
//             difference:   0
//
//             list1:        EMPTY
//             list2:        NULL
//             code:         CMP_L1_EMPTY | CMP_L2_NULL
//             difference:   0
//
//             list1:        NULL
//             list2:        1 -> 2 -> NULL
//             code:         CMP_L1_NULL
//             difference:   0
//
//             list1:        EMPTY
//             list2:        1 -> 2 -> NULL
//             code:         CMP_L1_EMPTY
//             difference:   0
//
//             list1:        1 -> 2 -> NULL
//             list2:        NULL
//             code:         CMP_L2_NULL
//             difference:   0
//
//             list1:        1 -> 2 -> NULL
//             list2:        EMPTY
//             code:         CMP_L2_EMPTY
//             difference:   0
//
//             list1:        2 -> NULL
//             list2:        1 -> 2 -> NULL
//             code:         CMP_L1_GREATER | CMP_L2_LESS
//             difference:   1
//
//             list1:        1 -> NULL
//             list2:        1 -> 3 -> NULL
//             code:         CMP_L2_GREATER
//             difference:   2
//
//             list1:        1 -> 2 -> NULL
//             list2:        1 -> 3 -> NULL
//             code:         CMP_L1_LESS    | CMP_L2_GREATER
//             difference:   2
//
//             list1:        1 -> 3 -> NULL
//             list2:        1 -> 3 -> NULL
//             code:         CMP_EQUALITY
//             difference:   2
//
//             you are to have only ONE return statement for this
//             entire function. Change the existing one as needed.
//
code_t  compare(List *myList1, List *myList2, ulli *difference)
{
    //variable initializations and declarations
    code_t result = 0;

	return(result);
}
