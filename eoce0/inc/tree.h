#ifndef _TREE_H
#define _TREE_H

#include "data.h"
#include "list.h"

#define  INORDER       0
#define  PREORDER      1
#define  POSTORDER     2

struct tree {
    Node *root;                         // pointer to root node of tree
    uc    max_height;                   // max height of tree (0 = unlimited)
};

code_t mktree    (Tree **, uc        ); // create new tree
code_t cptree_r  (Tree  *, Tree **   ); // copy given tree (recursive)
code_t rmtree    (Tree **            ); // purge and deallocate tree

code_t addnode   (Tree **, Node *    ); // add given node to tree
code_t grabnode_r(Tree **, Node **   ); // get node from tree (recursive)
code_t traverse_i(Tree  *, List **,uc); // traverse tree by mode (iterative)
code_t traverse_r(Tree  *, List **,uc); // traverse tree by mode (recursive)
code_t traverse_s(Tree  *, List **,uc); // traverse tree by mode (stacks)

code_t searchtree(Tree  *, Node **,sc); // find node in tree (by value)

#endif
