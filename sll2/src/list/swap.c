#include "list.h"

//////////////////////////////////////////////////////////////////////
//
// swapnode() - swap the position of two given nodes in a list, being
//              sure to appropriately adjust any and all pertinent
//              pointers to ensure list integrity following the
//              operation (including potential changes to the list's
//              own first and last pointers, along with connectivity
//              between the nodes from the start to end of the list).
//
//        note: you are NOT to just adjust node info values. You must
//              disconnect the identified nodes from the list and 
//              reconnect them- the node is our unit of transaction,
//              NOT the data it contains.
//
//    behavior: on a NULL list- do nothing: return NULL
//              on an EMPTY list- do nothing: return list unchanged
//              on a NULL/invalid nodes to swap- do nothing: return
//                  the list unchanged
//
//        note: where applicable, make use of the getpos() and
//              setpos() functions to aid you in accomplishing this
//              task. Don't needlessly reinvent the wheel.
//
//              as with the other functions, you may use no more
//              than one return() statement per function.
//
List *swapnode(List *myList, Node *item1, Node *item2)
{
	// your implementation here (please remove this comment when done)
	return(NULL);
}
