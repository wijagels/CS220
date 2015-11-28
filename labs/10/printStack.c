#include <stdio.h>
#include "printStack.h"

void printFrameStack(stackptr sp,baseptr bp,int nparms) {
	do {
		printStackFrame(sp,bp,nparms);
		if (bp==main_base) break;
		sp=(void *)bp-4;
		bp=bp->prev_nframe;
	} while(1);
}


void printStackFrame(stackptr sp,baseptr bp,int nparms) {
	int i;
	printf("  Frame @ esp=%08x -> ebp=%08x\n",sp,bp);
	printf("    Previous frame @ %08x\n", bp->prev_nframe);
	printf("    Return address @ %08x\n", bp->return_addr);
	if (nparms>0) {
		printf("    Parameters:\n");
		for(i=0; i < nparms; i++) {
			printf("    	Parm %3d   = %08x\n",i,bp->parms[i]);
		}
	}
	printf("    Stack Frame Contents:\n");
	int stackSize=(((void *)bp-(void *)sp)/4)-1;
	for(i=stackSize; i>=0; i--) {
		printf("    	0x%02x(esp) = -0x%02x(ebp) -> %08x = %12d\n",
			i*sizeof(void *),(stackSize-i)*sizeof(void *),*(sp+i),*(sp+i));
	}
	printf("\n");
}
