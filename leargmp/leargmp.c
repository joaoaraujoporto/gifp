#include "stdio.h"
#include "stdarg.h"
#include "gmp.h"

typedef mpz_t integer;



#define init_i __gmpz_init
#define inits_i __gmpz_inits
#define add_i __gmpz_add
#define clear_i __gmpz_clear
#define clears_i __gmpz_clears
#define set_i __gmpz_set_ui

// void init_i(mpz_t x) { mpz_init(x); }
// void clear_i(mpz_t x) { mpz_clear(x); }
// void add_i(mpz_t rop, const mpz_t op1, const mpz_t op2) { mpz_add(rop, op1, op2); }

int main() {
    integer n, m, sum;
    inits_i(n, m, sum, NULL);

    set_i(n, 1);
    set_i(m, 1);\
    add_i(sum, n, m);

    printf("hello\n");

    clears_i(n, m, sum, NULL);
}