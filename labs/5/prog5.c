#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {

	char testval[1024]="This is a test... this is only a test... for the next sixty seconds this will be a test of the emergency broadcasting system.";

	int inWord=0;
	int wordCount=0;
	int i=0;

	while(testval[i] != 0) {
		if (testval[i]==' ') {
			if (inWord) inWord=0;
		} else {
			if (!inWord) {
				inWord=1;
				wordCount++;
            }
		}
		i++;
	}

	printf("The number of words in testval is %d\n",wordCount);
	return 0;
}
