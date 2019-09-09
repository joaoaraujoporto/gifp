#ifndef __util_h__
#define __util_h__

#include "stdio.h"
#include "math.h"
#include "stdlib.h"

typedef enum {
    false,
    true
} bool;

bool assert_equal(int expected, int actual);

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

    if (expected == true)
        printf("Expected true, but actual false\n");
    else
        printf("Expected false, but actual true\n");

    return false;
}

/**
 * @param places_precision util 6 places
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

#endif