#include "../src/util.h"

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

void test_ndigits() {
    assert_equal(1, cdigits(0));
    assert_equal(2, cdigits(11));
    assert_equal(2, cdigits(13));
    assert_equal(3, cdigits(137));
    assert_equal(4, cdigits(4887));
    assert_equal(10, cdigits(1234567890));
    assert_equal(10, cdigits(3797281624));
    assert_equal(10, cdigits(6585872435));
    assert_equal(10, cdigits(9468553006));
}

int main() {
    // test_assert_equal_double();
    // test_assert_equal_bool();
    test_ndigits();
}