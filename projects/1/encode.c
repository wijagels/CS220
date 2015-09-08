#include "base64.h"
#include <stdio.h>
#include <assert.h>

char * b64encode(char string[],int len);
static char b64Result[MAX_MSG_LENGTH];

int main(int argc, char **argv) {
	char inputMsg[MAX_MSG_LENGTH] = "";
	int stri=0;
	char in;
	while(1) {
		in=getchar();
		if (feof(stdin)) break;
		inputMsg[stri++]=in;
	}
	inputMsg[stri]=0;
	assert(stri<MAX_MSG_LENGTH);

	char * result=b64encode(inputMsg,stri);
	int b64i=0;
	for(b64i=0; result[b64i]; b64i++) {
		putchar(result[b64i]);
	}
	return 0;
}

char * b64encode(char string[],int len) {

    /* Your code to convert the input array of chars to a base64 string goes here */
    for(int k=0;k < len;++k) {
        for (int i = 0; i < 8; i++) {
            printf("%d", !!((string[k] << i) & 0x80));
        }
    }
	b64Result[0]=0; // Make sure result is null terminated
	return b64Result;
}
