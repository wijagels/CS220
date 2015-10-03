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


unsigned char b64ToValue(char c) {
    if(c == '=')
        return 0;
    for(int i=0;i<64;i++) {
        if(base64[i] == c)
            return i;
    }
    return -1;
}

char * b64decode(char b64[],int len) {

	/* Your code to convert base 64 to an array of chars goes here */
    for(int k=0;k<len;k++) {
        b64[k] = b64ToValue(b64[k]);
    }
    unsigned char trip[3];
    for(int i=0;i<len;i+=4) {
        trip[0] = b64[i+0] << 2 | b64[i+1] >> 4;
        if(trip[1] <= 0) continue;
        trip[1] = b64[i+1] << 4 | b64[i+2] >> 2;
        if(trip[2] <= 0) continue;
        trip[2] = b64[i+2] << 6 | b64[i+3];
        // printf("%d ", trip[0]);
        // printf("%d ", trip[1]);
        // printf("%d ", trip[2]);
        for(int k=0;k<3;k++)
            stringResult[i*3/4+k] = trip[k];
    }

	return stringResult;
}
