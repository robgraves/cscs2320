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
typedef unsigned long long int code_t; // status code data type
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

#endif
