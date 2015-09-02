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
    int buildinput = 0;
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
                printf("Build List Function:\n");
                printf("Enter values for the list.  Enter a '-1' to signify the end of data.\n");
                while (buildinput != -1)
                {
                    printf("Enter value: \n");    
                    scanf("%d", &buildinput);
                    buildlist();
                }
                break;
            case 2:         //Display List
                printf("Display List Function\n");
                displaylist();
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
void buildlist()
{
    
}
void displaylist()
{

}
void insert()
{

}
void append()
{

}
void obtain()
{

}
void clearlist()
{

}
