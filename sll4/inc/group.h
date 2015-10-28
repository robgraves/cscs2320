#ifndef _GROUP_H
#define _GROUP_H

#include "list.h"                        // list relies on node to work

struct groupoflists {
    List *first;                         // pointer to first list
    List *last;                          // pointer to last list
};
typedef struct groupoflists Group;       // because we deserve nice things

Group *mkgroup(void);                    // create/allocate new Group
Group *rmgroup(Group *);                 // clear/deallocate Group

Group *linsert(Group *, List *, List *); // add list before given list
Group *lappend(Group *, List *, List *); // add list after given list
Group *lobtain(Group *, List **);        // obtain/disconnect list from group

long int  ldisplay(Group *, long int);   // display entire/aspects of list group

long int  lgetpos(Group *, List *);      // retrieve position from given node
List     *lsetpos(Group *, long int);    // seek to indicated node in list

#endif
