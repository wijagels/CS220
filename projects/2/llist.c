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

lnode insertWord(char * word, lnode head) {
	/* Your code to insert a word in the linked list goes here */
    if(!head) {
        return makeLnode(word);
    }
    lnode headcp, prev;
    headcp = head;
    prev = head;
    while(head->next) {
        short comp = isGreater(word, head->value);
        if(comp == -1) {
            printf("%s is smaller than %s\n", word, head->value);
            prev->next = makeLnode(word);
            prev->next->next = head;
            return headcp;
        }
        if(comp == 0) {
            head->count++;
            return headcp;
        }
        if(comp == 1) {
            printf("%s is greater than %s\n", word, head->value);
            prev = head;
            head = head->next;
        }
    }
head->next = makeLnode(word);
return headcp;
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
