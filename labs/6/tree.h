#ifndef TREE_H
#define TREE_H

typedef struct tnode * tree;

struct tnode {
   tree left;
   tree right;
   int value;
};

tree makeNode(int value);
void freeTree(tree t);

tree getLeft(tree t);
tree getRight(tree t);
int getVal(tree t);
void setLeft(tree t, tree l);
void setRight(tree t, tree r);


#endif
