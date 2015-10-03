#include <stdio.h>
int main() {
    int x = 1000000001;
    float fx=x;
    if (x==fx) printf("x and fx are the same");
    else printf("x and fx are different");

    float frac=5.56;
    float base=20.0;
    int percent=100*frac/base+0.5;
    printf("\n%d", percent);
    printf("\n%d", func("string 1", "string"));
}

int func(char a[],char b[]) {
    while((*a)) if ((*a++)!=(*b++)) return 0;
    if ((*b)) return 0;
    return 1;
}
