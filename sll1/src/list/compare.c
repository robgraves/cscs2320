#include "list.h"

//////////////////////////////////////////////////////////////////////
//
// compare() - a list library utility function to compare two lists,
//             and to return a result indicating equality (or the lack
//             thereof), as well as the position of difference.
//
//       note: if pos is initially NULL, care should be taken not to
//             assign any values to it.
//
//             a pos of 0 indicates a NULL or EMPTY list is our 
//             point of difference. Any actual list node positions
//             will start from 1 (be aware of this difference from
//             setpos()/getpos()).
//
//             the condition of both lists should be reflected in
//             the code that is ultimately returned. In the event 
//             of a NULL or EMPTY list, those conditions trump 
//             any greater/less/equality status.
//
//   examples: a few examples for reference.
//
//             list1: NULL
//             list2: NULL
//             code:  CMP_L1_NULL  | CMP_L2_NULL
//             pos:   0
//
//             list1: EMPTY
//             list2: EMPTY
//             code:  CMP_L1_EMPTY | CMP_L2_EMPTY
//             pos:   0
//
//             list1: NULL
//             list2: EMPTY
//             code:  CMP_L1_NULL  | CMP_L2_EMPTY
//             pos:   0
//
//             list1: EMPTY
//             list2: NULL
//             code:  CMP_L1_EMPTY | CMP_L2_NULL
//             pos:   0
//
//             list1: NULL
//             list2: 1 -> 2 -> NULL
//             code:  CMP_L1_NULL
//             pos:   0
//
//             list1: EMPTY
//             list2: 1 -> 2 -> NULL
//             code:  CMP_L1_EMPTY
//             pos:   0
//
//             list1: 1 -> 2 -> NULL
//             list2: NULL
//             code:  CMP_L2_NULL
//             pos:   0
//
//             list1: 1 -> 2 -> NULL
//             list2: EMPTY
//             code:  CMP_L2_EMPTY
//             pos:   0
//
//             list1: 2 -> NULL
//             list2: 1 -> 2 -> NULL
//             code:  CMP_L1_GREATER | CMP_L2_LESS
//             pos:   1
//
//             list1: 1 -> NULL
//             list2: 1 -> 2 -> NULL
//             code:  CMP_L2_GREATER
//             pos:   2
//
//             list1: 1 -> 2 -> NULL
//             list2: 1 -> 3 -> NULL
//             code:  CMP_L1_LESS    | CMP_L2_GREATER
//             pos:   2
//
//             list1: 1 -> 3 -> NULL
//             list2: 1 -> 3 -> NULL
//             code:  CMP_EQUALITY
//             pos:   2
//
//             you are to have only ONE return statement for this
//             entire function. Change the existing one as needed.
//
uc compare(List *myList1, List *myList2, ulli *pos)
{
    //variable and pointer declarations and initializations
    Node *tmp   = NULL;
    Node *tmp2  = NULL;
    unsigned char returnable = 0;
    //(*pos) = 0;
    int i = 0;
    
    //status of myList1 and myList2 respectively
    //0 is NULL, 1 is empty, 2 is populated
    int status1 = 0; 
    int status2 = 0;

    //setting status1 for myList1 to 0 for NULL list,
    //1 for EMPTY list, and 2 for a populated list
    if (myList1 == NULL)
    {
        status1 = 0;
    }
    else if (myList1->first == NULL)
    {
        status1 = 1;   
    }
    else
    {
        status1 = 2;
    }

    //setting status2 for myList2 to 0 for NULL list,
    //1 for EMPTY list, and 2 for a populated list
    if (myList2 == NULL)
    {
        status2 = 0;
    }
    else if (myList2->first == NULL)
    {
        status2 = 1;
    }
    else
    {
        status2 = 2;
    }

    if ((status1 == 2) && (status2 == 2))
    {
        //setting tmp to beginning of list 1 and
        //setting tmp2 to beginning of list 2
        tmp     = myList1->first;
        tmp2    = myList2->first;
        
        //checking for single node list

        //moving tmp and tmp2 pointers through lists
        //while tmp and tmp2 aren't NULL
        while ((tmp != NULL) && (tmp2 != NULL))
        {
            //if values in nodes are different
            if (tmp->info != tmp2->info)
            {
                //get current position
                (*pos)=i;

                //determine which value is larger

                if (tmp->info > tmp2->info)
                {
                    returnable = (CMP_L1_GREATER|CMP_L2_LESS);
                }
                if (tmp2->info > tmp->info)
                {
                    returnable = (CMP_L1_LESS|CMP_L2_GREATER);
                }

                //force end of loop
                tmp == NULL;
                tmp2 == NULL;
            }
            //if myList1 is shorter than return postition
            //and returnable is assigned list 2 as greater
            if (tmp == NULL)
            {
                (*pos)=i;
                returnable = (CMP_L2_GREATER);
            }
            //if myList2 is shorter than return postition
            //and returnable is assigned list 1 as greater
            if (tmp2 == NULL)
            {   
                (*pos)=i;
                returnable = (CMP_L1_GREATER);
            }
            
            tmp = tmp->after;
            tmp2 = tmp2->after;
            i++;

        }

        /*
        //if myList1 is shorter than return postition
        //and returnable is assigned list 2 as greater
        if (tmp == NULL)
        {
            (*pos)=i;
            returnable = (CMP_L2_GREATER);
        }
        //if myList2 is shorter than return postition
        //and returnable is assigned list 1 as greater
        if (tmp2 == NULL)
        {   
            (*pos)=i;
            returnable = (CMP_L1_GREATER);
        }
        */

        //if position is NULL return position as i
        if (pos != NULL)
        {    
            (*pos)=i;
        }

    }
    else
    {
        //checking for NULL and NULL lists
        if ((status1 == 0) && (status2 == 0))
        {
            (*pos)=0;
            returnable = (CMP_L1_NULL|CMP_L2_NULL);
        }
        //checking for EMPTY and NULL lists
        if ((status1 == 1) && (status2 == 0))
        {
            (*pos)=0;
            returnable = (CMP_L1_EMPTY|CMP_L2_NULL);
        }
        //checking for NULL and EMPTY lists
        if ((status1 == 0) && (status2 == 1))
        {
            (*pos)=0;
            returnable = (CMP_L1_NULL|CMP_L2_EMPTY);
        }
        //checking for EMPTY and EMPTY lists
        if ((status1 == 1) && (status2 == 1))
        {
            (*pos)=0;
            returnable = (CMP_L1_EMPTY|CMP_L2_EMPTY);
        }

        //checking for NULL and populated lists
        if ((status1 == 0) && (status2 == 2))
        {
            (*pos)=0;
            returnable = (CMP_L1_NULL);
        }
        //checking for EMPTY and populated lists
        if ((status1 == 1) && (status2 == 2))
        {
            (*pos)=0;
            returnable = (CMP_L1_EMPTY);
        }
        //checking for populated and NULL lists
        if ((status1 == 2) && (status2 == 0))
        {
            (*pos)=0;
            returnable = (CMP_L2_NULL);
        }
        //checking for populated and EMPTY lists
        if ((status1 == 2) && (status2 == 1))
        {
            (*pos)=0;
            returnable = (CMP_L2_EMPTY);
        }
    }

    //setting tmp to beginning of list 1 and
    //setting tmp2 to beginning of list 2
    //tmp     = myList1->first;
    //tmp2    = myList2->first;
    
    //checking for single node list

    //moving tmp and tmp2 pointers through lists
    //while (tmp != NULL)
    //{
    
   //     tmp = tmp->after;
   //     tmp2 = tmp2->after;

    //}

    /*
    if (tmp->info != tmp2->info)
    {
        (*pos)=i;
    }
    else
    {

    }
    */

    //if ((myList1 == NULL) && (myList2 == NULL))
    //{
    //    (*pos)=0;
    //    returnable = (CMP_L1_NULL|CMP_L2_NULL);
    //}
    //if ((myList1->first == NULL) (myList2 == NULL))
    //{
    //    (*pos)=0;
    //    returnable = (CMP_L1_EMPTY|CMP_L2_NULL);
    //}
    //setting tmp to beginning of list 1 and
    //setting tmp2 to beginning of list 2
    //tmp     = myList1->first;
    //tmp2    = myList2->first;

	//return(CMP_L1_LESS|CMP_L2_LESS);
	return(returnable);
}
