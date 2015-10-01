#include <stdio.h>
#include <stdlib.h>
#include "node.h"

int main()
{
	Node *tmp = mknode(17);
	
	fprintf(stdout, "Before calling rmnode(tmp) ...   \n");
	fprintf(stdout, "---------------------------------------------\n");
	fprintf(stdout, "tmp has an address of:         %p\n", &tmp);
	fprintf(stdout, "tmp points to:                 %p\n",  tmp);

	tmp = rmnode(tmp);

	fprintf(stdout, "\nAfter calling rmnode(tmp) ...    \n");
	fprintf(stdout, "---------------------------------------------\n");
	fprintf(stdout, "tmp has an address of:         %p\n", &tmp);
	fprintf(stdout, "tmp points to:                 %p\n",  tmp);

	if (tmp == NULL)
	{
		fprintf(stdout, "tmp successfully deleted.\n");
	}
	else
	{
		fprintf(stderr, "error deleting tmp.\n");
		exit(1);
	}

	return(0);
}
