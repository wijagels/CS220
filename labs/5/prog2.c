#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {

	if (argc<3) {
		printf("Not enough arguments... need 2, only found %d\n",argc-1);
		return 1;
	}

	char inc=atoi(argv[1]);
	short int max=atoi(argv[2]);
	int i=0;
	while (i<max) {
		printf("Next value of i is %d\n",i);
		i = i + inc;
	}
	return 0;
}
