#include <stdio.h>
#include "node.h"

int main()
{
	Node *tmp, *tmp2, *tmp3, *tmp4;

	tmp           = (Node *) malloc (sizeof(Node)*1);
	tmp  -> info = 8;
	tmp  -> after  = tmp2 = (Node *) malloc (sizeof(Node)*1);
	tmp2 -> info = 12;
	tmp2 -> after  = NULL;

	tmp3          = (Node *) malloc (sizeof(Node)*1);
	tmp3 -> info = 17;
	tmp3 -> after  = tmp2;

	tmp2 -> info = tmp2 -> info + 16;

	tmp2 -> after  = tmp4 = (Node *) malloc (sizeof(Node)*1);
	tmp4 -> info = tmp2 -> info - 2;
	tmp4 -> after  = NULL;

	fprintf(stdout, "tmp  points to %p, contains: %d, ", tmp,  tmp  -> info);
	fprintf(stdout, "tmp's after is: %p\n", tmp -> after);
	fprintf(stdout, "tmp2 points to %p, contains: %d, ", tmp2, tmp2 -> info);
	fprintf(stdout, "tmp2's after is: %p\n", tmp2 -> after);
	fprintf(stdout, "tmp3 points to %p, contains: %d, ", tmp3, tmp3 -> info);
	fprintf(stdout, "tmp3's after is: %p\n", tmp3 -> after);
	fprintf(stdout, "tmp4 points to %p, contains: %d, ", tmp4, tmp4 -> info);
	fprintf(stdout, "tmp4's after is: %p\n", tmp4 -> after);

	return(0);
}
