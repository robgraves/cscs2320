#include <stdio.h>
#include "group.h"

//////////////////////////////////////////////////////////////////////
//
// ldisplay() - display the list group in an organized fashion (list
//              by list) or to display an isolated list from the group
//              of lists (as indicated by the pos parameter).
//
//    behavior: on a NULL group, output "<NULL>", return -1
//              on an EMPTY group, output "<EMPTY>", return 0
//              on an error state, output "<ERROR>", return -2
//
//              pos serves a dual purpose:
//                  -1: displays all lists in the list group
//                   0-n: displays that particular list in the group
//
//      output: (if pos is a -1):
//              <0>: 2 -> 4 -> 8 -> NULL
//              <1>: 3 -> 6 -> NULL
//              <2>: -> NULL
//              <3>: 12 -> 36 -> 96 -> 112 -> 119 -> NULL
//
//              (if pos is a 1):
//              <1>: 3 -> 6 -> NULL
//
//return value: the number of lists displayed
//
//        note: ALL output ends with a newline character
//
long int ldisplay(Group *myListGroup, long int pos)
{
	// your implementation here (please remove this comment when done)
}
