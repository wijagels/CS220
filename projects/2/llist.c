#include "lnode.h"
#include <stdio.h>
#include <ctype.h>

int normalize(char *w);
int isGreater(char * s1, char *s2);
lnode insertWord(char * word, lnode head);

int main(int argc, char **argv) {

	lnode head=NULL;
	char word[1024];
	while(!feof(stdin)) {
		if (scanf("%s",word)) { // If we can read another white space terminated string
			if (normalize(word)) { // And if that string is non-empty after normalization...
				// printf ("Read word %s\n",word);
				head=insertWord(word,head);
			}
		}
	}

	lnode node;
	int i=1;
	for(node=head; node; node=getNextLnode(node)) {
		printf("%3d. - %3d - %s\n",i++,getLnodeCount(node),getLnodeValue(node));
	}

	lnode next;
	for(node=head; node; node=next) {
			next=getNextLnode(node);
			deleteLnode(node);
	}
	return 0;
}

int normalize(char *r) {
	int ret=0;
	char *w=r;
	while(*r) {
		if (!isalpha((int)*r)) { r++; continue; }
		(*w++)=tolower((int)*r++);
		ret=1;
	}
	(*w)=0;
	return ret;
}

/**
 * How to make this not so inefficient:
 * LinkedLists aren't the best data structure
 * for this, a tree would allow log(n) insertions.
 * Or, with a simple array, binary searches could
 * be used to also acheive log(n) insertion.
 * Using a linked list locks you in to O(n), but
 * some level of caching may improve real world
 * performance.  For example, knowing the size of the
 * list and storing pointers to midpoints would
 * improve performance at the expense of memory.
 * When using this on very large real world text,
 * it would be useful to store pointers to the most
 * popular words (the, and, a, etc.) because access
 * to these words in constant time would significantly
 * improve performance in a text with enough unique
 * words.  Even with all this magic, a tree will
 * outperform the linkedlist.
 */
lnode insertWord(char * word, lnode head) {
	/* Your code to insert a word in the linked list goes here */
    if(!head) return makeLnode(word);
    lnode node = head;
    lnode prev = node;
    if(isGreater(word, node->value) == -1) {
        head = makeLnode(word);
        head->next = node;
        return head;
    }
    while(node) {
        if(isGreater(word, node->value) == -1) {
            prev->next = makeLnode(word);
            prev->next->next = node;
            return head;
        }
        if(isGreater(word, node->value) == 0) {
            node->count++;
            return head;
        }
        if(isGreater(word, node->value) == 1) {
            prev = node;
            node = node->next;
        }
    }
    prev->next = makeLnode(word);
    return head;
}

int isGreater(char *s1,char *s2) {
	while(*s1) {
		if ((*s1)>(*s2)) return 1;
		if ((*s1)<(*s2)) return -1;
		s1++; s2++;
	}
	if ((*s2)==0) return 0;
	return -1;
}
