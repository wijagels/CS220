#include <stdio.h>
#include <stdlib.h>


int main(int argc, char *argv[])
{

    int *mynumbers=(int *)malloc(sizeof(int)*10);
    int sum=0;
    int i;

    for(i=0;i<10;i++) mynumbers[i]=i; // Initialize dynamic array


    for (i=0; i<10; i++) {
        sum=sum + mynumbers[i];
        mynumbers[i]=0;
    }

    printf("The sum of the first ten numbers is %d\n",sum);

    free(mynumbers);
    return 0;

}

