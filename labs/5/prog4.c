#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {

	char testval[1024]="This is a test... this is only a test... for the next sixty seconds this will be a test of the emergency broadcasting system.";

	if (argc < 2) {
		printf("Expected at least one argument... letter to change\n");
		return 1;
	}

	char from=argv[1][0];
	char to=argv[1][1];

	int i=0;
	while(testval[i]!=0) {
		if (testval[i]==from)
			testval[i++]=to;
		else i++;
	}
	printf("Testval is now: %s\n",testval);
	return 0;
}
