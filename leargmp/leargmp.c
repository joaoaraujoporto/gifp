#include "stdio.h"
#include "stdarg.h"
#include "gmp.h"

#define integer mpz_t
#define init_i __gmpz_init
#define inits_i __gmpz_inits
#define sum_i mpz_add
#define clear_i __gmpz_clear
#define clears_i __gmpz_clears
#define set_i __gmpz_set_ui
#define set_s __gmpz_set_str
#define init_set_i __gmpz_init_set_ui

// void init_i(mpz_t x) { mpz_init(x); }
// void clear_i(mpz_t x) { mpz_clear(x); }
// void add_i(mpz_t rop, const mpz_t op1, const mpz_t op2) { mpz_add(rop, op1, op2); }

int main() {
    integer n, m, sum;
    inits_i(n, m, sum, NULL);

    set_i(n, 1);
    mpz_set_str(m, "900000000000000000000000000000000000000000000000000000000000000000", 0);
    sum_i(sum, n, m);

    gmp_printf("n + m = %Zd\n", sum);

    clears_i(n, m, sum, NULL);
}