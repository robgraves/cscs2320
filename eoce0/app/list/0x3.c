#include <stdio.h>
#include "list.h"

int main()
{
    FILE *file          = NULL;
    Node *tmp           = NULL;
    List *myListAttd    = NULL;
    List *myListOpus    = NULL;
    List *myListProj    = NULL;
    int num             = 0;
    int accumulator     = 0;
    int totalAttd       = 0;
    int totalOpus       = 0;
    int totalProj       = 0;
    int totalGrade      = 0;

    if ((file = fopen("status.flat", "r"))!=NULL)
    {
        mklist(&myListAttd);                 //making list for Attendance
        mklist(&myListOpus);                 //making list for Opus
        mklist(&myListProj);                 //making list for Projects

        fscanf(file, "%d", &num);       //should burn off the starting -1

        //iterating through attendance/participation portion of data
        while (num != -2)
        {
            fscanf(file, "%d", &num);   //read next value 
            tmp = NULL;
            mknode(&tmp, num);           //make new node containing read value as char
            append(&myListAttd, myListAttd->last, tmp);
            
        }
    
        //tallying totals for attendance/participiation
        tmp = myListAttd->first;

        while (tmp->VALUE != -2)
        {
            totalAttd = totalAttd + tmp->VALUE;
            tmp = tmp->after;
        }
        totalAttd = ((totalAttd * 28) / 24);

        //output for attendance/participation
        printf("Participation Component:  %d/28\n", totalAttd);

        //iterating through opus portion of data
        while (num != -3)
        {
            fscanf(file, "%d", &num);   //read next value 
            tmp = NULL;
            mknode(&tmp, num);           //make new node containing read value as char
            append(&myListOpus, myListOpus->last, tmp);
            
        }

        //tallying totals for opus
        tmp = myListOpus->first;

        while (tmp->VALUE != -3)
        {
            totalOpus = totalOpus + tmp->VALUE;
            tmp = tmp->after;
        }
        totalOpus = ((totalOpus * 36) / 13);

        //output for attendance/participation
        printf("Journal Component:        %d/36\n", totalOpus);

        //iterating through project portion of data
        while (num != -4)
        {
            fscanf(file, "%d", &num);   //read next value 
            tmp = NULL;
            //resolving char limit
            if (num > 127)
            {
                while (num > 127)
                {
                    num = num - 127;        //subtracting 127 from num that exceeeds 127 for char limit
                    tmp = NULL;
                    mknode(&tmp, 127);
                    append(&myListProj, myListProj->last, tmp); 
                }

                tmp = NULL;
                mknode(&tmp, num);
                append(&myListProj, myListProj->last, tmp); 

            }
            mknode(&tmp, num);           //make new node containing read value as char
            append(&myListProj, myListProj->last, tmp); 
            fscanf(file, "%d", &num);   //burn off second value (x/y) the y value in status command 
            accumulator = accumulator + num;    //adding up totals of each project possible points
            
        }

        //tallying totals for projecta
        tmp = myListProj->first;

        while (tmp->VALUE != -4)
        {
            totalProj = totalProj + tmp->VALUE;
            tmp = tmp->after;
        }
        totalProj = ((totalProj * 36) / accumulator);

        //output for attendance/participation
        printf("Projects Component:       %d/36\n", totalProj);


        totalGrade = totalAttd + totalOpus + totalProj;

        //total grade output
        printf("Total:                    %d/100\n", totalGrade);



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
