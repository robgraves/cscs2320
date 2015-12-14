#include <stdio.h>
#include "list.h"

int main()
{
    FILE *file  = NULL;
    //tmp *node   = NULL;
    //list *list  = NULL;
    int num     = 0;

    if ((file = fopen("status.flat", "r"))!=NULL)
    {
        while (num != -2)
        {
            fscanf(file, "%d", &num);
            printf("%d", num);
        }
        fclose(file);
        return 1;
    }
    else
    {
        //system("flattendata");
        printf("File: status.flat does not exist!\n");
        printf("Please run \"flattendata\" first.\n");
    } 

	return(0);
}
