#ifndef _SUPPORT_H
#define _SUPPORT_H

//////////////////////////////////////////////////////////////////////
//
// Function prototypes for project support routines
//
void lscodes(code_t);
#ifdef _LIST_H
void echolst(List *, int);
void listcat(List *);
void listncat(List *);
void listntac(List *);
void listtac(List *);
void catnode(List **, Node *, Node *);
void tacnode(List **, Node *, Node *);
void echolst(List *, int);
#endif

#endif
