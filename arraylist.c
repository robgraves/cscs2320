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
    void buildlist();
    void displaylist();
    void insert();
    void append();
    void obtain();
    void clearlist();

main()
{
    //variable declarations
    int input = 0;
    int quitflag = 0;

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
                buildlist();
                break;
            case 2:         //Display List
                displaylist();
                break;
            case 3:         //Insert into List 
                insert();
                break;
            case 4:         //Append into List
                append();
                break;     
            case 5:         //Obtain from List
                obtain();
                break;
            case 6:         //Clear List         
                clearlist();
                break;
            case 7:         //Quit
                printf("Leaving...Have a Nice Day!! :)\n");
                quitflag = 1;
                break;
            default:
                printf("ERROR: Invalid entry!\n");
        }
    }


    return (0);
}

//User menu function
void menu()
{
    //output menu
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
void buildlist()
{
    printf("Build List Function\n");
}
void displaylist()
{
    printf("Display List Function\n");
}
void insert()
{
    printf("Insert into List Function\n");
}
void append()
{
    printf("Append into List Function\n");
}
void obtain()
{
    printf("Obtain from List Function\n");
}
void clearlist()
{
    printf("Clear List Function\n");
}
