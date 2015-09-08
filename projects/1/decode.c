#include "base64.h"
#include <stdio.h>
#include <assert.h>

char * b64decode(char b64[],int len);
static char stringResult[MAX_MSG_LENGTH];

int main(int argc, char **argv) {
	char inputMsg[MAX_MSG_LENGTH] = "";
	int b64i=0;
	char in;
	while(1) {
		in=getchar();
		if (feof(stdin)) break;
		inputMsg[b64i++]=in;
	}
	assert(b64i<MAX_MSG_LENGTH);

	char * result=b64decode(inputMsg,b64i);
	int stri=0;
	for(stri=0; result[stri]; stri++) {
		putchar(result[stri]);
	}
	return 0;
}

char * b64decode(char b64[],int len) {

	/* Your code to convert base 64 to an array of chars goes here */

	stringResult[0]=0; // Make sure result is null terminated
	return stringResult;
}