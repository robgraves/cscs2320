#include "list.h"

//////////////////////////////////////////////////////////////////////
//
// compare() - a list library utility function to compare two lists,
//             and to return a result indicating equality (or the lack
//             thereof), as well as the position of difference.
//
//       note: if pos is initially NULL, care should be taken not to
//             assign any values to it.
//
//             a pos of 0 indicates a NULL or EMPTY list is our 
//             point of difference. Any actual list node positions
//             will start from 1 (be aware of this difference from
//             setpos()/getpos()).
//
//             the condition of both lists should be reflected in
//             the code that is ultimately returned. In the event 
//             of a NULL or EMPTY list, those conditions trump 
//             any greater/less/equality status.
//
//   examples: a few examples for reference.
//
//             list1: NULL
//             list2: NULL
//             code:  CMP_L1_NULL  | CMP_L2_NULL
//             pos:   0
//
//             list1: EMPTY
//             list2: EMPTY
//             code:  CMP_L1_EMPTY | CMP_L2_EMPTY
//             pos:   0
//
//             list1: NULL
//             list2: EMPTY
//             code:  CMP_L1_NULL  | CMP_L2_EMPTY
//             pos:   0
//
//             list1: EMPTY
//             list2: NULL
//             code:  CMP_L1_EMPTY | CMP_L2_NULL
//             pos:   0
//
//             list1: NULL
//             list2: 1 -> 2 -> NULL
//             code:  CMP_L1_NULL
//             pos:   0
//
//             list1: EMPTY
//             list2: 1 -> 2 -> NULL
//             code:  CMP_L1_EMPTY
//             pos:   0
//
//             list1: 1 -> 2 -> NULL
//             list2: NULL
//             code:  CMP_L2_NULL
//             pos:   0
//
//             list1: 1 -> 2 -> NULL
//             list2: EMPTY
//             code:  CMP_L2_EMPTY
//             pos:   0
//
//             list1: 2 -> NULL
//             list2: 1 -> 2 -> NULL
//             code:  CMP_L1_GREATER | CMP_L2_LESS
//             pos:   1
//
//             list1: 1 -> NULL
//             list2: 1 -> 2 -> NULL
//             code:  CMP_L2_GREATER
//             pos:   2
//
//             list1: 1 -> 2 -> NULL
//             list2: 1 -> 3 -> NULL
//             code:  CMP_L1_LESS    | CMP_L2_GREATER
//             pos:   2
//
//             list1: 1 -> 3 -> NULL
//             list2: 1 -> 3 -> NULL
//             code:  CMP_EQUALITY
//             pos:   2
//
//             you are to have only ONE return statement for this
//             entire function. Change the existing one as needed.
//

///////////////////////////////////////////////////////////////////
//
//  Borrowing my buddy Dan Shadeck's code for educational purposes
//
///////////////////////////////////////////////////////////////////

uc compare(List *myList1, List *myList2, ulli *pos)
{
    uc comparvar;
	int position = 0;
        if(myList1 == NULL && myList2 == NULL) { // check for null lists
            comparvar = CMP_L1_NULL|CMP_L2_NULL;
        } else if(myList1 == NULL && myList2 != NULL) { //  check if one list is null and other is not null
            if(myList2->first == NULL || myList2->last == NULL) {
                comparvar = CMP_L1_NULL|CMP_L2_EMPTY;
            } else {
                comparvar = CMP_L1_NULL;
            }
        } else if(myList1 != NULL && myList2 == NULL) { // check if one list i null and other isn't
            if(myList1 -> first == NULL || myList1 -> last == NULL) {
                comparvar = CMP_L2_NULL|CMP_L1_EMPTY;
            } else {
                comparvar = CMP_L2_NULL;
            }
        } else {
            if((myList1 -> first == NULL || myList1 -> last == NULL) && (myList2 -> first == NULL || myList2 -> last == NULL)) { // checks if lists are empty
                comparvar = CMP_L1_EMPTY|CMP_L2_EMPTY;
            } else if((myList1 -> first == NULL || myList1 -> last == NULL) && (myList2 -> first != NULL && myList2 -> last != NULL)) { // checks if one list is empty and other is
                comparvar = CMP_L1_EMPTY;
            } else if((myList1 -> first != NULL && myList1 -> last != NULL) && (myList2 -> first == NULL || myList2 -> last == NULL)) { // checks if one list is empty and other is
                comparvar = CMP_L2_EMPTY;
            } else {
                int list1size = 0, list2size = 0;
				Node *tmp = NULL;
				Node *tmp2 = NULL;
                tmp = myList1 -> first;
                while(tmp != NULL) { // get size of list 1
                    list1size = list1size + 1;
                    tmp = tmp -> after;
                }
                tmp2 = myList2 -> first;
                while(tmp2 != NULL) { // get size of list 2
                    list2size = list2size +1;
                    tmp2 = tmp2 -> after;
                }
                if(list1size == list2size) { //  check if both lists are same size
                    tmp = myList1 -> first;
                    tmp2 = myList2 -> first;
                    char isequal = 't';
					int i;
                    for(i = 0; i < list1size; i++) { // loop through all list items and check if they are both equal
                        if(tmp -> info != tmp2 -> info) {
                            isequal = 'f';
                            break;
                        }
                        tmp = tmp -> after;
                        tmp2 = tmp2 -> after;
                    }
                    if(isequal == 't') {
                        comparvar = CMP_EQUALITY;
                        position = list1size;
                    } else {
                        if(tmp -> info > tmp2 -> info) { // checks which value is bigger
                            comparvar = CMP_L1_GREATER|CMP_L2_LESS;
                        } else {
                            comparvar = CMP_L1_LESS|CMP_L2_GREATER;
                        }
                        position = i + 1;
                    }
                } else {
                    if(list1size > list2size) {// check which list is bigger
                        tmp = myList1 -> first;
                        tmp2 = myList2 -> first;
                    } else {
                        tmp = myList2 -> first;
                        tmp2 = myList1 -> first;
                    }
                    int positionint = 1;
                    do {
                        if(tmp -> info != tmp2 -> info) {
                            position = positionint;
                            if(tmp -> info > tmp2 -> info) {
                                comparvar = CMP_L1_GREATER|CMP_L2_LESS;
                            } else {
                                comparvar = CMP_L1_LESS|CMP_L2_GREATER;
                            }
                            break;
                        }
                        if(tmp2 -> after == NULL) {
                            position = positionint + 1;
                            if(list1size > list2size) {
                                comparvar = CMP_L1_GREATER;
                            } else {
                                comparvar = CMP_L2_GREATER;
                            }
                            break;
                        }
                        tmp = tmp -> after;
                        tmp2 = tmp2 -> after;
                        positionint = positionint + 1;
                    } while(tmp != NULL);
                }
            }
        }
    if(pos != NULL) { // check if pointer is null
        *pos = position;
    }
    return(comparvar);
}

// Author: Dan Shadeck
// 10/6/2015
// Data Structures
