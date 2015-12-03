#ifndef _DATA_H
#define _DATA_H

//////////////////////////////////////////////////////////////////////
//
// We make use of NULL, so we need stdlib
//
#include <stdlib.h>

//////////////////////////////////////////////////////////////////////
//
// Set up union for node payload (multipurpose use)
//
union info {
    char         value;
    struct node *data;
    void        *other;
};

//////////////////////////////////////////////////////////////////////
//
// node struct helper defines
//
#define  VALUE   payload.value
#define  DATA    payload.data
#define  OTHER   payload.other

//////////////////////////////////////////////////////////////////////
//
// create some peers to NULL for our endeavors: UNDEFINED
//
#if !defined(UNDEFINED)
    #define UNDEFINED ((void*)1)
#endif

//////////////////////////////////////////////////////////////////////
//
// custom types (mostly for shortening typing)
//
typedef struct node            Node;   // because we deserve nice things
typedef struct list            List;   // because we deserve nice things
typedef struct stack           Stack;  // because we deserve nice things
typedef struct queue           Queue;  // because we deserve nice things
typedef struct tree            Tree;   // because we deserve nice things
typedef unsigned long long int code_t; // status code data type
typedef unsigned char          uc;
typedef   signed char          sc;
typedef unsigned long long int ulli;
typedef   signed long long int slli;

//////////////////////////////////////////////////////////////////////
//
// Status codes for the doubly linked node implementation
//
#define  DLN_SUCCESS         0x0000000000000100
#define  DLN_MALLOC_FAIL     0x0000000000000200
#define  DLN_ALREADY_ALLOC   0x0000000000000400
#define  DLN_NULL            0x0000000000000800
#define  DLN_ERROR           0x0000000000001000
#define  DLN_INVALID         0x0000000000002000
#define  DLN_DEFAULT_FAIL    0x0000000000004000
#define  DLN_RESERVED_CODE   0x0000000000008000

//////////////////////////////////////////////////////////////////////
//
// Status codes for the doubly linked list implementation
//
#define  DLL_SUCCESS         0x0000000000010000
#define  DLL_MALLOC_FAIL     0x0000000000020000
#define  DLL_ALREADY_ALLOC   0x0000000000040000
#define  DLL_NULL            0x0000000000080000
#define  DLL_ERROR           0x0000000000100000
#define  DLL_EMPTY           0x0000000000200000
#define  DLL_INVALID         0x0000000000400000
#define  DLL_DEFAULT_FAIL    0x0000000000800000

//////////////////////////////////////////////////////////////////////
//
// Status codes for the doubly linked stack implementation
//
#define  DLS_SUCCESS         0x0000000001000000
#define  DLS_CREATE_FAIL     0x0000000002000000
#define  DLS_NULL            0x0000000004000000
#define  DLS_EMPTY           0x0000000008000000
#define  DLS_OVERFLOW        0x0000000010000000
#define  DLS_UNDERFLOW       0x0000000020000000
#define  DLS_ERROR           0x0000000040000000
#define  DLS_INVALID         0x0000000080000000
#define  DLS_DEFAULT_FAIL    0x0000000000804000

//////////////////////////////////////////////////////////////////////
//
// Status codes for the doubly linked queue implementation
//
#define  DLQ_SUCCESS         0x0000000100000000
#define  DLQ_CREATE_FAIL     0x0000000200000000
#define  DLQ_NULL            0x0000000400000000
#define  DLQ_EMPTY           0x0000000800000000        
#define  DLQ_OVERRUN         0x0000001000000000        
#define  DLQ_UNDERRUN        0x0000002000000000        
#define  DLQ_ERROR           0x0000004000000000
#define  DLQ_INVALID         0x0000008000000000
#define  DLQ_DEFAULT_FAIL    0x0000000000808000       

//////////////////////////////////////////////////////////////////////
//
// Status codes for the doubly linked tree implementation
//
#define  DLT_SUCCESS         0x0000010000000000
#define  DLT_CREATE_FAIL     0x0000020000000000
#define  DLT_NULL            0x0000040000000000
#define  DLT_EMPTY           0x0000080000000000        
#define  DLT_MAX             0x0000100000000000        
#define  DLT_ERROR           0x0000200000000000
#define  DLT_INVALID         0x0000400000000000
#define  DLT_DEFAULT_FAIL    0x0000800000000000       

//////////////////////////////////////////////////////////////////////
//
// Options for list display() and support catlist() functions
//
#define  DISPLAY_FORWARD     000
#define  DISPLAY_NOPOSVALS   000
#define  DISPLAY_NOASCII     000
#define  DISPLAY_SEPS        000
#define  DISPLAY_POSVALS     001
#define  DISPLAY_BACKWARD    002
#define  DISPLAY_ASCII       004
#define  DISPLAY_NOSEPS      010

//////////////////////////////////////////////////////////////////////
//
// Status codes for the doubly-linked list compare() function
//
#define  CMP_EQUALITY        0x00
#define  CMP_L1_NULL         0x01
#define  CMP_L1_EMPTY        0x02
#define  CMP_L1_GREATER      0x04
#define  CMP_L1_LESS         0x08
#define  CMP_L2_NULL         0x10
#define  CMP_L2_EMPTY        0x20
#define  CMP_L2_GREATER      0x40
#define  CMP_L2_LESS         0x80

#endif
