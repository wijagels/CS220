#include <stdlib.h>
#include <stdio.h>
#include <math.h>

float root(float n,float tol);
float howClose(float n, float root);

int main(int argc, char **argv) {

    if (argc != 3) {
        printf("Invoke %s <n> <e> where <n> is the number to find the square root of, and <e> is the tolerance.\n",argv[0]);
        return 1;
    }

    float n=atof(argv[1]);
    float err=atof(argv[2]);

    if (n<=0) {
        printf("Invoke %s <n> where <n> is a positive floating point number - you entered %s\n",argv[0],argv[1]);
        return 1;
    }

    float rn=root(n,err);
    printf("The square root of %f is %f\n",n,rn);
    return 0;
}

float root(float n,float tol) {

    int iter=0;
    float root=n/2;
    float error=howClose(n,root);

    float y = 1;
    float prev_root = -1;

    while(error > tol) {

        iter++;

        /* Calculate a new value for root here */
        root = (root + y)/2;
        y = n/root;
        if(prev_root == root) break;
        prev_root = root;

        error=howClose(n,root);
        printf("  After %d iterations, root=%f error=%f\n",iter,root,error);
    }
    return root;
}

float howClose(float n, float root) {

    return fabs(n-root*root); /* fabs is floating point absolute value... fabs(3.6) = 3.6; fabs(-2.5) = 2.5 */

}
