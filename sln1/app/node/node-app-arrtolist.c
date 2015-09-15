#include <stdio.h>
#include "node.h"

int main()
{
	char data[] = { 3, 1, 4, 1, 5, 9, 2, 6, 5, 3, 5, 8, 9, 7 };
	int i;

	fprintf(stdout, "Array: ");
	for(i = 0; i < 14; i++)
		fprintf(stdout, "%hhd ", *(data+i));
	fprintf(stdout, "\n");

	// Create a linked list of nodes, using the node library 
	// functions where applicable (mknode() specifically), and
	// have each node contain one of the above array elements,
	// to have a linked list equivalent of the array.

	// Display the list from beginning to end- the above order
	// of values should be seen.

	return(0);
}
