#include "list.h"

//////////////////////////////////////////////////////////////////////
//
// sortlist() - a list library function to sort an existing list
//              according to the mode indicated.
//
//              the original list is **preserved**, and the altered/
//              sorted list (a new list) is what is returned.
//
//   modes are: 0 - least to greatest (least is first)
//              1 - greatest to least (greatest is first)
//              2 - reverse order of original list
//
//    behavior: on error, return NULL.
//              on invalid mode, MOD by total modes and continue,
//                  performing whatever that result is.
//
//        note: you are to have only ONE return statement for this
//              entire function. Change the existing one as needed.
//

///////////////////////////////////////////////////////////////////
//
//  Borrowing my buddy Dan Shadeck's code for educational purposes
//
///////////////////////////////////////////////////////////////////

int sort(const void* a, const void* b) {
	return (*(char*)a - *(char*)b);
}

int sort2(const void* a, const void* b) {
	return (*(char*)b - *(char*)a);
}

List *sortlist(List *myList, int mode)
{
	List *newList = NULL; // new list
	if(myList != NULL) { // check if list null
		if(myList -> first == NULL) { // check if list null
			newList = mklist();
		} else {
			if(mode >= 0 && mode <= 2) { // make sure mode is good
				mode = mode % 3;
			}
			if(mode == 0 || mode == 1) { // sorting
				int listsize = 0;
				Node *tmp = myList -> first;
				while(tmp != NULL) {
					listsize = listsize+1;
					tmp = tmp -> after;
				}
				char liststuff[listsize];
				tmp = myList -> first;
				int index = 0;
				while(tmp != NULL) { // loop through list
					liststuff[index++] = tmp -> info;
					tmp = tmp -> after;
				}
				if(mode == 0) { // sort
					qsort(liststuff, listsize, sizeof(char), sort);
				} else {
					qsort(liststuff, listsize, sizeof(char), sort2);
				}
				newList = mklist();
				newList -> first = mknode(liststuff[0]);
				tmp = NULL;
				Node *tmp2 = newList -> first;
				for(index = 1; index < listsize; index++) {
					tmp = mknode(liststuff[index]);
					tmp2 -> after = tmp;
					tmp2 = tmp;
				}
				myList -> last = tmp;
			} else if(mode==2) { // reversing
				int listsize =0;
				Node *tmp = myList -> first;
				while(tmp != NULL) {
					listsize++;
					tmp = tmp -> after;
				}
				char liststuff[listsize];
				tmp = myList -> first;
				int index = 0;
				while(tmp != NULL) { // loop through list
					liststuff[index++] = tmp -> info;
					tmp = tmp -> after;
				}
				newList = mklist();
				newList -> first = mknode(liststuff[listsize-1]);
				Node *tmp2 = newList -> first;
				for(index = listsize-2; index>=0; index--) {
					tmp = mknode(liststuff[index]);
					tmp2 -> after = tmp;
					tmp2 = tmp;
				}
				myList -> last = tmp;
			}
		}
	}
	return(newList);
}

// Author: Dan Shadeck
// October 20, 2015
// Data Structures
