#include <stdio.h>
#include <ctype.h>
#include <assert.h>
#define MAX_MSG_LENGTH 4096

int listWords(char *in,char * words[]);
int uniqueWords(char *inWords[],int nin,char * unqWords[],int unqCount[]);
int maxCount(int unqCounts[],int nunq);
void printWordsUsed(int used,int nunq,char * unqWords[], int unqCounts[]);
int compareWords(char *w1,char *w2);

int main(int argc, char **argv) {

    char inputMsg[MAX_MSG_LENGTH] = "";
    int stri=0;
    char * words[MAX_MSG_LENGTH];
    char * unqWords[MAX_MSG_LENGTH];
    int unqCount[MAX_MSG_LENGTH];
    char in;
    while(1) {
        in=getchar();
        if (feof(stdin)) break;
        inputMsg[stri++]=in;
    }
    inputMsg[stri]=0;
    assert(stri<MAX_MSG_LENGTH);

    int nwords=listWords(inputMsg,words);
    int nunq=uniqueWords(words,nwords,unqWords,unqCount);
    printf("Found a total of %d words %d unique in the input string\n",
            nwords,nunq);

    // int max=maxCount(unqCount,nunq);
    // printf("At least one word is used %d times\n",max);
    //	int i;
    //	for(i=max; i>2; i--) {
    //		printWordsUsed(i,nunq,unqWords,unqCount);
    //}

    return 0;
}

int listWords(char *in,char * words[]) {

    int w=0;
    char * ip=in;
    int newWord=1;
    while((*ip)!=0) {
        (*ip)=tolower(*ip);
        if ((*ip)=='\'') {ip++; continue; }
        if (isalpha(*ip)) {
            if (newWord) {
                newWord=0;
                words[w++]=ip;
            }
        } else { /* Not alphabetic... ignore */
            if (!newWord) {
                (*ip)=0; /* Put a null terminator on the previous word */
                newWord=1; /* Look for a new word */
            }
        }
        ip++;
    }
    return w;
}

int uniqueWords(char *inWords[],int nin,char * unqWords[],int unqCount[]) {
    int unq=0; // Count of the number of unique words
    /* Your code to identify unique words and counts goes here */
    for(int i=0;i < MAX_MSG_LENGTH;i++) {
    }
    return unq;
}

int maxCount(int unqCounts[],int nunq) {
    int max=0;
    /* Your code to identify the largest count goes here */
    return max;
}

void printWordsUsed(int used,int nunq,char * unqWords[], int unqCounts[]) {
    int i;
    for(i=0;i<nunq; i++) {
        if (unqCounts[i]==used) {
            printf("  %d - %s\n",used,unqWords[i]);
        }
    }
}

int compareWords(char *w1,char *w2) {
    while(w1!=NULL) {
        if (w1!=w2) return 0;
        *w1++;
        *w2++;
    }
    if (w2==NULL) return 1;
    return 0;
}
