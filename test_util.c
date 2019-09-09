#include "util.h"

void test_assert_equal_bool() {
    assert_equal(1, assert_equal_bool(false, false));
    assert_equal(0, assert_equal_bool(false, true));
    assert_equal(0, assert_equal_bool(true, false));
    assert_equal(1, assert_equal_bool(true, true));
}

void test_assert_equal_double() {
    assert_equal_bool(true, assert_equal_double(1, 1, 0));
    assert_equal_bool(true, assert_equal_double(1, 1, -1));
    assert_equal_bool(false, assert_equal_double(1, 2, 0));
    assert_equal_bool(false, assert_equal_double(1, 2, -1));
    assert_equal_bool(true, assert_equal_double(0.1, 0.1, 0));
    assert_equal_bool(true, assert_equal_double(0.1, 0.1, -1));
    assert_equal_bool(true, assert_equal_double(0.1, 0.2, 0));
    assert_equal_bool(true, assert_equal_double(0.1, 0.2, -1));
    assert_equal_bool(false, assert_equal_double(1, 2, 1));
    assert_equal_bool(false, assert_equal_double(0.1, 0.2, 1));
    assert_equal_bool(true, assert_equal_double(0.01, 0.02, 1));
    assert_equal_bool(true, assert_equal_double(0.000001, 0.000001, 6));
    assert_equal_bool(false, assert_equal_double(0.000001, 0.000002, 6));
}

int main() {
    test_assert_equal_double();
    // test_assert_equal_bool();
}