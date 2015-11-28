#include <stdio.h>
#include <stdlib.h>

typedef struct node_struct * node;

struct node_struct {
	int value;
	node next;
} ;

node makeNode(int val);
void deleteNode(node this);
void addNode(node root,node this);
void printList(node root);
void deleteList(node root);


int main(int argc, char *argv[])
{

	setbuf(stdout,0);
	int i;
	node root=makeNode(0);
	for (i=1; i<10; i++) {
		addNode(root,makeNode(i));
	}
	
	printList(root);
	deleteList(root);
	 
	return 0; 
   
}

node makeNode(int val) {
	node result;
	result=(node)malloc(sizeof(struct node_struct));
	result->value=val;
	result->next=NULL;
	return result;
}

void deleteNode(node this) {
	free(this);
}

void addNode(node root,node this) {
	node tail=root;
	while(tail->next != NULL) tail=tail->next;
	tail->next=this;
}

void printList(node root) {
	while (root != NULL) {
		printf(" %d ",root->value);
		if (root->next) printf("->");
		root=root->next;
	}
	printf("\n");
}

void deleteList(node root) {
	if (root->next) deleteList(root->next);
	deleteNode(root);
}
