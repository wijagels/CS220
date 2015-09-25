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

int toPower(int b, int e) {
    int s = 1;
    for(int i = 0;i < e;i++) {
        s *= b;
    }
    return s;
}

char * b64encode(char string[],int len) {
    char bin[len*8];
    /* Your code to convert the input array of chars to a base64 string goes here */
    for(int k=0;k < len;++k) {
        for (int i = 0; i < 8; ++i) {
            bin[k*8 + i] = !!((string[k] << i) & 0x80);
            // printf("%d", bin[k*8 + i]);
        }
    }

    // for(int i =0;i<=6;i++) {
    //     printf("%d : %d : %d\t", bin[i], 6- i%6, bin[i]*toPower(2, (6- i%6)));
    // }

    int sum = 0;
    int j = 0;
    for(;j < len*8;++j) {
        // printf("j%%6 = %d, %d += %d", j%6, sum, bin[j]*toPower(2, (5- j%6)));
        sum +=  bin[j]*toPower(2, (5- j%6));
        printf("%d", bin[j]);
        if(j > 0 && j%6 == 0) {
            b64Result[j/6 - 1] = base64[sum];
            printf(" %d\t", sum);
            sum = 0;
        }
    }
    printf("\n");
    b64Result[j+1]=0; // Make sure result is null terminated
    return b64Result;
}


