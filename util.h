#ifndef __util_h__
#define __util_h__

#include "stdio.h"

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

#endif