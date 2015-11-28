#include <stdio.h>
#include <stdlib.h>


int main(int argc, char *argv[])
{

   int mynumbers[11]={0,1,2,3,4,5,6,7,8,9};
   int sum=0;
   int i;
   
   for (i=0; i<=10; i++) {
   	sum=sum + mynumbers[i];
   	mynumbers[i]=0;
	}
	
	printf("The sum of the first ten numbers is %d\n",sum);
	return 0; 
   
}


