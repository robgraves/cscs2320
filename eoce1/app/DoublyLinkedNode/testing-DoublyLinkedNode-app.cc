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
			tail -> setAfter(new DoublyLinkedNode(i));
			tail -> getAfter() -> setPrior(tail);
			tail  = tail -> getAfter();
		}

		fprintf(stdout, "Forward: ");
		tmp = head;
		while (tmp != NULL)
		{
			fprintf(stdout, "%d -> ", tmp -> getValue());
			tmp = tmp -> getAfter();
		}
		fprintf(stdout, "NULL\n");

		fprintf(stdout, "Reverse: ");
		tmp = tail;
		while (tmp != NULL)
		{
			fprintf(stdout, "%d -> ", tmp -> getValue());
			tmp = tmp -> getPrior();
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
			tmp = tmp -> getPrior();
		}
		fprintf(stdout, "NULL\n");

		tmp = tail;
		tail = tail -> getPrior();

		delete tmp;
	}

    return(0);
}
