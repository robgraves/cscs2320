#include <cstdio>
#include <ListOfDoublyLinkedNodes.h>

int main()
{
    List *myList  = NULL;
    Node *tmp     = NULL;

    int   i;

    myList        = new ListOfDoublyLinkedNodes();

    for (i = 1; i < 96; i+= 8)
    {
		myList -> insert(myList -> getStart(), new DoublyLinkedNode(i));

        fprintf(stdout, "Forward: ");
        tmp = myList -> getStart();
        while (tmp != NULL)
        {
            fprintf(stdout, "%d -> ", tmp -> getValue());
            tmp = tmp -> getNext();
        }
        fprintf(stdout, "NULL (quantity is %d)\n", myList -> getQuantity());

        fprintf(stdout, "Reverse: ");
        tmp = myList -> getEnd();
        while (tmp != NULL)
        {
            fprintf(stdout, "%d -> ", tmp -> getValue());
            tmp = tmp -> getPrev();
        }
        fprintf(stdout, "NULL (quantity is %d)\n\n", myList -> getQuantity());
    }

    return(0);
}
