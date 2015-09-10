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

int ipow(int base, int exp)
{
    int result = 1;
    while (exp)
    {
        if (exp & 1)
            result *= base;
        exp >>= 1;
        base *= base;
    }

    return result;
}

char * b64encode(char string[],int len) {
    char bin[len*8];
    /* Your code to convert the input array of chars to a base64 string goes here */
    for(int k=0;k < len;++k) {
        printf("%d\n", string[k]);
        for (int i = 0; i < 8; ++i) {
            bin[k*8 + i] = !!((string[k] << i) & 0x80);
        }
    }
    int sum = 0;
    for(int j=0;j < len*8;++j) {
        sum += ipow(2, bin[j] * 6- j%6);
        if(j%6) sum = 0;
        printf("\n%d", sum);
    }
    printf("\n");
	b64Result[0]=0; // Make sure result is null terminated
	return b64Result;
}


