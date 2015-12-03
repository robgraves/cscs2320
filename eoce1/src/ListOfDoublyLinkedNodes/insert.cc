#include "ListOfDoublyLinkedNodes.h"

// insert() - insert newNode before place in this
//
void ListOfDoublyLinkedNodes :: insert(Node *place, Node *newNode)
{
    //////////////////////////////////////////////////////////////////
    //
    // check for NULL list or NULL newNode
    //
    if ((this                != NULL) &&
        (newNode             != NULL))
    {
        //////////////////////////////////////////////////////////////
        //
        // check for empty list
        //
        if (this    -> getFirst() == NULL)
        {
            this    -> setFirst(newNode);
			this    -> setLast  (newNode);
            newNode -> setPrior(NULL);
            newNode -> setAfter(NULL);
        }

        //////////////////////////////////////////////////////////////
        //
        // if we are inserting at the start of the list
        //
        else if (place       == this -> getFirst())
        {
            this    -> getFirst() -> setPrior(newNode);
            newNode -> setAfter(this -> getFirst());
            this    -> setFirst(newNode);
        }

        //////////////////////////////////////////////////////////////
        //
        // average case list insertion
        //
        else
        {
            newNode -> setAfter(place);
            if (place        != NULL)
            {
                newNode -> setPrior(place -> getPrior());
                place   -> setPrior(newNode);
                newNode -> getPrior()     -> setAfter(newNode);
            }
        }

        //////////////////////////////////////////////////////////////
        //
        // node inserted; adjust list quantity
        //
        this -> setQuantity(this -> getQuantity() + 1);
    }
}
