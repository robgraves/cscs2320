#include <cstdio>
#include <SinglyLinkedNode.h>

int main()
{
    Node *head    = NULL;
    Node *tail    = NULL;
    Node *tmp     = NULL;

	int   i       = 0;

	fprintf(stdout, "SinglyLinkedNode library testing application\n");
	fprintf(stdout, "============================================\n");
	for (i = 1; i < 128; i*=2)
	{
		if (head == NULL)
		{
			head  = tail = tmp = new SinglyLinkedNode(i);
		}
		else
		{
			tail -> setNext(new SinglyLinkedNode(i));
			tail  = tail -> getNext();
		}

		fprintf(stdout, "[%d] ", i);
		tmp = head;
		while (tmp != NULL)
		{
			fprintf(stdout, "%d -> ", tmp -> getValue());
			tmp = tmp -> getNext();
		}
		fprintf(stdout, "NULL\n");
	}

	fprintf(stdout, "\nPointing tmp at head (tmp = head;) ...\n");
	tmp = head;
	fprintf(stdout, "head: %p, value: %d\n", head, head -> getValue());
	fprintf(stdout, " tmp: %p, value: %d\n\n", tmp, tmp -> getValue());

	fprintf(stdout, "tmp is a copy of head (tmp = head -> copy();) ...\n");
	tmp = head -> copy();
	fprintf(stdout, "head: %p, value: %d\n", head, head -> getValue());
	fprintf(stdout, " tmp: %p, value: %d\n\n",  tmp,  tmp -> getValue());

	fprintf(stdout, "Removing nodes (calling destructor) ...\n");
	while (head != NULL)
	{
		tmp = head;
		while (tmp != NULL)
		{
			fprintf(stdout, "%d -> ", tmp -> getValue());
			tmp = tmp -> getNext();
		}
		fprintf(stdout, "NULL\n");

		tmp = head;
		head = head -> getNext();

		delete tmp;
	}

    return(0);
}
