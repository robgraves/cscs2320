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
    int * insert(int, int, int *);      //passing requested index, new value, and array
    int * append(int, int, int *);      //passing requested index, new value, and array
    int * obtain(int, int *, int*);     //passing index, array, and address of obt_value
    int * clearlist(int *);             //clears out the array, pass array

main()
{
    //variable declarations
    int input = 0;                      //user's choice on menu
    int buildinput = 0;                 //values entered to build list
    int quitflag = 0;                   //quit variable for main program loop
    int index = 0;                      //index associated with build list entries
    int array[21];                      //the array set to a size of 21
    int ins_index = 0;                  //index of desired insertion point for insert() function
    int app_index = 0;                  //index of desired appending point for append() function
    int ins_value = 0;                  //value entered at insertion point for insert() function
    int app_value = 0;                  //value entered at appending point for append() function
    int obt_index = 0;                  //index of desired value to obtain in obtain() function
    int obt_value = 0;                  //obtained and removed value from obtain() function

    clearlist(array);           //calling clearlist passing it the array, to enter all -1's in array

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
                printf("Enter index of array element to insert before: \n");
                scanf("%d", &ins_index);
                printf("Enter new value to insert before this index: \n");
                scanf("%d", &ins_value);
                insert(ins_index, ins_value, array);
                break;
            case 4:         //Append into List
                printf("Append into List Function\n");
                printf("Enter index of array element to append after: \n");
                scanf("%d", &app_index);
                printf("Enter new value to append after this index: \n");
                scanf("%d", &app_value);
                append(app_index, app_value, array);
                break;     
            case 5:         //Obtain from List
                printf("Obtain from List Function\n");
                printf("Enter index of array element to obtain: \n");
                printf("(This will remove this value from the list)\n");
                scanf("%d", &obt_index);
                obtain(obt_index, array, &obt_value);
                printf("Removing Element #%d : %d from the list. \n", obt_index, obt_value );
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
                break;                                    
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
int * insert(int ins_index, int ins_value, int * array)               
{
    int i = ins_index;
    for (i=19;i>=ins_index;i--)
    {
        array[i+1]=array[i];
    }
    array[ins_index]=ins_value;
    return array;
}

//Append into List Function
int * append(int app_index, int app_value, int * array)           
{
    int i = app_index;
    for (i=19;i>=app_index;i--)
    {
        array[i+1]=array[i];
    }
    array[app_index+1]=app_value;
    return array;
}

//Obtain from List Function
int * obtain(int obt_index, int * array, int* obt_value)                        //WORK IN PROGRESS
{                                                                      
    int i = obt_index;
    //int *obt_value = & obt_value;
    (*obt_value)=array[obt_index];
    //array[obt_index]=*obt_value;
    for (i=obt_index;i<=19;i++)
    {
        array[i]=array[i+1];
    }
    //array[obt_index]=(sizeof(int))obt_value;
    return array;
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
