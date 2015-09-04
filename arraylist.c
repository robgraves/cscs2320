/**************************************************
 *
 *  Matthew Page
 *  08/29/2015
 *  CSCS2320 - Data Structures
 *  Fall 2015
 *
 *  arraylist.c -   project dsi0 for data structs
 *                  where creating a program that
 *                  presents the user with a menu  
 *                  to build list, display list, 
 *                  insert into list, append into
 *                  list, obtain from list, clear
 *                  list, and quit.  This first 
 *                  project will be using an array
 *                  and functions for each option
 *                  in the menu, in later projects
 *                  we will use linked lists with 
 *                  nodes.
 *
 *************************************************/

#include <stdio.h>

    //Function Prototypes
    void menu();                        
    int buildlist(int, int *, int);     //passing index, array pointer, and buildinput
    void displaylist(int *);            //passing array pointer
    void insert();
    void append();
    void obtain();
    int * clearlist(int *);

main()
{
    //variable declarations
    int input = 0;
    int buildinput = 0;
    int quitflag = 0;
    int index = 0;
    int array[21];

    //main program loop
    while (quitflag != 1)          
    {
        
        //calling menu function
        menu();               

        //User input
        scanf("%d", &input);

        //case switching statement
        switch(input)
        {
            case 1:         //Build List
                printf("Build List Function:\n");
                printf("Enter values into the list up to 20 values total.\n");  
                printf("Enter a '-1' to signify the end of data.\n");

                while ((buildinput != -1) && (index<20))
                {
                    printf("Enter value: \n");    
                    scanf("%d", &buildinput);
                    index=buildlist(index,array,buildinput);
                }

                if (index == 20)            //Testing for full array
                {
                    printf("Maximum values reached.  Array is full.\n");    //Full array message
                }

                break;
            case 2:         //Display List
                printf("Display List Function\n");
                displaylist(array);
                break;
            case 3:         //Insert into List 
                printf("Insert into List Function\n");
                insert();
                break;
            case 4:         //Append into List
                printf("Append into List Function\n");
                append();
                break;     
            case 5:         //Obtain from List
                printf("Obtain from List Function\n");
                obtain();
                break;
            case 6:         //Clear List         
                printf("Clear List Function\n");
                clearlist(array);                           //calling clearlist passing it the array
                break;
            case 7:         //Quit
                printf("Leaving...Have a Nice Day!! :)\n");
                quitflag = 1;                               //changing quit flag upon quit selection
                break;
            default:
                printf("ERROR: Invalid entry!\n");          //Error message for invalid entry
        }
    }


    return (0);
}

//User Menu Function
void menu()
{
    //output menu
    printf("---------------------------------------\n");
    printf("Data Structures Array List Program Menu\n");
    printf("---------------------------------------\n");
    printf("Please choose one of the following:\n");
    printf("1 - Build List\n");
    printf("2 - Display List\n");
    printf("3 - Insert into List\n");
    printf("4 - Append into List\n");
    printf("5 - Obtain from List\n");
    printf("6 - Clear List\n");
    printf("7 - Quit\n");
    printf("---------------------------------------\n");

}

//Build List Function
int buildlist(int index, int *array, int buildinput)
{
    array[index]=buildinput;
    printf("Array index %d is %d\n", index, array[index]);
    index++;
    return index;
}

//Display List Function
void displaylist(int *array)
{
    int i = 0;
    printf("The list is: \n");
    while ((array[i] != -1) && (i<20))
    { 
        printf("Element #%d: %d\n", i, array[i]);
        i++;
    }
}

//Insert into List Function
void insert()                   //WORK IN  PROGRESS
{
    int ins_index = 0;
    printf("Enter index of array element to append after: \n");
}

//Append into List Function
void append()
{

}

//Obtain from List Function
void obtain()
{

}

//Clear List Function
int * clearlist(int *array)
{
    int i;
    for (i=0;i<=20;i++)
    {
        array[i]=-1;
    }
    return array;
}
