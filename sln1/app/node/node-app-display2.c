#include <stdio.h>
#include "node.h"

void display(Node *);

int main()
{
    Node *tmp;
    Node *tmp2;
    tmp = NULL;
    tmp2 = NULL;
    int input = 0;


    fprintf(stdout, "Enter a info (-1 to quit): ");
    fscanf(stdin, "%d", &input);

    tmp = mknode(input);

    while (input != -1)
    {
        tmp2 = mknode(input);

        fprintf(stdout, "Enter a info (-1 to quit): ");
        fscanf(stdin, "%d", &input);
        
        tmp2->after = mknode(input);

        if (input == -1)
        {
            free(tmp2 -> after);
            tmp2 -> after = NULL;
        }
        else
            tmp2 = tmp2 -> after;
    }

    display(tmp);

	return(0);
}

void display(Node *start)
{
    Node *tmp;
    tmp = NULL;

    tmp = start;

    while (tmp->after != NULL)
    {
        printf("%d -> ", tmp->info);
        tmp = tmp->after;
    }
    printf("%d -> ",tmp->info);
    printf("NULL\n");
}
