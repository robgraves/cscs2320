#include <stdio.h>
#include "list.h"

int main()
{
    FILE *file      = NULL;
    Node *tmp       = NULL;
    List *myList    = NULL;
    int num         = 0;

    if ((file = fopen("status.flat", "r"))!=NULL)
    {
        mklist(&myList);                 //making list
        //myList = mklist();                 //making list

        fscanf(file, "%d", &num);       //should burn off the starting -1

        while (num != -2)
        {
            fscanf(file, "%d", &num);   //read next value 
            tmp = NULL;
            mknode(&tmp, num);           //make new node containing read value as char
            //tmp = mknode(num);           //make new node containing read value as char
            append(&myList, myList->last, tmp); 
            //myList = append(myList, myList->first, tmp); 
            
            display(myList, 0);
            //printf("%d", num);
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

    //display(myList, 0);

	return(0);
}
