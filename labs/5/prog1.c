#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {

	int i=1;
	while (i < argc) {
		printf("Argument %d is : %s\n",i, argv[i]);
        i++;
	}

	int p1=atoi(argv[1]);
	if (p1>100) printf("First argument is really big\n");
	else if (p1 > 10) printf("First argument is big\n");
	else if (p1<0) printf("First argument is negative\n");
	else if (p1==0) printf("First argument is zero\n");
	else printf("First argument is boring\n");

	return 0;
}
