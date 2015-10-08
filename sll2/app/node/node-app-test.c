#include <stdio.h>
#include "node.h"

int main()
{
	Node *tmp, *tmp2, *tmp3, *tmp4;

	tmp           = (Node *) malloc (sizeof(Node)*1);
	tmp  -> info = 8;
	tmp  -> after  = NULL;

	tmp2          = (Node *) malloc (sizeof(Node)*1);
	tmp2 -> info = 12;
	tmp2 -> after  = NULL;

	tmp3          = (Node *) malloc (sizeof(Node)*1);
	tmp3 -> info = 17;
	tmp3 -> after  = NULL;
	tmp2 -> info = tmp3 -> info;

	tmp2 -> info = tmp2 -> info + 16;

	tmp4          = (Node *) malloc (sizeof(Node)*1);
	tmp4 -> info = tmp2 -> info;
	tmp4 -> after  = NULL;

	fprintf(stdout, "tmp  points to %p, contains: %d\n", tmp,  tmp  -> info);
	fprintf(stdout, "tmp2 points to %p, contains: %d\n", tmp2, tmp2 -> info);
	fprintf(stdout, "tmp3 points to %p, contains: %d\n", tmp3, tmp3 -> info);
	fprintf(stdout, "tmp4 points to %p, contains: %d\n", tmp4, tmp4 -> info);

	return(0);
}
