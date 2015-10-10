#include "tree.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

void insertVal(tree t, int value);
void prPrefix(tree t);
void prInfix(tree t);
void prPostfix(tree t);
void printTree(tree t, char * prefix);

int main(int argc, char **argv) {
   int i;

   if (argc<2) {
        printf("You must specify at least one argument to %s\n",argv[0]);
        return 1;
    }
    tree r=makeNode(atoi(argv[1]));
   for(i=2; i<argc; i++) {
      int val=atoi(argv[i]);
      insertVal(r,val);
   }
   printf("In prefix order...\n");
   prPrefix(r);
   printf("\nIn inFix order...\n");
   prInfix(r);
   printf("\nIn postFix order...\n");
   prPostfix(r);
   printf("\nGraphic Representation\n");
   printTree(r,"");
   freeTree(r);

   return 0;
}

void insertVal(tree t, int value) {
    /* Write code to insert value into tree t here */
    if(value >= getVal(t)) {
        if(getRight(t) != NULL) {
            insertVal(getRight(t), value);
        }
        else
            setRight(t, makeNode(value));
    }
    else {
        if(getLeft(t) != NULL) {
            insertVal(getLeft(t), value);
        }
        else
            setLeft(t, makeNode(value));
    }
}

void prPrefix(tree t) {
    /* Write code to:
       - prPrefix the left sub-tree,
       - print the value of the node,
       - prPrefix the right sub-tree
    */
    if(t != NULL) {
        prPrefix(getLeft(t));
        printf("%d ", getVal(t));
        prPrefix(getRight(t));
    }
}

void prInfix(tree t) {
    /* Write code to:
        - print the value of the node,
        - prInfix the left sub-tree,
        - prInfix the right sub-tree
   */
    if(t != NULL) {
        printf("%d ", getVal(t));
        prInfix(getLeft(t));
        prInfix(getRight(t));
    }
}

void prPostfix(tree t) {
   /* Write code to:
    - prPostfix the right sub-tree,
    - print the value of the node,
    - prPostfix the left sub-tree
   */
    if(t != NULL) {
        prInfix(getRight(t));
        printf("%d ", getVal(t));
        prInfix(getLeft(t));
    }
}

void printTree(tree t, char * prefix) {
    /* Write code to print a tree graphically */
}

