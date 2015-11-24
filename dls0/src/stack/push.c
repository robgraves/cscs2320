#include "stack.h"

//////////////////////////////////////////////////////////////////////
//
//     push() - place newNode onto top of given stack
//
//              be sure to utilize existing list and stack library
//              functions to facilitate your implementation. Do NOT
//              reinvent the wheel.
//
//              the top of the stack should track the last node in
//              its underlying list.
//
// status code: this function can generate the following status codes
//                  DLN_NULL:     newNode is NULL (an error)
//                  DLS_SUCCESS:  normal operation (push successful)
//                  DLS_NULL:     stack is NULL
//                  DLS_OVERFLOW: tried to push onto a full bounded
//                                stack (considered an error)
//                  DLS_ERROR:    error encountered
//                  DLS_INVALID:  stack does not exist
//
//        note: you are to have only ONE return statement for this
//              entire function. Change the existing one as needed.
//
code_t push(Stack **myStack, Node *newNode)
{
    //variable declarations and initializations
    code_t result = 0;
    code_t push_result = 0;
    
    if (myStack != NULL)
    {
        if ((*myStack) != NULL)
        {
            //result = DLS_ERROR | DLS_INVALID;
            result = DLS_ERROR | DLN_NULL;
        }
        else
        {
            if (newNode == NULL)
            {
                result = DLS_ERROR | DLN_NULL;
            }
            else
            {
                if ((*myStack)->top == NULL)
                {
                    result = DLS_ERROR | DLN_NULL;    
                }
                else
                {
                    //newNode->after = (*myStack)->top;
                    //(*myStack)->top = newNode;
                    push_result = append(&((*myStack)->data), ((*myStack)->data->last), newNode);
                    (*myStack)->top = (*myStack)->data->last;

                    result = DLS_SUCCESS;
                }
            }
        }
    }
    else
    {
        result = DLS_INVALID | DLS_ERROR;
    }


	return (result);
}
