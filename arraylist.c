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

main()
{
    //Variable declarations

    
    //Function Prototypes
    void menu();                //Do I want the menu to be a function?        
    void buildlist();
    void displaylist();
    void insert();
    void append();
    void obtain();
    void clearlist();
    
    menu();                     //calling menu fucntion

    //case switching for user input
    
    return (0);
}

//User menu function
void menu()
{
    //variable declarations
    int input = 0;

    //output menu
    printf("Data Structures Array List Program Menu\n");
    printf("---------------------------------------\n");
    printf("Please choose one of the following:\n");
    printf("1 - Build List\n");
    printf("2 - Display List\n");
    printf("3 - Insert into List\n");
    printf("4 - Append into List\n");
    printf("5 - Obtain from List\n");
    printf("7 - Clear List\n");
    printf("8 - Quit\n");

    //User input
    scanf("%d", &input);

    switch(input)
    {
        case 1:

            break;
        case 2:

            break;
        case 3:

            break;
        case 4:

            break;
        case 5:

            break;
        case 6:

            break;
        case 7:

            break;
        case 8:

            break;
        default:
            printf("ERROR: Invalide entry!\n");
    }

    //Test
    printf("You chose number: %d\n", input);
}
