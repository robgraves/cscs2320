#include "stack.h"

//////////////////////////////////////////////////////////////////////
//
//  isempty() - return an indication as to stack's emptiness
//
//              be sure to utilize existing list and stack library
//              functions to facilitate your implementation. Do NOT
//              reinvent the wheel.
//
//              the top of the stack should follow the last node in
//              its underlying list.
//
// status code: this function can generate the following status codes
//                  DLS_SUCCESS:  normal operations
//                  DLS_OVERFLOW: stack is populated
//                  DLS_NULL:     stack is NULL
//                  DLS_EMPTY:    stack is empty
//                  DLS_ERROR:    error encountered (stack is NULL)
//
//        note: you are to have only ONE return statement for this
//              entire function. Change the existing one as needed.
//
code_t isempty(Stack *myStack)
{
    //variable declarations and initializations
    code_t result = 0;

    //checking for NULL stack
    if (myStack == NULL)
    {
        result = DLS_ERROR | DLS_NULL;
    }
    else
    {
        //cehcking for empty stack
        if (myStack->top == NULL)
        {
            result = DLS_EMPTY | DLS_SUCCESS;
        }
        else
        {
            result = DLS_OVERFLOW | DLS_SUCCESS;
        }
    }

	return (result);
}
