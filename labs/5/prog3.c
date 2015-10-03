#include <stdio.h>
#include <stdlib.h>
#define MAX_STR_LEN 100

int main(int argc, char **argv) {

	char *testval="This is a test, this is only a test.  For the next sixty seconds, this will be a test of the emergency broadcasting system.";

	if (argc<2) {
		printf("Expected at least one argument.\n");
		return 1;
	}

	int inc=atoi(argv[1]);

	if (inc <=0) {
		printf("Expected first argument to be a positive number.\n");
		return 1;
	}

	int max=MAX_STR_LEN;
	if (argc==3) {
		max=atoi(argv[2]);
		if (max<0) max=MAX_STR_LEN;
	}

	int i=0;

    // while(i<max) {
    //     string[i]=testval[i];
    //     i++;
    // }
    // return 0;
    // string[i]=0;

    i=0;
    while(testval[i]!=0) {
        printf("The %d char is %c\n",i,testval[i]);
        i = i + inc;
        if(i >= max)
            return 0;
    }

	return 0;
}
