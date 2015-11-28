#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv) {
	char buffer[1024];
	char result[1026]="";

	while(fgets(buffer,sizeof(buffer),stdin)) {
		buffer[strlen(buffer)-1]=0x00; // chomp newline
		union {
			void *ptr;
			char pc[5];
		} pval;
		switch(buffer[0]) {
			case 'C' :
				strcat(result,buffer+2);
				break;

			case '@' :
				if (1==sscanf(buffer+2,"%p",&pval.ptr)) {
					pval.pc[4]=0x00;
					strcat(result,pval.pc);
				}
				break;
			default:
				fprintf(stderr,"Unrecognized: %s\n",buffer);
		}
	}
	printf("%s\n",result);
	return 0;
}

