#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main(int argc, const char* argv[]) {
    int x; int y; int s_sum;
    unsigned int v; unsigned int w; unsigned int u_sum;
    printf("%d\n", INT_MAX);
    x=atoi(argv[1]);
    y=atoi(argv[2]);
    v=x;
    w=y;
    s_sum=x*y;
    u_sum=v*w;
    printf("%d %d\n%d %d\n%d %d\n", x, y, v, w, s_sum, u_sum);
    if (s_sum==u_sum) {
        printf("Unsigned and signed are the same\n");
    }
    else {
        printf("Different!!!\n");
    }
    return 0;
}
