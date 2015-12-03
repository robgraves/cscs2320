#include <cstdio>
#include <DoublyLinkedNode.h>

int main()
{
    Node *head    = NULL;
    Node *tail    = NULL;
    Node *tmp     = NULL;

	int   i       = 0;

	fprintf(stdout, "DoublyLinkedNode library testing application\n");
	fprintf(stdout, "============================================\n");
	for (i = 1; i < 128; i*=2)
	{
		if (head == NULL)
		{
			head  = tail = tmp = new DoublyLinkedNode(i);
		}
		else
		{
			tail -> setNext(new DoublyLinkedNode(i));
			tail -> getNext() -> setPrev(tail);
			tail  = tail -> getNext();
		}

		fprintf(stdout, "Forward: ");
		tmp = head;
		while (tmp != NULL)
		{
			fprintf(stdout, "%d -> ", tmp -> getValue());
			tmp = tmp -> getNext();
		}
		fprintf(stdout, "NULL\n");

		fprintf(stdout, "Reverse: ");
		tmp = tail;
		while (tmp != NULL)
		{
			fprintf(stdout, "%d -> ", tmp -> getValue());
			tmp = tmp -> getPrev();
		}
		fprintf(stdout, "NULL\n\n");
	}

	fprintf(stdout, "Pointing tmp at head (tmp = head;) ...\n");
	tmp = head;
	fprintf(stdout, "head: %p, value: %d\n", head, head -> getValue());
	fprintf(stdout, " tmp: %p, value: %d\n\n", tmp, tmp -> getValue());

	fprintf(stdout, "tmp is a copy of head (tmp = head -> copy();) ...\n");
	tmp = head -> copy();
	fprintf(stdout, "head: %p, value: %d\n", head, head -> getValue());
	fprintf(stdout, " tmp: %p, value: %d\n\n",  tmp,  tmp -> getValue());

	fprintf(stdout, "Removing nodes (calling destructor) ...\n");
	while (tail != NULL)
	{
		tmp = tail;
		while (tmp != NULL)
		{
			fprintf(stdout, "%d -> ", tmp -> getValue());
			tmp = tmp -> getPrev();
		}
		fprintf(stdout, "NULL\n");

		tmp = tail;
		tail = tail -> getPrev();

		delete tmp;
	}

    return(0);
}
