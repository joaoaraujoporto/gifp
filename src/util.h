#ifndef __util_h__
#define __util_h__

#include "stdio.h"
#include "math.h"
#include "gmp.h"

#define init_i __gmpz_init
#define inits_i __gmpz_inits
#define sum_i __gmpz_add
#define clear_i __gmpz_clear
#define clears_i __gmpz_clears
#define set_i __gmpz_set
#define set_i_ui __gmpz_set_ui
#define set_i_s __gmpz_set_str
#define init_set_i __gmpz_init_set_ui
#define cmp_i __gmpz_cmp
#define cmp_r __gmpf_cmp
#define init_r __gmpf_init
#define inits_r __gmpf_inits
#define set_r __gmpf_set
#define set_r_d __gmpf_set_d
#define set_r_s __gmpf_set_str
#define clear_r __gmpf_clear
#define clears_r __gmpf_clears

typedef enum {
    false,
    true
} bool;

typedef mpz_t integer;
typedef mpf_t real;
typedef unsigned long int ul_int;
typedef unsigned int u_int;

bool assert_equal(ul_int expected, ul_int actual);
bool assert_equal_bool(bool expected, bool actual);
bool assert_equal_double(double expected, double actual, int places_precision);

int ndigits(int number);

bool assert_equal(ul_int expected, ul_int actual) {
    if (expected == actual) {
        printf("passed\n");
        return true;
    }
    
    printf("Expected %ld, but actual %ld\n", expected, actual);
    return false;
}

bool assert_equal_integer(integer expected, integer actual) {
    if (!cmp_i(expected, actual)) {
        printf("passed\n");
        return true;
    }

    gmp_printf("Expected %Zd, but actual %Zd\n", expected, actual);
    return false;
}

bool assert_equal_bool(bool expected, bool actual) {
    if (expected == actual) {
        printf("passed\n");
        return true;
    }

    if (expected == true) printf("Expected true, but actual false\n");
    else printf("Expected false, but actual true\n");

    return false;
}

/**
 * @param places_precision until 6 places
 **/
bool assert_equal_double(double expected, double actual, int places_precision) {
    double precision = 1;

    if (places_precision > 0)
        precision /= pow(10, places_precision);

    if (fabs(expected-actual) < precision) {
        printf("passed\n");
        return true;
    }

    printf("Expected %f, but actual %f\n", expected, actual);
    return false;
}

/**
 * @param places_precision until 6 places
 **/
bool assert_equal_real(real expected, real actual) {
    if (!cmp_r(expected, actual)) {
        printf("passed\n");
        return true;
    }

    gmp_printf("Expected %Ff, but actual %Ff\n", expected, actual);
    return false;
}

/**
 * Count the number of digits of a number
 * @param n is the number for count (n must b natural)
 * @return the number of digits that compose n
 */
u_int cdigits(ul_int n) {
    u_int c = 1;
    for (; n/10 != 0; c++) n /= 10; 
    return c;
}

ul_int expi(int x, int y) {
    if (y == 0) return 1;
    return x * expi(x, y-1);
}

ul_int get_upper(u_int n_bits) {
    // return pow(2, n_bits) - 1;
    return expi(2, n_bits) - 1;
}

void get_range(u_int n_bits, ul_int *b, ul_int *e) {
    *b = get_upper(n_bits-1) + 1;
    if (n_bits == 1) *b -= 1;
    *e = get_upper(n_bits);
}

bool contains(ul_int e, ul_int l[], ul_int size_l) {
    int i;

    for (i = 0; i < size_l; i++)
        if (e == l[i])
            return true;

    return false;
}

#endif