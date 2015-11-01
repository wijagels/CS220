void func(int a, int b) {
    int c;
    switch(a) {
        case 9:
            b = a;
            break;
        case 10:
            b = a + 2;
            break;
        case 11:
            b = a + 3;
            break;
        case 12:
            b = a + 5;
            break;
        case 13:
            b = a + 7;
            break;
        case 14:
            b = a + 11;
            break;
        default:
            b = c;
    }
}

int myfunc(int a,int b) {
    int c;
    switch(a) {
        case 10 : c=a; break;
        case 11: b++;
        case 12:
        case 13: c=a+b; break;
        case 14: c=a*b; break;
        case 15: c=a+2; break;
        default: c=0;
    }
    return c;
}
