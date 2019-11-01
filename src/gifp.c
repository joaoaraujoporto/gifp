#include "stdio.h"
#include "stdlib.h"
#include "util.h"

void xorSwap (int* x, int* y) {
    if (x != y) { //ensure that memory locations are different
       *x ^= *y;
       *y ^= *x;
       *x ^= *y;
    }
}

int main(int argc, char **argv) {
    // if (argc != 3) return 0;

    // int n = atoi(argv[1]);
    // int k = atoi(argv[2]);

    // printf("%i\n", is_prime(n, k));

    printf("ul_int = %ld\n", sizeof(ul_int));
    printf("int = %ld\n", sizeof(int));
    printf("double = %ld\n", sizeof(double));
    printf("double = %ld\n", sizeof(long double));
    // printf("double = %ld\n", 9000000000000000000);

    int x, y;
    x = 3; y = 4;
    xorSwap(&x,&y);
    printf("x = %d and y = %d", x, y);
}