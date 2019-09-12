#ifndef __util_h__
#define __util_h__

#include "stdio.h"
#include "math.h"

typedef enum {
    false,
    true
} bool;

typedef unsigned long int ul_int;
typedef unsigned int u_int;

bool assert_equal(int expected, int actual);
bool assert_equal_bool(bool expected, bool actual);
bool assert_equal_double(double expected, double actual, int places_precision);

int ndigits(int number);

bool assert_equal(int expected, int actual) {
    if (expected == actual) {
        printf("passed\n");
        return true;
    }

    printf("Expected %d, but actual %d\n", expected, actual);
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

#endif