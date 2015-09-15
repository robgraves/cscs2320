#include <stdio.h>
#include "node.h"

int main()
{
	Node *tmp, *tmp2;
	char input;

	tmp          = tmp2 = (Node *) malloc (sizeof(Node)*1);
	tmp -> info = 0;
	tmp -> after  = NULL;

	fprintf(stdout, "Enter a info (-1 to quit): ");
	fscanf(stdin, "%hhd", &input);

	while (input != -1)
	{
		tmp2 -> info = input;

		tmp2 -> after = (Node *) malloc (sizeof(Node)*1);
		tmp2 -> after -> info = 0;
		tmp2 -> after -> after  = NULL;

		fprintf(stdout, "Enter a info (-1 to quit): ");
		fscanf(stdin, "%hhd", &input);

		if (input == -1)
		{
			free(tmp2 -> after);
			tmp2 -> after = NULL;
		}
		else
			tmp2 = tmp2 -> after;
	}

	// Provide code to display list from start to end

	return(0);
}
