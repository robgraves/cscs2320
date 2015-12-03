#include <cstdio>
#include <ListOfSinglyLinkedNodes.h>

int main()
{
    List *myList  = NULL;
	List *cpList  = NULL;
    Node *tmp     = NULL;

    int   i;

    myList        = new ListOfSinglyLinkedNodes();

	fprintf(stdout, "ListOfSinglyLinkedNodes library testing application\n");
	fprintf(stdout, "===================================================\n");

    for (i = 1; i < 96; i+= 8)
    {
		myList -> insert(myList -> getStart(), new SinglyLinkedNode(i));

        fprintf(stdout, "[%d]: ", i);
        tmp = myList -> getStart();
        while (tmp != NULL)
        {
            fprintf(stdout, "%d -> ", tmp -> getValue());
            tmp = tmp -> getNext();
        }
        fprintf(stdout, "NULL (quantity is %d)\n", myList -> getQuantity());
    }

	fprintf(stdout, "\nCopying myList (cpList = myList -> copy();) ...\n\n");
	cpList = myList -> copy();

	// If obtain() isn't implemented/working, this will result in an infinite loop!
	fprintf(stdout, "Clearing myList manually (needs a working obtain() ...\n");
	while (myList -> getStart() != NULL)
	{
		delete myList -> obtain(myList -> getStart());

        tmp = myList -> getStart();
        while (tmp != NULL)
        {
            fprintf(stdout, "%d -> ", tmp -> getValue());
            tmp = tmp -> getNext();
        }
        fprintf(stdout, "NULL (quantity is %d)\n\n", myList -> getQuantity());
	}
	delete myList;

	fprintf(stdout, "Displaying cpList (now that myList is cleared) ... \n");
	tmp = cpList -> getStart();
	while (tmp != NULL)
	{
		fprintf(stdout, "%d -> ", tmp -> getValue());
		tmp = tmp -> getNext();
	}
	fprintf(stdout, "NULL (quantity is %d)\n\n", cpList -> getQuantity());

	fprintf(stdout, "Deleting cpList (delete cpList;) ...\n\n");
	delete cpList;

    return(0);
}
