#include "base64.h"
#include <stdio.h>
#include <assert.h>
#define debug 0

char * b64encode(char string[],int len);
static char b64Result[MAX_MSG_LENGTH];
void printbincharpad(char c);


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

int toPower(int b, int e) {
    int s = 1;
    for(int i = 0;i < e;i++) {
        s *= b;
    }
    return s;
}

char * b64encode(char string[],int len) {
    /* Your code to convert the input array of chars to a base64 string goes here */
    unsigned char quad[4];
    int pads = 0;
    while(len % 3 != 0) {
        len++;
        pads++;
    }
    for(int i=0;i<len;i+=3) {
        // printf("%c", string[i]);
        // printbincharpad(string[i] << 4);
        // printf("%c", string[i+1]);
        // printbincharpad(string[i+1] >> 4);
        quad[0] = string[i] >> 2;
        quad[1] = ((string[i] << 4) | string[i+1] >> 4) & 0x3F;
        quad[2] = ((string[i+1] << 2) | string[i+2] >> 6) & 0x3F;
        quad[3] = string[i+2] & 0x3F;
        if(debug) printf("%c, %c, %c\n", string[i], string[i+1], string[i+2]);
        if(debug) printf("%d, %d, %d, %d\n", quad[0], quad[1], quad[2], quad[3]);
        if(debug) printf("%c, %c, %c, %c\n", base64[quad[0]], base64[quad[1]], base64[quad[2]], base64[quad[3]]);
        for(int j=0;j<4;j++) {
            // if(quad[j] == 0)
            //     b64Result[i*4/3+j] = base64Pad;
            b64Result[i*4/3+j] = base64[quad[j]];
        }
        for(int p=0;p <= pads;p++) {
            b64Result[len*4/3-p] = '=';
        }
    }
    return b64Result;
}
