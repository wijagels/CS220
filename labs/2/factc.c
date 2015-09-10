#include <quadmath.h>
#include <stdio.h>
#include <stdlib.h>
#include <float.h>
#include <math.h>

__float128 factorial(__float128 n);

int main() {
    printf("%d\n", LDBL_DIG);

    int n;
	__float128 fn;

	for(fn=n=1; fn>0 && fn != INFINITY && fn < pow(10, 31); n++) {
        fn=factorial(n);
        printf("factorial(%d)=%.32Qe\n",n,(long double)fn);

        /*int width = 46;
        char buf[128];
        int n = quadmath_snprintf (buf, sizeof buf, "%+-#*.20Qe", width, fn);
        printf ("%s\n", buf);*/
    }
    return(0);

}

__float128 factorial(__float128 n) {
    if(n == 1) {
        return 1;
    }
    return n * factorial(n-1);
}
