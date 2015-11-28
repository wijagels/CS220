#include <stdio.h>
#include <stdlib.h>
#include "printStack.h"

int factorial(int);

int main(int argc, char *argv[])
{
    SAVE_BASE_POINTER;


    printf("Factorial 6=%d\n",factorial(6));


    exit(0);
}

int factorial(int n) {
    int answer = 0x00beef00;
    printStack(1);
    if (n<3) answer=n;
    else answer=(factorial(n-1) * n);
    return answer;
}
