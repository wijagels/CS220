#include "tree.h"
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

tree makeNode(int value) {
   tree t = malloc(sizeof(struct tnode));
   t->value=value;
   t->left=NULL;
   t->right=NULL;
   return t;
}

void freeTree(tree t) {
   assert(t);
   if (t->left) freeTree(t->left);
   if (t->right) freeTree(t->right);
   free(t);
}

tree getLeft(tree t) { assert(t); return t->left; }
tree getRight(tree t) { assert(t); return t->right; }
int getVal(tree t) { assert(t); return t->value; }
void setLeft(tree t, tree l) { assert(t); t->left=l; }
void setRight(tree t, tree r) { assert(t); t->right=r; }